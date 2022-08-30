/* Generated by re2c 2.2 */
//-----------------------------------------------------------------------------
// z80asm
// lexer
// Copyright (C) Paulo Custodio, 2011-2022
// License: The Artistic License 2.0, http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------

#include "args.h"
#include "errors.h"
#include "if.h"
#include "lex.h"
#include "preproc.h"
#include "utils.h"
#include <cctype>
#include <unordered_map>
using namespace std;



//-----------------------------------------------------------------------------

static unordered_map<string, Keyword> keyword_table = {
#	define X(id, text)		{ text, Keyword::id },
#	include "keyword.def"
};

static int a2i(const char* str, int base) {
	return (int)strtol(str, NULL, base);
}

static Keyword lu_keyword(const string& text) {
	auto it = keyword_table.find(str_tolower(text));
	if (it == keyword_table.end())
		return Keyword::None;
	else
		return it->second;
}

static string ident_change_case(const string& ident) {
	if (g_args.ucase())
		return str_toupper(ident);
	else
		return ident;
}

bool isident(const string& ident) {
	if (ident.empty())
		return false;
	else if (ident[0] != '_' && !isalpha(ident[0]))
		return false;
	else {
		for (auto c : ident) {
			if (c != '_' && !isalnum(c))
				return false;
		}
	}
	return true;
}

bool starts_with_hash(const string& line) {
	const char* p = line.c_str();
	const char* YYMARKER{ nullptr };
	
		{
			char yych;
			yych = *p;
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy4;
			case '#':	goto yy5;
			default:	goto yy2;
			}
yy2:
			++p;
yy3:
			{ return false; }
yy4:
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy7;
			case '#':	goto yy5;
			default:	goto yy3;
			}
yy5:
			++p;
			{ return true; }
yy7:
			yych = *++p;
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy7;
			case '#':	goto yy5;
			default:	goto yy9;
			}
yy9:
			p = YYMARKER;
			goto yy3;
		}

}

bool remove_final_backslash(string& line) {
	const char* p = line.c_str();
	const char* YYMARKER{ nullptr };
	while (true) {
		size_t parsed_len = p - line.c_str();
		
		{
			char yych;
			unsigned int yyaccept = 0;
			yych = *p;
			switch (yych) {
			case 0x00:	goto yy12;
			case '"':	goto yy16;
			case '\'':	goto yy17;
			case ';':	goto yy18;
			case 'A':
			case 'a':	goto yy20;
			case 'B':
			case 'b':	goto yy22;
			case 'C':
			case 'c':	goto yy23;
			case 'D':
			case 'd':	goto yy24;
			case 'E':
			case 'L':
			case 'e':
			case 'l':	goto yy25;
			case 'F':
			case 'G':
			case 'I':
			case 'J':
			case 'K':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'f':
			case 'g':
			case 'i':
			case 'j':
			case 'k':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy26;
			case 'H':
			case 'h':	goto yy28;
			case 'R':
			case 'r':	goto yy29;
			case 'S':
			case 's':	goto yy30;
			case '\\':	goto yy31;
			default:	goto yy14;
			}
yy12:
			++p;
			{ return false; }
yy14:
			++p;
yy15:
			{ continue; }
yy16:
			yyaccept = 0;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy15;
			default:	goto yy33;
			}
yy17:
			yyaccept = 0;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy15;
			default:	goto yy38;
			}
yy18:
			++p;
			{ return false; }
yy20:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy35;
			case 'F':
			case 'f':	goto yy25;
			default:	goto yy27;
			}
yy21:
			{ continue; }
yy22:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy35;
			case 'C':
			case 'c':	goto yy25;
			default:	goto yy27;
			}
yy23:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy35;
			case 'C':
			case 'c':	goto yy40;
			default:	goto yy27;
			}
yy24:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy35;
			case 'E':
			case 'e':	goto yy25;
			case 'S':
			case 's':	goto yy41;
			default:	goto yy27;
			}
