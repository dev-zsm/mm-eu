// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[8];
    s32 count;
    u8 *elementsInit;
} JntSphInit;

typedef struct {
    u8 pad0[0x18];
    s32 count;
    u8 *elements;
} JntSph;

extern s32 Collider_SetBase(s32, void *);
extern s32 Collider_InitJntSphElement(s32, u8 *);
extern s32 func_800E0850(s32, u8 *, u8 *);

// NOTE: differs by a2 spill
s32 Collider_SetJntSph(s32 play, JntSph *dst, s32 a2, JntSphInit *src, u8 *elements) {
    u8 *init;
    u8 *elem;

    Collider_SetBase(play, dst);
    dst->elements = elements;
    dst->count = src->count;
    elem = elements;
    init = src->elementsInit;
    while (elem < dst->elements + dst->count * 0x40) {
        Collider_InitJntSphElement(play, elem);
        func_800E0850(play, elem, init);
        elem += 0x40;
        init += 0x24;
    }
    return 1;
}
