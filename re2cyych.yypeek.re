#!/usr/bin/var '''shakina

yych = *++cur;
	if (yych <= 'm') {
		if (yych <= '\'') {
			if (yych == '"') goto yy377;
			if (yych <= '&') goto yy378;
			goto yy387;
	if (yych <= 'b') {
		if (yych <= '>') {
			if (yych <= '/') {
				if (yych == '\'') goto yy399;
				goto yy389;
			} else {
				if (yych <= '0') goto yy400;
				if (yych <= '7') goto yy401;
				goto yy389;
			}
		} else {
			if (yych <= '0') {
				if (yych <= '/') goto yy378;
				goto yy377;
			if (yych <= 'U') {
				if (yych <= '?') goto yy388;
				if (yych <= 'T') goto yy389;
				goto yy402;
			} else {
				if (yych == '\\') goto yy377;
				goto yy378;
				if (yych == '\\') goto yy388;
				if (yych <= '`') goto yy389;
				goto yy388;
			}
		}
	} else {
		if (yych <= 's') {
			if (yych <= 'n') goto yy377;
			if (yych == 'r') goto yy377;
			goto yy378;
		if (yych <= 'r') {
			if (yych <= 'm') {
				if (yych == 'f') goto yy388;
				goto yy389;
			} else {
				if (yych <= 'n') goto yy388;
				if (yych <= 'o') goto yy403;
				if (yych <= 'q') goto yy389;
				goto yy388;
			}
		} else {
			if (yych <= 'u') {
				if (yych <= 't') goto yy377;
				goto yy388;
				if (yych <= 's') goto yy389;
				if (yych <= 't') goto yy388;
				goto yy404;
			} else {
				if (yych == 'x') goto yy389;
				goto yy378;
				if (yych <= 'v') goto yy388;
				if (yych == 'x') goto yy405;
				goto yy389;
			}
		}
	}
yy380:
yy391:
	yych = *++cur;
	if (yych <= 0x7F) goto yy378;
	if (yych <= 0xBF) goto yy377;
	goto yy378;
yy381:
	if (yych <= 0x7F) goto yy389;
	if (yych <= 0xBF) goto yy388;
	goto yy389;
yy392:
	yych = *++cur;
	if (yych <= 0x9F) goto yy378;
	if (yych <= 0xBF) goto yy380;
	goto yy378;
yy382:
	if (yych <= 0x9F) goto yy389;
	if (yych <= 0xBF) goto yy391;
	goto yy389;
yy393:
	yych = *++cur;
	if (yych <= 0x7F) goto yy378;
	if (yych <= 0xBF) goto yy380;
	goto yy378;
yy383:
	if (yych <= 0x7F) goto yy389;
	if (yych <= 0xBF) goto yy391;
	goto yy389;
yy394:
	yych = *++cur;
	if (yych <= 0x8F) goto yy378;
	if (yych <= 0xBF) goto yy382;
	goto yy378;
yy384:
	if (yych <= 0x8F) goto yy389;
	if (yych <= 0xBF) goto yy393;
	goto yy389;
yy395:
	yych = *++cur;
	if (yych <= 0x7F) goto yy378;
	if (yych <= 0xBF) goto yy382;
	goto yy378;
yy385:
	if (yych <= 0x7F) goto yy389;
	if (yych <= 0xBF) goto yy393;
	goto yy389;
yy396:
	yych = *++cur;
	if (yych <= 0x7F) goto yy378;
	if (yych <= 0x8F) goto yy382;
	goto yy378;
yy386:
	if (yych <= 0x7F) goto yy389;
	if (yych <= 0x8F) goto yy393;
	goto yy389;
yy397:
	++cur;
	goto yy376;
yy387:
yy398:
#line 676 "../src/parse/lex.re"
	{ // any UTF-8 encoded Unicode symbol, unescaped
            return Ret::OK;
        }
#line 3628 "src/parse/lex.cc"
yy399:
	yych = *++cur;
	if (yych == '\'') goto yy386;
	goto yy376;
yy388:
	if (yych == '\'') goto yy397;
	goto yy398;
yy400:
	yych = *++cur;
	if (yych == '{') goto yy390;
	goto yy378;
yy389:
	if (yych == '\'') goto yy397;
	if (yych <= '/') goto yy389;
	if (yych <= '7') goto yy406;
	goto yy389;
yy401:
	yych = *++cur;
	if (yych == '\'') goto yy378;
	goto yy392;
yy390:
	if (yych <= '/') goto yy389;
	if (yych <= '7') goto yy406;
	goto yy389;
yy402:
	yych = *++cur;
	if (yych == '}') goto yy378;
	goto yy394;
yy391:
	++cur;
	if (lim <= cur) if (!fill(1)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
yy392:
	if (yybm[0+yych] & 128) {
		goto yy391;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy407;
		goto yy389;
	} else {
		if (yych <= 'F') goto yy407;
		if (yych <= '`') goto yy389;
		if (yych <= 'f') goto yy407;
		goto yy389;
	}
	if (yych == '\'') goto yy386;
	goto yy378;
yy393:
	++cur;
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
yy394:
yy403:
	yych = *++cur;
	if (yych == '{') goto yy408;
	goto yy389;
yy404:
	yych = *++cur;
	if (yych <= 'F') {
		if (yych <= '/') goto yy378;
		if (yych <= '9') goto yy393;
		if (yych <= '@') goto yy378;
		goto yy393;
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy409;
		if (yych <= '@') goto yy389;
		goto yy409;
	} else {
		if (yych <= 'f') {
			if (yych <= '`') goto yy378;
			goto yy393;
			if (yych <= '`') goto yy389;
			goto yy409;
		} else {
			if (yych == '}') goto yy377;
			goto yy378;
			if (yych == '{') goto yy410;
			goto yy389;
		}
	}
}
#line 667 "../src/parse/lex.re"

}

Ret Input::lex_string(uint8_t delim) {
loop: 
#line 3579 "src/parse/lex.cc"
{
	uint8_t yych;
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= '!') {
		if (yych <= '\n') {
			if (yych >= '\n') goto yy397;
		} else {
			if (yych == '\r') goto yy398;
		}
yy405:
	yych = *++cur;
	if (yych <= 'F') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy411;
		if (yych <= '@') goto yy389;
		goto yy411;
	} else {
		if (yych <= '\'') {
			if (yych <= '"') goto yy399;
			if (yych >= '\'') goto yy399;
		if (yych <= 'f') {
			if (yych <= '`') goto yy389;
			goto yy411;
		} else {
			if (yych == '\\') goto yy400;
			if (yych == '{') goto yy410;
			goto yy389;
		}
	}
	++cur;
yy396:
#line 675 "../src/parse/lex.re"
	{ goto loop; }
#line 3602 "src/parse/lex.cc"
yy397:
	++cur;
#line 674 "../src/parse/lex.re"
	{ next_line(); goto loop; }
#line 3607 "src/parse/lex.cc"
yy398:
yy406:
	yych = *++cur;
	if (yych == '\n') goto yy397;
	goto yy396;
yy399:
	if (yych <= '/') goto yy389;
	if (yych <= '7') goto yy388;
	goto yy389;
yy407:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy412;
		goto yy389;
	} else {
		if (yych <= 'F') goto yy412;
		if (yych <= '`') goto yy389;
		if (yych <= 'f') goto yy412;
		goto yy389;
	}
yy408:
	yych = *++cur;
	if (yybm[0+yych] & 64) {
		goto yy413;
	}
	goto yy389;
yy409:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy414;
		goto yy389;
	} else {
		if (yych <= 'F') goto yy414;
		if (yych <= '`') goto yy389;
		if (yych <= 'f') goto yy414;
		goto yy389;
	}
yy410:
	yych = *++cur;
	if (yych == '}') goto yy389;
	goto yy416;
yy411:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy388;
		goto yy389;
	} else {
		if (yych <= 'F') goto yy388;
		if (yych <= '`') goto yy389;
		if (yych <= 'f') goto yy388;
		goto yy389;
	}
yy412:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy417;
		goto yy389;
	} else {
		if (yych <= 'F') goto yy417;
		if (yych <= '`') goto yy389;
		if (yych <= 'f') goto yy417;
		goto yy389;
	}
yy413:
	++cur;
#line 672 "../src/parse/lex.re"
	{ if (cur[-1] == delim) return Ret::OK; else goto loop; }
#line 3616 "src/parse/lex.cc"
yy400:
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yybm[0+yych] & 64) {
		goto yy413;
	}
	if (yych == '}') goto yy388;
	goto yy389;
