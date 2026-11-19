#include "tree_sitter/array.h"

#include <string.h>

typedef enum {
    AREA,
    BASE,
    BASEFONT,
    BGSOUND,
    BR,
    COL,
    COMMAND,
    EMBED,
    FRAME,
    HR,
    IMAGE,
    IMG,
    INPUT,
    ISINDEX,
    KEYGEN,
    LINK,
    MENUITEM,
    META,
    NEXTID,
    PARAM,
    SOURCE,
    TRACK,
    WBR,
    END_OF_VOID_TAGS,

    A,
    ABBR,
    ADDRESS,
    ARTICLE,
    ASIDE,
    AUDIO,
    B,
    BDI,
    BDO,
    BLOCKQUOTE,
    BODY,
    BUTTON,
    CANVAS,
    CAPTION,
    CITE,
    CODE,
    COLGROUP,
    DATA,
    DATALIST,
    DD,
    DEL,
    DETAILS,
    DFN,
    DIALOG,
    DIV,
    DL,
    DT,
    EM,
    FIELDSET,
    FIGCAPTION,
    FIGURE,
    FOOTER,
    FORM,
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    HEAD,
    HEADER,
    HGROUP,
    HTML,
    I,
    IFRAME,
    INS,
    KBD,
    LABEL,
    LEGEND,
    LI,
    MAIN,
    MAP,
    MARK,
    MATH,
    MENU,
    METER,
    NAV,
    NOSCRIPT,
    OBJECT,
    OL,
    OPTGROUP,
    OPTION,
    OUTPUT,
    P,
    PICTURE,
    PRE,
    PROGRESS,
    Q,
    RB,
    RP,
    RT,
    RTC,
    RUBY,
    S,
    SAMP,
    SCRIPT,
    SECTION,
    SELECT,
    SLOT,
    SMALL,
    SPAN,
    STRONG,
    STYLE,
    SUB,
    SUMMARY,
    SUP,
    SVG,
    TABLE,
    TBODY,
    TD,
    TEMPLATE,
    TEXTAREA,
    TFOOT,
    TH,
    THEAD,
    TIME,
    TITLE,
    TR,
    U,
    UL,
    VAR,
    VIDEO,

    CUSTOM,

    END_,
} TagType;

typedef Array(char) String;

typedef struct {
    char tag_name[15];
    uint8_t tag_name_length;
    TagType tag_type;
} TagMapEntry;

#define TAG_MAP_ENTRY(name, type) { name, sizeof(name) - 1, type }

typedef struct {
    TagType type;
    String custom_tag_name;
} Tag;

