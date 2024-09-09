#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 100
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 45
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
  sym_attribute_value_fragment = 10,
  sym_entity = 11,
  sym_unescaped_single_attribute_value_fragment = 12,
  sym_unescaped_double_attribute_value_fragment = 13,
  anon_sym_SQUOTE = 14,
  anon_sym_DQUOTE = 15,
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
  sym_attribute_value = 38,
  sym_quoted_attribute_value = 39,
  aux_sym_document_repeat1 = 40,
  aux_sym_start_tag_repeat1 = 41,
  aux_sym_attribute_value_repeat1 = 42,
  aux_sym_quoted_attribute_value_repeat1 = 43,
  aux_sym_quoted_attribute_value_repeat2 = 44,
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
  [sym_attribute_value_fragment] = "attribute_value_fragment",
  [sym_entity] = "entity",
  [sym_unescaped_single_attribute_value_fragment] = "attribute_value_fragment",
  [sym_unescaped_double_attribute_value_fragment] = "attribute_value_fragment",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_DQUOTE] = "\"",
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
  [sym_attribute_value] = "attribute_value",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_start_tag_repeat1] = "start_tag_repeat1",
  [aux_sym_attribute_value_repeat1] = "attribute_value_repeat1",
  [aux_sym_quoted_attribute_value_repeat1] = "quoted_attribute_value_repeat1",
  [aux_sym_quoted_attribute_value_repeat2] = "quoted_attribute_value_repeat2",
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
  [sym_attribute_value_fragment] = sym_attribute_value_fragment,
  [sym_entity] = sym_entity,
  [sym_unescaped_single_attribute_value_fragment] = sym_attribute_value_fragment,
  [sym_unescaped_double_attribute_value_fragment] = sym_attribute_value_fragment,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
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
  [sym_attribute_value] = sym_attribute_value,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_start_tag_repeat1] = aux_sym_start_tag_repeat1,
  [aux_sym_attribute_value_repeat1] = aux_sym_attribute_value_repeat1,
  [aux_sym_quoted_attribute_value_repeat1] = aux_sym_quoted_attribute_value_repeat1,
  [aux_sym_quoted_attribute_value_repeat2] = aux_sym_quoted_attribute_value_repeat2,
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
  [sym_attribute_value_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_unescaped_single_attribute_value_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_unescaped_double_attribute_value_fragment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
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
  [sym_attribute_value] = {
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
  [aux_sym_attribute_value_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_repeat2] = {
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
  [3] = 3,
  [4] = 3,
  [5] = 2,
  [6] = 6,
  [7] = 7,
  [8] = 7,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 21,
  [23] = 20,
  [24] = 11,
  [25] = 16,
  [26] = 26,
  [27] = 17,
  [28] = 9,
  [29] = 12,
  [30] = 13,
  [31] = 10,
  [32] = 18,
  [33] = 33,
  [34] = 15,
  [35] = 19,
  [36] = 14,
  [37] = 37,
  [38] = 38,
  [39] = 38,
  [40] = 40,
  [41] = 41,
  [42] = 40,
  [43] = 43,
  [44] = 37,
  [45] = 41,
  [46] = 46,
  [47] = 47,
  [48] = 47,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 49,
  [55] = 43,
  [56] = 56,
  [57] = 57,
  [58] = 52,
  [59] = 59,
  [60] = 53,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 59,
  [66] = 64,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 69,
  [71] = 68,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 67,
  [76] = 76,
  [77] = 62,
  [78] = 78,
  [79] = 78,
  [80] = 73,
  [81] = 81,
  [82] = 82,
  [83] = 76,
  [84] = 63,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 85,
  [93] = 89,
  [94] = 87,
  [95] = 88,
  [96] = 86,
  [97] = 97,
  [98] = 90,
  [99] = 91,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      ADVANCE_MAP(
        '"', 87,
        '&', 4,
        '\'', 86,
        '/', 34,
        '<', 28,
        '=', 31,
        '>', 26,
        'D', 37,
        'd', 37,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      if (lookahead != 0) ADVANCE(41);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(87);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '\'') ADVANCE(86);
      if (lookahead == '/') ADVANCE(41);
      if (lookahead == '>') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead != 0 &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(33);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(87);
      if (lookahead == '&') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(84);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(87);
      if (lookahead == '\'') ADVANCE(86);
      if (lookahead == '>') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(32);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(16);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 5:
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '\'') ADVANCE(86);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0) ADVANCE(83);
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '/') ADVANCE(34);
      if (lookahead == '>') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(33);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(32);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '>') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(32);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(29);
      END_STATE();
    case 10:
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(15);
      END_STATE();
    case 11:
      if (lookahead == 'D' ||
          lookahead == 'd') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 13:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(10);
      END_STATE();
    case 14:
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(12);
      END_STATE();
    case 15:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(17);
      END_STATE();
    case 16:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(47);
      END_STATE();
    case 17:
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(14);
      END_STATE();
    case 18:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(25);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 20:
      if (eof) ADVANCE(22);
      ADVANCE_MAP(
        '"', 87,
        '\'', 86,
        '/', 9,
        '<', 28,
        '=', 31,
        '>', 26,
        'D', 13,
        'd', 13,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead == '&') ADVANCE(4);
      if (lookahead == '<') ADVANCE(28);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(89);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_LT_BANG);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(25);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_doctype_token1);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__doctype);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '!') ADVANCE(23);
      if (lookahead == '/') ADVANCE(30);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LT_SLASH);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          lookahead != '/' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == '/') ADVANCE(41);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == '>') ADVANCE(29);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == 'C' ||
          lookahead == 'c') ADVANCE(39);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(41);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(35);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(36);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(40);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead == 'Y' ||
          lookahead == 'y') ADVANCE(38);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_attribute_value_fragment);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '"' &&
          lookahead != '&' &&
          lookahead != '\'' &&
          (lookahead < '<' || '>' < lookahead)) ADVANCE(41);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_entity);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(43);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(44);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(43);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(48);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(53);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(54);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(55);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(58);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(59);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(60);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(61);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(62);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(65);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(74);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(75);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(76);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(77);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(78);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(79);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_entity);
      if (lookahead == ';') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_unescaped_single_attribute_value_fragment);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '\'') ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_unescaped_single_attribute_value_fragment);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '\'') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_unescaped_double_attribute_value_fragment);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '&') ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_unescaped_double_attribute_value_fragment);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '&') ADVANCE(85);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_text);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(89);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_text);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(89);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 21, .external_lex_state = 2},
  [2] = {.lex_state = 21, .external_lex_state = 3},
  [3] = {.lex_state = 21, .external_lex_state = 3},
  [4] = {.lex_state = 21, .external_lex_state = 3},
  [5] = {.lex_state = 21, .external_lex_state = 3},
  [6] = {.lex_state = 21, .external_lex_state = 2},
  [7] = {.lex_state = 21, .external_lex_state = 2},
  [8] = {.lex_state = 21, .external_lex_state = 3},
  [9] = {.lex_state = 21, .external_lex_state = 2},
  [10] = {.lex_state = 21, .external_lex_state = 3},
  [11] = {.lex_state = 21, .external_lex_state = 3},
  [12] = {.lex_state = 21, .external_lex_state = 3},
  [13] = {.lex_state = 21, .external_lex_state = 3},
  [14] = {.lex_state = 21, .external_lex_state = 3},
  [15] = {.lex_state = 21, .external_lex_state = 3},
  [16] = {.lex_state = 21, .external_lex_state = 2},
  [17] = {.lex_state = 21, .external_lex_state = 3},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 21, .external_lex_state = 3},
  [20] = {.lex_state = 21, .external_lex_state = 3},
  [21] = {.lex_state = 21, .external_lex_state = 2},
  [22] = {.lex_state = 21, .external_lex_state = 3},
  [23] = {.lex_state = 21, .external_lex_state = 2},
  [24] = {.lex_state = 21, .external_lex_state = 2},
  [25] = {.lex_state = 21, .external_lex_state = 3},
  [26] = {.lex_state = 21, .external_lex_state = 3},
  [27] = {.lex_state = 21, .external_lex_state = 2},
  [28] = {.lex_state = 21, .external_lex_state = 3},
  [29] = {.lex_state = 21, .external_lex_state = 2},
  [30] = {.lex_state = 21, .external_lex_state = 2},
  [31] = {.lex_state = 21, .external_lex_state = 2},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 21, .external_lex_state = 3},
  [34] = {.lex_state = 21, .external_lex_state = 2},
  [35] = {.lex_state = 21, .external_lex_state = 2},
  [36] = {.lex_state = 21, .external_lex_state = 2},
  [37] = {.lex_state = 6, .external_lex_state = 4},
  [38] = {.lex_state = 6, .external_lex_state = 4},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 7, .external_lex_state = 4},
  [41] = {.lex_state = 7, .external_lex_state = 4},
  [42] = {.lex_state = 7, .external_lex_state = 4},
  [43] = {.lex_state = 7, .external_lex_state = 4},
  [44] = {.lex_state = 1},
  [45] = {.lex_state = 7, .external_lex_state = 4},
  [46] = {.lex_state = 7},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 5},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 7},
  [51] = {.lex_state = 7},
  [52] = {.lex_state = 5},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 7},
  [56] = {.lex_state = 5},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 5},
  [59] = {.lex_state = 7, .external_lex_state = 4},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 7},
  [62] = {.lex_state = 7, .external_lex_state = 4},
  [63] = {.lex_state = 7, .external_lex_state = 4},
  [64] = {.lex_state = 0, .external_lex_state = 5},
  [65] = {.lex_state = 7},
  [66] = {.lex_state = 0, .external_lex_state = 5},
  [67] = {.lex_state = 7, .external_lex_state = 4},
  [68] = {.lex_state = 0, .external_lex_state = 6},
  [69] = {.lex_state = 0, .external_lex_state = 6},
  [70] = {.lex_state = 0, .external_lex_state = 6},
  [71] = {.lex_state = 0, .external_lex_state = 6},
  [72] = {.lex_state = 0, .external_lex_state = 6},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0, .external_lex_state = 6},
  [75] = {.lex_state = 7},
  [76] = {.lex_state = 0, .external_lex_state = 7},
  [77] = {.lex_state = 7},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0, .external_lex_state = 6},
  [82] = {.lex_state = 0, .external_lex_state = 6},
  [83] = {.lex_state = 0, .external_lex_state = 7},
  [84] = {.lex_state = 7},
  [85] = {.lex_state = 0, .external_lex_state = 8},
  [86] = {.lex_state = 18},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0, .external_lex_state = 9},
  [91] = {.lex_state = 11},
  [92] = {.lex_state = 0, .external_lex_state = 8},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 18},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0, .external_lex_state = 9},
  [99] = {.lex_state = 11},
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
    [sym_attribute_value_fragment] = ACTIONS(1),
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
    [sym_comment] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(97),
    [sym_doctype] = STATE(6),
    [sym__node] = STATE(6),
    [sym_element] = STATE(6),
    [sym_script_element] = STATE(6),
    [sym_style_element] = STATE(6),
    [sym_start_tag] = STATE(4),
    [sym_script_start_tag] = STATE(70),
    [sym_style_start_tag] = STATE(71),
    [sym_self_closing_tag] = STATE(9),
    [sym_erroneous_end_tag] = STATE(6),
    [aux_sym_document_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LT_BANG] = ACTIONS(5),
    [anon_sym_LT] = ACTIONS(7),
    [anon_sym_LT_SLASH] = ACTIONS(9),
    [sym_entity] = ACTIONS(11),
    [sym_text] = ACTIONS(11),
    [sym_comment] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(13), 1,
      anon_sym_LT_BANG,
    ACTIONS(15), 1,
      anon_sym_LT,
    ACTIONS(17), 1,
      anon_sym_LT_SLASH,
    ACTIONS(21), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(14), 1,
      sym_end_tag,
    STATE(28), 1,
      sym_self_closing_tag,
    STATE(68), 1,
      sym_style_start_tag,
    STATE(69), 1,
      sym_script_start_tag,
    ACTIONS(19), 3,
      sym_comment,
      sym_entity,
      sym_text,
    STATE(8), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [42] = 11,
    ACTIONS(13), 1,
      anon_sym_LT_BANG,
    ACTIONS(15), 1,
      anon_sym_LT,
    ACTIONS(17), 1,
      anon_sym_LT_SLASH,
    ACTIONS(25), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(25), 1,
      sym_end_tag,
    STATE(28), 1,
      sym_self_closing_tag,
    STATE(68), 1,
      sym_style_start_tag,
    STATE(69), 1,
      sym_script_start_tag,
    ACTIONS(23), 3,
      sym_comment,
      sym_entity,
      sym_text,
    STATE(2), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [84] = 11,
    ACTIONS(13), 1,
      anon_sym_LT_BANG,
    ACTIONS(15), 1,
      anon_sym_LT,
    ACTIONS(27), 1,
      anon_sym_LT_SLASH,
    ACTIONS(31), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(16), 1,
      sym_end_tag,
    STATE(28), 1,
      sym_self_closing_tag,
    STATE(68), 1,
      sym_style_start_tag,
    STATE(69), 1,
      sym_script_start_tag,
    ACTIONS(29), 3,
      sym_comment,
      sym_entity,
      sym_text,
    STATE(5), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [126] = 11,
    ACTIONS(13), 1,
      anon_sym_LT_BANG,
    ACTIONS(15), 1,
      anon_sym_LT,
    ACTIONS(27), 1,
      anon_sym_LT_SLASH,
    ACTIONS(33), 1,
      sym__implicit_end_tag,
    STATE(3), 1,
      sym_start_tag,
    STATE(28), 1,
      sym_self_closing_tag,
    STATE(36), 1,
      sym_end_tag,
    STATE(68), 1,
      sym_style_start_tag,
    STATE(69), 1,
      sym_script_start_tag,
    ACTIONS(19), 3,
      sym_comment,
      sym_entity,
      sym_text,
    STATE(8), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [168] = 10,
    ACTIONS(5), 1,
      anon_sym_LT_BANG,
    ACTIONS(7), 1,
      anon_sym_LT,
    ACTIONS(9), 1,
      anon_sym_LT_SLASH,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_start_tag,
    STATE(9), 1,
      sym_self_closing_tag,
    STATE(70), 1,
      sym_script_start_tag,
    STATE(71), 1,
      sym_style_start_tag,
    ACTIONS(37), 3,
      sym_comment,
      sym_entity,
      sym_text,
    STATE(7), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [207] = 10,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(41), 1,
      anon_sym_LT_BANG,
    ACTIONS(44), 1,
      anon_sym_LT,
    ACTIONS(47), 1,
      anon_sym_LT_SLASH,
    STATE(4), 1,
      sym_start_tag,
    STATE(9), 1,
      sym_self_closing_tag,
    STATE(70), 1,
      sym_script_start_tag,
    STATE(71), 1,
      sym_style_start_tag,
    ACTIONS(50), 3,
      sym_comment,
      sym_entity,
      sym_text,
    STATE(7), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [246] = 10,
    ACTIONS(39), 1,
      sym__implicit_end_tag,
    ACTIONS(53), 1,
      anon_sym_LT_BANG,
    ACTIONS(56), 1,
      anon_sym_LT,
    ACTIONS(59), 1,
      anon_sym_LT_SLASH,
    STATE(3), 1,
      sym_start_tag,
    STATE(28), 1,
      sym_self_closing_tag,
    STATE(68), 1,
      sym_style_start_tag,
    STATE(69), 1,
      sym_script_start_tag,
    ACTIONS(62), 3,
      sym_comment,
      sym_entity,
      sym_text,
    STATE(8), 7,
      sym_doctype,
      sym__node,
      sym_element,
      sym_script_element,
      sym_style_element,
      sym_erroneous_end_tag,
      aux_sym_document_repeat1,
  [285] = 2,
    ACTIONS(67), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(65), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [297] = 2,
    ACTIONS(69), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(71), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [309] = 2,
    ACTIONS(73), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(75), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [321] = 2,
    ACTIONS(77), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(79), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [333] = 2,
    ACTIONS(81), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(83), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [345] = 2,
    ACTIONS(85), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(87), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [357] = 2,
    ACTIONS(89), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(91), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [369] = 2,
    ACTIONS(95), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(93), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [381] = 2,
    ACTIONS(97), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(99), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [393] = 5,
    ACTIONS(103), 1,
      anon_sym_SQUOTE,
    ACTIONS(105), 1,
      anon_sym_DQUOTE,
    STATE(44), 1,
      aux_sym_attribute_value_repeat1,
    ACTIONS(101), 2,
      sym_attribute_value_fragment,
      sym_entity,
    STATE(84), 2,
      sym_attribute_value,
      sym_quoted_attribute_value,
  [411] = 2,
    ACTIONS(107), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(109), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [423] = 2,
    ACTIONS(111), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(113), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [435] = 2,
    ACTIONS(117), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(115), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [447] = 2,
    ACTIONS(117), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(115), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [459] = 2,
    ACTIONS(111), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(113), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [471] = 2,
    ACTIONS(73), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(75), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [483] = 2,
    ACTIONS(95), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(93), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [495] = 2,
    ACTIONS(119), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(121), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [507] = 2,
    ACTIONS(97), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(99), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [519] = 2,
    ACTIONS(67), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(65), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [531] = 2,
    ACTIONS(77), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(79), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [543] = 2,
    ACTIONS(81), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(83), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [555] = 2,
    ACTIONS(69), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(71), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [567] = 5,
    ACTIONS(125), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      anon_sym_DQUOTE,
    STATE(37), 1,
      aux_sym_attribute_value_repeat1,
    ACTIONS(123), 2,
      sym_attribute_value_fragment,
      sym_entity,
    STATE(63), 2,
      sym_attribute_value,
      sym_quoted_attribute_value,
  [585] = 2,
    ACTIONS(129), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(131), 4,
      sym__implicit_end_tag,
      sym_comment,
      sym_entity,
      sym_text,
  [597] = 2,
    ACTIONS(89), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(91), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [609] = 2,
    ACTIONS(107), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(109), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [621] = 2,
    ACTIONS(85), 3,
      anon_sym_LT_BANG,
      anon_sym_LT,
      anon_sym_LT_SLASH,
    ACTIONS(87), 4,
      sym_comment,
      ts_builtin_sym_end,
      sym_entity,
      sym_text,
  [633] = 5,
    ACTIONS(135), 1,
      sym_attribute_name,
    ACTIONS(137), 1,
      sym_attribute_value_fragment,
    ACTIONS(139), 1,
      sym_entity,
    STATE(38), 1,
      aux_sym_attribute_value_repeat1,
    ACTIONS(133), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [650] = 5,
    ACTIONS(143), 1,
      sym_attribute_name,
    ACTIONS(145), 1,
      sym_attribute_value_fragment,
    ACTIONS(148), 1,
      sym_entity,
    STATE(38), 1,
      aux_sym_attribute_value_repeat1,
    ACTIONS(141), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
  [667] = 4,
    ACTIONS(141), 1,
      anon_sym_GT,
    ACTIONS(143), 1,
      sym_attribute_name,
    STATE(39), 1,
      aux_sym_attribute_value_repeat1,
    ACTIONS(151), 2,
      sym_attribute_value_fragment,
      sym_entity,
  [681] = 4,
    ACTIONS(154), 1,
      anon_sym_GT,
    ACTIONS(156), 1,
      anon_sym_SLASH_GT,
    ACTIONS(158), 1,
      sym_attribute_name,
    STATE(43), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [695] = 4,
    ACTIONS(158), 1,
      sym_attribute_name,
    ACTIONS(160), 1,
      anon_sym_GT,
    ACTIONS(162), 1,
      anon_sym_SLASH_GT,
    STATE(42), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [709] = 4,
    ACTIONS(154), 1,
      anon_sym_GT,
    ACTIONS(158), 1,
      sym_attribute_name,
    ACTIONS(164), 1,
      anon_sym_SLASH_GT,
    STATE(43), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [723] = 3,
    ACTIONS(168), 1,
      sym_attribute_name,
    ACTIONS(166), 2,
      anon_sym_GT,
      anon_sym_SLASH_GT,
    STATE(43), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [735] = 4,
    ACTIONS(133), 1,
      anon_sym_GT,
    ACTIONS(135), 1,
      sym_attribute_name,
    STATE(39), 1,
      aux_sym_attribute_value_repeat1,
    ACTIONS(171), 2,
      sym_attribute_value_fragment,
      sym_entity,
  [749] = 4,
    ACTIONS(158), 1,
      sym_attribute_name,
    ACTIONS(160), 1,
      anon_sym_GT,
    ACTIONS(173), 1,
      anon_sym_SLASH_GT,
    STATE(40), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [763] = 3,
    ACTIONS(175), 1,
      anon_sym_GT,
    ACTIONS(177), 1,
      sym_attribute_name,
    STATE(55), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [774] = 3,
    ACTIONS(181), 1,
      anon_sym_SQUOTE,
    STATE(58), 1,
      aux_sym_quoted_attribute_value_repeat1,
    ACTIONS(179), 2,
      sym_entity,
      sym_unescaped_single_attribute_value_fragment,
  [785] = 3,
    ACTIONS(185), 1,
      anon_sym_SQUOTE,
    STATE(52), 1,
      aux_sym_quoted_attribute_value_repeat1,
    ACTIONS(183), 2,
      sym_entity,
      sym_unescaped_single_attribute_value_fragment,
  [796] = 3,
    ACTIONS(185), 1,
      anon_sym_DQUOTE,
    STATE(53), 1,
      aux_sym_quoted_attribute_value_repeat2,
    ACTIONS(187), 2,
      sym_entity,
      sym_unescaped_double_attribute_value_fragment,
  [807] = 3,
    ACTIONS(177), 1,
      sym_attribute_name,
    ACTIONS(189), 1,
      anon_sym_GT,
    STATE(51), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [818] = 3,
    ACTIONS(177), 1,
      sym_attribute_name,
    ACTIONS(191), 1,
      anon_sym_GT,
    STATE(55), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [829] = 3,
    ACTIONS(195), 1,
      anon_sym_SQUOTE,
    STATE(56), 1,
      aux_sym_quoted_attribute_value_repeat1,
    ACTIONS(193), 2,
      sym_entity,
      sym_unescaped_single_attribute_value_fragment,
  [840] = 3,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    STATE(57), 1,
      aux_sym_quoted_attribute_value_repeat2,
    ACTIONS(197), 2,
      sym_entity,
      sym_unescaped_double_attribute_value_fragment,
  [851] = 3,
    ACTIONS(181), 1,
      anon_sym_DQUOTE,
    STATE(60), 1,
      aux_sym_quoted_attribute_value_repeat2,
    ACTIONS(199), 2,
      sym_entity,
      sym_unescaped_double_attribute_value_fragment,
  [862] = 3,
    ACTIONS(166), 1,
      anon_sym_GT,
    ACTIONS(201), 1,
      sym_attribute_name,
    STATE(55), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [873] = 3,
    ACTIONS(207), 1,
      anon_sym_SQUOTE,
    STATE(56), 1,
      aux_sym_quoted_attribute_value_repeat1,
    ACTIONS(204), 2,
      sym_entity,
      sym_unescaped_single_attribute_value_fragment,
  [884] = 3,
    ACTIONS(212), 1,
      anon_sym_DQUOTE,
    STATE(57), 1,
      aux_sym_quoted_attribute_value_repeat2,
    ACTIONS(209), 2,
      sym_entity,
      sym_unescaped_double_attribute_value_fragment,
  [895] = 3,
    ACTIONS(214), 1,
      anon_sym_SQUOTE,
    STATE(56), 1,
      aux_sym_quoted_attribute_value_repeat1,
    ACTIONS(193), 2,
      sym_entity,
      sym_unescaped_single_attribute_value_fragment,
  [906] = 2,
    ACTIONS(218), 1,
      anon_sym_EQ,
    ACTIONS(216), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [915] = 3,
    ACTIONS(214), 1,
      anon_sym_DQUOTE,
    STATE(57), 1,
      aux_sym_quoted_attribute_value_repeat2,
    ACTIONS(197), 2,
      sym_entity,
      sym_unescaped_double_attribute_value_fragment,
  [926] = 3,
    ACTIONS(177), 1,
      sym_attribute_name,
    ACTIONS(220), 1,
      anon_sym_GT,
    STATE(46), 2,
      sym_attribute,
      aux_sym_start_tag_repeat1,
  [937] = 1,
    ACTIONS(222), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [943] = 1,
    ACTIONS(224), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [949] = 3,
    ACTIONS(226), 1,
      sym__start_tag_name,
    ACTIONS(228), 1,
      sym__script_start_tag_name,
    ACTIONS(230), 1,
      sym__style_start_tag_name,
  [959] = 2,
    ACTIONS(232), 1,
      anon_sym_EQ,
    ACTIONS(216), 2,
      anon_sym_GT,
      sym_attribute_name,
  [967] = 3,
    ACTIONS(228), 1,
      sym__script_start_tag_name,
    ACTIONS(230), 1,
      sym__style_start_tag_name,
    ACTIONS(234), 1,
      sym__start_tag_name,
  [977] = 1,
    ACTIONS(236), 3,
      anon_sym_GT,
      anon_sym_SLASH_GT,
      sym_attribute_name,
  [983] = 3,
    ACTIONS(238), 1,
      anon_sym_LT_SLASH,
    ACTIONS(240), 1,
      sym_raw_text,
    STATE(20), 1,
      sym_end_tag,
  [993] = 3,
    ACTIONS(238), 1,
      anon_sym_LT_SLASH,
    ACTIONS(242), 1,
      sym_raw_text,
    STATE(22), 1,
      sym_end_tag,
  [1003] = 3,
    ACTIONS(244), 1,
      anon_sym_LT_SLASH,
    ACTIONS(246), 1,
      sym_raw_text,
    STATE(21), 1,
      sym_end_tag,
  [1013] = 3,
    ACTIONS(244), 1,
      anon_sym_LT_SLASH,
    ACTIONS(248), 1,
      sym_raw_text,
    STATE(23), 1,
      sym_end_tag,
  [1023] = 1,
    ACTIONS(250), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1028] = 2,
    ACTIONS(238), 1,
      anon_sym_LT_SLASH,
    STATE(13), 1,
      sym_end_tag,
  [1035] = 1,
    ACTIONS(252), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1040] = 1,
    ACTIONS(236), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1045] = 2,
    ACTIONS(254), 1,
      sym__end_tag_name,
    ACTIONS(256), 1,
      sym_erroneous_end_tag_name,
  [1052] = 1,
    ACTIONS(222), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1057] = 2,
    ACTIONS(238), 1,
      anon_sym_LT_SLASH,
    STATE(12), 1,
      sym_end_tag,
  [1064] = 2,
    ACTIONS(244), 1,
      anon_sym_LT_SLASH,
    STATE(29), 1,
      sym_end_tag,
  [1071] = 2,
    ACTIONS(244), 1,
      anon_sym_LT_SLASH,
    STATE(30), 1,
      sym_end_tag,
  [1078] = 1,
    ACTIONS(258), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1083] = 1,
    ACTIONS(260), 2,
      sym_raw_text,
      anon_sym_LT_SLASH,
  [1088] = 2,
    ACTIONS(256), 1,
      sym_erroneous_end_tag_name,
    ACTIONS(262), 1,
      sym__end_tag_name,
  [1095] = 1,
    ACTIONS(224), 2,
      anon_sym_GT,
      sym_attribute_name,
  [1100] = 1,
    ACTIONS(256), 1,
      sym_erroneous_end_tag_name,
  [1104] = 1,
    ACTIONS(264), 1,
      aux_sym_doctype_token1,
  [1108] = 1,
    ACTIONS(266), 1,
      anon_sym_GT,
  [1112] = 1,
    ACTIONS(268), 1,
      anon_sym_GT,
  [1116] = 1,
    ACTIONS(270), 1,
      anon_sym_GT,
  [1120] = 1,
    ACTIONS(262), 1,
      sym__end_tag_name,
  [1124] = 1,
    ACTIONS(272), 1,
      sym__doctype,
  [1128] = 1,
    ACTIONS(274), 1,
      sym_erroneous_end_tag_name,
  [1132] = 1,
    ACTIONS(276), 1,
      anon_sym_GT,
  [1136] = 1,
    ACTIONS(278), 1,
      anon_sym_GT,
  [1140] = 1,
    ACTIONS(280), 1,
      anon_sym_GT,
  [1144] = 1,
    ACTIONS(282), 1,
      aux_sym_doctype_token1,
  [1148] = 1,
    ACTIONS(284), 1,
      ts_builtin_sym_end,
  [1152] = 1,
    ACTIONS(254), 1,
      sym__end_tag_name,
  [1156] = 1,
    ACTIONS(286), 1,
      sym__doctype,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 84,
  [SMALL_STATE(5)] = 126,
  [SMALL_STATE(6)] = 168,
  [SMALL_STATE(7)] = 207,
  [SMALL_STATE(8)] = 246,
  [SMALL_STATE(9)] = 285,
  [SMALL_STATE(10)] = 297,
  [SMALL_STATE(11)] = 309,
  [SMALL_STATE(12)] = 321,
  [SMALL_STATE(13)] = 333,
  [SMALL_STATE(14)] = 345,
  [SMALL_STATE(15)] = 357,
  [SMALL_STATE(16)] = 369,
  [SMALL_STATE(17)] = 381,
  [SMALL_STATE(18)] = 393,
  [SMALL_STATE(19)] = 411,
  [SMALL_STATE(20)] = 423,
  [SMALL_STATE(21)] = 435,
  [SMALL_STATE(22)] = 447,
  [SMALL_STATE(23)] = 459,
  [SMALL_STATE(24)] = 471,
  [SMALL_STATE(25)] = 483,
  [SMALL_STATE(26)] = 495,
  [SMALL_STATE(27)] = 507,
  [SMALL_STATE(28)] = 519,
  [SMALL_STATE(29)] = 531,
  [SMALL_STATE(30)] = 543,
  [SMALL_STATE(31)] = 555,
  [SMALL_STATE(32)] = 567,
  [SMALL_STATE(33)] = 585,
  [SMALL_STATE(34)] = 597,
  [SMALL_STATE(35)] = 609,
  [SMALL_STATE(36)] = 621,
  [SMALL_STATE(37)] = 633,
  [SMALL_STATE(38)] = 650,
  [SMALL_STATE(39)] = 667,
  [SMALL_STATE(40)] = 681,
  [SMALL_STATE(41)] = 695,
  [SMALL_STATE(42)] = 709,
  [SMALL_STATE(43)] = 723,
  [SMALL_STATE(44)] = 735,
  [SMALL_STATE(45)] = 749,
  [SMALL_STATE(46)] = 763,
  [SMALL_STATE(47)] = 774,
  [SMALL_STATE(48)] = 785,
  [SMALL_STATE(49)] = 796,
  [SMALL_STATE(50)] = 807,
  [SMALL_STATE(51)] = 818,
  [SMALL_STATE(52)] = 829,
  [SMALL_STATE(53)] = 840,
  [SMALL_STATE(54)] = 851,
  [SMALL_STATE(55)] = 862,
  [SMALL_STATE(56)] = 873,
  [SMALL_STATE(57)] = 884,
  [SMALL_STATE(58)] = 895,
  [SMALL_STATE(59)] = 906,
  [SMALL_STATE(60)] = 915,
  [SMALL_STATE(61)] = 926,
  [SMALL_STATE(62)] = 937,
  [SMALL_STATE(63)] = 943,
  [SMALL_STATE(64)] = 949,
  [SMALL_STATE(65)] = 959,
  [SMALL_STATE(66)] = 967,
  [SMALL_STATE(67)] = 977,
  [SMALL_STATE(68)] = 983,
  [SMALL_STATE(69)] = 993,
  [SMALL_STATE(70)] = 1003,
  [SMALL_STATE(71)] = 1013,
  [SMALL_STATE(72)] = 1023,
  [SMALL_STATE(73)] = 1028,
  [SMALL_STATE(74)] = 1035,
  [SMALL_STATE(75)] = 1040,
  [SMALL_STATE(76)] = 1045,
  [SMALL_STATE(77)] = 1052,
  [SMALL_STATE(78)] = 1057,
  [SMALL_STATE(79)] = 1064,
  [SMALL_STATE(80)] = 1071,
  [SMALL_STATE(81)] = 1078,
  [SMALL_STATE(82)] = 1083,
  [SMALL_STATE(83)] = 1088,
  [SMALL_STATE(84)] = 1095,
  [SMALL_STATE(85)] = 1100,
  [SMALL_STATE(86)] = 1104,
  [SMALL_STATE(87)] = 1108,
  [SMALL_STATE(88)] = 1112,
  [SMALL_STATE(89)] = 1116,
  [SMALL_STATE(90)] = 1120,
  [SMALL_STATE(91)] = 1124,
  [SMALL_STATE(92)] = 1128,
  [SMALL_STATE(93)] = 1132,
  [SMALL_STATE(94)] = 1136,
  [SMALL_STATE(95)] = 1140,
  [SMALL_STATE(96)] = 1144,
  [SMALL_STATE(97)] = 1148,
  [SMALL_STATE(98)] = 1152,
  [SMALL_STATE(99)] = 1156,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(85),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 1, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 1, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_end_tag, 3, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_end_tag, 3, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_doctype, 4, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doctype, 4, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 3, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 3, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 3, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 3, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_erroneous_end_tag, 3, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_element, 2, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_element, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 3, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_self_closing_tag, 4, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_style_element, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_element, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_element, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_element, 2, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 3, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 3, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_start_tag, 4, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_tag, 4, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_value, 1, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute_value, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_value_repeat1, 2, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_attribute_value_repeat1, 2, 0, 0),
  [145] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_value_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_value_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_value_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0),
  [168] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [201] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_start_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [204] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_attribute_value_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quoted_attribute_value_repeat1, 2, 0, 0),
  [209] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_attribute_value_repeat2, 2, 0, 0), SHIFT_REPEAT(57),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quoted_attribute_value_repeat2, 2, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 4, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 3, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_start_tag, 3, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_style_start_tag, 4, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [284] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
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
  },
  [5] = {
    [ts_external_token__start_tag_name] = true,
    [ts_external_token__script_start_tag_name] = true,
    [ts_external_token__style_start_tag_name] = true,
  },
  [6] = {
    [ts_external_token_raw_text] = true,
  },
  [7] = {
    [ts_external_token__end_tag_name] = true,
    [ts_external_token_erroneous_end_tag_name] = true,
  },
  [8] = {
    [ts_external_token_erroneous_end_tag_name] = true,
  },
  [9] = {
    [ts_external_token__end_tag_name] = true,
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

TS_PUBLIC const TSLanguage *tree_sitter_html(void) {
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
