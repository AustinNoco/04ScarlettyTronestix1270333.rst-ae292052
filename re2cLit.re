yy340:
	++cur;
yy341:
#line 607 "../src/parse/lex.re"
yy340:
#line 608 "../src/parse/lex.re"
	{ goto code; }
#line 3082 "src/parse/lex.cc"
yy342:
#line 3085 "src/parse/lex.cc"
yy341:
	++cur;
#line 602 "../src/parse/lex.re"
#line 603 "../src/parse/lex.re"
	{ next_line(); goto indent; }
#line 3087 "src/parse/lex.cc"
yy343:
#line 3090 "src/parse/lex.cc"
yy342:
	yych = *++cur;
	if (yych == '\n') goto yy342;
	goto yy341;
yy344:
	if (yych == '\n') goto yy341;
	goto yy340;
yy343:
	++cur;
#line 605 "../src/parse/lex.re"
	{ CHECK_RET(try_lex_string_in_code(cur[-1])); goto code; }
#line 3096 "src/parse/lex.cc"
yy345:
#line 606 "../src/parse/lex.re"
	{ CHECK_RET(try_lex_literal_in_code(cur[-1])); goto code; }
#line 3099 "src/parse/lex.cc"
yy344:
	yych = *++cur;
	if (yych == '*') goto yy347;
	if (yych == '/') goto yy348;
	goto yy341;
yy346:
	if (yych == '*') goto yy346;
	if (yych == '/') goto yy347;
	goto yy340;
yy345:
	++cur;
#line 606 "../src/parse/lex.re"
#line 607 "../src/parse/lex.re"
	{ RET_FAIL(error_at_cur("Curly braces are not allowed after ':='")); }
#line 3106 "src/parse/lex.cc"
yy347:
#line 3109 "src/parse/lex.cc"
yy346:
	++cur;
#line 604 "../src/parse/lex.re"
#line 605 "../src/parse/lex.re"
	{ CHECK_RET(lex_c_comment()); goto code; }
#line 3111 "src/parse/lex.cc"
yy348:
#line 3114 "src/parse/lex.cc"
yy347:
	++cur;
#line 603 "../src/parse/lex.re"
#line 604 "../src/parse/lex.re"
	{ CHECK_RET(lex_cpp_comment()); goto indent; }
#line 3116 "src/parse/lex.cc"
#line 3119 "src/parse/lex.cc"
}
#line 608 "../src/parse/lex.re"
#line 609 "../src/parse/lex.re"

indent: 
#line 3121 "src/parse/lex.cc"
#line 3124 "src/parse/lex.cc"
{
	uint8_t yych;
	if (lim <= cur) if (!fill(1)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= '\f') {
		if (yych <= 0x08) goto yy350;
		if (yych <= '\n') goto yy351;
		if (yych <= 0x08) goto yy349;
		if (yych <= '\n') goto yy350;
	} else {
		if (yych <= '\r') goto yy351;
		if (yych == ' ') goto yy351;
		if (yych <= '\r') goto yy350;
		if (yych == ' ') goto yy350;
	}
yy350:
#line 611 "../src/parse/lex.re"
yy349:
#line 612 "../src/parse/lex.re"
	{
        while (isspace(tok[0])) ++tok;
        uint8_t* p = cur;
        while (p > tok && isspace(p[-1])) --p;
        yylval->semact = ast.sem_act(loc, ast.cstr_global(tok, p), nullptr, false);
        return Ret::OK;
    }
#line 3142 "src/parse/lex.cc"
yy351:
#line 3145 "src/parse/lex.cc"
yy350:
	++cur;
	cur -= 1;
#line 610 "../src/parse/lex.re"
#line 611 "../src/parse/lex.re"
	{ goto code; }
#line 3148 "src/parse/lex.cc"
#line 3151 "src/parse/lex.cc"
}
#line 618 "../src/parse/lex.re"
#line 619 "../src/parse/lex.re"

}