yy25:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy35;
			default:	goto yy27;
			}
yy26:
			yych = *++p;
yy27:
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy26;
			default:	goto yy21;
			}
yy28:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy35;
			case 'L':
			case 'l':	goto yy25;
			default:	goto yy27;
			}
yy29:
			yych = *++p;
			switch (yych) {
			case 'L':
			case 'R':
			case 'l':
			case 'r':	goto yy42;
			default:	goto yy27;
			}
yy30:
			yych = *++p;
			switch (yych) {
			case 'C':
			case 'c':	goto yy40;
			default:	goto yy27;
			}
yy31:
			yyaccept = 0;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 0x00:	goto yy43;
			case '\n':	goto yy45;
			case '\r':	goto yy46;
			default:	goto yy15;
			}
yy32:
			yych = *++p;
yy33:
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy34;
			case '"':	goto yy35;
			case '\\':	goto yy36;
			default:	goto yy32;
			}
yy34:
			p = YYMARKER;
			if (yyaccept == 0) {
				goto yy15;
			} else {
				goto yy21;
			}
yy35:
			++p;
			goto yy21;
yy36:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy34;
			default:	goto yy32;
			}
yy37:
			yych = *++p;
yy38:
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy34;
			case '\'':	goto yy35;
			case '\\':	goto yy39;
			default:	goto yy37;
			}
yy39:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy34;
			default:	goto yy37;
			}
yy40:
			yych = *++p;
			switch (yych) {
			case 'F':
			case 'f':	goto yy25;
			default:	goto yy27;
			}
yy41:
			yyaccept = 1;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '.':	goto yy47;
			default:	goto yy27;
			}
yy42:
			yych = *++p;
			switch (yych) {
			case 'A':
			case 'a':	goto yy25;
			case 'C':
			case 'c':	goto yy48;
			default:	goto yy27;
			}
yy43:
			++p;
			{ line.erase(parsed_len);
								  line.push_back(' ');
								  return true; }
yy45:
			yych = *++p;
			if (yych <= 0x00) goto yy43;
			goto yy34;
yy46:
			yych = *++p;
			switch (yych) {
			case 0x00:	goto yy43;
			case '\n':	goto yy45;
			default:	goto yy34;
			}
yy47:
			yych = *++p;
			switch (yych) {
			case 'B':
			case 'P':
			case 'Q':
			case 'W':
			case 'b':
			case 'p':
			case 'q':
			case 'w':	goto yy35;
			default:	goto yy34;
			}
yy48:
			yych = *++p;
			switch (yych) {
			case 'A':
			case 'a':	goto yy25;
			default:	goto yy27;
			}
		}

	}
}

void split_lines(deque<string>& lines, const string& line) {
	string output;
	const char* YYMARKER{ nullptr };
	const char* p = line.c_str();

	while (true) {
		const char* p0 = p;
		
		{
			char yych;
			unsigned int yyaccept = 0;
			yych = *p;
			switch (yych) {
			case 0x00:	goto yy51;
			case '\n':
			case '\\':	goto yy55;
			case '\r':	goto yy57;
			case '"':	goto yy58;
			case '\'':	goto yy59;
			case ';':	goto yy60;
			case 'A':
			case 'a':	goto yy63;
			case 'B':
			case 'b':	goto yy65;
			case 'C':
			case 'c':	goto yy66;
			case 'D':
			case 'd':	goto yy67;
			case 'E':
			case 'L':
			case 'e':
			case 'l':	goto yy68;
			case 'F':
			case 'G':
			case 'I':
			case 'J':
			case 'K':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'f':
			case 'g':
			case 'i':
			case 'j':
			case 'k':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy69;
			case 'H':
			case 'h':	goto yy71;
			case 'R':
			case 'r':	goto yy72;
			case 'S':
			case 's':	goto yy73;
			default:	goto yy53;
			}
yy51:
			++p;
			{ if (!output.empty()) {
								  output += "\n"; lines.push_back(output); }
							  return; }
yy53:
			++p;
yy54:
			{ output += string(p0, p); continue; }
yy55:
			++p;
yy56:
			{ output += "\n"; lines.push_back(output);
							  output.clear(); continue; }
yy57:
			yych = *++p;
			switch (yych) {
			case '\n':	goto yy55;
			default:	goto yy56;
			}
yy58:
			yyaccept = 0;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy54;
			default:	goto yy75;
			}
yy59:
			yyaccept = 0;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy54;
			default:	goto yy80;
			}
yy60:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy62;
			default:	goto yy60;
			}