static const TagMapEntry TAG_TYPES_BY_TAG_NAME[126] = {
    TAG_MAP_ENTRY("AREA",       AREA      ),
    TAG_MAP_ENTRY("BASE",       BASE      ),
    TAG_MAP_ENTRY("BASEFONT",   BASEFONT  ),
    TAG_MAP_ENTRY("BGSOUND",    BGSOUND   ),
    TAG_MAP_ENTRY("BR",         BR        ),
    TAG_MAP_ENTRY("COL",        COL       ),
    TAG_MAP_ENTRY("COMMAND",    COMMAND   ),
    TAG_MAP_ENTRY("EMBED",      EMBED     ),
    TAG_MAP_ENTRY("FRAME",      FRAME     ),
    TAG_MAP_ENTRY("HR",         HR        ),
    TAG_MAP_ENTRY("IMAGE",      IMAGE     ),
    TAG_MAP_ENTRY("IMG",        IMG       ),
    TAG_MAP_ENTRY("INPUT",      INPUT     ),
    TAG_MAP_ENTRY("ISINDEX",    ISINDEX   ),
    TAG_MAP_ENTRY("KEYGEN",     KEYGEN    ),
    TAG_MAP_ENTRY("LINK",       LINK      ),
    TAG_MAP_ENTRY("MENUITEM",   MENUITEM  ),
    TAG_MAP_ENTRY("META",       META      ),
    TAG_MAP_ENTRY("NEXTID",     NEXTID    ),
    TAG_MAP_ENTRY("PARAM",      PARAM     ),
    TAG_MAP_ENTRY("SOURCE",     SOURCE    ),
    TAG_MAP_ENTRY("TRACK",      TRACK     ),
    TAG_MAP_ENTRY("WBR",        WBR       ),
    TAG_MAP_ENTRY("A",          A         ),
    TAG_MAP_ENTRY("ABBR",       ABBR      ),
    TAG_MAP_ENTRY("ADDRESS",    ADDRESS   ),
    TAG_MAP_ENTRY("ARTICLE",    ARTICLE   ),
    TAG_MAP_ENTRY("ASIDE",      ASIDE     ),
    TAG_MAP_ENTRY("AUDIO",      AUDIO     ),
    TAG_MAP_ENTRY("B",          B         ),
    TAG_MAP_ENTRY("BDI",        BDI       ),
    TAG_MAP_ENTRY("BDO",        BDO       ),
    TAG_MAP_ENTRY("BLOCKQUOTE", BLOCKQUOTE),
    TAG_MAP_ENTRY("BODY",       BODY      ),
    TAG_MAP_ENTRY("BUTTON",     BUTTON    ),
    TAG_MAP_ENTRY("CANVAS",     CANVAS    ),
    TAG_MAP_ENTRY("CAPTION",    CAPTION   ),
    TAG_MAP_ENTRY("CITE",       CITE      ),
    TAG_MAP_ENTRY("CODE",       CODE      ),
    TAG_MAP_ENTRY("COLGROUP",   COLGROUP  ),
    TAG_MAP_ENTRY("DATA",       DATA      ),
    TAG_MAP_ENTRY("DATALIST",   DATALIST  ),
    TAG_MAP_ENTRY("DD",         DD        ),
    TAG_MAP_ENTRY("DEL",        DEL       ),
    TAG_MAP_ENTRY("DETAILS",    DETAILS   ),
    TAG_MAP_ENTRY("DFN",        DFN       ),
    TAG_MAP_ENTRY("DIALOG",     DIALOG    ),
    TAG_MAP_ENTRY("DIV",        DIV       ),
    TAG_MAP_ENTRY("DL",         DL        ),
    TAG_MAP_ENTRY("DT",         DT        ),
    TAG_MAP_ENTRY("EM",         EM        ),
    TAG_MAP_ENTRY("FIELDSET",   FIELDSET  ),
    TAG_MAP_ENTRY("FIGCAPTION", FIGCAPTION),
    TAG_MAP_ENTRY("FIGURE",     FIGURE    ),
    TAG_MAP_ENTRY("FOOTER",     FOOTER    ),
    TAG_MAP_ENTRY("FORM",       FORM      ),
    TAG_MAP_ENTRY("H1",         H1        ),
    TAG_MAP_ENTRY("H2",         H2        ),
    TAG_MAP_ENTRY("H3",         H3        ),
    TAG_MAP_ENTRY("H4",         H4        ),
    TAG_MAP_ENTRY("H5",         H5        ),
    TAG_MAP_ENTRY("H6",         H6        ),
    TAG_MAP_ENTRY("HEAD",       HEAD      ),
    TAG_MAP_ENTRY("HEADER",     HEADER    ),
    TAG_MAP_ENTRY("HGROUP",     HGROUP    ),
    TAG_MAP_ENTRY("HTML",       HTML      ),
    TAG_MAP_ENTRY("I",          I         ),
    TAG_MAP_ENTRY("IFRAME",     IFRAME    ),
    TAG_MAP_ENTRY("INS",        INS       ),
    TAG_MAP_ENTRY("KBD",        KBD       ),
    TAG_MAP_ENTRY("LABEL",      LABEL     ),
    TAG_MAP_ENTRY("LEGEND",     LEGEND    ),
    TAG_MAP_ENTRY("LI",         LI        ),
    TAG_MAP_ENTRY("MAIN",       MAIN      ),
    TAG_MAP_ENTRY("MAP",        MAP       ),
    TAG_MAP_ENTRY("MARK",       MARK      ),
    TAG_MAP_ENTRY("MATH",       MATH      ),
    TAG_MAP_ENTRY("MENU",       MENU      ),
    TAG_MAP_ENTRY("METER",      METER     ),
    TAG_MAP_ENTRY("NAV",        NAV       ),
    TAG_MAP_ENTRY("NOSCRIPT",   NOSCRIPT  ),
    TAG_MAP_ENTRY("OBJECT",     OBJECT    ),
    TAG_MAP_ENTRY("OL",         OL        ),
    TAG_MAP_ENTRY("OPTGROUP",   OPTGROUP  ),
    TAG_MAP_ENTRY("OPTION",     OPTION    ),
    TAG_MAP_ENTRY("OUTPUT",     OUTPUT    ),
    TAG_MAP_ENTRY("P",          P         ),
    TAG_MAP_ENTRY("PICTURE",    PICTURE   ),
    TAG_MAP_ENTRY("PRE",        PRE       ),
    TAG_MAP_ENTRY("PROGRESS",   PROGRESS  ),
    TAG_MAP_ENTRY("Q",          Q         ),
    TAG_MAP_ENTRY("RB",         RB        ),
    TAG_MAP_ENTRY("RP",         RP        ),
    TAG_MAP_ENTRY("RT",         RT        ),
    TAG_MAP_ENTRY("RTC",        RTC       ),
    TAG_MAP_ENTRY("RUBY",       RUBY      ),
    TAG_MAP_ENTRY("S",          S         ),
    TAG_MAP_ENTRY("SAMP",       SAMP      ),
    TAG_MAP_ENTRY("SCRIPT",     SCRIPT    ),
    TAG_MAP_ENTRY("SECTION",    SECTION   ),
    TAG_MAP_ENTRY("SELECT",     SELECT    ),
    TAG_MAP_ENTRY("SLOT",       SLOT      ),
    TAG_MAP_ENTRY("SMALL",      SMALL     ),
    TAG_MAP_ENTRY("SPAN",       SPAN      ),
    TAG_MAP_ENTRY("STRONG",     STRONG    ),
    TAG_MAP_ENTRY("STYLE",      STYLE     ),
    TAG_MAP_ENTRY("SUB",        SUB       ),
    TAG_MAP_ENTRY("SUMMARY",    SUMMARY   ),
    TAG_MAP_ENTRY("SUP",        SUP       ),
    TAG_MAP_ENTRY("SVG",        SVG       ),
    TAG_MAP_ENTRY("TABLE",      TABLE     ),
    TAG_MAP_ENTRY("TBODY",      TBODY     ),
    TAG_MAP_ENTRY("TD",         TD        ),
    TAG_MAP_ENTRY("TEMPLATE",   TEMPLATE  ),
    TAG_MAP_ENTRY("TEXTAREA",   TEXTAREA  ),
    TAG_MAP_ENTRY("TFOOT",      TFOOT     ),
    TAG_MAP_ENTRY("TH",         TH        ),
    TAG_MAP_ENTRY("THEAD",      THEAD     ),
    TAG_MAP_ENTRY("TIME",       TIME      ),
    TAG_MAP_ENTRY("TITLE",      TITLE     ),
    TAG_MAP_ENTRY("TR",         TR        ),
    TAG_MAP_ENTRY("U",          U         ),
    TAG_MAP_ENTRY("UL",         UL        ),
    TAG_MAP_ENTRY("VAR",        VAR       ),
    TAG_MAP_ENTRY("VIDEO",      VIDEO     ),
    TAG_MAP_ENTRY("CUSTOM",     CUSTOM    ),
};

