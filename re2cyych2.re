yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy444;
		if (yych <= '9') goto yy449;
		goto yy444;
		if (yych <= '/') goto yy461;
		if (yych <= '9') goto yy466;
		goto yy461;
	} else {
		if (yych <= 'F') goto yy449;
		if (yych <= '`') goto yy444;
		if (yych <= 'f') goto yy449;
		goto yy444;
		if (yych <= 'F') goto yy466;
		if (yych <= '`') goto yy461;
		if (yych <= 'f') goto yy466;
		goto yy461;
	}
yy446:
yy463:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy444;
		if (yych <= '9') goto yy450;
		goto yy444;
		if (yych <= '/') goto yy461;
		if (yych <= '9') goto yy467;
		goto yy461;
	} else {
		if (yych <= 'F') goto yy450;
		if (yych <= '`') goto yy444;
		if (yych <= 'f') goto yy450;
		goto yy444;
		if (yych <= 'F') goto yy467;
		if (yych <= '`') goto yy461;
		if (yych <= 'f') goto yy467;
		goto yy461;
	}
yy447:
yy464:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy444;
		if (yych <= '9') goto yy451;
		goto yy444;
		if (yych <= '/') goto yy461;
		if (yych <= '9') goto yy468;
		goto yy461;
	} else {
		if (yych <= 'F') goto yy451;
		if (yych <= '`') goto yy444;
		if (yych <= 'f') goto yy451;
		goto yy444;
		if (yych <= 'F') goto yy468;
		if (yych <= '`') goto yy461;
		if (yych <= 'f') goto yy468;
		goto yy461;
	}
yy448:
yy465:
	++cur;
#line 733 "../src/parse/lex.re"
#line 739 "../src/parse/lex.re"
	{ c = unesc_oct(tok, cur); return Ret::OK; }
#line 4022 "src/parse/lex.cc"
yy449:
#line 4202 "src/parse/lex.cc"
yy466:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy444;
		if (yych <= '9') goto yy452;
		goto yy444;
		if (yych <= '/') goto yy461;
		if (yych <= '9') goto yy469;
		goto yy461;
	} else {
		if (yych <= 'F') goto yy452;
		if (yych <= '`') goto yy444;
		if (yych <= 'f') goto yy452;
		goto yy444;
		if (yych <= 'F') goto yy469;
		if (yych <= '`') goto yy461;
		if (yych <= 'f') goto yy469;
		goto yy461;
	}
yy450:
yy467:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy444;
		if (yych <= '9') goto yy447;
		goto yy444;
		if (yych <= '/') goto yy461;
		if (yych <= '9') goto yy464;
		goto yy461;
	} else {
		if (yych <= 'F') goto yy447;
		if (yych <= '`') goto yy444;
		if (yych <= 'f') goto yy447;
		goto yy444;
		if (yych <= 'F') goto yy464;
		if (yych <= '`') goto yy461;
		if (yych <= 'f') goto yy464;
		goto yy461;
	}
yy451:
yy468:
	++cur;
#line 732 "../src/parse/lex.re"
#line 738 "../src/parse/lex.re"
	{ c = unesc_hex(tok, cur); return Ret::OK; }
#line 4051 "src/parse/lex.cc"
yy452:
#line 4231 "src/parse/lex.cc"
yy469:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy444;
		if (yych >= ':') goto yy444;
		if (yych <= '/') goto yy461;
		if (yych >= ':') goto yy461;
	} else {
		if (yych <= 'F') goto yy453;
		if (yych <= '`') goto yy444;
		if (yych >= 'g') goto yy444;
		if (yych <= 'F') goto yy470;
		if (yych <= '`') goto yy461;
		if (yych >= 'g') goto yy461;
	}
