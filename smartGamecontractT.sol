// SPDX-License-Identifier: MIT
pragma solidity ^0.8.25;

import "forge-std/Test.sol";
import "../src/OracleGame.sol";
import "../src/interfaces/SupraOracle.sol";
import "../src/CheckInStorage.sol";

contract MockSupraOracle is ISupraOraclePull {
    function verifyOracleProofV2(bytes calldata) external view override returns (PriceInfo memory) {
        uint256[] memory pairs = new uint256[](2);
        pairs[0] = 1;
        pairs[1] = 0;
        uint256[] memory prices = new uint256[](2);
        prices[0] = 2000 * 10**18;
        prices[1] = 2000 * 10**18;
        uint256[] memory decimals = new uint256[](2);
        decimals[0] = 18;
        decimals[1] = 18;
        uint256[] memory roundIds = new uint256[](2);
        roundIds[0] = 1;
        roundIds[1] = 1;
        uint256[] memory timestamps = new uint256[](2);
        timestamps[0] = block.timestamp;
        timestamps[1] = block.timestamp;
        return PriceInfo(pairs, prices, timestamps, decimals, roundIds);
    }
}

contract MockCheckIn is ICheckIn {
    mapping(address => mapping(CheckInStorage.Task => uint256)) public taskPoints;

    function incrementTaskPoints(address user, CheckInStorage.Task task) external override {
        taskPoints[user][task]++;
    }

    function getReRolls(address) external pure override returns (uint256) {
        return 0;
    }

    function incrementPoints(address, uint8) external pure override {
        // Implementation not needed for these tests
    }

    function incrementFaucetPoints(address, string memory) external pure override {
        // Implementation not needed for these tests
    }

    function incrementNestPoints(address, uint256) external pure override {
        // Implementation not needed for these tests
    }
}