yy62:
			{ continue; }
yy63:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy77;
			case 'F':
			case 'f':	goto yy68;
			default:	goto yy70;
			}
yy64:
			{ output += string(p0, p); continue; }
yy65:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy77;
			case 'C':
			case 'c':	goto yy68;
			default:	goto yy70;
			}
yy66:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy77;
			case 'C':
			case 'c':	goto yy82;
			default:	goto yy70;
			}
yy67:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy77;
			case 'E':
			case 'e':	goto yy68;
			case 'S':
			case 's':	goto yy83;
			default:	goto yy70;
			}
yy68:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy77;
			default:	goto yy70;
			}
yy69:
			yych = *++p;
yy70:
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy69;
			default:	goto yy64;
			}
yy71:
			yych = *++p;
			switch (yych) {
			case '\'':	goto yy77;
			case 'L':
			case 'l':	goto yy68;
			default:	goto yy70;
			}
yy72:
			yych = *++p;
			switch (yych) {
			case 'L':
			case 'R':
			case 'l':
			case 'r':	goto yy84;
			default:	goto yy70;
			}
yy73:
			yych = *++p;
			switch (yych) {
			case 'C':
			case 'c':	goto yy82;
			default:	goto yy70;
			}
yy74:
			yych = *++p;
yy75:
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy76;
			case '"':	goto yy77;
			case '\\':	goto yy78;
			default:	goto yy74;
			}
yy76:
			p = YYMARKER;
			if (yyaccept == 0) {
				goto yy54;
			} else {
				goto yy64;
			}
yy77:
			++p;
			goto yy64;
yy78:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy76;
			default:	goto yy74;
			}
yy79:
			yych = *++p;
yy80:
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy76;
			case '\'':	goto yy77;
			case '\\':	goto yy81;
			default:	goto yy79;
			}
yy81:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy76;
			default:	goto yy79;
			}
yy82:
			yych = *++p;
			switch (yych) {
			case 'F':
			case 'f':	goto yy68;
			default:	goto yy70;
			}
yy83:
			yyaccept = 1;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '.':	goto yy85;
			default:	goto yy70;
			}
yy84:
			yych = *++p;
			switch (yych) {
			case 'A':
			case 'a':	goto yy68;
			case 'C':
			case 'c':	goto yy86;
			default:	goto yy70;
			}
yy85:
			yych = *++p;
			switch (yych) {
			case 'B':
			case 'P':
			case 'Q':
			case 'W':
			case 'b':
			case 'p':
			case 'q':
			case 'w':	goto yy77;
			default:	goto yy76;
			}
yy86:
			yych = *++p;
			switch (yych) {
			case 'A':
			case 'a':	goto yy68;
			default:	goto yy70;
			}
		}

	}
}

//-----------------------------------------------------------------------------

const char* Lexer::text_ptr(int offset) const {
	int index = m_pos + offset;
	if (index < 0)
		return m_text.c_str();
	else if (index < static_cast<int>(m_tokens.size()))
		return m_text.c_str() + m_tokens[index].col;
	else
		return m_text.c_str() + m_text.length();
}

string Lexer::token_text(int offset) const {
	const char* p1 = text_ptr(offset);
	const char* p2 = text_ptr(offset + 1);
	return string(p1, p2);
}

Token& Lexer::peek(int offset) {
	static Token end{ TType::End };
	size_t index = m_pos + offset;
	if (index >= m_tokens.size())
		return end;
	else
		return m_tokens[index];
}