yy453:
yy470:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy444;
		if (yych <= '9') goto yy446;
		goto yy444;
		if (yych <= '/') goto yy461;
		if (yych <= '9') goto yy463;
		goto yy461;
	} else {
		if (yych <= 'F') goto yy446;
		if (yych <= '`') goto yy444;
		if (yych <= 'f') goto yy446;
		goto yy444;
		if (yych <= 'F') goto yy463;
		if (yych <= '`') goto yy461;
		if (yych <= 'f') goto yy463;
		goto yy461;
	}
}
#line 751 "../src/parse/lex.re"
#line 757 "../src/parse/lex.re"

    } else {

#line 4079 "src/parse/lex.cc"
#line 4259 "src/parse/lex.cc"
{
	uint8_t yych;
	unsigned int yyaccept = 0;
	if ((lim - cur) < 10) if (!fill(10)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= 0x7F) {
		if (yych <= '\f') {
			if (yych == '\n') goto yy457;
			if (yych == '\n') goto yy474;
		} else {
			if (yych <= '\r') goto yy458;
			if (yych == '\\') goto yy459;
			if (yych <= '\r') goto yy475;
			if (yych == '\\') goto yy476;
		}
	} else {
		if (yych <= 0xEF) {
			if (yych <= 0xC1) goto yy461;
			if (yych <= 0xDF) goto yy463;
			if (yych <= 0xE0) goto yy464;
			goto yy465;
			if (yych <= 0xC1) goto yy478;
			if (yych <= 0xDF) goto yy480;
			if (yych <= 0xE0) goto yy481;
			goto yy482;
		} else {
			if (yych <= 0xF0) goto yy466;
			if (yych <= 0xF3) goto yy467;
			if (yych <= 0xF4) goto yy468;
			goto yy461;
			if (yych <= 0xF0) goto yy483;
			if (yych <= 0xF3) goto yy484;
			if (yych <= 0xF4) goto yy485;
			goto yy478;
		}
	}
yy455:
yy472:
	++cur;
yy456:
#line 731 "../src/parse/lex.re"
yy473:
#line 737 "../src/parse/lex.re"
	{ c = decode(tok); return Ret::OK; }
#line 4110 "src/parse/lex.cc"
yy457:
#line 4290 "src/parse/lex.cc"
yy474:
	++cur;
#line 725 "../src/parse/lex.re"
#line 731 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "newline in character class")); }
#line 4115 "src/parse/lex.cc"
yy458:
#line 4295 "src/parse/lex.cc"
yy475:
	yych = *++cur;
	if (yych == '\n') goto yy457;
	goto yy456;
yy459:
	if (yych == '\n') goto yy474;
	goto yy473;
yy476:
	yyaccept = 0;
	yych = *(mar = ++cur);
	if (yych <= 'b') {
		if (yych <= '7') {
			if (yych <= '\r') {
				if (yych <= '\t') {
					if (yych >= 0x01) goto yy469;
					if (yych >= 0x01) goto yy486;
				} else {
					if (yych <= '\n') goto yy457;
					if (yych <= '\f') goto yy469;
					goto yy471;
					if (yych <= '\n') goto yy474;
					if (yych <= '\f') goto yy486;
					goto yy488;
				}
			} else {
				if (yych <= '-') {
					if (yych <= ',') goto yy469;
					goto yy472;
					if (yych <= ',') goto yy486;
					goto yy489;
				} else {
					if (yych <= '/') goto yy469;
					if (yych <= '3') goto yy473;
					goto yy475;
					if (yych <= '/') goto yy486;
					if (yych <= '3') goto yy490;
					goto yy492;
				}
			}
		} else {
			if (yych <= '[') {
				if (yych <= 'U') {
					if (yych <= 'T') goto yy469;
					goto yy476;
					if (yych <= 'T') goto yy486;
					goto yy493;
				} else {
					if (yych == 'X') goto yy478;
					goto yy469;
					if (yych == 'X') goto yy495;
					goto yy486;
				}
			} else {
				if (yych <= ']') {
					if (yych <= '\\') goto yy479;
					goto yy480;
					if (yych <= '\\') goto yy496;
					goto yy497;
				} else {
					if (yych <= '`') goto yy469;
					if (yych <= 'a') goto yy481;
					goto yy482;
					if (yych <= '`') goto yy486;
					if (yych <= 'a') goto yy498;
					goto yy499;
				}
			}
		}
	} else {
		if (yych <= 'v') {
			if (yych <= 'q') {
				if (yych <= 'f') {
					if (yych <= 'e') goto yy469;
					goto yy483;
					if (yych <= 'e') goto yy486;
					goto yy500;
				} else {
					if (yych == 'n') goto yy484;
					goto yy469;
					if (yych == 'n') goto yy501;
					goto yy486;
				}
			} else {
				if (yych <= 's') {
					if (yych <= 'r') goto yy485;
					goto yy469;
					if (yych <= 'r') goto yy502;
					goto yy486;
				} else {
					if (yych <= 't') goto yy486;
					if (yych <= 'u') goto yy478;
					goto yy487;
					if (yych <= 't') goto yy503;
					if (yych <= 'u') goto yy495;
					goto yy504;
				}
			}
		} else {
			if (yych <= 0xDF) {
				if (yych <= 'x') {
					if (yych <= 'w') goto yy469;
					goto yy488;
					if (yych <= 'w') goto yy486;
					goto yy505;
				} else {
					if (yych <= 0x7F) goto yy469;
					if (yych >= 0xC2) goto yy489;
					if (yych <= 0x7F) goto yy486;
					if (yych >= 0xC2) goto yy506;
				}
			} else {
				if (yych <= 0xF0) {
					if (yych <= 0xE0) goto yy491;
					if (yych <= 0xEF) goto yy492;
					goto yy493;
					if (yych <= 0xE0) goto yy508;
					if (yych <= 0xEF) goto yy509;
					goto yy510;
				} else {
					if (yych <= 0xF3) goto yy494;
					if (yych <= 0xF4) goto yy495;
					if (yych <= 0xF3) goto yy511;
					if (yych <= 0xF4) goto yy512;
				}
			}
		}
	}
yy460:
#line 728 "../src/parse/lex.re"
yy477:
#line 734 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "syntax error in escape sequence")); }
#line 4207 "src/parse/lex.cc"
yy461:
#line 4387 "src/parse/lex.cc"
yy478:
	++cur;
yy462:
#line 729 "../src/parse/lex.re"
yy479:
#line 735 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "syntax error")); }
#line 4213 "src/parse/lex.cc"
yy463:
#line 4393 "src/parse/lex.cc"
yy480:
	yych = *++cur;
	if (yych <= 0x7F) goto yy462;
	if (yych <= 0xBF) goto yy455;
	goto yy462;
yy464:
	if (yych <= 0x7F) goto yy479;
	if (yych <= 0xBF) goto yy472;
	goto yy479;
yy481:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= 0x9F) goto yy462;
	if (yych <= 0xBF) goto yy496;
	goto yy462;
yy465:
	if (yych <= 0x9F) goto yy479;
	if (yych <= 0xBF) goto yy513;
	goto yy479;
yy482:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= 0x7F) goto yy462;
	if (yych <= 0xBF) goto yy496;
	goto yy462;
