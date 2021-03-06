/**
 * ------- UTILS CONTENTS --------
 * 67 - 318     -> allocator
 * 320 - 474    -> vc_vector
 * 476 - 527    -> ekstring
 * 529 - 746    -> tags
 * 748 - 1216   -> hashmap
 * -------------------------------
 * */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
// Workaround a bug in the MSVC runtime where it uses __cplusplus when not
// defined.
#pragma warning(push, 0)
#pragma warning(disable : 4668)
#endif

#if (defined(_MSC_VER) && defined(__AVX__)) ||                                 \
    (!defined(_MSC_VER) && defined(__SSE4_2__))
#define HASHMAP_SSE42
#endif

#if defined(HASHMAP_SSE42)
#include <nmmintrin.h>
#endif

#if defined(_MSC_VER)
#pragma warning(pop)
#endif

#if defined(_MSC_VER)
#pragma warning(push)
/* Stop MSVC complaining about unreferenced functions */
#pragma warning(disable : 4505)
/* Stop MSVC complaining about not inlining functions */
#pragma warning(disable : 4710)
/* Stop MSVC complaining about inlining functions! */
#pragma warning(disable : 4711)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

#if defined(_MSC_VER)
#define HASHMAP_USED
#elif defined(__GNUC__)
#define HASHMAP_USED __attribute__((used))
#else
#define HASHMAP_USED
#endif

#if defined(__cplusplus)
#define HASHMAP_CAST(type, x) static_cast<type>(x)
#define HASHMAP_PTR_CAST(type, x) reinterpret_cast<type>(x)
#define HASHMAP_NULL NULL
#else
#define HASHMAP_CAST(type, x) ((type)x)
#define HASHMAP_PTR_CAST(type, x) ((type)x)
#define HASHMAP_NULL 0
#endif

// ------------------- ALLOCATOR ----------------------
// 默认每次内存翻倍
#ifndef za_Delta
#define za_Delta 2
#endif

#ifndef za_INIT_SIZE
#define za_INIT_SIZE (1024 * 128)
#endif

#ifndef za_BIN_LEVEL
#define za_BIN_LEVEL 5
#endif

#ifndef za_BIN_LEVEL_SIZE
#define za_BIN_LEVEL_SIZE 16
#endif

#ifndef za_BIN_MIN_CHUNK
#define za_BIN_MIN_CHUNK 8
#endif

#if defined(__GNUC__) || defined(__clang__)
#define za_LIKELY(x) __builtin_expect(x, 1)
#define za_UNLIKELY(x) __builtin_expect(x, 0)
#else
#define za_LIKELY(x) x
#define za_UNLIKELY(x) x
#endif

// 内存基本单元链表
typedef struct za_binNode {
  void *Ptr;
  struct za_binNode *Next;

} za_binNode;

typedef struct za_bin {
  size_t ChunkSize;
  za_binNode *Head;
  za_binNode *FreeHead;

} za_bin;

// 内存分配器的节点
typedef struct za_allocatorNode {
  void *Data;
  size_t Pos;
  size_t Size;
  struct za_allocatorNode *Next;
} za_allocatorNode;

// 内存分配器
typedef struct za_Allocator {
  za_allocatorNode *Head;
  za_allocatorNode *End;
  za_bin Bins[za_BIN_LEVEL * za_BIN_LEVEL_SIZE];
  size_t LevelMins[za_BIN_LEVEL];
  size_t LevelMaxs[za_BIN_LEVEL];
#ifdef za_ALLOCTOR_DEBUG
  size_t AllocSize;
  size_t FreeSize;
#endif
} za_Allocator;

static inline void *za_innerNew(size_t size);
static inline void za_innerFree(void *pointer);

// 新建一个Allocator
static inline za_Allocator *za_New() {
  // 分配大块内存
  void *ptr = za_innerNew(sizeof(za_Allocator) + sizeof(za_allocatorNode) +
                          za_INIT_SIZE);
  if (za_UNLIKELY(ptr == 0))
    return 0;
  za_Allocator *allocator = (za_Allocator *)ptr;
  allocator->Head = (za_allocatorNode *)((char *)ptr + sizeof(za_Allocator));
  allocator->End = allocator->Head;
#ifdef za_ALLOCTOR_DEBUG
  allocator->AllocSize = 0;
  allocator->FreeSize = 0;
#endif
  memset(allocator->Bins, 0, sizeof(allocator->Bins));
  size_t chunk_size = za_BIN_MIN_CHUNK;
  for (size_t i = 0; i < za_BIN_LEVEL; ++i) {
    allocator->LevelMins[i] = chunk_size;
    for (size_t j = 0; j < za_BIN_LEVEL_SIZE;) {
      za_bin *b = allocator->Bins + i * za_BIN_LEVEL_SIZE + j;
      b->Head = 0;
      b->ChunkSize = chunk_size * (++j);
    }
    allocator->LevelMaxs[i] = chunk_size * za_BIN_LEVEL_SIZE;
    chunk_size = chunk_size * za_BIN_LEVEL_SIZE * 2;
  }

  allocator->Head->Size = za_INIT_SIZE;
  allocator->Head->Data =
      (char *)ptr + sizeof(za_Allocator) + sizeof(za_allocatorNode);
  allocator->Head->Pos = 0;
  allocator->Head->Next = 0;
  return allocator;
}

