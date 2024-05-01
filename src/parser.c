#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 94
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 41
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 9
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_LT_BANG = 1,
  aux_sym_doctype_token1 = 2,
  anon_sym_GT = 3,
  sym__doctype = 4,
  anon_sym_LT = 5,
  anon_sym_SLASH_GT = 6,
  anon_sym_LT_SLASH = 7,
  anon_sym_EQ = 8,
  sym_attribute_name = 9,
  sym_attribute_value = 10,
  sym_entity = 11,
  anon_sym_SQUOTE = 12,
  aux_sym_quoted_attribute_value_token1 = 13,
  anon_sym_DQUOTE = 14,
  aux_sym_quoted_attribute_value_token2 = 15,
  sym_text = 16,
  sym__start_tag_name = 17,
  sym__script_start_tag_name = 18,
  sym__style_start_tag_name = 19,
  sym__end_tag_name = 20,
  sym_erroneous_end_tag_name = 21,
  sym__implicit_end_tag = 22,
  sym_raw_text = 23,
  sym_comment = 24,
  sym_document = 25,
  sym_doctype = 26,
  sym__node = 27,
  sym_element = 28,
  sym_script_element = 29,
  sym_style_element = 30,
  sym_start_tag = 31,
  sym_script_start_tag = 32,
  sym_style_start_tag = 33,
  sym_self_closing_tag = 34,
  sym_end_tag = 35,
  sym_erroneous_end_tag = 36,
  sym_attribute = 37,
  sym_quoted_attribute_value = 38,
  aux_sym_document_repeat1 = 39,
  aux_sym_start_tag_repeat1 = 40,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LT_BANG] = "<!",
  [aux_sym_doctype_token1] = "doctype_token1",
  [anon_sym_GT] = ">",
  [sym__doctype] = "doctype",
  [anon_sym_LT] = "<",
  [anon_sym_SLASH_GT] = "/>",
  [anon_sym_LT_SLASH] = "</",
  [anon_sym_EQ] = "=",
  [sym_attribute_name] = "attribute_name",
  [sym_attribute_value] = "attribute_value",
  [sym_entity] = "entity",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_attribute_value_token2] = "attribute_value",
  [sym_text] = "text",
  [sym__start_tag_name] = "tag_name",
  [sym__script_start_tag_name] = "tag_name",
  [sym__style_start_tag_name] = "tag_name",
  [sym__end_tag_name] = "tag_name",
  [sym_erroneous_end_tag_name] = "erroneous_end_tag_name",
  [sym__implicit_end_tag] = "_implicit_end_tag",
  [sym_raw_text] = "raw_text",
  [sym_comment] = "comment",
  [sym_document] = "document",
  [sym_doctype] = "doctype",
  [sym__node] = "_node",
  [sym_element] = "element",
  [sym_script_element] = "script_element",
  [sym_style_element] = "style_element",
  [sym_start_tag] = "start_tag",
  [sym_script_start_tag] = "start_tag",
  [sym_style_start_tag] = "start_tag",
  [sym_self_closing_tag] = "self_closing_tag",
  [sym_end_tag] = "end_tag",
  [sym_erroneous_end_tag] = "erroneous_end_tag",
  [sym_attribute] = "attribute",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_start_tag_repeat1] = "start_tag_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LT_BANG] = anon_sym_LT_BANG,
  [aux_sym_doctype_token1] = aux_sym_doctype_token1,
  [anon_sym_GT] = anon_sym_GT,
  [sym__doctype] = sym__doctype,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
  [anon_sym_LT_SLASH] = anon_sym_LT_SLASH,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_attribute_name] = sym_attribute_name,
  [sym_attribute_value] = sym_attribute_value,
  [sym_entity] = sym_entity,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = sym_attribute_value,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_attribute_value_token2] = sym_attribute_value,
  [sym_text] = sym_text,
  [sym__start_tag_name] = sym__start_tag_name,
  [sym__script_start_tag_name] = sym__start_tag_name,
  [sym__style_start_tag_name] = sym__start_tag_name,
  [sym__end_tag_name] = sym__start_tag_name,
  [sym_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
  [sym__implicit_end_tag] = sym__implicit_end_tag,
  [sym_raw_text] = sym_raw_text,
  [sym_comment] = sym_comment,
  [sym_document] = sym_document,
  [sym_doctype] = sym_doctype,
  [sym__node] = sym__node,
  [sym_element] = sym_element,
  [sym_script_element] = sym_script_element,
  [sym_style_element] = sym_style_element,
  [sym_start_tag] = sym_start_tag,
  [sym_script_start_tag] = sym_start_tag,
  [sym_style_start_tag] = sym_start_tag,
  [sym_self_closing_tag] = sym_self_closing_tag,
  [sym_end_tag] = sym_end_tag,
  [sym_erroneous_end_tag] = sym_erroneous_end_tag,
  [sym_attribute] = sym_attribute,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_start_tag_repeat1] = aux_sym_start_tag_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LT_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_doctype_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym__doctype] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token2] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym__start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__script_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__style_start_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_erroneous_end_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym__implicit_end_tag] = {
    .visible = false,
    .named = true,
  },
  [sym_raw_text] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_doctype] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_element] = {
    .visible = true,
    .named = true,
  },
  [sym_script_element] = {
    .visible = true,
    .named = true,
  },
  [sym_style_element] = {
    .visible = true,
    .named = true,
  },
  [sym_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_script_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_style_start_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_self_closing_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_erroneous_end_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_start_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 2,
  [4] = 4,
  [5] = 4,
  [6] = 6,
  [7] = 6,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 11,
  [14] = 14,
  [15] = 15,
  [16] = 15,
  [17] = 12,
  [18] = 18,
  [19] = 19,
  [20] = 10,
  [21] = 21,
  [22] = 9,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 18,
  [29] = 19,
  [30] = 27,
  [31] = 14,
  [32] = 21,
  [33] = 23,
  [34] = 25,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 36,
  [39] = 35,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 43,
  [45] = 45,
  [46] = 46,
  [47] = 37,
  [48] = 48,
  [49] = 42,
  [50] = 50,
  [51] = 51,
  [52] = 51,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 54,
  [57] = 55,
  [58] = 53,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 62,
  [67] = 67,
  [68] = 63,
  [69] = 48,
  [70] = 50,
  [71] = 64,
  [72] = 65,
  [73] = 73,
  [74] = 67,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 82,
  [84] = 76,
  [85] = 85,
  [86] = 78,
  [87] = 87,
  [88] = 87,
  [89] = 81,
  [90] = 79,
  [91] = 80,
  [92] = 85,
  [93] = 75,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(17);
      if (lookahead == '"') ADVANCE(72);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '\'') ADVANCE(69);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == '<') ADVANCE(23);
      if (lookahead == '=') ADVANCE(26);
      if (lookahead == '>') ADVANCE(21);
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(9);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(72);
      if (lookahead == '\'') ADVANCE(69);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(28);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(72);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(73);
      if (lookahead != 0) ADVANCE(74);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(69);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(70);
      if (lookahead != 0) ADVANCE(71);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == '=') ADVANCE(26);
      if (lookahead == '>') ADVANCE(21);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5)
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '<') ADVANCE(27);
      END_STATE();
    case 6:
      if (lookahead == '>') ADVANCE(24);
      END_STATE();
    case 7:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(7);
      END_STATE();
    case 10:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(8);
      END_STATE();
    case 11:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(13);
      END_STATE();
    case 12:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 13:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(10);
      END_STATE();
    case 14:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(20);
      END_STATE();
    case 15:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 16:
      if (eof) ADVANCE(17);
      if (lookahead == '&') ADVANCE(3);
      if (lookahead == '<') ADVANCE(23);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(75);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(76);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(20);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(18);
      if (lookahead == '/') ADVANCE(25);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_attribute_value);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(30);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(33);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(44);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(48);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(49);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(50);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(52);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(60);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(62);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(65);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(70);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(71);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(73);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(74);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token2);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(75);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(76);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_text);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(76);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 16, .external_lex_state = 2},
  [2] = {.lex_state = 16, .external_lex_state = 3},
  [3] = {.lex_state = 16, .external_lex_state = 3},
  [4] = {.lex_state = 16, .external_lex_state = 3},
  [5] = {.lex_state = 16, .external_lex_state = 3},
  [6] = {.lex_state = 16, .external_lex_state = 3},
  [7] = {.lex_state = 16, .external_lex_state = 2},
  [8] = {.lex_state = 16, .external_lex_state = 2},
  [9] = {.lex_state = 16, .external_lex_state = 2},
  [10] = {.lex_state = 16, .external_lex_state = 2},
  [11] = {.lex_state = 16, .external_lex_state = 2},
  [12] = {.lex_state = 16, .external_lex_state = 3},
  [13] = {.lex_state = 16, .external_lex_state = 3},
  [14] = {.lex_state = 16, .external_lex_state = 2},
  [15] = {.lex_state = 16, .external_lex_state = 2},
  [16] = {.lex_state = 16, .external_lex_state = 3},
  [17] = {.lex_state = 16, .external_lex_state = 2},
  [18] = {.lex_state = 16, .external_lex_state = 3},
  [19] = {.lex_state = 16, .external_lex_state = 3},
  [20] = {.lex_state = 16, .external_lex_state = 3},
  [21] = {.lex_state = 16, .external_lex_state = 2},
  [22] = {.lex_state = 16, .external_lex_state = 3},
  [23] = {.lex_state = 16, .external_lex_state = 2},
  [24] = {.lex_state = 16, .external_lex_state = 3},
  [25] = {.lex_state = 16, .external_lex_state = 3},
  [26] = {.lex_state = 16, .external_lex_state = 3},
  [27] = {.lex_state = 16, .external_lex_state = 2},
  [28] = {.lex_state = 16, .external_lex_state = 2},
  [29] = {.lex_state = 16, .external_lex_state = 2},
  [30] = {.lex_state = 16, .external_lex_state = 3},
  [31] = {.lex_state = 16, .external_lex_state = 3},
  [32] = {.lex_state = 16, .external_lex_state = 3},
  [33] = {.lex_state = 16, .external_lex_state = 3},
  [34] = {.lex_state = 16, .external_lex_state = 2},
  [35] = {.lex_state = 5, .external_lex_state = 4},
  [36] = {.lex_state = 5, .external_lex_state = 4},
  [37] = {.lex_state = 5, .external_lex_state = 4},
  [38] = {.lex_state = 5, .external_lex_state = 4},
  [39] = {.lex_state = 5, .external_lex_state = 4},
  [40] = {.lex_state = 5, .external_lex_state = 2},
  [41] = {.lex_state = 5, .external_lex_state = 2},
  [42] = {.lex_state = 5, .external_lex_state = 4},
  [43] = {.lex_state = 1, .external_lex_state = 2},
  [44] = {.lex_state = 1, .external_lex_state = 2},
  [45] = {.lex_state = 5, .external_lex_state = 2},
  [46] = {.lex_state = 5, .external_lex_state = 2},
  [47] = {.lex_state = 5, .external_lex_state = 2},
  [48] = {.lex_state = 5, .external_lex_state = 4},
  [49] = {.lex_state = 5, .external_lex_state = 2},
  [50] = {.lex_state = 5, .external_lex_state = 4},
  [51] = {.lex_state = 0, .external_lex_state = 5},
  [52] = {.lex_state = 0, .external_lex_state = 5},
  [53] = {.lex_state = 5, .external_lex_state = 4},
  [54] = {.lex_state = 0, .external_lex_state = 6},
  [55] = {.lex_state = 0, .external_lex_state = 6},
  [56] = {.lex_state = 0, .external_lex_state = 6},
  [57] = {.lex_state = 0, .external_lex_state = 6},
  [58] = {.lex_state = 5, .external_lex_state = 2},
  [59] = {.lex_state = 0, .external_lex_state = 6},
  [60] = {.lex_state = 0, .external_lex_state = 6},
  [61] = {.lex_state = 0, .external_lex_state = 6},
  [62] = {.lex_state = 0, .external_lex_state = 7},
  [63] = {.lex_state = 0, .external_lex_state = 2},
  [64] = {.lex_state = 2, .external_lex_state = 2},
  [65] = {.lex_state = 0, .external_lex_state = 2},
  [66] = {.lex_state = 0, .external_lex_state = 7},
  [67] = {.lex_state = 4, .external_lex_state = 2},
  [68] = {.lex_state = 0, .external_lex_state = 2},
  [69] = {.lex_state = 5, .external_lex_state = 2},
  [70] = {.lex_state = 5, .external_lex_state = 2},
  [71] = {.lex_state = 2, .external_lex_state = 2},
  [72] = {.lex_state = 0, .external_lex_state = 2},
  [73] = {.lex_state = 0, .external_lex_state = 6},
  [74] = {.lex_state = 4, .external_lex_state = 2},
  [75] = {.lex_state = 0, .external_lex_state = 2},
  [76] = {.lex_state = 0, .external_lex_state = 2},
  [77] = {.lex_state = 0, .external_lex_state = 2},
  [78] = {.lex_state = 0, .external_lex_state = 2},
  [79] = {.lex_state = 14, .external_lex_state = 2},
  [80] = {.lex_state = 0, .external_lex_state = 2},
  [81] = {.lex_state = 0, .external_lex_state = 8},
  [82] = {.lex_state = 0, .external_lex_state = 2},
  [83] = {.lex_state = 0, .external_lex_state = 2},
  [84] = {.lex_state = 0, .external_lex_state = 2},
  [85] = {.lex_state = 0, .external_lex_state = 9},
  [86] = {.lex_state = 0, .external_lex_state = 2},
  [87] = {.lex_state = 0, .external_lex_state = 2},
  [88] = {.lex_state = 0, .external_lex_state = 2},
  [89] = {.lex_state = 0, .external_lex_state = 8},
  [90] = {.lex_state = 14, .external_lex_state = 2},
  [91] = {.lex_state = 0, .external_lex_state = 2},
  [92] = {.lex_state = 0, .external_lex_state = 9},
  [93] = {.lex_state = 0, .external_lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LT_BANG] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym__doctype] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_SLASH_GT] = ACTIONS(1),
    [anon_sym_LT_SLASH] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_entity] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__start_tag_name] = ACTIONS(1),
    [sym__script_start_tag_name] = ACTIONS(1),
    [sym__style_start_tag_name] = ACTIONS(1),
    [sym__end_tag_name] = ACTIONS(1),
    [sym_erroneous_end_tag_name] = ACTIONS(1),
    [sym__implicit_end_tag] = ACTIONS(1),
    [sym_raw_text] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_document] = STATE(77),
    [sym_doctype] = STATE(8),
    [sym__node] = STATE(8),
    [sym_element] = STATE(8),
    [sym_script_element] = STATE(8),
    [sym_style_element] = STATE(8),
    [sym_start_tag] = STATE(4),
    [sym_script_start_tag] = STATE(54),
    [sym_style_start_tag] = STATE(57),
    [sym_self_closing_tag] = STATE(11),
    [sym_erroneous_end_tag] = STATE(8),
    [aux_sym_document_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LT_BANG] = ACTIONS(7),
    [anon_sym_LT] = ACTIONS(9),
    [anon_sym_LT_SLASH] = ACTIONS(11),
    [sym_entity] = ACTIONS(13),
    [sym_text] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_LT_BANG,
    ACTIONS(19), 1,
      anon_sym_LT,
    ACTIONS(21), 1,
      anon_sym_LT_SLASH,
    ACTIONS(23), 1,
      sym_entity,
    ACTIONS(25), 1,
      sym_text,
    ACTIONS(27), 1,
      sym__implicit_end_tag,
    STATE(5), 1,
      sym_start_tag,
    STATE(9), 1,
      sym_end_tag,
    STATE(13), 1,
      sym_self_closing_tag,
    STATE(55), 1,
      sym_style_start_tag,
    STATE(56), 1,
      sym_script_start_tag,
    STATE(6), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [46] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_LT_BANG,
    ACTIONS(19), 1,
      anon_sym_LT,
    ACTIONS(23), 1,
      sym_entity,
    ACTIONS(25), 1,
      sym_text,
    ACTIONS(29), 1,
      anon_sym_LT_SLASH,
    ACTIONS(31), 1,
      sym__implicit_end_tag,
    STATE(5), 1,
      sym_start_tag,
    STATE(13), 1,
      sym_self_closing_tag,
    STATE(22), 1,
      sym_end_tag,
    STATE(55), 1,
      sym_style_start_tag,
    STATE(56), 1,
      sym_script_start_tag,
    STATE(6), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [92] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_LT_BANG,
    ACTIONS(19), 1,
      anon_sym_LT,
    ACTIONS(21), 1,
      anon_sym_LT_SLASH,
    ACTIONS(33), 1,
      sym_entity,
    ACTIONS(35), 1,
      sym_text,
    ACTIONS(37), 1,
      sym__implicit_end_tag,
    STATE(5), 1,
      sym_start_tag,
    STATE(13), 1,
      sym_self_closing_tag,
    STATE(17), 1,
      sym_end_tag,
    STATE(55), 1,
      sym_style_start_tag,
    STATE(56), 1,
      sym_script_start_tag,
    STATE(2), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [138] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_LT_BANG,
    ACTIONS(19), 1,
      anon_sym_LT,
    ACTIONS(29), 1,
      anon_sym_LT_SLASH,
    ACTIONS(39), 1,
      sym_entity,
    ACTIONS(41), 1,
      sym_text,
    ACTIONS(43), 1,
      sym__implicit_end_tag,
    STATE(5), 1,
      sym_start_tag,
    STATE(12), 1,
      sym_end_tag,
    STATE(13), 1,
      sym_self_closing_tag,
    STATE(55), 1,
      sym_style_start_tag,
    STATE(56), 1,
      sym_script_start_tag,
    STATE(3), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [184] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(45), 1,
      anon_sym_LT_BANG,
    ACTIONS(48), 1,
      anon_sym_LT,
    ACTIONS(51), 1,
      anon_sym_LT_SLASH,
    ACTIONS(54), 1,
      sym_entity,
    ACTIONS(57), 1,
      sym_text,
    ACTIONS(60), 1,
      sym__implicit_end_tag,
    STATE(5), 1,
      sym_start_tag,
    STATE(13), 1,
      sym_self_closing_tag,
    STATE(55), 1,
      sym_style_start_tag,
    STATE(56), 1,
      sym_script_start_tag,
    STATE(6), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [227] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
    ACTIONS(62), 1,
      anon_sym_LT_BANG,
    ACTIONS(65), 1,
      anon_sym_LT,
    ACTIONS(68), 1,
      anon_sym_LT_SLASH,
    ACTIONS(71), 1,
      sym_entity,
    ACTIONS(74), 1,
      sym_text,
    STATE(4), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_self_closing_tag,
    STATE(54), 1,
      sym_script_start_tag,
    STATE(57), 1,
      sym_style_start_tag,
    STATE(7), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [270] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_LT_BANG,
    ACTIONS(9), 1,
      anon_sym_LT,
    ACTIONS(11), 1,
      anon_sym_LT_SLASH,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
    ACTIONS(79), 1,
      sym_entity,
    ACTIONS(81), 1,
      sym_text,
    STATE(4), 1,
      sym_start_tag,
    STATE(11), 1,
      sym_self_closing_tag,
    STATE(54), 1,
      sym_script_start_tag,
    STATE(57), 1,
      sym_style_start_tag,
    STATE(7), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [313] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(83), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(85), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [327] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(89), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [341] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(93), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [355] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(95), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [369] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(91), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(93), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [383] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(101), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [397] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(105), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [411] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(103), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(105), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [425] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(97), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(95), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [439] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(109), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(107), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [453] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(113), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(111), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [467] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(87), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(89), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [481] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(117), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [495] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(83), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(85), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [509] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(121), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [523] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(123), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [537] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(129), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(127), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [551] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(133), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(131), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [565] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(137), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [579] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(109), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(107), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [593] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(113), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(111), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [607] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(135), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(137), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [621] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(99), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(101), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [635] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(115), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(117), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [649] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 2,
      sym__implicit_end_tag,
      sym_text,
    ACTIONS(121), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [663] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(127), 4,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
      sym_entity,
  [677] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      anon_sym_GT,
    ACTIONS(141), 1,
      anon_sym_SLASH_GT,
    ACTIONS(143), 1,
      sym_attribute_name,
    STATE(38), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [694] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      sym_attribute_name,
    ACTIONS(145), 1,
      anon_sym_GT,
    ACTIONS(147), 1,
      anon_sym_SLASH_GT,
    STATE(37), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [711] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      sym_attribute_name,
    ACTIONS(149), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(37), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [726] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      sym_attribute_name,
    ACTIONS(145), 1,
      anon_sym_GT,
    ACTIONS(154), 1,
      anon_sym_SLASH_GT,
    STATE(37), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [743] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(139), 1,
      anon_sym_GT,
    ACTIONS(143), 1,
      sym_attribute_name,
    ACTIONS(156), 1,
      anon_sym_SLASH_GT,
    STATE(36), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [760] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 1,
      anon_sym_GT,
    ACTIONS(160), 1,
      sym_attribute_name,
    STATE(47), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [774] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(160), 1,
      sym_attribute_name,
    ACTIONS(162), 1,
      anon_sym_GT,
    STATE(47), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [788] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(166), 1,
      anon_sym_EQ,
    ACTIONS(164), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [800] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(168), 1,
      sym_attribute_value,
    ACTIONS(170), 1,
      anon_sym_SQUOTE,
    ACTIONS(172), 1,
      anon_sym_DQUOTE,
    STATE(48), 1,
      sym_quoted_attribute_value,
  [816] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(174), 1,
      sym_attribute_value,
    ACTIONS(176), 1,
      anon_sym_SQUOTE,
    ACTIONS(178), 1,
      anon_sym_DQUOTE,
    STATE(69), 1,
      sym_quoted_attribute_value,
  [832] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(160), 1,
      sym_attribute_name,
    ACTIONS(180), 1,
      anon_sym_GT,
    STATE(40), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [846] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(160), 1,
      sym_attribute_name,
    ACTIONS(182), 1,
      anon_sym_GT,
    STATE(41), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [860] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(149), 1,
      anon_sym_GT,
    ACTIONS(184), 1,
      sym_attribute_name,
    STATE(47), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [874] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(187), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [883] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(189), 1,
      anon_sym_EQ,
    ACTIONS(164), 2,
      anon_sym_GT,
      sym_attribute_name,
  [894] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(191), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [903] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(193), 1,
      sym__start_tag_name,
    ACTIONS(195), 1,
      sym__script_start_tag_name,
    ACTIONS(197), 1,
      sym__style_start_tag_name,
  [916] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(195), 1,
      sym__script_start_tag_name,
    ACTIONS(197), 1,
      sym__style_start_tag_name,
    ACTIONS(199), 1,
      sym__start_tag_name,
  [929] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [938] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    ACTIONS(205), 1,
      sym_raw_text,
    STATE(21), 1,
      sym_end_tag,
  [951] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    ACTIONS(209), 1,
      sym_raw_text,
    STATE(33), 1,
      sym_end_tag,
  [964] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    ACTIONS(211), 1,
      sym_raw_text,
    STATE(32), 1,
      sym_end_tag,
  [977] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    ACTIONS(213), 1,
      sym_raw_text,
    STATE(23), 1,
      sym_end_tag,
  [990] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 2,
      anon_sym_GT,
      sym_attribute_name,
  [998] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1006] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1014] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1022] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(221), 1,
      sym__end_tag_name,
    ACTIONS(223), 1,
      sym_erroneous_end_tag_name,
  [1032] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    STATE(29), 1,
      sym_end_tag,
  [1042] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_DQUOTE,
    ACTIONS(227), 1,
      aux_sym_quoted_attribute_value_token2,
  [1052] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_LT_SLASH,
    STATE(10), 1,
      sym_end_tag,
  [1062] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(229), 1,
      sym__end_tag_name,
  [1072] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_SQUOTE,
    ACTIONS(231), 1,
      aux_sym_quoted_attribute_value_token1,
  [1082] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    STATE(19), 1,
      sym_end_tag,
  [1092] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(187), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1100] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(191), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1108] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(233), 1,
      anon_sym_DQUOTE,
    ACTIONS(235), 1,
      aux_sym_quoted_attribute_value_token2,
  [1118] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LT_SLASH,
    STATE(20), 1,
      sym_end_tag,
  [1128] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(237), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1136] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(233), 1,
      anon_sym_SQUOTE,
    ACTIONS(239), 1,
      aux_sym_quoted_attribute_value_token1,
  [1146] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(241), 1,
      sym__doctype,
  [1153] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(243), 1,
      anon_sym_GT,
  [1160] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(245), 1,
      ts_builtin_sym_end,
  [1167] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(247), 1,
      anon_sym_SQUOTE,
  [1174] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(249), 1,
      aux_sym_doctype_token1,
  [1181] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(251), 1,
      anon_sym_GT,
  [1188] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(253), 1,
      sym_erroneous_end_tag_name,
  [1195] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(255), 1,
      anon_sym_GT,
  [1202] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(257), 1,
      anon_sym_GT,
  [1209] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(259), 1,
      anon_sym_GT,
  [1216] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(229), 1,
      sym__end_tag_name,
  [1223] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(261), 1,
      anon_sym_SQUOTE,
  [1230] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(261), 1,
      anon_sym_DQUOTE,
  [1237] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(247), 1,
      anon_sym_DQUOTE,
  [1244] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 1,
      sym_erroneous_end_tag_name,
  [1251] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(263), 1,
      aux_sym_doctype_token1,
  [1258] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(265), 1,
      anon_sym_GT,
  [1265] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(221), 1,
      sym__end_tag_name,
  [1272] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(267), 1,
      sym__doctype,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 46,
  [SMALL_STATE(4)] = 92,
  [SMALL_STATE(5)] = 138,
  [SMALL_STATE(6)] = 184,
  [SMALL_STATE(7)] = 227,
  [SMALL_STATE(8)] = 270,
  [SMALL_STATE(9)] = 313,
  [SMALL_STATE(10)] = 327,
  [SMALL_STATE(11)] = 341,
  [SMALL_STATE(12)] = 355,
  [SMALL_STATE(13)] = 369,
  [SMALL_STATE(14)] = 383,
  [SMALL_STATE(15)] = 397,
  [SMALL_STATE(16)] = 411,
  [SMALL_STATE(17)] = 425,
  [SMALL_STATE(18)] = 439,
  [SMALL_STATE(19)] = 453,
  [SMALL_STATE(20)] = 467,
  [SMALL_STATE(21)] = 481,
  [SMALL_STATE(22)] = 495,
  [SMALL_STATE(23)] = 509,
  [SMALL_STATE(24)] = 523,
  [SMALL_STATE(25)] = 537,
  [SMALL_STATE(26)] = 551,
  [SMALL_STATE(27)] = 565,
  [SMALL_STATE(28)] = 579,
  [SMALL_STATE(29)] = 593,
  [SMALL_STATE(30)] = 607,
  [SMALL_STATE(31)] = 621,
  [SMALL_STATE(32)] = 635,
  [SMALL_STATE(33)] = 649,
  [SMALL_STATE(34)] = 663,
  [SMALL_STATE(35)] = 677,
  [SMALL_STATE(36)] = 694,
  [SMALL_STATE(37)] = 711,
  [SMALL_STATE(38)] = 726,
  [SMALL_STATE(39)] = 743,
  [SMALL_STATE(40)] = 760,
  [SMALL_STATE(41)] = 774,
  [SMALL_STATE(42)] = 788,
  [SMALL_STATE(43)] = 800,
  [SMALL_STATE(44)] = 816,
  [SMALL_STATE(45)] = 832,
  [SMALL_STATE(46)] = 846,
  [SMALL_STATE(47)] = 860,
  [SMALL_STATE(48)] = 874,
  [SMALL_STATE(49)] = 883,
  [SMALL_STATE(50)] = 894,
  [SMALL_STATE(51)] = 903,
  [SMALL_STATE(52)] = 916,
  [SMALL_STATE(53)] = 929,
  [SMALL_STATE(54)] = 938,
  [SMALL_STATE(55)] = 951,
  [SMALL_STATE(56)] = 964,
  [SMALL_STATE(57)] = 977,
  [SMALL_STATE(58)] = 990,
  [SMALL_STATE(59)] = 998,
  [SMALL_STATE(60)] = 1006,
  [SMALL_STATE(61)] = 1014,
  [SMALL_STATE(62)] = 1022,
  [SMALL_STATE(63)] = 1032,
  [SMALL_STATE(64)] = 1042,
  [SMALL_STATE(65)] = 1052,
  [SMALL_STATE(66)] = 1062,
  [SMALL_STATE(67)] = 1072,
  [SMALL_STATE(68)] = 1082,
  [SMALL_STATE(69)] = 1092,
  [SMALL_STATE(70)] = 1100,
  [SMALL_STATE(71)] = 1108,
  [SMALL_STATE(72)] = 1118,
  [SMALL_STATE(73)] = 1128,
  [SMALL_STATE(74)] = 1136,
  [SMALL_STATE(75)] = 1146,
  [SMALL_STATE(76)] = 1153,
  [SMALL_STATE(77)] = 1160,
  [SMALL_STATE(78)] = 1167,
  [SMALL_STATE(79)] = 1174,
  [SMALL_STATE(80)] = 1181,
  [SMALL_STATE(81)] = 1188,
  [SMALL_STATE(82)] = 1195,
  [SMALL_STATE(83)] = 1202,
  [SMALL_STATE(84)] = 1209,
  [SMALL_STATE(85)] = 1216,
  [SMALL_STATE(86)] = 1223,
  [SMALL_STATE(87)] = 1230,
  [SMALL_STATE(88)] = 1237,
  [SMALL_STATE(89)] = 1244,
  [SMALL_STATE(90)] = 1251,
  [SMALL_STATE(91)] = 1258,
  [SMALL_STATE(92)] = 1265,
  [SMALL_STATE(93)] = 1272,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(93),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(51),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(89),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(6),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(6),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(75),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(52),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(81),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(7),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(7),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(42),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [184] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2), SHIFT_REPEAT(49),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [245] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__start_tag_name = 0,
  ts_external_token__script_start_tag_name = 1,
  ts_external_token__style_start_tag_name = 2,
  ts_external_token__end_tag_name = 3,
  ts_external_token_erroneous_end_tag_name = 4,
  ts_external_token_SLASH_GT = 5,
  ts_external_token__implicit_end_tag = 6,
  ts_external_token_raw_text = 7,
  ts_external_token_comment = 8,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__start_tag_name] = sym__start_tag_name,
  [ts_external_token__script_start_tag_name] = sym__script_start_tag_name,
  [ts_external_token__style_start_tag_name] = sym__style_start_tag_name,
  [ts_external_token__end_tag_name] = sym__end_tag_name,
  [ts_external_token_erroneous_end_tag_name] = sym_erroneous_end_tag_name,
  [ts_external_token_SLASH_GT] = anon_sym_SLASH_GT,
  [ts_external_token__implicit_end_tag] = sym__implicit_end_tag,
  [ts_external_token_raw_text] = sym_raw_text,
  [ts_external_token_comment] = sym_comment,
};