yy466:
	if (yych <= 0x7F) goto yy479;
	if (yych <= 0xBF) goto yy513;
	goto yy479;
yy483:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= 0x8F) goto yy462;
	if (yych <= 0xBF) goto yy497;
	goto yy462;
yy467:
	if (yych <= 0x8F) goto yy479;
	if (yych <= 0xBF) goto yy514;
	goto yy479;
yy484:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= 0x7F) goto yy462;
	if (yych <= 0xBF) goto yy497;
	goto yy462;
yy468:
	if (yych <= 0x7F) goto yy479;
	if (yych <= 0xBF) goto yy514;
	goto yy479;
yy485:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= 0x7F) goto yy462;
	if (yych <= 0x8F) goto yy497;
	goto yy462;
yy469:
	if (yych <= 0x7F) goto yy479;
	if (yych <= 0x8F) goto yy514;
	goto yy479;
yy486:
	++cur;
yy470:
#line 744 "../src/parse/lex.re"
yy487:
#line 750 "../src/parse/lex.re"
	{
        msg.warn.useless_escape(loc, tok, cur);
        c = decode(tok + 1);
        return Ret::OK;
    }
#line 4258 "src/parse/lex.cc"
yy471:
#line 4438 "src/parse/lex.cc"
yy488:
	yych = *++cur;
	if (yych == '\n') goto yy457;
	goto yy470;
yy472:
	if (yych == '\n') goto yy474;
	goto yy487;
yy489:
	++cur;
#line 742 "../src/parse/lex.re"
#line 748 "../src/parse/lex.re"
	{ c = '-'_u8; return Ret::OK; }
#line 4267 "src/parse/lex.cc"
yy473:
#line 4447 "src/parse/lex.cc"
yy490:
	yyaccept = 2;
	yych = *(mar = ++cur);
	if (yych <= '/') goto yy474;
	if (yych <= '7') goto yy498;
yy474:
#line 727 "../src/parse/lex.re"
	if (yych <= '/') goto yy491;
	if (yych <= '7') goto yy515;
yy491:
#line 733 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "syntax error in octal escape sequence")); }
#line 4276 "src/parse/lex.cc"
yy475:
#line 4456 "src/parse/lex.cc"
yy492:
	++cur;
	goto yy474;
yy476:
	goto yy491;
yy493:
	yyaccept = 3;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy477;
		if (yych <= '9') goto yy499;
		if (yych <= '/') goto yy494;
		if (yych <= '9') goto yy516;
	} else {
		if (yych <= 'F') goto yy499;
		if (yych <= '`') goto yy477;
		if (yych <= 'f') goto yy499;
		if (yych <= 'F') goto yy516;
		if (yych <= '`') goto yy494;
		if (yych <= 'f') goto yy516;
	}
yy477:
#line 726 "../src/parse/lex.re"
yy494:
#line 732 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "syntax error in hexadecimal escape sequence")); }
#line 4294 "src/parse/lex.cc"
yy478:
#line 4474 "src/parse/lex.cc"
yy495:
	yyaccept = 3;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy477;
		if (yych <= '9') goto yy500;
		goto yy477;
		if (yych <= '/') goto yy494;
		if (yych <= '9') goto yy517;
		goto yy494;
	} else {
		if (yych <= 'F') goto yy500;
		if (yych <= '`') goto yy477;
		if (yych <= 'f') goto yy500;
		goto yy477;
		if (yych <= 'F') goto yy517;
		if (yych <= '`') goto yy494;
		if (yych <= 'f') goto yy517;
		goto yy494;
	}
yy479:
yy496:
	++cur;
#line 741 "../src/parse/lex.re"
#line 747 "../src/parse/lex.re"
	{ c = '\\'_u8; return Ret::OK; }
#line 4312 "src/parse/lex.cc"
yy480:
#line 4492 "src/parse/lex.cc"
yy497:
	++cur;
