#include "types.h"

typedef struct {
    u8 pad0[8];
    s32 count;
    s32 elem;
} ColSrc;

typedef struct {
    u8 pad0[0x18];
    s32 count;
    u8 *elements;
} ColTris;

extern void Collider_SetBase(s32 a, ColTris *b);
extern void Collider_InitTrisElement(s32 a, u8 *b);
extern void func_800E13D4(s32 a, u8 *b, s32 c);

s32 Collider_SetTris(s32 arg0, ColTris *arg1, s32 arg2, ColSrc *arg3, u8 *arg4) {
    u8 *p;
    u8 *q;

    Collider_SetBase(arg0, arg1);
    p = arg4;
    arg1->count = arg3->count;
    arg1->elements = p;
    q = (u8 *)arg3->elem;
    if (p < (u8 *)((s32)p + arg1->count * 0x5C)) {
        do {
            Collider_InitTrisElement(arg0, p);
            func_800E13D4(arg0, p, (s32)q);
            p += 0x5C;
            q += 0x3C;
        } while (p < (u8 *)((s32)arg1->elements + arg1->count * 0x5C));
    }
    return 1;
}