contract OracleGameTest is Test {
    OracleGame public game;
    MockSupraOracle public mockOracle;
    MockCheckIn public mockCheckIn;

    address public admin = address(1);
    address public user1 = address(2);
    address public user2 = address(3);
    address public user3 = address(4);
    address public user4 = address(5);

    uint256[] public pairs;
    uint256 public startTime;
    uint256 public pairDuration;
    uint256 public waitTime;
    uint256 public cooldownTime;

    function setUp() public {
        mockOracle = new MockSupraOracle();
        mockCheckIn = new MockCheckIn();

        pairs = new uint256[](2);
        pairs[0] = 1;
        pairs[1] = 0;
        startTime = block.timestamp + 1 hours;
        pairDuration = 1 days;
        waitTime = 1 hours;
        cooldownTime = 1 hours;

        game = new OracleGame();
        game.initialize(
            address(mockOracle),
            address(mockCheckIn),
            pairs,
            startTime,
            pairDuration,
            waitTime,
            cooldownTime,
            admin
        );
    }

    function testInitialize() public view {
        assert(game.oracle() == address(mockOracle));
        assert(game.checkIn() == address(mockCheckIn));
        assert(game.startTime() == startTime);
        assert(game.pairDuration() == pairDuration);
        assert(game.predictionWaitTime() == waitTime);
        assert(game.predictionCooldown() == cooldownTime);
        assert(game.currentPairIndex() == -1);
        assert(game.hasRole(game.DEFAULT_ADMIN_ROLE(), admin));
        assert(game.hasRole(game.UPGRADER_ROLE(), admin));
    }

    function testPredictPriceMovement() public {
        vm.warp(startTime + 1);
        vm.prank(user1);
        game.predictPriceMovement(0, true);

        assertTrue(game.userParticipated(user1));
        assertEq(game.firstPrediction(1), user1);
        assertEq(game.lastPrediction(1), user1);

        OracleGameStorage.PriceMovement memory movement = game.getPriceMovement(1, user1);
        assertEq(movement.timestamp, block.timestamp);
        assertEq(movement.originalPrice, 0);
        assertTrue(movement.isLong);
        assertFalse(movement.revealed);
        assertEq(movement.next, address(0));
    }

    function testPredictPriceMovementBeforeStart() public {
        vm.expectRevert("Game has not started yet");
        game.predictPriceMovement(0, true);
    }

    function testPredictPriceMovementCooldown() public {
        vm.warp(startTime + 1);
        vm.startPrank(user1);
        game.predictPriceMovement(0, true);

        vm.expectRevert("Wait for cooldown");
        game.predictPriceMovement(0, false);
        vm.stopPrank();
    }

    function testPullPairPrices() public {
        vm.warp(startTime + 1);
        vm.prank(user1);
        game.predictPriceMovement(0, true);

        vm.warp(startTime + waitTime + 2);
        game.pullPairPrices("");

        assertEq(game.getPairPrice(1), 2000 * 10**18);
        OracleGameStorage.PriceMovement memory movement = game.getPriceMovement(1, user1);
        assertTrue(movement.revealed);
    }

    function testSetOracle() public {
        address newOracle = address(4);
        vm.prank(admin);
        game.setOracle(newOracle);
        assertEq(game.oracle(), newOracle);
    }

    function testSetCheckIn() public {
        address newCheckIn = address(5);
        vm.prank(admin);
        game.setCheckIn(newCheckIn);
        assertEq(game.checkIn(), newCheckIn);
    }

    function testSetPairs() public {
        uint256[] memory newPairs = new uint256[](2);
        newPairs[0] = 1;
        newPairs[1] = 2;
        vm.prank(admin);
        game.setPairs(newPairs);
        assertEq(game.getAllPairs().length, 2);
        assertEq(game.getPair(1), 2);
    }

    function testSetStartTime() public {
        uint256 newStartTime = block.timestamp + 7200; // 2 hours
        vm.prank(admin);
        game.setStartTime(newStartTime);
        assertEq(game.startTime(), newStartTime);
    }

    function testSetWaitTime() public {
        uint256 newWaitTime = 7200; // 2 hours
        vm.prank(admin);
        game.setWaitTime(newWaitTime);
        assertEq(game.predictionWaitTime(), newWaitTime);
    }

    function testSetCooldownTime() public {
        uint256 newCooldownTime = 3600; // 1 hour
        vm.prank(admin);
        game.setCooldownTime(newCooldownTime);
        assertEq(game.predictionCooldown(), newCooldownTime);
    }

    function testGetUserParticipation() public {
        vm.warp(startTime + 1);
        vm.prank(user1);
        game.predictPriceMovement(0, true);

        address[] memory users = new address[](2);
        users[0] = user1;
        users[1] = user2;

        bool[] memory participation = game.getUserParticipation(users);
        assertTrue(participation[0]);
        assertFalse(participation[1]);
    }

    function testMultipleUserPredictions() public {
        vm.warp(startTime + 1);

        vm.prank(user1);
        game.predictPriceMovement(0, true);

        vm.warp(block.timestamp + cooldownTime + 1);

        vm.prank(user2);
        game.predictPriceMovement(0, false);

        vm.warp(startTime + pairDuration);

        vm.prank(user3);
        game.predictPriceMovement(1, true);

        vm.prank(user4);
        game.predictPriceMovement(1, false);

        assertEq(game.firstPrediction(1), user1);
        assertEq(game.lastPrediction(1), user2);

        assertEq(game.firstPrediction(0), user3);
        assertEq(game.lastPrediction(0), user4);

        OracleGameStorage.PriceMovement memory movement = game.getPriceMovement(1, user1);
        assertEq(movement.next, user2);

        OracleGameStorage.PriceMovement memory movement2 = game.getPriceMovement(0, user3);
        assertEq(movement2.next, user4);


    }

    function testPullPairPricesMultipleTimes() public {
        vm.warp(startTime + 1);

        vm.prank(user1);
        game.predictPriceMovement(0, true);

        vm.prank(user2);
        game.predictPriceMovement(0, false);

        vm.prank(user3);
        game.predictPriceMovement(0, true);

        vm.prank(user4);
        game.predictPriceMovement(0, false);

        vm.warp(startTime + waitTime + 2);
        game.pullPairPrices("");

        OracleGameStorage.PriceMovement memory movement1 = game.getPriceMovement(1, user1);
        OracleGameStorage.PriceMovement memory movement2 = game.getPriceMovement(1, user2);
        OracleGameStorage.PriceMovement memory movement3 = game.getPriceMovement(1, user3);
        OracleGameStorage.PriceMovement memory movement4 = game.getPriceMovement(1, user4);
        assertTrue(movement1.revealed);
        assertTrue(movement2.revealed);
        assertTrue(movement3.revealed);
        assertTrue(movement4.revealed);
    }
}	
	require(_value > 0, "Value must be positive");
	_;
	}
	
	// Fallback function
	fallback() external payable {
	    // Custom logic
	}
();}