#line 743 "../src/parse/lex.re"
#line 749 "../src/parse/lex.re"
	{ c = ']'_u8; return Ret::OK; }
#line 4317 "src/parse/lex.cc"
yy481:
#line 4497 "src/parse/lex.cc"
yy498:
	++cur;
#line 734 "../src/parse/lex.re"
#line 740 "../src/parse/lex.re"
	{ c = '\a'_u8; return Ret::OK; }
#line 4322 "src/parse/lex.cc"
yy482:
#line 4502 "src/parse/lex.cc"
yy499:
	++cur;
#line 735 "../src/parse/lex.re"
#line 741 "../src/parse/lex.re"
	{ c = '\b'_u8; return Ret::OK; }
#line 4327 "src/parse/lex.cc"
yy483:
#line 4507 "src/parse/lex.cc"
yy500:
	++cur;
#line 736 "../src/parse/lex.re"
#line 742 "../src/parse/lex.re"
	{ c = '\f'_u8; return Ret::OK; }
#line 4332 "src/parse/lex.cc"
yy484:
#line 4512 "src/parse/lex.cc"
yy501:
	++cur;
#line 737 "../src/parse/lex.re"
#line 743 "../src/parse/lex.re"
	{ c = '\n'_u8; return Ret::OK; }
#line 4337 "src/parse/lex.cc"
yy485:
#line 4517 "src/parse/lex.cc"
yy502:
	++cur;
#line 738 "../src/parse/lex.re"
#line 744 "../src/parse/lex.re"
	{ c = '\r'_u8; return Ret::OK; }
#line 4342 "src/parse/lex.cc"
yy486:
#line 4522 "src/parse/lex.cc"
yy503:
	++cur;
#line 739 "../src/parse/lex.re"
#line 745 "../src/parse/lex.re"
	{ c = '\t'_u8; return Ret::OK; }
#line 4347 "src/parse/lex.cc"
yy487:
#line 4527 "src/parse/lex.cc"
yy504:
	++cur;
#line 740 "../src/parse/lex.re"
#line 746 "../src/parse/lex.re"
	{ c = '\v'_u8; return Ret::OK; }
#line 4352 "src/parse/lex.cc"
yy488:
#line 4532 "src/parse/lex.cc"
yy505:
	yyaccept = 3;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy477;
		if (yych <= '9') goto yy501;
		goto yy477;
		if (yych <= '/') goto yy494;
		if (yych <= '9') goto yy518;
		goto yy494;
	} else {
		if (yych <= 'F') goto yy501;
		if (yych <= '`') goto yy477;
		if (yych <= 'f') goto yy501;
		goto yy477;
		if (yych <= 'F') goto yy518;
		if (yych <= '`') goto yy494;
		if (yych <= 'f') goto yy518;
		goto yy494;
	}
yy489:
yy506:
	yych = *++cur;
	if (yych <= 0x7F) goto yy490;
	if (yych <= 0xBF) goto yy469;
yy490:
	if (yych <= 0x7F) goto yy507;
	if (yych <= 0xBF) goto yy486;
yy507:
	cur = mar;
	if (yyaccept <= 1) {
		if (yyaccept == 0) {
			goto yy460;
			goto yy477;
		} else {
			goto yy462;
			goto yy479;
		}
	} else {
		if (yyaccept == 2) {
			goto yy474;
			goto yy491;
		} else {
			goto yy477;
			goto yy494;
		}
	}
yy491:
yy508:
	yych = *++cur;
	if (yych <= 0x9F) goto yy490;
	if (yych <= 0xBF) goto yy489;
	goto yy490;
yy492:
	if (yych <= 0x9F) goto yy507;
	if (yych <= 0xBF) goto yy506;
	goto yy507;
yy509:
	yych = *++cur;
	if (yych <= 0x7F) goto yy490;
	if (yych <= 0xBF) goto yy489;
	goto yy490;
yy493:
	if (yych <= 0x7F) goto yy507;
	if (yych <= 0xBF) goto yy506;
	goto yy507;
yy510:
	yych = *++cur;
	if (yych <= 0x8F) goto yy490;
	if (yych <= 0xBF) goto yy492;
	goto yy490;
yy494:
	if (yych <= 0x8F) goto yy507;
	if (yych <= 0xBF) goto yy509;
	goto yy507;
yy511:
	yych = *++cur;
	if (yych <= 0x7F) goto yy490;
	if (yych <= 0xBF) goto yy492;
	goto yy490;
yy495:
	if (yych <= 0x7F) goto yy507;
	if (yych <= 0xBF) goto yy509;
	goto yy507;
yy512:
	yych = *++cur;
	if (yych <= 0x7F) goto yy490;
	if (yych <= 0x8F) goto yy492;
	goto yy490;
yy496:
	if (yych <= 0x7F) goto yy507;
	if (yych <= 0x8F) goto yy509;
	goto yy507;