void Lexer::next(int n) {
	m_pos += n;
	if (m_pos > m_tokens.size())
		m_pos = m_tokens.size();
}

void Lexer::set(const string& text) {
	m_text = text;
	m_tokens.clear();
	m_pos = 0;
	const char* p = text.c_str(), * YYMARKER{ nullptr };
	while (true) {
		const char* p0{ p }, * p1{ nullptr }, * p2{ nullptr }, * yyt1{ nullptr };
		size_t col = p - text.c_str();
		bool first_token = m_tokens.empty();
		
		{
			char yych;
			unsigned int yyaccept = 0;
			yych = *p;
			switch (yych) {
			case 0x00:	goto yy89;
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy93;
			case '\n':	goto yy96;
			case '!':	goto yy98;
			case '"':	goto yy100;
			case '#':	goto yy102;
			case '$':	goto yy104;
			case '%':	goto yy106;
			case '&':	goto yy108;
			case '\'':	goto yy110;
			case '(':	goto yy111;
			case ')':	goto yy113;
			case '*':	goto yy115;
			case '+':	goto yy117;
			case ',':	goto yy119;
			case '-':	goto yy121;
			case '.':	goto yy123;
			case '/':	goto yy125;
			case '0':	goto yy127;
			case '1':	goto yy129;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy131;
			case ':':	goto yy133;
			case ';':	goto yy135;
			case '<':	goto yy138;
			case '=':	goto yy140;
			case '>':	goto yy142;
			case '?':	goto yy144;
			case '@':	goto yy146;
			case 'A':
			case 'a':	goto yy147;
			case 'B':
			case 'b':	goto yy149;
			case 'C':
			case 'c':	goto yy150;
			case 'D':
			case 'd':	goto yy151;
			case 'E':
			case 'L':
			case 'e':
			case 'l':	goto yy152;
			case 'F':
			case 'G':
			case 'I':
			case 'J':
			case 'K':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'f':
			case 'g':
			case 'i':
			case 'j':
			case 'k':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy153;
			case 'H':
			case 'h':	goto yy155;
			case 'R':
			case 'r':	goto yy156;
			case 'S':
			case 's':	goto yy157;
			case '[':	goto yy158;
			case '\\':	goto yy160;
			case ']':	goto yy162;
			case '^':	goto yy164;
			case '{':	goto yy166;
			case '|':	goto yy168;
			case '}':	goto yy170;
			case '~':	goto yy172;
			default:	goto yy91;
			}
yy89:
			++p;
			{ return; }
yy91:
			++p;
yy92:
			{ g_errors.error(ErrCode::InvalidChar); clear(); return; }
yy93:
			yych = *++p;
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy93;
			default:	goto yy95;
			}
yy95:
			{ continue; }
yy96:
			++p;
			{ m_tokens.emplace_back(TType::Newline);
							  m_tokens.back().col = col;
							  continue; }
yy98:
			yych = *++p;
			switch (yych) {
			case '=':	goto yy174;
			default:	goto yy99;
			}
yy99:
			{ m_tokens.emplace_back(TType::LogNot);
							  m_tokens.back().col = col;
							  continue; }
yy100:
			yyaccept = 0;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy101;
			case '"':
				yyt1 = p;
				goto yy179;
			case '\\':
				yyt1 = p;
				goto yy181;
			default:
				yyt1 = p;
				goto yy176;
			}
yy101:
			{ g_errors.error(ErrCode::MissingQuote); clear(); return; }
yy102:
			yych = *++p;
			switch (yych) {
			case '#':	goto yy182;
			default:	goto yy103;
			}
yy103:
			{ m_tokens.emplace_back(TType::Hash);
							  m_tokens.back().col = col;
							  continue; }
yy104:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy184;
			default:	goto yy105;
			}
yy105:
			{ m_tokens.emplace_back(TType::ASMPC);
							  m_tokens.back().col = col;
							  continue; }