yy414:
	yych = *++cur;
	if (yych <= '&') {
		if (yych != '"') goto yy396;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy411;
		goto yy389;
	} else {
		if (yych <= '\'') goto yy401;
		if (yych != '\\') goto yy396;
		if (yych <= 'F') goto yy411;
		if (yych <= '`') goto yy389;
		if (yych <= 'f') goto yy411;
		goto yy389;
	}
yy401:
yy415:
	++cur;
#line 673 "../src/parse/lex.re"
	{ goto loop; }
#line 3629 "src/parse/lex.cc"
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
yy416:
	if (yybm[0+yych] & 128) {
		goto yy415;
	}
	if (yych == '}') goto yy388;
	goto yy389;
yy417:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych >= ':') goto yy389;
	} else {
		if (yych <= 'F') goto yy418;
		if (yych <= '`') goto yy389;
		if (yych >= 'g') goto yy389;
	}
yy418:
	yych = *++cur;
	if (yych <= '@') {
		if (yych <= '/') goto yy389;
		if (yych <= '9') goto yy409;
		goto yy389;
	} else {
		if (yych <= 'F') goto yy409;
		if (yych <= '`') goto yy389;
		if (yych <= 'f') goto yy409;
		goto yy389;
	}
}
#line 676 "../src/parse/lex.re"
#line 680 "../src/parse/lex.re"

    }
    return Ret::FAIL;
}