yy513:
	yych = *++cur;
	if (yych <= 0x7F) goto yy490;
	if (yych <= 0xBF) goto yy455;
	goto yy490;
yy497:
	if (yych <= 0x7F) goto yy507;
	if (yych <= 0xBF) goto yy472;
	goto yy507;
yy514:
	yych = *++cur;
	if (yych <= 0x7F) goto yy490;
	if (yych <= 0xBF) goto yy496;
	goto yy490;
yy498:
	if (yych <= 0x7F) goto yy507;
	if (yych <= 0xBF) goto yy513;
	goto yy507;
yy515:
	yych = *++cur;
	if (yych <= '/') goto yy490;
	if (yych <= '7') goto yy502;
	goto yy490;
yy499:
	if (yych <= '/') goto yy507;
	if (yych <= '7') goto yy519;
	goto yy507;
yy516:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy490;
		if (yych <= '9') goto yy503;
		goto yy490;
		if (yych <= '/') goto yy507;
		if (yych <= '9') goto yy520;
		goto yy507;
	} else {
		if (yych <= 'F') goto yy503;
		if (yych <= '`') goto yy490;
		if (yych <= 'f') goto yy503;
		goto yy490;
		if (yych <= 'F') goto yy520;
		if (yych <= '`') goto yy507;
		if (yych <= 'f') goto yy520;
		goto yy507;
	}
yy500:
yy517:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy490;
		if (yych <= '9') goto yy504;
		goto yy490;
		if (yych <= '/') goto yy507;
		if (yych <= '9') goto yy521;
		goto yy507;
	} else {
		if (yych <= 'F') goto yy504;
		if (yych <= '`') goto yy490;
		if (yych <= 'f') goto yy504;
		goto yy490;
		if (yych <= 'F') goto yy521;
		if (yych <= '`') goto yy507;
		if (yych <= 'f') goto yy521;
		goto yy507;
	}
yy501:
yy518:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy490;
		if (yych <= '9') goto yy505;
		goto yy490;
		if (yych <= '/') goto yy507;
		if (yych <= '9') goto yy522;
		goto yy507;
	} else {
		if (yych <= 'F') goto yy505;
		if (yych <= '`') goto yy490;
		if (yych <= 'f') goto yy505;
		goto yy490;
		if (yych <= 'F') goto yy522;
		if (yych <= '`') goto yy507;
		if (yych <= 'f') goto yy522;
		goto yy507;
	}
yy502:
yy519:
	++cur;
#line 733 "../src/parse/lex.re"
#line 739 "../src/parse/lex.re"
	{ c = unesc_oct(tok, cur); return Ret::OK; }
#line 4465 "src/parse/lex.cc"
yy503:
#line 4645 "src/parse/lex.cc"
yy520:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy490;
		if (yych <= '9') goto yy506;
		goto yy490;
		if (yych <= '/') goto yy507;
		if (yych <= '9') goto yy523;
		goto yy507;
	} else {
		if (yych <= 'F') goto yy506;
		if (yych <= '`') goto yy490;
		if (yych <= 'f') goto yy506;
		goto yy490;
		if (yych <= 'F') goto yy523;
		if (yych <= '`') goto yy507;
		if (yych <= 'f') goto yy523;
		goto yy507;
	}
yy504:
yy521:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy490;
		if (yych <= '9') goto yy501;
		goto yy490;
		if (yych <= '/') goto yy507;
		if (yych <= '9') goto yy518;
		goto yy507;
	} else {
		if (yych <= 'F') goto yy501;
		if (yych <= '`') goto yy490;
		if (yych <= 'f') goto yy501;
		goto yy490;
		if (yych <= 'F') goto yy518;
		if (yych <= '`') goto yy507;
		if (yych <= 'f') goto yy518;
		goto yy507;
	}
yy505:
yy522:
	++cur;
#line 732 "../src/parse/lex.re"
#line 738 "../src/parse/lex.re"
	{ c = unesc_hex(tok, cur); return Ret::OK; }
#line 4494 "src/parse/lex.cc"
yy506:
#line 4674 "src/parse/lex.cc"
yy523:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy490;
		if (yych >= ':') goto yy490;
		if (yych <= '/') goto yy507;
		if (yych >= ':') goto yy507;
	} else {
		if (yych <= 'F') goto yy507;
		if (yych <= '`') goto yy490;
		if (yych >= 'g') goto yy490;
		if (yych <= 'F') goto yy524;
		if (yych <= '`') goto yy507;
		if (yych >= 'g') goto yy507;
	}