static const TagType TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS[] = {
    ADDRESS,  ARTICLE,    ASIDE,  BLOCKQUOTE, DETAILS, DIV, DL,
    FIELDSET, FIGCAPTION, FIGURE, FOOTER,     FORM,    H1,  H2,
    H3,       H4,         H5,     H6,         HEADER,  HR,  MAIN,
    NAV,      OL,         P,      PRE,        SECTION,
};

static TagType tag_type_for_name(const String *tag_name) {
    for (int i = 0; i < 126; i++) {
        const TagMapEntry *entry = &TAG_TYPES_BY_TAG_NAME[i];
        if (
            entry->tag_name_length == tag_name->size &&
            memcmp(tag_name->contents, entry->tag_name, tag_name->size) == 0
        ) {
            return entry->tag_type;
        }
    }
    return CUSTOM;
}

static inline Tag tag_new() {
    Tag tag;
    tag.type = END_;
    tag.custom_tag_name = (String) array_new();
    return tag;
}

static inline Tag tag_for_name(String name) {
    Tag tag = tag_new();
    tag.type = tag_type_for_name(&name);
    if (tag.type == CUSTOM) {
        tag.custom_tag_name = name;
    } else {
        array_delete(&name);
    }
    return tag;
}

static inline void tag_free(Tag *tag) {
    if (tag->type == CUSTOM) {
        array_delete(&tag->custom_tag_name);
    }
}

static inline bool tag_is_void(const Tag *self) {
    return self->type < END_OF_VOID_TAGS;
}

static inline bool tag_eq(const Tag *self, const Tag *other) {
    if (self->type != other->type) return false;
    if (self->type == CUSTOM) {
        if (self->custom_tag_name.size != other->custom_tag_name.size) {
            return false;
        }
        if (memcmp(
            self->custom_tag_name.contents,
            other->custom_tag_name.contents,
            self->custom_tag_name.size
        ) != 0) {
            return false;
        }
    }
    return true;
}

static bool tag_can_contain(Tag *self, const Tag *other) {
    TagType child = other->type;

    switch (self->type) {
        case LI:
            return child != LI;

        case DT:
        case DD:
            return child != DT && child != DD;

        case P:
            for (int i = 0; i < 26; i++) {
                if (child == TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS[i]) {
                    return false;
                }
            }
            return true;

        case COLGROUP:
            return child == COL;

        case RB:
        case RT:
        case RP:
            return child != RB && child != RT && child != RP;

        case OPTGROUP:
            return child != OPTGROUP;

        case TR:
            return child != TR;

        case TD:
        case TH:
            return child != TD && child != TH && child != TR;

        default:
            return true;
    }
}