// 释放一个Allocator
static inline void za_Release(za_Allocator *allocator) {
  // 遍历整个链表，每次释放一块内存
  za_allocatorNode *next = allocator->Head->Next;
  while (za_LIKELY(next != 0)) {
    za_allocatorNode *nn = next->Next;
    za_innerFree((void *)next);
    next = nn;
  }
  // 最后释放第一块内存
  za_innerFree((void *)allocator);
}

static inline za_bin *za_findBin(za_Allocator *allocator, size_t size);
static inline void *za_alloc(za_Allocator *allocator, size_t size);
static inline void za_Free(za_Allocator *allocator, void *ptr);
// 分配内存
static inline void *za_Alloc(za_Allocator *allocator, size_t size) {
  if (za_UNLIKELY(size == 0))
    return 0;
  za_bin *bin = za_findBin(allocator, size);
  size_t *s;
  if (za_UNLIKELY(bin == 0)) {
    s = (size_t *)za_innerNew(sizeof(size_t) + size);
    if (za_UNLIKELY(s == 0))
      return 0;
    *s = size;
#ifdef za_ALLOCTOR_DEBUG
    allocator->AllocSize += size;
#endif
    return (void *)(s + 1);
  }
  if (bin->Head != 0) {
    s = (size_t *)bin->Head->Ptr;
    *s = size;

    za_binNode *bn = bin->Head;
    bin->Head = bin->Head->Next;

    bn->Next = bin->FreeHead;
    bin->FreeHead = bn;
#ifdef za_ALLOCTOR_DEBUG
    allocator->AllocSize += size;
#endif
    return (void *)(s + 1);
  }
  s = (size_t *)za_alloc(allocator, sizeof(size_t) + bin->ChunkSize);
  if (za_UNLIKELY(s == 0))
    return 0;
  *s = size;
#ifdef za_ALLOCTOR_DEBUG
  allocator->AllocSize += size;
#endif
  return (void *)(s + 1);
}
static inline void *za_ReAlloc(za_Allocator *allocator, void *addr,
                               size_t size) {
  void *ret = za_Alloc(allocator, size);
  size_t *addr_size = (size_t *)addr - 1;
  if (za_UNLIKELY(*addr_size > size)) {
    memcpy(ret, addr, size);
  } else {
    memcpy(ret, addr, *addr_size);
  }
  za_Free(allocator, addr);
  return ret;
}

// 释放内存
static inline void za_Free(za_Allocator *allocator, void *ptr) {
  size_t *s = (size_t *)ptr - 1;
  if (za_UNLIKELY(*s == 0))
    return;
#ifdef za_ALLOCTOR_DEBUG
  allocator->FreeSize += *s;
#endif
  za_bin *bin = za_findBin(allocator, *s);
  if (za_UNLIKELY(bin == 0)) {
    za_innerFree(s);
    return;
  }
  *s = 0;
  za_binNode *bn;
  if (bin->FreeHead != 0) {
    bn = bin->FreeHead;
    bin->FreeHead = bin->FreeHead->Next;
  } else {
    bn = (za_binNode *)za_alloc(allocator, sizeof(za_binNode));
    if (za_UNLIKELY(bn == 0)) {
      return;
    }
  }

  bn->Ptr = (void *)s;
  bn->Next = bin->Head;
  bin->Head = bn;
  return;
}
// 找到合适的Bin
static inline za_bin *za_findBin(za_Allocator *allocator, size_t size) {
  for (size_t i = 0; i < za_BIN_LEVEL; ++i) {
    if (za_LIKELY(size <= allocator->LevelMaxs[i])) {
      return allocator->Bins + ((size - 1) / allocator->LevelMins[i]) +
             za_BIN_LEVEL_SIZE * i;
    }
  }
  return 0;
}
// 追加一个Allocator
static inline bool za_appendChild(size_t init_size,
                                  struct za_Allocator *allocator) {
  // 每次分配一大块内存，避免多次分配
  void *ptr = za_innerNew(sizeof(za_allocatorNode) + init_size);
  if (za_UNLIKELY(ptr == 0))
    return false;
  za_allocatorNode *node = (za_allocatorNode *)ptr;
  node->Size = init_size;
  node->Data = (char *)ptr + sizeof(za_allocatorNode);
  node->Pos = 0;
  node->Next = 0;
  // 在ANode组成的链表最后加一个ANode
  allocator->End->Next = node;
  allocator->End = node;
  return true;
}

