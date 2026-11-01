#include "types.h"

typedef struct {
    /* 0x00 */ u8 used;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 padC;
    /* 0x10 */ s32 arg;
} CacheEntry; /* size 0x14 */

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ CacheEntry entries[0x80];
} CacheTable;

extern CacheTable D_801FB3C0;
extern s32 D_801FBDD0;
extern s32 AudioHeap_Alloc(CacheTable *t, s32 arg);

CacheEntry *AudioHeap_AllocPersistentSampleCacheEntry(s32 arg) {
    CacheEntry *e;
    s32 ret = AudioHeap_Alloc(&D_801FB3C0, arg);

    if (ret == 0) {
        return 0;
    }
    if (D_801FBDD0 == 0x80) {
        return 0;
    }
    e = &D_801FB3C0.entries[D_801FBDD0];
    e->used = 1;
    e->unk8 = ret;
    e->arg = arg;
    D_801FBDD0++;
    return e;
}
