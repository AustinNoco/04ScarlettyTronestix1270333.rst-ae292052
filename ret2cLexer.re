namespace re2c {

// Global re2c configurations and definitions.
#line 56 "../src/parse/lex.re"
#line 57 "../src/parse/lex.re"


#line 115 "../src/parse/lex.re"
#line 116 "../src/parse/lex.re"


#define RET_BLOCK(k) do { kind = k; return Ret::OK; } while(0)
@@ -107,7 +107,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	}
yy1:
	++cur;
#line 259 "../src/parse/lex.re"
#line 260 "../src/parse/lex.re"
	{
        if (is_eof()) {
            out.gen_raw(tok, ptr);
@@ -119,7 +119,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
yy2:
	++cur;
yy3:
#line 279 "../src/parse/lex.re"
#line 280 "../src/parse/lex.re"
	{ goto loop; }
#line 125 "src/parse/lex.cc"
yy4:
@@ -140,7 +140,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
		if (yych == '#') goto yy14;
	}
yy6:
#line 274 "../src/parse/lex.re"
#line 275 "../src/parse/lex.re"
	{
        next_line();
        goto loop;
@@ -215,7 +215,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	}
yy15:
	++cur;
#line 132 "../src/parse/lex.re"
#line 133 "../src/parse/lex.re"
	{
        if (pos != ptr) {
            // re2c does not parse user-defined code outside of re2c blocks, therefore it can
@@ -467,7 +467,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	goto yy11;
yy69:
	++cur;
#line 144 "../src/parse/lex.re"
#line 145 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        CHECK_RET(lex_opt_name(block_name));
@@ -577,7 +577,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
yy89:
	++cur;
	cur = yyt1;
#line 267 "../src/parse/lex.re"
#line 268 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        out.gen_stmt(code_newline(alc));
@@ -741,7 +741,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	goto yy11;
yy126:
	++cur;
#line 171 "../src/parse/lex.re"
#line 172 "../src/parse/lex.re"
	{
        CHECK_RET(lex_special_block(out, CodeKind::MAXFILL, DCONF_FORMAT));
        goto next;
@@ -769,7 +769,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	goto yy11;
yy132:
	++cur;
#line 165 "../src/parse/lex.re"
#line 166 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        CHECK_RET(lex_opt_name(block_name));
@@ -834,7 +834,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	goto yy11;
yy147:
	++cur;
#line 153 "../src/parse/lex.re"
#line 154 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        CHECK_RET(lex_opt_name(block_name));
@@ -847,7 +847,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	goto yy11;
yy149:
	++cur;
#line 187 "../src/parse/lex.re"
#line 188 "../src/parse/lex.re"
	{
        uint32_t allow = DCONF_FORMAT | DCONF_SEPARATOR;
        CHECK_RET(lex_special_block(out, CodeKind::MTAGS, allow));
@@ -856,7 +856,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
#line 857 "src/parse/lex.cc"
yy150:
	++cur;
#line 159 "../src/parse/lex.re"
#line 160 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        CHECK_RET(lex_opt_name(block_name));
@@ -865,7 +865,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
#line 866 "src/parse/lex.cc"
yy151:
	++cur;
#line 181 "../src/parse/lex.re"
#line 182 "../src/parse/lex.re"
	{
        uint32_t allow = DCONF_FORMAT | DCONF_SEPARATOR;
        CHECK_RET(lex_special_block(out, CodeKind::STAGS, allow));
@@ -874,7 +874,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
#line 875 "src/parse/lex.cc"
yy152:
	++cur;
#line 193 "../src/parse/lex.re"
#line 194 "../src/parse/lex.re"
	{
        out.cond_enum_autogen = false;
        out.warn_condition_order = false; // see note [condition order]
@@ -892,7 +892,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	yych = *(mar = ++cur);
	if (yych == ':') goto yy161;
yy155:
#line 229 "../src/parse/lex.re"
#line 230 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_cur(
                "ill-formed header directive: expected `/*!header:re2c:<on|off>` followed by a"
@@ -926,7 +926,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
		}
	}
yy157:
#line 253 "../src/parse/lex.re"
#line 254 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_cur(
                "ill-formed start of `ignore:re2c` block: expected a space, a newline, or the end"
@@ -952,7 +952,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
yy162:
	++cur;
	cur = yyt1;
#line 247 "../src/parse/lex.re"
#line 248 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        // allows arbitrary garbage before the end of the comment
@@ -970,7 +970,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	if (yych == '\t') goto yy169;
	if (yych == ' ') goto yy169;
yy165:
#line 242 "../src/parse/lex.re"
#line 243 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_cur(
                "ill-formed include directive: expected `/*!include:re2c \"<file>\" *" "/`"));
@@ -982,7 +982,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	goto yy11;
yy167:
	++cur;
#line 201 "../src/parse/lex.re"
#line 202 "../src/parse/lex.re"
	{
        out.state_goto = true;
        if (!opts->storable_state) {
@@ -1026,7 +1026,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	goto yy11;
yy172:
	++cur;
#line 214 "../src/parse/lex.re"
#line 215 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        out.header_mode(true);
@@ -1050,15 +1050,15 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	}
yy174:
	++cur;
#line 176 "../src/parse/lex.re"
#line 177 "../src/parse/lex.re"
	{
        CHECK_RET(lex_special_block(out, CodeKind::MAXNMATCH, DCONF_FORMAT));
        goto next;
    }
#line 1059 "src/parse/lex.cc"
yy175:
	++cur;
#line 222 "../src/parse/lex.re"
#line 223 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        out.header_mode(false);
@@ -1103,7 +1103,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	x = yyt1;
	y = yyt2;
	cur = yyt2;
#line 235 "../src/parse/lex.re"
#line 236 "../src/parse/lex.re"
	{
        out.gen_raw(tok, ptr);
        CHECK_RET(lex_block_end(out));
@@ -1117,7 +1117,7 @@ Ret Input::lex_program(Output& out, std::string& block_name, InputBlock& kind) {
	if (yych == '/') goto yy178;
	goto yy11;
}
#line 280 "../src/parse/lex.re"
#line 281 "../src/parse/lex.re"

}

@@ -1192,7 +1192,7 @@ Ret Input::lex_opt_name(std::string& name) {
		}
	}
yy181:
#line 288 "../src/parse/lex.re"
#line 289 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_cur(
                "ill-formed start of a block: expected a space, a newline, a colon followed by a"
@@ -1202,7 +1202,7 @@ Ret Input::lex_opt_name(std::string& name) {
yy182:
	++cur;
	cur = yyt1;
#line 294 "../src/parse/lex.re"
#line 295 "../src/parse/lex.re"
	{ name.clear();              return Ret::OK; }
#line 1208 "src/parse/lex.cc"
yy183:
@@ -1250,15 +1250,15 @@ Ret Input::lex_opt_name(std::string& name) {
yy187:
	++cur;
	cur = yyt1;
#line 295 "../src/parse/lex.re"
#line 296 "../src/parse/lex.re"
	{ name.assign(tok + 1, cur); return Ret::OK; }
#line 1256 "src/parse/lex.cc"
yy188:
	yych = *++cur;
	if (yych == '/') goto yy187;
	goto yy184;
}
#line 296 "../src/parse/lex.re"
#line 297 "../src/parse/lex.re"

}

@@ -1333,7 +1333,7 @@ Ret Input::lex_name_list(OutAllocator& alc, BlockNameList** ptail) {
		}
	}
yy190:
#line 304 "../src/parse/lex.re"
#line 305 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_cur(
                "ill-formed start of a block: expected a space, a newline, a colon followed by a"
@@ -1343,7 +1343,7 @@ Ret Input::lex_name_list(OutAllocator& alc, BlockNameList** ptail) {
yy191:
	++cur;
	cur = yyt1;
#line 310 "../src/parse/lex.re"
#line 311 "../src/parse/lex.re"
	{ *ptail = nullptr; return Ret::OK; }
#line 1349 "src/parse/lex.cc"
yy192:
@@ -1368,7 +1368,7 @@ Ret Input::lex_name_list(OutAllocator& alc, BlockNameList** ptail) {
	if (yybm[0+yych] & 128) {
		goto yy195;
	}
#line 312 "../src/parse/lex.re"
#line 313 "../src/parse/lex.re"
	{
        BlockNameList *l = alc.alloct<BlockNameList>(1);
        l->name = newcstr(tok + 1, cur, alc);
@@ -1387,7 +1387,7 @@ Ret Input::lex_name_list(OutAllocator& alc, BlockNameList** ptail) {
    }
#line 1389 "src/parse/lex.cc"
}
#line 328 "../src/parse/lex.re"
#line 329 "../src/parse/lex.re"

}

@@ -1446,7 +1446,7 @@ Ret Input::lex_block_end(Output& out, bool allow_garbage) {
yy197:
	++cur;
yy198:
#line 334 "../src/parse/lex.re"
#line 335 "../src/parse/lex.re"
	{
        if (allow_garbage && !is_eof()) goto loop;
        RET_FAIL(error_at_cur(
@@ -1460,12 +1460,12 @@ Ret Input::lex_block_end(Output& out, bool allow_garbage) {
	if (yybm[0+yych] & 128) {
		goto yy199;
	}
#line 345 "../src/parse/lex.re"
#line 346 "../src/parse/lex.re"
	{ goto loop; }
#line 1466 "src/parse/lex.cc"
yy200:
	++cur;
#line 346 "../src/parse/lex.re"
#line 347 "../src/parse/lex.re"
	{ next_line(); multiline = true; goto loop; }
#line 1471 "src/parse/lex.cc"
yy201:
@@ -1476,7 +1476,7 @@ Ret Input::lex_block_end(Output& out, bool allow_garbage) {
	yych = *++cur;
	if (yych != '/') goto yy198;
	++cur;
#line 339 "../src/parse/lex.re"
#line 340 "../src/parse/lex.re"
	{
        if (multiline) {
            out.gen_stmt(code_line_info_input(out.allocator, globopts->lang, cur_loc()));
@@ -1485,7 +1485,7 @@ Ret Input::lex_block_end(Output& out, bool allow_garbage) {
    }
#line 1487 "src/parse/lex.cc"
}
#line 347 "../src/parse/lex.re"
#line 348 "../src/parse/lex.re"

}

@@ -1557,7 +1557,7 @@ Ret Input::lex_special_block(Output& out, CodeKind kind, uint32_t mask) {
	}
	++cur;
yy204:
#line 360 "../src/parse/lex.re"
#line 361 "../src/parse/lex.re"
	{
        RET_FAIL(error_at_cur(
                "ill-formed directive: expected optional configurations followed by the end of"
@@ -1571,12 +1571,12 @@ Ret Input::lex_special_block(Output& out, CodeKind kind, uint32_t mask) {
	if (yybm[0+yych] & 128) {
		goto yy205;
	}
#line 384 "../src/parse/lex.re"
#line 385 "../src/parse/lex.re"
	{ goto loop; }
#line 1577 "src/parse/lex.cc"
yy206:
	++cur;
#line 386 "../src/parse/lex.re"
#line 387 "../src/parse/lex.re"
	{ next_line(); goto loop; }
#line 1582 "src/parse/lex.cc"
yy207:
@@ -1597,7 +1597,7 @@ Ret Input::lex_special_block(Output& out, CodeKind kind, uint32_t mask) {
	goto yy204;
yy211:
	++cur;
#line 388 "../src/parse/lex.re"
#line 389 "../src/parse/lex.re"
	{
        out.gen_stmt(code_line_info_output(alc, globopts->lang));
        out.gen_stmt(code_fmt(alc, kind, blocks, fmt, sep));
@@ -1641,7 +1641,7 @@ Ret Input::lex_special_block(Output& out, CodeKind kind, uint32_t mask) {
	goto yy213;
yy221:
	++cur;
#line 366 "../src/parse/lex.re"
#line 367 "../src/parse/lex.re"
	{
        if ((mask & DCONF_FORMAT) == 0) {
            RET_FAIL(error_at_cur("unexpected configuration 'format'"));
@@ -1659,7 +1659,7 @@ Ret Input::lex_special_block(Output& out, CodeKind kind, uint32_t mask) {
	yych = *++cur;
	if (yych != 'r') goto yy213;
	++cur;
#line 375 "../src/parse/lex.re"
#line 376 "../src/parse/lex.re"
	{
        if ((mask & DCONF_SEPARATOR) == 0) {
            RET_FAIL(error_at_cur("unexpected configuration 'separator'"));
@@ -1670,7 +1670,7 @@ Ret Input::lex_special_block(Output& out, CodeKind kind, uint32_t mask) {
    }
#line 1672 "src/parse/lex.cc"
}
#line 394 "../src/parse/lex.re"
#line 395 "../src/parse/lex.re"

}

@@ -1795,7 +1795,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
yy224:
	++cur;
yy225:
#line 535 "../src/parse/lex.re"
#line 536 "../src/parse/lex.re"
	{
        if (globopts->flex_syntax && globopts->input_encoding == Enc::Type::UTF8) {
            // Try to lex this as a raw UTF-8 code point (not captured by the `name` rule above
@@ -1817,7 +1817,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	if (yybm[0+yych] & 16) {
		goto yy226;
	}
#line 522 "../src/parse/lex.re"
#line 523 "../src/parse/lex.re"
	{ goto scan; }
#line 1823 "src/parse/lex.cc"
yy227:
@@ -1830,7 +1830,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
		if (yych == '#') goto yy251;
	}
yy228:
#line 526 "../src/parse/lex.re"
#line 527 "../src/parse/lex.re"
	{
        next_line();
        if (mode == LexMode::FLEX_NAME) {
@@ -1850,12 +1850,12 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	if (yych == 'i') goto yy252;
	if (yych == 'u') goto yy253;
yy231:
#line 431 "../src/parse/lex.re"
#line 432 "../src/parse/lex.re"
	{ RET_TOK(*tok); }
#line 1856 "src/parse/lex.cc"
yy232:
	++cur;
#line 422 "../src/parse/lex.re"
#line 423 "../src/parse/lex.re"
	{ CHECK_RET(lex_str(ast, '"',   yylval->regexp)); RET_TOK(TOKEN_REGEXP); }
#line 1861 "src/parse/lex.cc"
yy233:
@@ -1878,7 +1878,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	goto yy225;
yy236:
	++cur;
#line 421 "../src/parse/lex.re"
#line 422 "../src/parse/lex.re"
	{ CHECK_RET(lex_str(ast, '\'',  yylval->regexp)); RET_TOK(TOKEN_REGEXP); }
#line 1884 "src/parse/lex.cc"
yy237:
@@ -1887,7 +1887,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	goto yy231;
yy238:
	++cur;
#line 520 "../src/parse/lex.re"
#line 521 "../src/parse/lex.re"
	{ yylval->regexp = ast.dot(tok_loc()); RET_TOK(TOKEN_REGEXP); }
#line 1893 "src/parse/lex.cc"
yy239:
@@ -1901,7 +1901,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	goto yy225;
yy241:
	++cur;
#line 414 "../src/parse/lex.re"
#line 415 "../src/parse/lex.re"
	{ return lex_clist(ast, token); }
#line 1907 "src/parse/lex.cc"
yy242:
@@ -1917,7 +1917,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
	if (yybm[0+yych] & 32) {
		goto yy243;
	}
#line 475 "../src/parse/lex.re"
#line 476 "../src/parse/lex.re"
	{
        bool yes;
        CHECK_RET(lex_namedef_context_re2c(yes));
@@ -1942,7 +1942,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
yy245:
	yych = *++cur;
	if (yych == '^') goto yy262;
#line 423 "../src/parse/lex.re"
#line 424 "../src/parse/lex.re"
	{ CHECK_RET(lex_cls(ast, false, yylval->regexp)); RET_TOK(TOKEN_REGEXP); }
#line 1948 "src/parse/lex.cc"
yy246:
@@ -1967,7 +1967,7 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
		}
	}
yy248:
#line 406 "../src/parse/lex.re"
#line 407 "../src/parse/lex.re"
	{ CHECK_RET(lex_code_in_braces(yylval, ast)); RET_TOK(TOKEN_CODE); }
#line 1973 "src/parse/lex.cc"
yy249:
@@ -2044,33 +2044,33 @@ Ret Input::lex_block(YYSTYPE* yylval, Ast& ast, int& token) {
		}
	}
yy255:
#line 426 "../src/parse/lex.re"
#line 427 "../src/parse/lex.re"
	{
        yylval->regexp = ast.tag(tok_loc(), ast.cstr_global(tok + 1, cur), tok[0] == '#');
        RET_TOK(TOKEN_REGEXP);
    }
#line 2053 "src/parse/lex.cc"
yy256:
	++cur;
#line 419 "../src/parse/lex.re"
#line 420 "../src/parse/lex.re"
	{ tok = cur; RET_TOK(0); }
#line 2058 "src/parse/lex.cc"
yy257:
	++cur;
#line 417 "../src/parse/lex.re"
#line 418 "../src/parse/lex.re"
	{ CHECK_RET(lex_c_comment());   goto scan; }
#line 2063 "src/parse/lex.cc"
yy258:
	++cur;
#line 416 "../src/parse/lex.re"
#line 417 "../src/parse/lex.re"
	{ CHECK_RET(lex_cpp_comment()); goto scan; }
#line 2068 "src/parse/lex.cc"
yy259:
	yyaccept = 3;
	yych = *(mar = ++cur);
	if (yych == '>') goto yy261;
yy260:
#line 407 "../src/parse/lex.re"