// 分配大小为size的内存
static inline void *za_alloc(za_Allocator *allocator, size_t size) {
  za_allocatorNode *cur_node = allocator->End;
  size_t s = cur_node->Size;
  if (za_UNLIKELY(cur_node->Pos + size > s)) {
    s *= za_Delta;
    // 通过循环计算最终需要的空间大小
    // 这里应该有更好的方法，就是直接通过计算所得
    while (za_UNLIKELY(size > s))
      s *= za_Delta; // 每次分配内存的大小是上次的za_Delta倍
    if (za_UNLIKELY(za_appendChild(s, allocator) == false))
      return 0;
    cur_node = allocator->End;
  }
  void *ret = (char *)(cur_node->Data) + cur_node->Pos;
  cur_node->Pos += size;
  return ret;
}

static inline void *za_innerNew(size_t size) { return malloc(size); }
static inline void za_innerFree(void *pointer) { free(pointer); }

// ---------------------------------------------------

// ------------------ VECTORS ------------------------
#define GROWTH_FACTOR 1.5
#define DEFAULT_COUNT_OF_ELEMENTS 8
#define MINIMUM_COUNT_OF_ELEMENTS 2

// vc_vector structure
typedef void(vc_vector_deleter)(void *, za_Allocator *);

typedef struct vc_vector {
  size_t count;
  size_t element_size;
  size_t reserved_size;
  char *data;
  vc_vector_deleter *deleter;
  za_Allocator *A;
} vc_vector;
// Constructs an empty vector with an reserver size for count_elements.
vc_vector *vc_vector_create(za_Allocator *A, size_t count_elements,
                            size_t size_of_element,
                            vc_vector_deleter *deleter) {
  vc_vector *v = (vc_vector *)za_Alloc(A, sizeof(vc_vector));

  if (count_elements < MINIMUM_COUNT_OF_ELEMENTS) {
    count_elements = DEFAULT_COUNT_OF_ELEMENTS;
  }

  if (v != NULL) {
    v->data = za_Alloc(A, size_of_element * count_elements);
    v->count = 0;
    v->element_size = size_of_element;
    v->deleter = deleter;
    v->A = A;
    v->reserved_size = count_elements * size_of_element;
  }

  return v;
}

void *vc_vector_at(vc_vector *vector, size_t index) {
  return vector->data + index * vector->element_size;
}

size_t vc_vector_count(const vc_vector *vector) { return vector->count; }

// [first_index, last_index)
void vc_vector_call_deleter(vc_vector *vector, size_t first_index,
                            size_t last_index) {
  for (size_t i = first_index; i < last_index; ++i) {
    vector->deleter(vc_vector_at(vector, i), vector->A);
  }
}

// delete all data
void vc_vector_call_deleter_all(vc_vector *vector) {
  vc_vector_call_deleter(vector, 0, vc_vector_count(vector));
}
// clear all data
void vc_vector_clear(vc_vector *vector) {
  if (vector->deleter != NULL) {
    vc_vector_call_deleter_all(vector);
  }

  vector->count = 0;
}

// Returns the last item in the vector.
void *vc_vector_back(vc_vector *vector) {
  return vector->data + (vector->count - 1) * vector->element_size;
}

bool vc_vector_realloc(vc_vector *vector, size_t new_count) {
  const size_t new_size = new_count * vector->element_size;
  char *new_data = (char *)za_ReAlloc(vector->A, vector->data, new_size);
  if (!new_data) {
    return false;
  }

  vector->reserved_size = new_size;
  vector->data = new_data;
  return true;
}

bool vc_vector_resize(vc_vector *vector, size_t new_count, void *defaultValue) {
  // trim or append elements, provide strong guarantee
  const size_t old_count = vector->count;

  if (new_count == old_count)
    return true;

  if (new_count < old_count) { // trim
    for (int i = new_count; i < old_count; i++)
      vector->deleter(vc_vector_at(vector, i), vector->A);
    return true;
  }

  // new_count > old_count
  const size_t old_capacity = vector->reserved_size;
  if (new_count > old_capacity) { // reallocate
    vc_vector_realloc(vector, new_count);
  }

  for (int i = old_count; i < new_count; i++)
    memcpy(vector->data + i, defaultValue, vector->element_size);

  vector->count = new_count;

  return true;
}

size_t vc_vector_max_count(const vc_vector *vector) {
  return vector->reserved_size / vector->element_size;
}

bool vc_vector_append(vc_vector *vector, const void *values, size_t count) {
  /* #define GROWTH_FACTOR 1.5 */
  const size_t count_new = count + vc_vector_count(vector);

  if (vc_vector_max_count(vector) < count_new) {
    size_t max_count_to_reserved = vc_vector_max_count(vector) * GROWTH_FACTOR;
    while (count_new > max_count_to_reserved) {
      max_count_to_reserved *= GROWTH_FACTOR;
    }

    if (!vc_vector_realloc(vector, max_count_to_reserved)) {
      return false;
    }
  }

  if (memcpy(vector->data + vector->count * vector->element_size, values,
             vector->element_size * count) == NULL) {
    return false;
  }

  vector->count = count_new;
  return true;
}

