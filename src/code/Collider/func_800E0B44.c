#include "types.h"

typedef struct {
    u8 pad0[0x18];
    s32 count;
    u8 *elements;
} JntSph;
typedef struct {
    u8 pad0[8];
    s32 count;
    u8 *elements;
} JntSphInit;
volatile unsigned long long Collider_SetBaseType1(s32 play, JntSph *dst, s32 a2, JntSphInit *src);
void *ZeldaArena_Malloc(s32 size);
void Collider_InitJntSphElement(s32 play, u8 *el);
void func_800E0850(s32 play, u8 *el, u8 *init);
s32 Collider_SetJntSphAllocType1(s32 play, JntSph *dst, s32 unused, JntSphInit *src) {
    u8 *el;
    u8 *init;
    Collider_SetBaseType1(play, dst, unused, src);
    dst->count = src->count;
    dst->elements = ZeldaArena_Malloc(src->count << 6);
    if (dst->elements == ((void *) 0)) {
        dst->count = 0;
        return 0;
    }
    init = src->elements;
    for (el = dst->elements; el < (dst->elements + (dst->count << 6)); el += 0x40, init += 0x24) {
        Collider_InitJntSphElement(play, el);
        func_800E0850(play, el, init);
    }

    return 1;
}
