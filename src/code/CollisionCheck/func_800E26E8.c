#include "types.h"

typedef struct {
    u8 pad0[0x138];
    s32 unk138;
} Actor;

typedef struct {
    u8 pad0[2];
    u16 flags2;
    u8 pad4[0x1BC];
    s32 count;
    void *list[1];
} OcCtx;

typedef struct {
    Actor *actor;
    u8 pad4[0x11];
    u8 type;
} Col;

extern s32 func_8016B1A4(void *);
// s32 return type matches register use in the ROM
extern s32 (*D_801BAE90[])(void *, Col *);

s32 CollisionCheck_SetOC(void *play, OcCtx *oc, Col *col) {
    s32 idx;

    if (func_8016B1A4(play)) {
        return -1;
    }
    D_801BAE90[col->type](play, col);
    if (col->actor != 0 && col->actor->unk138 == 0) {
        return -1;
    }
    idx = oc->count;
    if (idx >= 0x32) {
        return -1;
    }
    if (oc->flags2 & 1) {
        return -1;
    }
    oc->list[idx] = col;
    oc->count++;
    return idx;
}