bool vc_vector_push_back(vc_vector *vector, const void *value) {
  if (!vc_vector_append(vector, value, 1)) {
    return false;
  }
  return true;
}

bool vc_vector_pop_back(vc_vector *vector) {
  if (vector->deleter != NULL) {
    vector->deleter(vc_vector_back(vector), vector->A);
  }

  vector->count--;
  return true;
}
// ----------------------------------------------------------

// ----------------------- String ---------------------------
typedef struct {
  const char *buf;
  size_t length;
  za_Allocator *A;
} ekstring;

#define NaS(x) ((ekstring){NULL, 0, (x)})
const ekstring init_string_str(za_Allocator *A, const char *buf,
                               size_t length) {
  char *s = (char *)za_Alloc(A, sizeof(char) * (length + 1));
  strncpy(s, buf, length);
  s[length] = '\0';
  return (const ekstring){s, length, A};
}
const ekstring init_string_string(const ekstring str) {
  za_Allocator *A = str.A;
  char *s = (char *)za_Alloc(A, (str.length + 1) * sizeof(char));
  strncpy(s, str.buf, str.length + 1);
  return (const ekstring){s, str.length, A};
}
bool compare_string_string(const ekstring s1, const ekstring s2) {
  if (s1.length == s2.length)
    return strncmp(s1.buf, s2.buf, s1.length) == 0;
  return false;
}
const ekstring concat_string_string(const ekstring s1, const ekstring s2) {
  const size_t length = s1.length + s2.length + 1;
  char *s = (char *)za_Alloc(s1.A, length);
  strncpy(s, s1.buf, s1.length);
  strncpy(s + s1.length, s2.buf, s2.length);
  s[length] = '\0';
  return (const ekstring){s, length - 1, s1.A};
}
const ekstring concat_string_char(const ekstring s1, const char c) {
  if (s1.buf == NULL) {
    char *s = (char *)za_Alloc(s1.A, 2);
    s[0] = c;
    s[1] = '\0';
    return (const ekstring){s, 1, s1.A};
  }
  size_t length = s1.length + 2;
  char *s = (char *)za_Alloc(s1.A, length);
  strncpy(s, s1.buf, s1.length);
  s[length - 2] = c;
  s[length - 1] = '\0';
  return (const ekstring){s, length - 1, s1.A};
}
const int parse_int(const ekstring s1) { return atoi(s1.buf); }
const char *get_string_cstring(const ekstring s) { return s.buf; }
void destroy_string(const ekstring s) { za_Free(s.A, (void *)s.buf); }
// -----------------------------------------------------------

// ------------------------ Tag ------------------------------
typedef enum TagType {
  AREA = 1,
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
} TagType;

typedef struct Tag {
  TagType type;
  ekstring custom_tag_name;
} Tag;

static const TagType TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS[] = {
    ADDRESS,  ARTICLE,    ASIDE,  BLOCKQUOTE, DETAILS, DIV, DL,
    FIELDSET, FIGCAPTION, FIGURE, FOOTER,     FORM,    H1,  H2,
    H3,       H4,         H5,     H6,         HEADER,  HR,  MAIN,
    NAV,      OL,         P,      PRE,        SECTION,
};
static const unsigned int TTNAIP_LEN =
    sizeof(TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS) / sizeof(TagType);

Tag *initTag(za_Allocator *A) {
  Tag *t = (Tag *)za_Alloc(A, sizeof(Tag));
  t->type = END_OF_VOID_TAGS;
  t->custom_tag_name = NaS(A);
  return t;
}
Tag *initTagArgs(za_Allocator *A, TagType type, const ekstring name) {
  Tag *t = (Tag *)za_Alloc(A, sizeof(Tag));
  t->type = type;
  t->custom_tag_name = init_string_string(name);
  return t;
}

bool compareTags(const Tag *a, const Tag *b) {
  if (a == NULL || b == NULL) {
    if (a == NULL && b == NULL)
      return true;
    return false;
  }
  if (a->type != b->type)
    return false;
  if (a->type == CUSTOM &&
      !compare_string_string(a->custom_tag_name, b->custom_tag_name))
    return false;
  return true;
}

inline const bool is_void(Tag *tag) { return tag->type < END_OF_VOID_TAGS; }

const bool findTagType(const TagType *tt, TagType toFind) {
  for (int i = 0; i < TTNAIP_LEN; i++)
    if (tt[i] == toFind)
      return true;
  return false;
}