yy106:
			yyaccept = 1;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '"':	goto yy187;
			case '0':
			case '1':	goto yy189;
			default:	goto yy107;
			}
yy107:
			{ m_tokens.emplace_back(TType::Mod);
							  m_tokens.back().col = col;
							  continue; }
yy108:
			yych = *++p;
			switch (yych) {
			case '&':	goto yy192;
			default:	goto yy109;
			}
yy109:
			{ m_tokens.emplace_back(TType::BinAnd);
							  m_tokens.back().col = col;
							  continue; }
yy110:
			yyaccept = 0;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy101;
			case '\'':
				yyt1 = p;
				goto yy196;
			case '\\':
				yyt1 = p;
				goto yy198;
			default:
				yyt1 = p;
				goto yy194;
			}
yy111:
			++p;
			{ m_tokens.emplace_back(TType::LParen);
							  m_tokens.back().col = col;
							  continue; }
yy113:
			++p;
			{ m_tokens.emplace_back(TType::RParen);
							  m_tokens.back().col = col;
							  continue; }
yy115:
			yych = *++p;
			switch (yych) {
			case '*':	goto yy199;
			default:	goto yy116;
			}
yy116:
			{ m_tokens.emplace_back(TType::Mul);
							  m_tokens.back().col = col;
							  continue; }
yy117:
			++p;
			{ m_tokens.emplace_back(TType::Plus);
							  m_tokens.back().col = col;
							  continue; }
yy119:
			++p;
			{ m_tokens.emplace_back(TType::Comma);
							  m_tokens.back().col = col;
							  continue; }
yy121:
			++p;
			{ m_tokens.emplace_back(TType::Minus);
							  m_tokens.back().col = col;
							  continue; }
yy123:
			yyaccept = 2;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy201;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy203;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				yyt1 = p;
				goto yy206;
			default:	goto yy124;
			}
yy124:
			{ m_tokens.emplace_back(TType::Dot);
							  m_tokens.back().col = col;
							  continue; }
yy125:
			++p;
			{ m_tokens.emplace_back(TType::Div);
							  m_tokens.back().col = col;
							  continue; }
yy127:
			yyaccept = 3;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 'B':
			case 'b':	goto yy211;
			case 'X':
			case 'x':	goto yy216;
			default:	goto yy130;
			}
yy128:
			{ m_tokens.emplace_back(TType::Integer, a2i(p0, 10));
							  m_tokens.back().col = col;
							  continue; }
yy129:
			yyaccept = 3;
			yych = *(YYMARKER = ++p);
yy130:
			switch (yych) {
			case '.':	goto yy203;
			case '0':
			case '1':	goto yy129;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy131;
			case 'A':
			case 'C':
			case 'E':
			case 'F':
			case 'a':
			case 'c':
			case 'e':
			case 'f':	goto yy209;
			case 'B':
			case 'b':	goto yy217;
			case 'D':
			case 'd':	goto yy213;
			case 'H':
			case 'h':	goto yy214;
			default:	goto yy128;
			}
yy131:
			yyaccept = 3;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '.':	goto yy203;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy131;
			case 'A':
			case 'B':
			case 'C':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'e':
			case 'f':	goto yy209;
			case 'D':
			case 'd':	goto yy213;
			case 'H':
			case 'h':	goto yy214;
			default:	goto yy128;
			}
yy133:
			++p;
			{ m_tokens.emplace_back(TType::Colon);
							  m_tokens.back().col = col;
							  continue; }
yy135:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy137;
			default:	goto yy135;
			}
yy137:
			{ continue; }
yy138:
			yych = *++p;
			switch (yych) {
			case '<':	goto yy218;
			case '=':	goto yy220;
			case '>':	goto yy174;
			default:	goto yy139;
			}
yy139:
			{ m_tokens.emplace_back(TType::Lt);
							  m_tokens.back().col = col;
							  continue; }
