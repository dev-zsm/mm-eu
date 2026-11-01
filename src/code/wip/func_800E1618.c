#include "types.h"

typedef struct {
    u8 pad0[8];
    u32 count;
    u8 *elems;
} Init;

typedef struct {
    u8 pad0[0x18];
    u32 count;
    u8 *elems;
} Col;

extern void Collider_SetBaseType1();
extern u8 *ZeldaArena_Malloc();
extern void Collider_InitTrisElement();
extern void func_800E13D4();

s32 Collider_SetTrisAllocType1(s32 a0, Col *a1, s32 a2, Init *a3) {
    u8 *s0;
    u8 *s1;
    s32 n;

    Collider_SetBaseType1(a0, a1, a2, a3);
    n = a3->count;
    a1->count = n;
    a1->elems = ZeldaArena_Malloc(n * 0x5C);
    if (a1->elems == NULL) {
        a1->count = 0;
        return 0;
    }
    s0 = a1->elems;
    s1 = a3->elems;
    if (s0 < s0 + a1->count * 0x5C) {
        do {
            Collider_InitTrisElement(a0, s0);
            func_800E13D4(a0, s0, s1);
            s0 += 0x5C;
            s1 += 0x3C;
        } while (s0 < a1->elems + a1->count * 0x5C);
    }
    return 1;
}