const bool findTag(vc_vector *v, Tag *tag) {
  for (int i = 0; i < v->count; i++)
    if (compareTags(vc_vector_at(v, i), tag))
      return true;
  return false;
}

inline bool can_contain(const Tag *parent, const Tag *tag) {
  TagType child = tag->type;

  switch (parent->type) {
  case LI:
    return child != LI;
  case DT:
  case DD:
    return child != DT && child != DD;
  case P:
    return !findTagType(TAG_TYPES_NOT_ALLOWED_IN_PARAGRAPHS, tag->type);
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

// ------------------------------------------------------------

// ----------------------- Hashmap ---------------------------
/* We need to keep keys and values. */
struct hashmap_element_s {
  const char *key;
  unsigned key_len;
  int in_use;
  TagType data;
};

/* A hashmap has some maximum size and current size, as well as the data to
 * hold. */
struct hashmap_s {
  unsigned table_size;
  unsigned size;
  struct hashmap_element_s *data;
};

#define HASHMAP_MAX_CHAIN_LENGTH (8)

#if defined(__cplusplus)
extern "C" {
#endif

int hashmap_create(za_Allocator *A, const unsigned initial_size,
                   struct hashmap_s *const out_hashmap) {
  out_hashmap->table_size = initial_size;
  out_hashmap->size = 0;

  if (0 == initial_size || 0 != (initial_size & (initial_size - 1))) {
    return 1;
  }

  out_hashmap->data = HASHMAP_CAST(
      struct hashmap_element_s *,
      za_Alloc(A, initial_size * sizeof(struct hashmap_element_s)));
  if (!out_hashmap->data) {
    return 1;
  }

  return 0;
}

unsigned hashmap_crc32_helper(const char *const s, const unsigned len) {
  unsigned i;
  unsigned crc32val = 0;

#if defined(HASHMAP_SSE42)
  for (i = 0; i < len; i++) {
    crc32val = _mm_crc32_u8(crc32val, HASHMAP_CAST(unsigned char, s[i]));
  }

  return crc32val;
#else
  // Using polynomial 0x11EDC6F41 to match SSE 4.2's crc function.
  static const unsigned crc32_tab[] = {
      0x00000000U, 0xF26B8303U, 0xE13B70F7U, 0x1350F3F4U, 0xC79A971FU,
      0x35F1141CU, 0x26A1E7E8U, 0xD4CA64EBU, 0x8AD958CFU, 0x78B2DBCCU,
      0x6BE22838U, 0x9989AB3BU, 0x4D43CFD0U, 0xBF284CD3U, 0xAC78BF27U,
      0x5E133C24U, 0x105EC76FU, 0xE235446CU, 0xF165B798U, 0x030E349BU,
      0xD7C45070U, 0x25AFD373U, 0x36FF2087U, 0xC494A384U, 0x9A879FA0U,
      0x68EC1CA3U, 0x7BBCEF57U, 0x89D76C54U, 0x5D1D08BFU, 0xAF768BBCU,
      0xBC267848U, 0x4E4DFB4BU, 0x20BD8EDEU, 0xD2D60DDDU, 0xC186FE29U,
      0x33ED7D2AU, 0xE72719C1U, 0x154C9AC2U, 0x061C6936U, 0xF477EA35U,
      0xAA64D611U, 0x580F5512U, 0x4B5FA6E6U, 0xB93425E5U, 0x6DFE410EU,
      0x9F95C20DU, 0x8CC531F9U, 0x7EAEB2FAU, 0x30E349B1U, 0xC288CAB2U,
      0xD1D83946U, 0x23B3BA45U, 0xF779DEAEU, 0x05125DADU, 0x1642AE59U,
      0xE4292D5AU, 0xBA3A117EU, 0x4851927DU, 0x5B016189U, 0xA96AE28AU,
      0x7DA08661U, 0x8FCB0562U, 0x9C9BF696U, 0x6EF07595U, 0x417B1DBCU,
      0xB3109EBFU, 0xA0406D4BU, 0x522BEE48U, 0x86E18AA3U, 0x748A09A0U,
      0x67DAFA54U, 0x95B17957U, 0xCBA24573U, 0x39C9C670U, 0x2A993584U,
      0xD8F2B687U, 0x0C38D26CU, 0xFE53516FU, 0xED03A29BU, 0x1F682198U,
      0x5125DAD3U, 0xA34E59D0U, 0xB01EAA24U, 0x42752927U, 0x96BF4DCCU,
      0x64D4CECFU, 0x77843D3BU, 0x85EFBE38U, 0xDBFC821CU, 0x2997011FU,
      0x3AC7F2EBU, 0xC8AC71E8U, 0x1C661503U, 0xEE0D9600U, 0xFD5D65F4U,
      0x0F36E6F7U, 0x61C69362U, 0x93AD1061U, 0x80FDE395U, 0x72966096U,
      0xA65C047DU, 0x5437877EU, 0x4767748AU, 0xB50CF789U, 0xEB1FCBADU,
      0x197448AEU, 0x0A24BB5AU, 0xF84F3859U, 0x2C855CB2U, 0xDEEEDFB1U,
      0xCDBE2C45U, 0x3FD5AF46U, 0x7198540DU, 0x83F3D70EU, 0x90A324FAU,
      0x62C8A7F9U, 0xB602C312U, 0x44694011U, 0x5739B3E5U, 0xA55230E6U,
      0xFB410CC2U, 0x092A8FC1U, 0x1A7A7C35U, 0xE811FF36U, 0x3CDB9BDDU,
      0xCEB018DEU, 0xDDE0EB2AU, 0x2F8B6829U, 0x82F63B78U, 0x709DB87BU,
      0x63CD4B8FU, 0x91A6C88CU, 0x456CAC67U, 0xB7072F64U, 0xA457DC90U,
      0x563C5F93U, 0x082F63B7U, 0xFA44E0B4U, 0xE9141340U, 0x1B7F9043U,
      0xCFB5F4A8U, 0x3DDE77ABU, 0x2E8E845FU, 0xDCE5075CU, 0x92A8FC17U,
      0x60C37F14U, 0x73938CE0U, 0x81F80FE3U, 0x55326B08U, 0xA759E80BU,
      0xB4091BFFU, 0x466298FCU, 0x1871A4D8U, 0xEA1A27DBU, 0xF94AD42FU,
      0x0B21572CU, 0xDFEB33C7U, 0x2D80B0C4U, 0x3ED04330U, 0xCCBBC033U,
      0xA24BB5A6U, 0x502036A5U, 0x4370C551U, 0xB11B4652U, 0x65D122B9U,
      0x97BAA1BAU, 0x84EA524EU, 0x7681D14DU, 0x2892ED69U, 0xDAF96E6AU,
      0xC9A99D9EU, 0x3BC21E9DU, 0xEF087A76U, 0x1D63F975U, 0x0E330A81U,
      0xFC588982U, 0xB21572C9U, 0x407EF1CAU, 0x532E023EU, 0xA145813DU,
      0x758FE5D6U, 0x87E466D5U, 0x94B49521U, 0x66DF1622U, 0x38CC2A06U,
      0xCAA7A905U, 0xD9F75AF1U, 0x2B9CD9F2U, 0xFF56BD19U, 0x0D3D3E1AU,
      0x1E6DCDEEU, 0xEC064EEDU, 0xC38D26C4U, 0x31E6A5C7U, 0x22B65633U,
      0xD0DDD530U, 0x0417B1DBU, 0xF67C32D8U, 0xE52CC12CU, 0x1747422FU,
      0x49547E0BU, 0xBB3FFD08U, 0xA86F0EFCU, 0x5A048DFFU, 0x8ECEE914U,
      0x7CA56A17U, 0x6FF599E3U, 0x9D9E1AE0U, 0xD3D3E1ABU, 0x21B862A8U,
      0x32E8915CU, 0xC083125FU, 0x144976B4U, 0xE622F5B7U, 0xF5720643U,
      0x07198540U, 0x590AB964U, 0xAB613A67U, 0xB831C993U, 0x4A5A4A90U,
      0x9E902E7BU, 0x6CFBAD78U, 0x7FAB5E8CU, 0x8DC0DD8FU, 0xE330A81AU,
      0x115B2B19U, 0x020BD8EDU, 0xF0605BEEU, 0x24AA3F05U, 0xD6C1BC06U,
      0xC5914FF2U, 0x37FACCF1U, 0x69E9F0D5U, 0x9B8273D6U, 0x88D28022U,
      0x7AB90321U, 0xAE7367CAU, 0x5C18E4C9U, 0x4F48173DU, 0xBD23943EU,
      0xF36E6F75U, 0x0105EC76U, 0x12551F82U, 0xE03E9C81U, 0x34F4F86AU,
      0xC69F7B69U, 0xD5CF889DU, 0x27A40B9EU, 0x79B737BAU, 0x8BDCB4B9U,
      0x988C474DU, 0x6AE7C44EU, 0xBE2DA0A5U, 0x4C4623A6U, 0x5F16D052U,
      0xAD7D5351U};

  for (i = 0; i < len; i++) {
    crc32val = crc32_tab[(HASHMAP_CAST(unsigned char, crc32val) ^
                          HASHMAP_CAST(unsigned char, s[i]))] ^
               (crc32val >> 8);
  }
  return crc32val;
#endif
}

unsigned hashmap_hash_helper_int_helper(const struct hashmap_s *const m,
                                        const char *const keystring,
                                        const unsigned len) {
  unsigned key = hashmap_crc32_helper(keystring, len);

  /* Robert Jenkins' 32 bit Mix Function */
  key += (key << 12);
  key ^= (key >> 22);
  key += (key << 4);
  key ^= (key >> 9);
  key += (key << 10);
  key ^= (key >> 2);
  key += (key << 7);
  key ^= (key >> 12);

  /* Knuth's Multiplicative Method */
  key = (key >> 3) * 2654435761;

  return key % m->table_size;
}
int hashmap_match_helper(const struct hashmap_element_s *const element,
                         const char *const key, const unsigned len) {
  return (element->key_len == len) && (0 == memcmp(element->key, key, len));
}

int hashmap_hash_helper(za_Allocator *A, const struct hashmap_s *const m,
                        const char *const key, const unsigned len,
                        unsigned *const out_index) {
  unsigned int start, curr;
  unsigned int i;
  int total_in_use;

  /* If full, return immediately */
  if (m->size >= m->table_size) {
    return 0;
  }

  /* Find the best index */
  curr = start = hashmap_hash_helper_int_helper(m, key, len);

  /* First linear probe to check if we've already insert the element */
  total_in_use = 0;

  for (i = 0; i < HASHMAP_MAX_CHAIN_LENGTH; i++) {
    const int in_use = m->data[curr].in_use;

    total_in_use += in_use;

    if (in_use && hashmap_match_helper(&m->data[curr], key, len)) {
      *out_index = curr;
      return 1;
    }

    curr = (curr + 1) % m->table_size;
  }

  curr = start;

  /* Second linear probe to actually insert our element (only if there was at
   * least one empty entry) */
  if (HASHMAP_MAX_CHAIN_LENGTH > total_in_use) {
    for (i = 0; i < HASHMAP_MAX_CHAIN_LENGTH; i++) {
      if (!m->data[curr].in_use) {
        *out_index = curr;
        return 1;
      }

      curr = (curr + 1) % m->table_size;
    }
  }

  return 0;
}

int hashmap_iterate_pairs(za_Allocator *A, struct hashmap_s *const hashmap,
                          int (*f)(za_Allocator *, void *const,
                                   struct hashmap_element_s *const),
                          void *const context) {
  unsigned int i;
  struct hashmap_element_s *p;
  int r;

  /* Linear probing */
  for (i = 0; i < hashmap->table_size; i++) {
    p = &hashmap->data[i];
    if (p->in_use) {
      r = f(A, context, p);
      switch (r) {
      case -1: /* remove item */
        memset(p, 0, sizeof(struct hashmap_element_s));
        hashmap->size--;
        break;
      case 0: /* continue iterating */
        break;
      default: /* early exit */
        return 1;
      }
    }
  }
  return 0;
}

void hashmap_destroy(za_Allocator *A, struct hashmap_s *const m) {
  /* za_Free(A, m->data); */
  /* memset(m, 0, sizeof(struct hashmap_s)); */
}

int hashmap_put(za_Allocator *A, struct hashmap_s *const m,
                const char *const key, const unsigned len, TagType value);

int hashmap_rehash_iterator(za_Allocator *A, void *const new_hash,
                            struct hashmap_element_s *const e) {
  int temp = hashmap_put(A, HASHMAP_PTR_CAST(struct hashmap_s *, new_hash),
                         e->key, e->key_len, e->data);
  if (0 < temp) {
    return 1;
  }
  /* clear old value to avoid stale pointers */
  return -1;
}

// Doubles the size of the hashmap, and rehashes all the elements
int hashmap_rehash_helper(za_Allocator *A, struct hashmap_s *const m) {
  /* If this multiplication overflows hashmap_create will fail. */
  unsigned new_size = 2 * m->table_size;

  struct hashmap_s new_hash;

  int flag = hashmap_create(A, new_size, &new_hash);

  if (0 != flag) {
    return flag;
  }

  /* copy the old elements to the new table */
  flag = hashmap_iterate_pairs(A, m, hashmap_rehash_iterator,
                               HASHMAP_PTR_CAST(void *, &new_hash));

  if (0 != flag) {
    return flag;
  }

  hashmap_destroy(A, m);
  /* put new hash into old hash structure by copying */
  memcpy(m, &new_hash, sizeof(struct hashmap_s));

  return 0;
}

int hashmap_put(za_Allocator *A, struct hashmap_s *const m,
                const char *const key, const unsigned len, TagType value) {
  unsigned int index;

  /* Find a place to put our value. */
  while (!hashmap_hash_helper(A, m, key, len, &index)) {
    if (hashmap_rehash_helper(A, m)) {
      return 1;
    }
  }

  /* Set the data. */
  m->data[index].data = value;
  m->data[index].key = key;
  m->data[index].key_len = len;

  /* If the hashmap element was not already in use, set that it is being used
   * and bump our size. */
  if (0 == m->data[index].in_use) {
    m->data[index].in_use = 1;
    m->size++;
  }

  return 0;
}

TagType hashmap_get(const struct hashmap_s *const m, const char *const key,
                    const unsigned len) {
  unsigned int curr;
  unsigned int i;

  /* Find data location */
  curr = hashmap_hash_helper_int_helper(m, key, len);

  /* Linear probing, if necessary */
  for (i = 0; i < HASHMAP_MAX_CHAIN_LENGTH; i++) {
    if (m->data[curr].in_use) {
      if (hashmap_match_helper(&m->data[curr], key, len)) {
        return m->data[curr].data;
      }
    }
    curr = (curr + 1) % m->table_size;
  }

  /* Not found */
  return HASHMAP_NULL;
}

// for a name
Tag *for_name(za_Allocator *A, struct hashmap_s *m, const ekstring *name) {
  TagType type = hashmap_get(m, name->buf, name->length);
  if (type != 0) {
    Tag *t = (Tag *)za_Alloc(A, sizeof(Tag));
    t->type = type;
    t->custom_tag_name = (ekstring){NULL, 0, A};
    return t;
  } else {
    return initTagArgs(A, CUSTOM, *name);
  }
}

// init tags-hashmap
static const struct hashmap_s *get_tag_map(za_Allocator *AA) {
  struct hashmap_s *data =
      (struct hashmap_s *)za_Alloc(AA, sizeof(struct hashmap_s));
  int res = hashmap_create(AA, 128, data);
  if (res == 0) {
#define TAG(name) hashmap_put(AA, data, (#name), strlen(#name), name)
    TAG(AREA);
    TAG(BASE);
    TAG(BASEFONT);
    TAG(BGSOUND);
    TAG(BR);
    TAG(COL);
    TAG(COMMAND);
    TAG(EMBED);
    TAG(FRAME);
    TAG(HR);
    TAG(IMAGE);
    TAG(IMG);
    TAG(INPUT);
    TAG(ISINDEX);
    TAG(KEYGEN);
    TAG(LINK);
    TAG(MENUITEM);
    TAG(META);
    TAG(NEXTID);
    TAG(PARAM);
    TAG(SOURCE);
    TAG(TRACK);
    TAG(WBR);
    TAG(A);
    TAG(ABBR);
    TAG(ADDRESS);
    TAG(ARTICLE);
    TAG(ASIDE);
    TAG(AUDIO);
    TAG(B);
    TAG(BDI);
    TAG(BDO);
    TAG(BLOCKQUOTE);
    TAG(BODY);
    TAG(BUTTON);
    TAG(CANVAS);
    TAG(CAPTION);
    TAG(CITE);
    TAG(CODE);
    TAG(COLGROUP);
    TAG(DATA);
    TAG(DATALIST);
    TAG(DD);
    TAG(DEL);
    TAG(DETAILS);
    TAG(DFN);
    TAG(DIALOG);
    TAG(DIV);
    TAG(DL);
    TAG(DT);
    TAG(EM);
    TAG(FIELDSET);
    TAG(FIGCAPTION);
    TAG(FIGURE);
    TAG(FOOTER);
    TAG(FORM);
    TAG(H1);
    TAG(H2);
    TAG(H3);
    TAG(H4);
    TAG(H5);
    TAG(H6);
    TAG(HEAD);
    TAG(HEADER);
    TAG(HGROUP);
    TAG(HTML);
    TAG(I);
    TAG(IFRAME);
    TAG(INS);
    TAG(KBD);
    TAG(LABEL);
    TAG(LEGEND);
    TAG(LI);
    TAG(MAIN);
    TAG(MAP);
    TAG(MARK);
    TAG(MATH);
    TAG(MENU);
    TAG(METER);
    TAG(NAV);
    TAG(NOSCRIPT);
    TAG(OBJECT);
    TAG(OL);
    TAG(OPTGROUP);
    TAG(OPTION);
    TAG(OUTPUT);
    TAG(P);
    TAG(PICTURE);
    TAG(PRE);
    TAG(PROGRESS);
    TAG(Q);
    TAG(RB);
    TAG(RP);
    TAG(RT);
    TAG(RTC);
    TAG(RUBY);
    TAG(S);
    TAG(SAMP);
    TAG(SCRIPT);
    TAG(SECTION);
    TAG(SELECT);
    TAG(SLOT);
    TAG(SMALL);
    TAG(SPAN);
    TAG(STRONG);
    TAG(STYLE);
    TAG(SUB);
    TAG(SUMMARY);
    TAG(SUP);
    TAG(SVG);
    TAG(TABLE);
    TAG(TBODY);
    TAG(TD);
    TAG(TEMPLATE);
    TAG(TEXTAREA);
    TAG(TFOOT);
    TAG(TH);
    TAG(THEAD);
    TAG(TIME);
    TAG(TITLE);
    TAG(TR);
    TAG(U);
    TAG(UL);
    TAG(VAR);
    TAG(VIDEO);
#undef TAG
  }
  return data;
}

#if defined(__cplusplus)
}
#endif

// -------------------------------------------------------

#endif