yy140:
			yych = *++p;
			switch (yych) {
			case '=':	goto yy222;
			default:	goto yy141;
			}
yy141:
			{ m_tokens.emplace_back(TType::Eq);
							  m_tokens.back().col = col;
							  continue; }
yy142:
			yych = *++p;
			switch (yych) {
			case '=':	goto yy223;
			case '>':	goto yy225;
			default:	goto yy143;
			}
yy143:
			{ m_tokens.emplace_back(TType::Gt);
							  m_tokens.back().col = col;
							  continue; }
yy144:
			++p;
			{ m_tokens.emplace_back(TType::Quest);
							  m_tokens.back().col = col;
							  continue; }
yy146:
			yyaccept = 4;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '"':	goto yy187;
			case '0':
			case '1':	goto yy189;
			default:	goto yy92;
			}
yy147:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\'':	goto yy229;
			case 'F':
			case 'f':	goto yy152;
			default:	goto yy154;
			}
yy148:
			p1 = p;
			{ string str = ident_change_case(string(p0, p1));
							  Keyword keyword = lu_keyword(str);
							  if (keyword == Keyword::ASMPC) 
							      m_tokens.emplace_back(TType::ASMPC);
							  else
							      m_tokens.emplace_back(TType::Ident, str, keyword);
							  m_tokens.back().col = col;
							  continue; }
yy149:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\'':	goto yy229;
			case 'C':
			case 'c':	goto yy152;
			default:	goto yy154;
			}
yy150:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\'':	goto yy229;
			case 'C':
			case 'c':	goto yy232;
			default:	goto yy154;
			}
yy151:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\'':	goto yy229;
			case 'E':
			case 'e':	goto yy152;
			case 'S':
			case 's':	goto yy233;
			default:	goto yy154;
			}
yy152:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\'':	goto yy229;
			default:	goto yy154;
			}
yy153:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
yy154:
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':
				yyt1 = p;
				goto yy227;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy153;
			case ':':
				yyt1 = p;
				goto yy230;
			default:	goto yy148;
			}
yy155:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '\'':	goto yy229;
			case 'L':
			case 'l':	goto yy152;
			default:	goto yy154;
			}
yy156:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 'L':
			case 'R':
			case 'l':
			case 'r':	goto yy234;
			default:	goto yy154;
			}
yy157:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 'C':
			case 'c':	goto yy232;
			default:	goto yy154;
			}
yy158:
			++p;
			{ m_tokens.emplace_back(TType::LSquare);
							  m_tokens.back().col = col;
							  continue; }
yy160:
			++p;
			{ m_tokens.emplace_back(TType::Backslash);
							  m_tokens.back().col = col;
							  continue; }
yy162:
			++p;
			{ m_tokens.emplace_back(TType::RSquare);
							  m_tokens.back().col = col;
							  continue; }
yy164:
			yych = *++p;
			switch (yych) {
			case '^':	goto yy235;
			default:	goto yy165;
			}
yy165:
			{ m_tokens.emplace_back(TType::BinXor);
							  m_tokens.back().col = col;
							  continue; }
yy166:
			++p;
			{ m_tokens.emplace_back(TType::LBrace);
							  m_tokens.back().col = col;
							  continue; }
yy168:
			yych = *++p;
			switch (yych) {
			case '|':	goto yy237;
			default:	goto yy169;
			}
yy169:
			{ m_tokens.emplace_back(TType::BinOr);
							  m_tokens.back().col = col;
							  continue; }
yy170:
			++p;
			{ m_tokens.emplace_back(TType::RBrace);
							  m_tokens.back().col = col;
							  continue; }
yy172:
			++p;
			{ m_tokens.emplace_back(TType::BinNot);
							  m_tokens.back().col = col;
							  continue; }
yy174:
			++p;
			{ m_tokens.emplace_back(TType::Ne);
							  m_tokens.back().col = col;
							  continue; }
yy176:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy178;
			case '"':	goto yy179;
			case '\\':	goto yy181;
			default:	goto yy176;
			}