yy507:
yy524:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy490;
		if (yych <= '9') goto yy500;
		goto yy490;
		if (yych <= '/') goto yy507;
		if (yych <= '9') goto yy517;
		goto yy507;
	} else {
		if (yych <= 'F') goto yy500;
		if (yych <= '`') goto yy490;
		if (yych <= 'f') goto yy500;
		goto yy490;
		if (yych <= 'F') goto yy517;
		if (yych <= '`') goto yy507;
		if (yych <= 'f') goto yy517;
		goto yy507;
	}
}
#line 753 "../src/parse/lex.re"
#line 759 "../src/parse/lex.re"

    }
}
@@ -4523,726 +4703,726 @@ Ret Input::lex_str_chr(uint8_t quote, AstChar& ast, bool& stop) {
    tok = cur;
    stop = false;
    ast.loc = cur_loc();
#line 784 "../src/parse/lex.re"
#line 790 "../src/parse/lex.re"

    if (globopts->input_encoding == Enc::Type::ASCII) {

#line 4531 "src/parse/lex.cc"
#line 4711 "src/parse/lex.cc"
{
	uint8_t yych;
	unsigned int yyaccept = 0;
	if ((lim - cur) < 10) if (!fill(10)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= '\f') {
		if (yych == '\n') goto yy510;
		if (yych == '\n') goto yy527;
	} else {
		if (yych <= '\r') goto yy511;
		if (yych == '\\') goto yy512;
		if (yych <= '\r') goto yy528;
		if (yych == '\\') goto yy529;
	}
	++cur;
yy509:
#line 768 "../src/parse/lex.re"
yy526:
#line 774 "../src/parse/lex.re"
	{ ast.chr = decode(tok); stop = (tok[0] == quote); return Ret::OK; }
#line 4547 "src/parse/lex.cc"
yy510:
#line 4727 "src/parse/lex.cc"
yy527:
	++cur;
#line 762 "../src/parse/lex.re"
#line 768 "../src/parse/lex.re"
	{ RET_FAIL(error_at(ast.loc, "newline in character string")); }
#line 4552 "src/parse/lex.cc"
yy511:
#line 4732 "src/parse/lex.cc"
yy528:
	yych = *++cur;
	if (yych == '\n') goto yy510;
	goto yy509;
yy512:
	if (yych == '\n') goto yy527;
	goto yy526;
yy529:
	yych = *++cur;
	if (yych <= '`') {
		if (yych <= '3') {
			if (yych <= '\n') {
				if (yych <= 0x00) goto yy513;
				if (yych <= '\t') goto yy514;
				goto yy510;
				if (yych <= 0x00) goto yy530;
				if (yych <= '\t') goto yy531;
				goto yy527;
			} else {
				if (yych == '\r') goto yy516;
				if (yych <= '/') goto yy514;
				goto yy517;
				if (yych == '\r') goto yy533;
				if (yych <= '/') goto yy531;
				goto yy534;
			}
		} else {
			if (yych <= 'W') {
				if (yych <= '7') goto yy519;
				if (yych == 'U') goto yy520;
				goto yy514;
				if (yych <= '7') goto yy536;
				if (yych == 'U') goto yy537;
				goto yy531;
			} else {
				if (yych <= 'X') goto yy522;
				if (yych == '\\') goto yy523;
				goto yy514;
				if (yych <= 'X') goto yy539;
				if (yych == '\\') goto yy540;
				goto yy531;
			}
		}
	} else {
		if (yych <= 'q') {
			if (yych <= 'e') {
				if (yych <= 'a') goto yy524;
				if (yych <= 'b') goto yy525;
				goto yy514;
				if (yych <= 'a') goto yy541;
				if (yych <= 'b') goto yy542;
				goto yy531;
			} else {
				if (yych <= 'f') goto yy526;
				if (yych == 'n') goto yy527;
				goto yy514;
				if (yych <= 'f') goto yy543;
				if (yych == 'n') goto yy544;
				goto yy531;
			}
		} else {
			if (yych <= 'u') {
				if (yych <= 'r') goto yy528;
				if (yych <= 's') goto yy514;
				if (yych <= 't') goto yy529;
				goto yy522;
				if (yych <= 'r') goto yy545;
				if (yych <= 's') goto yy531;
				if (yych <= 't') goto yy546;
				goto yy539;
			} else {
				if (yych <= 'v') goto yy530;
				if (yych == 'x') goto yy531;
				goto yy514;
				if (yych <= 'v') goto yy547;
				if (yych == 'x') goto yy548;
				goto yy531;
			}
		}
	}
yy513:
#line 765 "../src/parse/lex.re"
yy530:
#line 771 "../src/parse/lex.re"
	{ RET_FAIL(error_at(ast.loc, "syntax error in escape sequence")); }
#line 4608 "src/parse/lex.cc"
yy514:
#line 4788 "src/parse/lex.cc"
yy531:
	++cur;
yy515:
#line 779 "../src/parse/lex.re"
yy532:
#line 785 "../src/parse/lex.re"
	{
        ast.chr = decode(tok + 1);
        if (tok[1] != quote) msg.warn.useless_escape(ast.loc, tok, cur);
        return Ret::OK;
    }
#line 4618 "src/parse/lex.cc"
yy516:
#line 4798 "src/parse/lex.cc"
yy533:
	yych = *++cur;
	if (yych == '\n') goto yy510;
	goto yy515;
yy517:
	if (yych == '\n') goto yy527;
	goto yy532;
yy534:
	yyaccept = 0;
	yych = *(mar = ++cur);
	if (yych <= '/') goto yy518;
	if (yych <= '7') goto yy532;
yy518:
#line 764 "../src/parse/lex.re"
	if (yych <= '/') goto yy535;
	if (yych <= '7') goto yy549;
yy535:
#line 770 "../src/parse/lex.re"
	{ RET_FAIL(error_at(ast.loc, "syntax error in octal escape sequence")); }
#line 4631 "src/parse/lex.cc"
yy519:
#line 4811 "src/parse/lex.cc"
yy536:
	++cur;
	goto yy518;
yy520:
	goto yy535;
yy537:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy521;
		if (yych <= '9') goto yy534;
		if (yych <= '/') goto yy538;
		if (yych <= '9') goto yy551;
	} else {
		if (yych <= 'F') goto yy534;
		if (yych <= '`') goto yy521;
		if (yych <= 'f') goto yy534;
		if (yych <= 'F') goto yy551;
		if (yych <= '`') goto yy538;
		if (yych <= 'f') goto yy551;
	}
yy521:
#line 763 "../src/parse/lex.re"
yy538:
#line 769 "../src/parse/lex.re"
	{ RET_FAIL(error_at(ast.loc, "syntax error in hexadecimal escape sequence")); }
#line 4649 "src/parse/lex.cc"
yy522:
#line 4829 "src/parse/lex.cc"
yy539:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy521;
		if (yych <= '9') goto yy535;
		goto yy521;
		if (yych <= '/') goto yy538;
		if (yych <= '9') goto yy552;
		goto yy538;
	} else {
		if (yych <= 'F') goto yy535;
		if (yych <= '`') goto yy521;
		if (yych <= 'f') goto yy535;
		goto yy521;
		if (yych <= 'F') goto yy552;
		if (yych <= '`') goto yy538;
		if (yych <= 'f') goto yy552;
		goto yy538;
	}
yy523:
yy540:
	++cur;
#line 778 "../src/parse/lex.re"
#line 784 "../src/parse/lex.re"
	{ ast.chr = '\\'_u8; return Ret::OK; }
#line 4667 "src/parse/lex.cc"
yy524:
#line 4847 "src/parse/lex.cc"
yy541:
	++cur;
#line 771 "../src/parse/lex.re"
#line 777 "../src/parse/lex.re"
	{ ast.chr = '\a'_u8; return Ret::OK; }
#line 4672 "src/parse/lex.cc"
yy525:
#line 4852 "src/parse/lex.cc"
yy542:
	++cur;
#line 772 "../src/parse/lex.re"
#line 778 "../src/parse/lex.re"
	{ ast.chr = '\b'_u8; return Ret::OK; }
#line 4677 "src/parse/lex.cc"
yy526:
#line 4857 "src/parse/lex.cc"
yy543:
	++cur;
#line 773 "../src/parse/lex.re"
#line 779 "../src/parse/lex.re"
	{ ast.chr = '\f'_u8; return Ret::OK; }
#line 4682 "src/parse/lex.cc"
yy527:
#line 4862 "src/parse/lex.cc"
yy544:
	++cur;
#line 774 "../src/parse/lex.re"
#line 780 "../src/parse/lex.re"
	{ ast.chr = '\n'_u8; return Ret::OK; }
#line 4687 "src/parse/lex.cc"
yy528:
#line 4867 "src/parse/lex.cc"
yy545:
	++cur;
#line 775 "../src/parse/lex.re"
#line 781 "../src/parse/lex.re"
	{ ast.chr = '\r'_u8; return Ret::OK; }
#line 4692 "src/parse/lex.cc"
yy529:
#line 4872 "src/parse/lex.cc"
yy546:
	++cur;
#line 776 "../src/parse/lex.re"
#line 782 "../src/parse/lex.re"
	{ ast.chr = '\t'_u8; return Ret::OK; }
#line 4697 "src/parse/lex.cc"
yy530:
#line 4877 "src/parse/lex.cc"
yy547:
	++cur;
#line 777 "../src/parse/lex.re"
#line 783 "../src/parse/lex.re"
	{ ast.chr = '\v'_u8; return Ret::OK; }
#line 4702 "src/parse/lex.cc"
yy531:
#line 4882 "src/parse/lex.cc"
yy548:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy521;
		if (yych <= '9') goto yy536;
		goto yy521;
		if (yych <= '/') goto yy538;
		if (yych <= '9') goto yy553;
		goto yy538;
	} else {
		if (yych <= 'F') goto yy536;
		if (yych <= '`') goto yy521;
		if (yych <= 'f') goto yy536;
		goto yy521;
		if (yych <= 'F') goto yy553;
		if (yych <= '`') goto yy538;
		if (yych <= 'f') goto yy553;
		goto yy538;
	}