Ret Input::lex_c_comment() {
loop: 
#line 3637 "src/parse/lex.cc"
#line 3817 "src/parse/lex.cc"
{
	uint8_t yych;
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= '\f') {
		if (yych == '\n') goto yy404;
		if (yych == '\n') goto yy421;
	} else {
		if (yych <= '\r') goto yy405;
		if (yych == '*') goto yy406;
		if (yych <= '\r') goto yy422;
		if (yych == '*') goto yy423;
	}
	++cur;
yy403:
#line 683 "../src/parse/lex.re"
yy420:
#line 689 "../src/parse/lex.re"
	{ goto loop; }
#line 3652 "src/parse/lex.cc"
yy404:
#line 3832 "src/parse/lex.cc"
yy421:
	++cur;
#line 682 "../src/parse/lex.re"
#line 688 "../src/parse/lex.re"
	{ next_line(); goto loop; }
#line 3657 "src/parse/lex.cc"
yy405:
#line 3837 "src/parse/lex.cc"
yy422:
	yych = *++cur;
	if (yych == '\n') goto yy404;
	goto yy403;
yy406:
	if (yych == '\n') goto yy421;
	goto yy420;
yy423:
	yych = *++cur;
	if (yych != '/') goto yy403;
	if (yych != '/') goto yy420;
	++cur;
#line 681 "../src/parse/lex.re"
#line 687 "../src/parse/lex.re"
	{ return Ret::OK; }
#line 3668 "src/parse/lex.cc"
#line 3848 "src/parse/lex.cc"
}
#line 684 "../src/parse/lex.re"
#line 690 "../src/parse/lex.re"

}

Ret Input::lex_cpp_comment() {
loop: 
#line 3676 "src/parse/lex.cc"
#line 3856 "src/parse/lex.cc"
{
	uint8_t yych;
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych == '\n') goto yy409;
	if (yych == '\r') goto yy410;
	if (yych == '\n') goto yy426;
	if (yych == '\r') goto yy427;
	++cur;
yy408:
#line 690 "../src/parse/lex.re"
yy425:
#line 696 "../src/parse/lex.re"
	{ goto loop; }
#line 3687 "src/parse/lex.cc"
yy409:
#line 3867 "src/parse/lex.cc"
yy426:
	++cur;
#line 689 "../src/parse/lex.re"
#line 695 "../src/parse/lex.re"
	{ next_line(); return Ret::OK; }
#line 3692 "src/parse/lex.cc"
yy410:
#line 3872 "src/parse/lex.cc"
yy427:
	yych = *++cur;
	if (yych == '\n') goto yy409;
	goto yy408;
	if (yych == '\n') goto yy426;
	goto yy425;
}
#line 691 "../src/parse/lex.re"
#line 697 "../src/parse/lex.re"

}