yy178:
			p = YYMARKER;
			switch (yyaccept) {
			case 0:
				goto yy101;
			case 1:
				goto yy107;
			case 2:
				goto yy124;
			case 3:
				goto yy128;
			case 4:
				goto yy92;
			case 5:
				goto yy148;
			case 6:
				goto yy205;
			case 7:
				goto yy212;
			default:
				goto yy244;
			}
yy179:
			++p;
			p1 = yyt1;
			p2 = p - 1;
			{
							  m_tokens.emplace_back(TType::String, string(p1, p2));
							  m_tokens.back().col = col;
							  continue; }
yy181:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy178;
			default:	goto yy176;
			}
yy182:
			++p;
			{ m_tokens.emplace_back(TType::DblHash);
							  m_tokens.back().col = col;
							  continue; }
yy184:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy184;
			default:	goto yy186;
			}
yy186:
			{ m_tokens.emplace_back(TType::Integer, a2i(p0+1, 16));
							  m_tokens.back().col = col;
							  continue; }
yy187:
			yych = *++p;
			switch (yych) {
			case '"':	goto yy239;
			case '#':
			case '-':	goto yy187;
			default:	goto yy178;
			}
yy189:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':	goto yy189;
			default:	goto yy191;
			}
yy191:
			{ m_tokens.emplace_back(TType::Integer, a2i(p0+1, 2));
							  m_tokens.back().col = col;
							  continue; }
yy192:
			++p;
			{ m_tokens.emplace_back(TType::LogAnd);
							  m_tokens.back().col = col;
							  continue; }
yy194:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy178;
			case '\'':	goto yy196;
			case '\\':	goto yy198;
			default:	goto yy194;
			}
yy196:
			++p;
			p1 = yyt1;
			p2 = p - 1;
			{
							  string str = str_compress_escapes(string(p1, p2));
							  if (str.length() != 1) {
								  g_errors.error(ErrCode::InvalidCharConst);
								  clear();
							  }
							  else {
								  m_tokens.emplace_back(TType::Integer, str[0]);
								  m_tokens.back().col = col;
							  }
							  continue; }
yy198:
			yych = *++p;
			switch (yych) {
			case 0x00:
			case '\n':
			case '\r':	goto yy178;
			default:	goto yy194;
			}
yy199:
			++p;
			{ m_tokens.emplace_back(TType::Pow);
							  m_tokens.back().col = col;
							  continue; }
yy201:
			yych = *++p;
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy201;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
				yyt1 = p;
				goto yy206;
			default:	goto yy178;
			}
yy203:
			yyaccept = 6;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy203;
			case 'E':
			case 'e':	goto yy241;
			default:	goto yy205;
			}
yy205:
			{ m_tokens.emplace_back(TType::Floating, atof(p0));
							  m_tokens.back().col = col;
							  continue; }
yy206:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy206;
			default:	goto yy208;
			}
yy208:
			p1 = yyt1;
			p2 = p;
			{
							  if (first_token) {
								  string str = ident_change_case(string(p1, p2));
								  m_tokens.emplace_back(TType::Label, str);
							  }
							  else {
								  p = p0 + 1;
								  m_tokens.emplace_back(TType::Dot);
							  }
							  m_tokens.back().col = col;
							  continue; }
yy209:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy209;
			case 'H':
			case 'h':	goto yy214;
			default:	goto yy178;
			}
yy211:
			yyaccept = 7;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'H':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'h':	goto yy243;
			default:	goto yy212;
			}
yy212:
			{ m_tokens.emplace_back(TType::Integer, a2i(p0, 2));
							  m_tokens.back().col = col;
							  continue; }
yy213:
			yyaccept = 3;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy209;
			case 'H':
			case 'h':	goto yy214;
			default:	goto yy128;
			}
yy214:
			++p;
			{ m_tokens.emplace_back(TType::Integer, a2i(p0, 16));
							  m_tokens.back().col = col;
							  continue; }