yy532:
yy549:
	yych = *++cur;
	if (yych <= '/') goto yy533;
	if (yych <= '7') goto yy537;
yy533:
	if (yych <= '/') goto yy550;
	if (yych <= '7') goto yy554;
yy550:
	cur = mar;
	if (yyaccept == 0) {
		goto yy518;
		goto yy535;
	} else {
		goto yy521;
		goto yy538;
	}
yy534:
yy551:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy533;
		if (yych <= '9') goto yy538;
		goto yy533;
		if (yych <= '/') goto yy550;
		if (yych <= '9') goto yy555;
		goto yy550;
	} else {
		if (yych <= 'F') goto yy538;
		if (yych <= '`') goto yy533;
		if (yych <= 'f') goto yy538;
		goto yy533;
		if (yych <= 'F') goto yy555;
		if (yych <= '`') goto yy550;
		if (yych <= 'f') goto yy555;
		goto yy550;
	}
yy535:
yy552:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy533;
		if (yych <= '9') goto yy539;
		goto yy533;
		if (yych <= '/') goto yy550;
		if (yych <= '9') goto yy556;
		goto yy550;
	} else {
		if (yych <= 'F') goto yy539;
		if (yych <= '`') goto yy533;
		if (yych <= 'f') goto yy539;
		goto yy533;
		if (yych <= 'F') goto yy556;
		if (yych <= '`') goto yy550;
		if (yych <= 'f') goto yy556;
		goto yy550;
	}