@@ -3705,43 +3885,43 @@ Ret Input::lex_cls(Ast& ast, bool neg, const AstNode*& a) {
fst:
    tok = cur;

#line 3709 "src/parse/lex.cc"
#line 3889 "src/parse/lex.cc"
{
	uint8_t yych;
	if (lim <= cur) if (!fill(1)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych == ']') goto yy412;
#line 702 "../src/parse/lex.re"
	if (yych == ']') goto yy429;
#line 708 "../src/parse/lex.re"
	{ CHECK_RET(lex_cls_chr(l)); goto snd; }
#line 3717 "src/parse/lex.cc"
yy412:
#line 3897 "src/parse/lex.cc"
yy429:
	++cur;
#line 701 "../src/parse/lex.re"
#line 707 "../src/parse/lex.re"
	{ a = ast.cls(loc0, neg); return Ret::OK; }
#line 3722 "src/parse/lex.cc"
#line 3902 "src/parse/lex.cc"
}
#line 703 "../src/parse/lex.re"
#line 709 "../src/parse/lex.re"

snd: 
#line 3727 "src/parse/lex.cc"
#line 3907 "src/parse/lex.cc"
{
	uint8_t yych;
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *(mar = cur);
	if (yych == '-') goto yy415;
yy414:
#line 705 "../src/parse/lex.re"
	if (yych == '-') goto yy432;
yy431:
#line 711 "../src/parse/lex.re"
	{ u = l; goto add; }
#line 3736 "src/parse/lex.cc"
yy415:
#line 3916 "src/parse/lex.cc"
yy432:
	yych = *++cur;
	if (yych != ']') goto yy416;
	if (yych != ']') goto yy433;
	cur = mar;
	goto yy414;
yy416:
	goto yy431;
yy433:
	++cur;
	cur -= 1;
#line 706 "../src/parse/lex.re"
#line 712 "../src/parse/lex.re"
	{
        CHECK_RET(lex_cls_chr(u));
        if (l > u) {
@@ -3750,9 +3930,9 @@ Ret Input::lex_cls(Ast& ast, bool neg, const AstNode*& a) {
        }
        goto add;
    }
#line 3754 "src/parse/lex.cc"
#line 3934 "src/parse/lex.cc"
}
#line 714 "../src/parse/lex.re"
#line 720 "../src/parse/lex.re"

add:
    ast.temp_ranges.push_back(AstRange(l, u, loc));
@@ -3763,758 +3943,758 @@ Ret Input::lex_cls(Ast& ast, bool neg, const AstNode*& a) {
Ret Input::lex_cls_chr(uint32_t& c) {
    tok = cur;
    const loc_t& loc = cur_loc();
#line 749 "../src/parse/lex.re"
#line 755 "../src/parse/lex.re"

    if (globopts->input_encoding == Enc::Type::ASCII) {

#line 3771 "src/parse/lex.cc"
#line 3951 "src/parse/lex.cc"
{
	uint8_t yych;
	unsigned int yyaccept = 0;
	if ((lim - cur) < 10) if (!fill(10)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= '\f') {
		if (yych == '\n') goto yy419;
		if (yych == '\n') goto yy436;
	} else {
		if (yych <= '\r') goto yy420;
		if (yych == '\\') goto yy421;
		if (yych <= '\r') goto yy437;
		if (yych == '\\') goto yy438;
	}
	++cur;
yy418:
#line 731 "../src/parse/lex.re"
yy435:
#line 737 "../src/parse/lex.re"
	{ c = decode(tok); return Ret::OK; }
#line 3787 "src/parse/lex.cc"
yy419:
#line 3967 "src/parse/lex.cc"
yy436:
	++cur;
#line 725 "../src/parse/lex.re"
#line 731 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "newline in character class")); }
#line 3792 "src/parse/lex.cc"
yy420:
#line 3972 "src/parse/lex.cc"
yy437:
	yych = *++cur;
	if (yych == '\n') goto yy419;
	goto yy418;
yy421:
	if (yych == '\n') goto yy436;
	goto yy435;
yy438:
	yych = *++cur;
	if (yych <= '\\') {
		if (yych <= '/') {
			if (yych <= '\f') {
				if (yych <= 0x00) goto yy422;
				if (yych == '\n') goto yy419;
				goto yy423;
				if (yych <= 0x00) goto yy439;
				if (yych == '\n') goto yy436;
				goto yy440;
			} else {
				if (yych <= '\r') goto yy425;
				if (yych == '-') goto yy426;
				goto yy423;
				if (yych <= '\r') goto yy442;
				if (yych == '-') goto yy443;
				goto yy440;
			}
		} else {
			if (yych <= 'U') {
				if (yych <= '3') goto yy427;
				if (yych <= '7') goto yy429;
				if (yych <= 'T') goto yy423;
				goto yy430;
				if (yych <= '3') goto yy444;
				if (yych <= '7') goto yy446;
				if (yych <= 'T') goto yy440;
				goto yy447;
			} else {
				if (yych == 'X') goto yy432;
				if (yych <= '[') goto yy423;
				goto yy433;
				if (yych == 'X') goto yy449;
				if (yych <= '[') goto yy440;
				goto yy450;
			}
		}
	} else {
		if (yych <= 'n') {
			if (yych <= 'b') {
				if (yych <= ']') goto yy434;
				if (yych <= '`') goto yy423;
				if (yych <= 'a') goto yy435;
				goto yy436;
				if (yych <= ']') goto yy451;
				if (yych <= '`') goto yy440;
				if (yych <= 'a') goto yy452;
				goto yy453;
			} else {
				if (yych == 'f') goto yy437;
				if (yych <= 'm') goto yy423;
				goto yy438;
				if (yych == 'f') goto yy454;
				if (yych <= 'm') goto yy440;
				goto yy455;
			}
		} else {
			if (yych <= 't') {
				if (yych == 'r') goto yy439;
				if (yych <= 's') goto yy423;
				goto yy440;
				if (yych == 'r') goto yy456;
				if (yych <= 's') goto yy440;
				goto yy457;
			} else {
				if (yych <= 'v') {
					if (yych <= 'u') goto yy432;
					goto yy441;
					if (yych <= 'u') goto yy449;
					goto yy458;
				} else {
					if (yych == 'x') goto yy442;
					goto yy423;
					if (yych == 'x') goto yy459;
					goto yy440;
				}
			}
		}
	}
yy422:
#line 728 "../src/parse/lex.re"
yy439:
#line 734 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "syntax error in escape sequence")); }
#line 3853 "src/parse/lex.cc"
yy423:
#line 4033 "src/parse/lex.cc"
yy440:
	++cur;
yy424:
#line 744 "../src/parse/lex.re"
yy441:
#line 750 "../src/parse/lex.re"
	{
        msg.warn.useless_escape(loc, tok, cur);
        c = decode(tok + 1);
        return Ret::OK;
    }
#line 3863 "src/parse/lex.cc"
yy425:
#line 4043 "src/parse/lex.cc"
yy442:
	yych = *++cur;
	if (yych == '\n') goto yy419;
	goto yy424;
yy426:
	if (yych == '\n') goto yy436;
	goto yy441;
yy443:
	++cur;
#line 742 "../src/parse/lex.re"
#line 748 "../src/parse/lex.re"
	{ c = '-'_u8; return Ret::OK; }
#line 3872 "src/parse/lex.cc"
yy427:
#line 4052 "src/parse/lex.cc"
yy444:
	yyaccept = 0;
	yych = *(mar = ++cur);
	if (yych <= '/') goto yy428;
	if (yych <= '7') goto yy443;
yy428:
#line 727 "../src/parse/lex.re"
	if (yych <= '/') goto yy445;
	if (yych <= '7') goto yy460;
yy445:
#line 733 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "syntax error in octal escape sequence")); }
#line 3881 "src/parse/lex.cc"
yy429:
#line 4061 "src/parse/lex.cc"
yy446:
	++cur;
	goto yy428;
yy430:
	goto yy445;
yy447:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy431;
		if (yych <= '9') goto yy445;
		if (yych <= '/') goto yy448;
		if (yych <= '9') goto yy462;
	} else {
		if (yych <= 'F') goto yy445;
		if (yych <= '`') goto yy431;
		if (yych <= 'f') goto yy445;
		if (yych <= 'F') goto yy462;
		if (yych <= '`') goto yy448;
		if (yych <= 'f') goto yy462;
	}
yy431:
#line 726 "../src/parse/lex.re"
yy448:
#line 732 "../src/parse/lex.re"
	{ RET_FAIL(error_at(loc, "syntax error in hexadecimal escape sequence")); }
#line 3899 "src/parse/lex.cc"
yy432:
#line 4079 "src/parse/lex.cc"
yy449:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy431;
		if (yych <= '9') goto yy446;
		goto yy431;
		if (yych <= '/') goto yy448;
		if (yych <= '9') goto yy463;
		goto yy448;
	} else {
		if (yych <= 'F') goto yy446;
		if (yych <= '`') goto yy431;
		if (yych <= 'f') goto yy446;
		goto yy431;
		if (yych <= 'F') goto yy463;
		if (yych <= '`') goto yy448;
		if (yych <= 'f') goto yy463;
		goto yy448;
	}
yy433:
yy450:
	++cur;
#line 741 "../src/parse/lex.re"
#line 747 "../src/parse/lex.re"
	{ c = '\\'_u8; return Ret::OK; }
#line 3917 "src/parse/lex.cc"
yy434:
#line 4097 "src/parse/lex.cc"
yy451:
	++cur;
#line 743 "../src/parse/lex.re"
#line 749 "../src/parse/lex.re"
	{ c = ']'_u8; return Ret::OK; }
#line 3922 "src/parse/lex.cc"
yy435:
#line 4102 "src/parse/lex.cc"
yy452:
	++cur;
#line 734 "../src/parse/lex.re"
#line 740 "../src/parse/lex.re"
	{ c = '\a'_u8; return Ret::OK; }
#line 3927 "src/parse/lex.cc"
yy436:
#line 4107 "src/parse/lex.cc"
yy453:
	++cur;
#line 735 "../src/parse/lex.re"
#line 741 "../src/parse/lex.re"
	{ c = '\b'_u8; return Ret::OK; }
#line 3932 "src/parse/lex.cc"
yy437:
#line 4112 "src/parse/lex.cc"
yy454:
	++cur;
#line 736 "../src/parse/lex.re"
#line 742 "../src/parse/lex.re"
	{ c = '\f'_u8; return Ret::OK; }
#line 3937 "src/parse/lex.cc"
yy438:
#line 4117 "src/parse/lex.cc"
yy455:
	++cur;
#line 737 "../src/parse/lex.re"
#line 743 "../src/parse/lex.re"
	{ c = '\n'_u8; return Ret::OK; }
#line 3942 "src/parse/lex.cc"
yy439:
#line 4122 "src/parse/lex.cc"
yy456:
	++cur;
#line 738 "../src/parse/lex.re"
#line 744 "../src/parse/lex.re"
	{ c = '\r'_u8; return Ret::OK; }
#line 3947 "src/parse/lex.cc"
yy440:
#line 4127 "src/parse/lex.cc"
yy457:
	++cur;
#line 739 "../src/parse/lex.re"
#line 745 "../src/parse/lex.re"
	{ c = '\t'_u8; return Ret::OK; }
#line 3952 "src/parse/lex.cc"
yy441:
#line 4132 "src/parse/lex.cc"
yy458:
	++cur;
#line 740 "../src/parse/lex.re"
#line 746 "../src/parse/lex.re"
	{ c = '\v'_u8; return Ret::OK; }
#line 3957 "src/parse/lex.cc"
yy442:
#line 4137 "src/parse/lex.cc"
yy459:
	yyaccept = 1;
	yych = *(mar = ++cur);
	if (yych <= '@') {
		if (yych <= '/') goto yy431;
		if (yych <= '9') goto yy447;
		goto yy431;
		if (yych <= '/') goto yy448;
		if (yych <= '9') goto yy464;
		goto yy448;
	} else {
		if (yych <= 'F') goto yy447;
		if (yych <= '`') goto yy431;
		if (yych <= 'f') goto yy447;
		goto yy431;
		if (yych <= 'F') goto yy464;
		if (yych <= '`') goto yy448;
		if (yych <= 'f') goto yy464;
		goto yy448;
	}
yy443:
yy460:
	yych = *++cur;
	if (yych <= '/') goto yy444;
	if (yych <= '7') goto yy448;
yy444:
	if (yych <= '/') goto yy461;
	if (yych <= '7') goto yy465;
yy461:
	cur = mar;
	if (yyaccept == 0) {
		goto yy428;
		goto yy445;
	} else {
		goto yy431;
		goto yy448;
	}
yy445:
yy462: