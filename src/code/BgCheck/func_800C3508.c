#include "types.h"

typedef struct {
    s16 id;
    s32 value;
} IdValueEntry;
extern IdValueEntry D_801B5204[];
extern IdValueEntry D_801B520C[];
s32 BgCheck_TryGetCustomMemsize(s32 id, s32 *value) {
    // one line: the ROM's scheduling depends on these stores sharing a single source line
    do { IdValueEntry *entry = D_801B5204; while (1) { if (id == entry->id) { *value = entry->value; return 1; } entry++; if (entry == D_801B520C) { break; } } return 0; } while (0);
}