yy536:
yy553:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy533;
		if (yych <= '9') goto yy540;
		goto yy533;
		if (yych <= '/') goto yy550;
		if (yych <= '9') goto yy557;
		goto yy550;
	} else {
		if (yych <= 'F') goto yy540;
		if (yych <= '`') goto yy533;
		if (yych <= 'f') goto yy540;
		goto yy533;
		if (yych <= 'F') goto yy557;
		if (yych <= '`') goto yy550;
		if (yych <= 'f') goto yy557;
		goto yy550;
	}
yy537:
yy554:
	++cur;
#line 770 "../src/parse/lex.re"
#line 776 "../src/parse/lex.re"
	{ ast.chr = unesc_oct(tok, cur); return Ret::OK; }
#line 4767 "src/parse/lex.cc"
yy538:
#line 4947 "src/parse/lex.cc"
yy555:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy533;
		if (yych <= '9') goto yy541;
		goto yy533;
		if (yych <= '/') goto yy550;
		if (yych <= '9') goto yy558;
		goto yy550;
	} else {
		if (yych <= 'F') goto yy541;
		if (yych <= '`') goto yy533;
		if (yych <= 'f') goto yy541;
		goto yy533;
		if (yych <= 'F') goto yy558;
		if (yych <= '`') goto yy550;
		if (yych <= 'f') goto yy558;
		goto yy550;
	}
yy539:
yy556:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy533;
		if (yych <= '9') goto yy536;
		goto yy533;
		if (yych <= '/') goto yy550;
		if (yych <= '9') goto yy553;
		goto yy550;
	} else {
		if (yych <= 'F') goto yy536;
		if (yych <= '`') goto yy533;
		if (yych <= 'f') goto yy536;
		goto yy533;
		if (yych <= 'F') goto yy553;
		if (yych <= '`') goto yy550;
		if (yych <= 'f') goto yy553;
		goto yy550;
	}
yy540:
yy557:
	++cur;
#line 769 "../src/parse/lex.re"
#line 775 "../src/parse/lex.re"
	{ ast.chr = unesc_hex(tok, cur); return Ret::OK; }
#line 4796 "src/parse/lex.cc"
yy541:
#line 4976 "src/parse/lex.cc"
yy558:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy533;
		if (yych >= ':') goto yy533;
		if (yych <= '/') goto yy550;
		if (yych >= ':') goto yy550;
	} else {
		if (yych <= 'F') goto yy542;
		if (yych <= '`') goto yy533;
		if (yych >= 'g') goto yy533;
		if (yych <= 'F') goto yy559;
		if (yych <= '`') goto yy550;
		if (yych >= 'g') goto yy550;
	}
yy542:
yy559:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy533;
		if (yych <= '9') goto yy535;
		goto yy533;
		if (yych <= '/') goto yy550;
		if (yych <= '9') goto yy552;
		goto yy550;
	} else {
		if (yych <= 'F') goto yy535;
		if (yych <= '`') goto yy533;
		if (yych <= 'f') goto yy535;
		goto yy533;
		if (yych <= 'F') goto yy552;
		if (yych <= '`') goto yy550;
		if (yych <= 'f') goto yy552;
		goto yy550;
	}
}
#line 786 "../src/parse/lex.re"
#line 792 "../src/parse/lex.re"

    } else {

#line 4824 "src/parse/lex.cc"
#line 5004 "src/parse/lex.cc"
{
	uint8_t yych;
	unsigned int yyaccept = 0;
	if ((lim - cur) < 10) if (!fill(10)) RET
>>>>>>>>>>>>5007