static const bool ts_external_scanner_states[10][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__script_start_tag_name] = true,
    [ts_external_token__style_start_tag_name] = true,
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_erroneous_end_tag_name] = true,
    [ts_external_token_SLASH_GT] = true,
    [ts_external_token__implicit_end_tag] = true,
    [ts_external_token_raw_text] = true,
    [ts_external_token_comment] = true,
  },
  [2] = {
    [ts_external_token_comment] = true,
  },
  [3] = {
    [ts_external_token__implicit_end_tag] = true,
    [ts_external_token_comment] = true,
  },
  [4] = {
    [ts_external_token_SLASH_GT] = true,
    [ts_external_token_comment] = true,
  },
  [5] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__script_start_tag_name] = true,
    [ts_external_token__style_start_tag_name] = true,
    [ts_external_token_comment] = true,
  },
  [6] = {
    [ts_external_token_raw_text] = true,
    [ts_external_token_comment] = true,
  },
  [7] = {
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_erroneous_end_tag_name] = true,
    [ts_external_token_comment] = true,
  },
  [8] = {
    [ts_external_token_erroneous_end_tag_name] = true,
    [ts_external_token_comment] = true,
  },
  [9] = {
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_comment] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_html_external_scanner_create(void);
void tree_sitter_html_external_scanner_destroy(void *);
bool tree_sitter_html_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_html_external_scanner_serialize(void *, char *);
void tree_sitter_html_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_html() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_html_external_scanner_create,
      tree_sitter_html_external_scanner_destroy,
      tree_sitter_html_external_scanner_scan,
      tree_sitter_html_external_scanner_serialize,
      tree_sitter_html_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