Ret Input::lex_code_in_braces(YYSTYPE* yylval, Ast& ast) {
    const loc_t& loc = tok_loc();
    uint32_t depth = 1;
code: 
#line 3158 "src/parse/lex.cc"
#line 3161 "src/parse/lex.cc"
{
	uint8_t yych;
	static const unsigned char yybm[] = {
@@ -3193,206 +3196,285 @@ Ret Input::lex_code_in_braces(YYSTYPE* yylval, Ast& ast) {
	};
	if ((lim - cur) < 3) if (!fill(3)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= '&') {
		if (yych <= '\f') {
			if (yych == '\n') goto yy354;
	if (yych <= '\'') {
		if (yych <= '\r') {
			if (yych == '\n') goto yy353;
			if (yych >= '\r') goto yy355;
		} else {
			if (yych <= '\r') goto yy356;
			if (yych == '"') goto yy357;
			if (yych == '"') goto yy356;
			if (yych >= '\'') goto yy356;
		}
	} else {
		if (yych <= 'z') {
			if (yych <= '\'') goto yy357;
			if (yych == '/') goto yy358;
		if (yych <= '`') {
			if (yych == '/') goto yy357;
			if (yych >= '`') goto yy356;
		} else {
			if (yych <= '{') goto yy359;
			if (yych == '}') goto yy360;
			if (yych <= '{') {
				if (yych >= '{') goto yy358;
			} else {
				if (yych == '}') goto yy359;
			}
		}
	}
	++cur;
yy353:
#line 639 "../src/parse/lex.re"
yy352:
#line 640 "../src/parse/lex.re"
	{ goto code; }
#line 3217 "src/parse/lex.cc"
yy354:
#line 3224 "src/parse/lex.cc"
yy353:
	yych = *(mar = ++cur);
	if (yybm[0+yych] & 32) {
		goto yy361;
		goto yy360;
	}
	if (yych == '#') goto yy363;
yy355:
#line 635 "../src/parse/lex.re"
	if (yych == '#') goto yy362;
yy354:
#line 636 "../src/parse/lex.re"
	{ next_line(); goto code; }
#line 3227 "src/parse/lex.cc"
yy356:
#line 3234 "src/parse/lex.cc"
yy355:
	yych = *++cur;
	if (yych == '\n') goto yy354;
	goto yy353;
yy357:
	if (yych == '\n') goto yy353;
	goto yy352;
yy356:
	++cur;
#line 638 "../src/parse/lex.re"
	{ CHECK_RET(try_lex_string_in_code(cur[-1])); goto code; }
#line 3236 "src/parse/lex.cc"
yy358:
#line 639 "../src/parse/lex.re"
	{ CHECK_RET(try_lex_literal_in_code(cur[-1])); goto code; }
#line 3243 "src/parse/lex.cc"
yy357:
	yych = *++cur;
	if (yych == '*') goto yy364;
	if (yych == '/') goto yy365;
	goto yy353;
yy359:
	if (yych == '*') goto yy363;
	if (yych == '/') goto yy364;
	goto yy352;
yy358:
	++cur;
#line 633 "../src/parse/lex.re"
#line 634 "../src/parse/lex.re"
	{ ++depth; goto code; }
#line 3246 "src/parse/lex.cc"
yy360:
#line 3253 "src/parse/lex.cc"
yy359:
	++cur;
#line 625 "../src/parse/lex.re"
#line 626 "../src/parse/lex.re"
	{
        if (--depth == 0) {
            yylval->semact = ast.sem_act(loc, ast.cstr_global(tok, cur), nullptr, false);
            return Ret::OK;
        }
        goto code;
    }
#line 3257 "src/parse/lex.cc"
yy361:
#line 3264 "src/parse/lex.cc"
yy360:
	++cur;
	if (lim <= cur) if (!fill(1)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yybm[0+yych] & 32) {
		goto yy361;
		goto yy360;
	}
	if (yych == '#') goto yy363;
yy362:
	if (yych == '#') goto yy362;
yy361:
	cur = mar;
	goto yy355;
yy363:
	goto yy354;
yy362:
	++cur;
	if ((lim - cur) < 5) if (!fill(5)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= 0x1F) {
		if (yych == '\t') goto yy363;
		goto yy362;
		if (yych == '\t') goto yy362;
		goto yy361;
	} else {
		if (yych <= ' ') goto yy363;
		if (yych == 'l') goto yy366;
		goto yy362;
		if (yych <= ' ') goto yy362;
		if (yych == 'l') goto yy365;
		goto yy361;
	}
yy364:
yy363:
	++cur;
#line 636 "../src/parse/lex.re"
#line 637 "../src/parse/lex.re"
	{ CHECK_RET(lex_c_comment()); goto code; }
#line 3285 "src/parse/lex.cc"
yy365:
#line 3292 "src/parse/lex.cc"
yy364:
	++cur;
#line 637 "../src/parse/lex.re"
#line 638 "../src/parse/lex.re"
	{ CHECK_RET(lex_cpp_comment()); goto code; }
#line 3290 "src/parse/lex.cc"
yy366:
#line 3297 "src/parse/lex.cc"
yy365:
	yych = *++cur;
	if (yych != 'i') goto yy362;
	if (yych != 'i') goto yy361;
	yych = *++cur;
	if (yych != 'n') goto yy362;
	if (yych != 'n') goto yy361;
	yych = *++cur;
	if (yych != 'e') goto yy362;
	if (yych != 'e') goto yy361;
	yych = *++cur;
	if (yych <= '0') goto yy368;
	if (yych <= '9') goto yy362;
	goto yy368;
yy367:
	if (yych <= '0') goto yy367;
	if (yych <= '9') goto yy361;
	goto yy367;
yy366:
	++cur;
	if (lim <= cur) if (!fill(1)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
yy368:
yy367:
	if (yych <= 0x1F) {
		if (yych == '\t') goto yy367;
		goto yy362;
		if (yych == '\t') goto yy366;
		goto yy361;
	} else {
		if (yych <= ' ') goto yy367;
		if (yych <= '0') goto yy362;
		if (yych >= ':') goto yy362;
		if (yych <= ' ') goto yy366;
		if (yych <= '0') goto yy361;
		if (yych >= ':') goto yy361;
		yyt1 = cur;
	}
yy369:
yy368:
	++cur;
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yybm[0+yych] & 64) {
		goto yy369;
		goto yy368;
	}
	if (yych <= '\f') {
		if (yych <= 0x08) goto yy362;
		if (yych <= '\t') goto yy370;
		if (yych <= '\n') goto yy371;
		goto yy362;
		if (yych <= 0x08) goto yy361;
		if (yych <= '\t') goto yy369;
		if (yych <= '\n') goto yy370;
		goto yy361;
	} else {
		if (yych <= '\r') goto yy372;
		if (yych != ' ') goto yy362;
		if (yych <= '\r') goto yy371;
		if (yych != ' ') goto yy361;
	}
yy370:
yy369:
	++cur;
	if (lim <= cur) if (!fill(1)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= 0x1F) {
		if (yych == '\t') goto yy370;
		goto yy362;
		if (yych == '\t') goto yy369;
		goto yy361;
	} else {
		if (yych <= ' ') goto yy370;
		if (yych == '"') goto yy373;
		goto yy362;
		if (yych <= ' ') goto yy369;
		if (yych == '"') goto yy372;
		goto yy361;
	}
yy371:
yy370:
	++cur;
	cur = yyt1;
#line 634 "../src/parse/lex.re"
#line 635 "../src/parse/lex.re"
	{ CHECK_RET(set_sourceline()); goto code; }
#line 3349 "src/parse/lex.cc"
yy372:
#line 3356 "src/parse/lex.cc"
yy371:
	yych = *++cur;
	if (yych == '\n') goto yy371;
	goto yy362;
yy373:
	if (yych == '\n') goto yy370;
	goto yy361;
yy372:
	++cur;
	if ((lim - cur) < 3) if (!fill(3)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yybm[0+yych] & 128) {
		goto yy373;
		goto yy372;
	}
	if (yych <= '\n') goto yy362;
	if (yych >= '#') goto yy374;
	if (yych <= '\n') goto yy361;
	if (yych >= '#') goto yy373;
	yych = *++cur;
	if (yych == '\n') goto yy371;
	if (yych == '\r') goto yy372;
	goto yy362;
yy374:
	if (yych == '\n') goto yy370;
	if (yych == '\r') goto yy371;
	goto yy361;
yy373:
	++cur;
	if (lim <= cur) if (!fill(1)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= 0x00) goto yy362;
	if (yych == '\n') goto yy362;
	goto yy373;
	if (yych <= 0x00) goto yy361;
	if (yych == '\n') goto yy361;
	goto yy372;
}
#line 640 "../src/parse/lex.re"
#line 641 "../src/parse/lex.re"

}

Ret Input::try_lex_string_in_code(uint8_t quote) {
    // We need to lex string literals in code blocks because they may contain closing brace symbol
    // that would otherwise be erroneously lexed as a real closing brace.
    //
    // However, single quote in Rust may be either the beginning of a char literal as in `\u{1F600}`
    // or a standalone one as in `'label`. In the latter case trying to lex a generic string literal
    // will consume a fragment of the file until the next single quote (if any) and result in either
    // a spurios parse error, or incorrect generated code. Therefore in Rust we try to lex a char
    // literal, or else consume the quote.

    if (globopts->lang != Lang::RUST || quote != '\'') {
        return lex_string(quote);
    }