#line 408 "../src/parse/lex.re"
	{ CHECK_RET(lex_code_indented(yylval, ast));  RET_TOK(TOKEN_CODE); }
#line 2076 "src/parse/lex.cc"
yy261:
@@ -2105,7 +2105,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	}
yy262:
	++cur;
#line 424 "../src/parse/lex.re"
#line 425 "../src/parse/lex.re"
	{ CHECK_RET(lex_cls(ast, true,  yylval->regexp)); RET_TOK(TOKEN_REGEXP); }
#line 2111 "src/parse/lex.cc"
yy263:
@@ -2115,7 +2115,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
yy264:
	++cur;
yy265:
#line 460 "../src/parse/lex.re"
#line 461 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_tok(
                "illegal closure form, use '{n}', '{n,}', '{n,m}' where n and m are numbers"));
@@ -2186,7 +2186,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	}
yy272:
	p = yyt1;
#line 409 "../src/parse/lex.re"
#line 410 "../src/parse/lex.re"
	{
        yylval->cstr = ast.cstr_global(p, cur);
        RET_TOK(tok[0] == ':' ? TOKEN_CJUMP : TOKEN_CNEXT);
@@ -2205,7 +2205,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	goto yy265;
yy275:
	++cur;
#line 433 "../src/parse/lex.re"
#line 434 "../src/parse/lex.re"
	{
        if (!s_to_u32_unsafe (tok + 1, cur - 1, yylval->bounds.min)) {
            RET_FAIL(error_at_tok("repetition count overflow"));
@@ -2216,7 +2216,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
#line 2217 "src/parse/lex.cc"
yy276:
	++cur;
#line 465 "../src/parse/lex.re"
#line 466 "../src/parse/lex.re"
	{
        if (!globopts->flex_syntax) {
            RET_FAIL(error_at_tok("curly braces for names only allowed with -F switch"));
@@ -2238,7 +2238,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	yych = *(mar = ++cur);
	if (yych == ':') goto yy286;
yy280:
#line 513 "../src/parse/lex.re"
#line 514 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_tok(
                "ill-formed use directive: expected `!use` followed by a colon, a block name,"
@@ -2260,7 +2260,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	goto yy250;
yy283:
	++cur;
#line 452 "../src/parse/lex.re"
#line 453 "../src/parse/lex.re"
	{
        if (!s_to_u32_unsafe (tok + 1, cur - 2, yylval->bounds.min)) {
            RET_FAIL(error_at_tok("repetition lower bound overflow"));
@@ -2296,13 +2296,13 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	}
yy287:
	++cur;
#line 473 "../src/parse/lex.re"
#line 474 "../src/parse/lex.re"
	{ RET_TOK(TOKEN_CONF); }
#line 2302 "src/parse/lex.cc"
yy288:
	++cur;
	p = yyt1;
#line 441 "../src/parse/lex.re"
#line 442 "../src/parse/lex.re"
	{
        if (!s_to_u32_unsafe(tok + 1, p, yylval->bounds.min)) {
            RET_FAIL(error_at_tok("repetition lower bound overflow"));
@@ -2443,7 +2443,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	if (yych == '\t') goto yy305;
	if (yych == ' ') goto yy305;
yy299:
#line 500 "../src/parse/lex.re"
#line 501 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_tok(
                "ill-formed include directive: expected `!include` followed by spaces, a"
@@ -2456,7 +2456,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	x = yyt1;
	y = yyt2;
	cur = yyt3;
#line 507 "../src/parse/lex.re"
#line 508 "../src/parse/lex.re"
	{
        // Save the name of the used block in a temporary buffer (ensure it is empty).
        CHECK(ast.temp_blockname.empty());
@@ -2483,7 +2483,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
yy303:
	++cur;
	cur = yyt1;
#line 524 "../src/parse/lex.re"
#line 525 "../src/parse/lex.re"
	{ CHECK_RET(set_sourceline()); RET_TOK(TOKEN_LINE_INFO); }
#line 2489 "src/parse/lex.cc"
yy304:
@@ -2604,7 +2604,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	x = yyt1;
	y = yyt2;
	cur = yyt3;
#line 496 "../src/parse/lex.re"
#line 497 "../src/parse/lex.re"
	{
        CHECK_RET(include(getstr(x + 1, y - 1), tok));
        goto scan;
@@ -2615,7 +2615,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	if (yych == '/') goto yy314;
	goto yy250;
}
#line 548 "../src/parse/lex.re"
#line 549 "../src/parse/lex.re"

}

@@ -2678,7 +2678,7 @@ Ret Input::lex_namedef_context_re2c(bool& yes) {
		}
	}
yy317:
#line 556 "../src/parse/lex.re"
#line 557 "../src/parse/lex.re"
	{ yes = false; return Ret::OK; }
#line 2684 "src/parse/lex.cc"
yy318:
@@ -2697,11 +2697,11 @@ Ret Input::lex_namedef_context_re2c(bool& yes) {
	if (yych == '>') goto yy319;
	++cur;
	cur = yyt1;
#line 555 "../src/parse/lex.re"
#line 556 "../src/parse/lex.re"
	{ yes = true;  return Ret::OK; }
#line 2703 "src/parse/lex.cc"
}
#line 557 "../src/parse/lex.re"
#line 558 "../src/parse/lex.re"

}

@@ -2754,7 +2754,7 @@ Ret Input::lex_namedef_context_flex(bool& yes) {
		yyt1 = cur;
		goto yy322;
	}
#line 564 "../src/parse/lex.re"
#line 565 "../src/parse/lex.re"
	{ yes = false; return Ret::OK; }
#line 2760 "src/parse/lex.cc"
yy322:
@@ -2771,17 +2771,17 @@ Ret Input::lex_namedef_context_flex(bool& yes) {
		if (yych == '{') goto yy323;
	}
	cur = yyt1;
#line 563 "../src/parse/lex.re"
#line 564 "../src/parse/lex.re"
	{ yes = true;  return Ret::OK; }
#line 2777 "src/parse/lex.cc"
yy323:
	++cur;
	cur = yyt1;
#line 562 "../src/parse/lex.re"
#line 563 "../src/parse/lex.re"
	{ yes = false; return Ret::OK; }
#line 2783 "src/parse/lex.cc"
}
#line 565 "../src/parse/lex.re"
#line 566 "../src/parse/lex.re"

}

@@ -2841,7 +2841,7 @@ Ret Input::lex_clist(Ast& ast, int& token) {
	if (yych <= '!') goto yy327;
	if (yych == '>') goto yy328;
yy326:
#line 576 "../src/parse/lex.re"
#line 577 "../src/parse/lex.re"
	{ goto cond; }
#line 2847 "src/parse/lex.cc"
yy327:
@@ -2850,16 +2850,16 @@ Ret Input::lex_clist(Ast& ast, int& token) {
	yych = *cur;
	if (yych == '\t') goto yy327;
	if (yych == ' ') goto yy327;
#line 574 "../src/parse/lex.re"
#line 575 "../src/parse/lex.re"
	{ token = TOKEN_CSETUP; goto cond; }
#line 2856 "src/parse/lex.cc"
yy328:
	++cur;
#line 575 "../src/parse/lex.re"
#line 576 "../src/parse/lex.re"
	{ token = TOKEN_CZERO;  goto end; }
#line 2861 "src/parse/lex.cc"
}
#line 577 "../src/parse/lex.re"
#line 578 "../src/parse/lex.re"

cond:
    tok = cur;
@@ -2916,12 +2916,12 @@ Ret Input::lex_clist(Ast& ast, int& token) {
	}
yy330:
	++cur;
#line 583 "../src/parse/lex.re"
#line 584 "../src/parse/lex.re"
	{ goto error; }
#line 2922 "src/parse/lex.cc"
yy331:
	++cur;
#line 582 "../src/parse/lex.re"
#line 583 "../src/parse/lex.re"
	{ if (!cl.empty()) goto error; cl.insert("*"); goto next; }
#line 2927 "src/parse/lex.cc"
yy332:
@@ -2931,11 +2931,11 @@ Ret Input::lex_clist(Ast& ast, int& token) {
	if (yybm[0+yych] & 128) {
		goto yy332;
	}
#line 581 "../src/parse/lex.re"
#line 582 "../src/parse/lex.re"
	{ cl.insert(getstr(tok, cur)); goto next; }
#line 2937 "src/parse/lex.cc"
}
#line 584 "../src/parse/lex.re"
#line 585 "../src/parse/lex.re"

next: 
#line 2942 "src/parse/lex.cc"
@@ -2989,7 +2989,7 @@ Ret Input::lex_clist(Ast& ast, int& token) {
	}
	++cur;
yy334:
#line 588 "../src/parse/lex.re"
#line 589 "../src/parse/lex.re"
	{ goto error; }
#line 2995 "src/parse/lex.cc"
yy335:
@@ -3013,12 +3013,12 @@ Ret Input::lex_clist(Ast& ast, int& token) {
	if (yybm[0+yych] & 128) {
		goto yy336;
	}
#line 586 "../src/parse/lex.re"
#line 587 "../src/parse/lex.re"
	{ goto cond; }
#line 3019 "src/parse/lex.cc"
yy337:
	++cur;
#line 587 "../src/parse/lex.re"
#line 588 "../src/parse/lex.re"
	{ goto end; }
#line 3024 "src/parse/lex.cc"
yy338:
@@ -3038,7 +3038,7 @@ Ret Input::lex_clist(Ast& ast, int& token) {
	cur = mar;
	goto yy334;
}
#line 589 "../src/parse/lex.re"
#line 590 "../src/parse/lex.re"

end:
    // semantic value `yylval` is implicitly passed in temporary condition list
@@ -3057,104 +3057,107 @@ Ret Input::lex_code_indented(YYSTYPE* yylval, Ast& ast) {
	uint8_t yych;
	if ((lim - cur) < 2) if (!fill(2)) RET_FAIL(error_at_cur("unexpected end of input"));
	yych = *cur;
	if (yych <= '&') {
		if (yych <= '\f') {
			if (yych == '\n') goto yy342;
	if (yych <= '\'') {
		if (yych <= '\r') {
			if (yych == '\n') goto yy341;
			if (yych >= '\r') goto yy342;
		} else {
			if (yych <= '\r') goto yy343;
			if (yych == '"') goto yy344;
			if (yych == '"') goto yy343;
			if (yych >= '\'') goto yy343;
		}
	} else {
		if (yych <= 'z') {
			if (yych <= '\'') goto yy344;
			if (yych == '/') goto yy345;
		if (yych <= '`') {
			if (yych == '/') goto yy344;
			if (yych >= '`') goto yy343;
		} else {
			if (yych == '|') goto yy340;
			if (yych <= '}') goto yy346;
			if (yych <= '{') {
				if (yych >= '{') goto yy345;
			} else {
				if (yych == '}') goto yy345;
			}
		}
	}