yy216:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy245;
			default:	goto yy178;
			}
yy217:
			yyaccept = 7;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy209;
			case 'H':
			case 'h':	goto yy214;
			default:	goto yy212;
			}
yy218:
			++p;
			{ m_tokens.emplace_back(TType::LShift);
							  m_tokens.back().col = col;
							  continue; }
yy220:
			++p;
			{ m_tokens.emplace_back(TType::Le);
							  m_tokens.back().col = col;
							  continue; }
yy222:
			++p;
			goto yy141;
yy223:
			++p;
			{ m_tokens.emplace_back(TType::Ge);
							  m_tokens.back().col = col;
							  continue; }
yy225:
			++p;
			{ m_tokens.emplace_back(TType::RShift);
							  m_tokens.back().col = col;
							  continue; }
yy227:
			yych = *++p;
			switch (yych) {
			case '\t':
			case '\v':
			case '\f':
			case ' ':	goto yy227;
			case ':':	goto yy230;
			default:	goto yy178;
			}
yy229:
			++p;
			goto yy148;
yy230:
			++p;
			p1 = yyt1;
			{
							  string str = ident_change_case(string(p0, p1));
							  if (first_token) {
								  m_tokens.emplace_back(TType::Label, str);
							  }
							  else {
								  p = p1;
								  Keyword keyword = lu_keyword(str);
								  if (keyword == Keyword::ASMPC)
									  m_tokens.emplace_back(TType::ASMPC);
								  else
								  m_tokens.emplace_back(TType::Ident, str, keyword);
							  }
							  m_tokens.back().col = col;
							  continue; }
yy232:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 'F':
			case 'f':	goto yy152;
			default:	goto yy154;
			}
yy233:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case '.':	goto yy248;
			default:	goto yy154;
			}
yy234:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 'A':
			case 'a':	goto yy152;
			case 'C':
			case 'c':	goto yy249;
			default:	goto yy154;
			}
yy235:
			++p;
			{ m_tokens.emplace_back(TType::LogXor);
							  m_tokens.back().col = col;
							  continue; }
yy237:
			++p;
			{ m_tokens.emplace_back(TType::LogOr);
							  m_tokens.back().col = col;
							  continue; }
yy239:
			++p;
			p1 = p - 1;
			{
							  int n = 0;
							  for (const char* p = p0+2; p < p1; p++) {
								  n *= 2;
								  if (*p == '#') n++;
							  }
							  m_tokens.emplace_back(TType::Integer, n);
							  m_tokens.back().col = col;
							  continue; }
yy241:
			yych = *++p;
			switch (yych) {
			case '+':
			case '-':	goto yy250;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy251;
			default:	goto yy178;
			}
yy242:
			yyaccept = 8;
			yych = *(YYMARKER = ++p);
yy243:
			switch (yych) {
			case '0':
			case '1':	goto yy242;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy209;
			case 'H':
			case 'h':	goto yy214;
			default:	goto yy244;
			}
yy244:
			{ m_tokens.emplace_back(TType::Integer, a2i(p0+2, 2));
							  m_tokens.back().col = col;
							  continue; }
yy245:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy245;
			default:	goto yy247;
			}
yy247:
			{ m_tokens.emplace_back(TType::Integer, a2i(p0+2, 16));
							  m_tokens.back().col = col;
							  continue; }
yy248:
			yych = *++p;
			switch (yych) {
			case 'B':
			case 'P':
			case 'Q':
			case 'W':
			case 'b':
			case 'p':
			case 'q':
			case 'w':	goto yy229;
			default:	goto yy178;
			}
yy249:
			yyaccept = 5;
			yych = *(YYMARKER = ++p);
			switch (yych) {
			case 'A':
			case 'a':	goto yy152;
			default:	goto yy154;
			}
yy250:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy251;
			default:	goto yy178;
			}
yy251:
			yych = *++p;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy251;
			default:	goto yy205;
			}
		}

	}
}
