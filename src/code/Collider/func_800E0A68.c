// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad[0x40];
} Elem;

typedef struct {
    u8 pad0[0x18];
    s32 count;
    Elem *elements;
} Jnt;

typedef struct {
    u8 pad0[8];
    s32 count;
    u8 *elements;
} Init;

// s32 return type matches register use in the ROM
extern s32 Collider_SetBaseToActor(s32, Jnt *, Init *);
extern void Collider_InitJntSphElement(s32, Elem *);
extern void func_800E0850(s32, Elem *, u8 *);
extern Elem *ZeldaArena_Malloc(s32);

s32 Collider_SetJntSphToActor(s32 a0, Jnt *jnt, Init *init) {
    Elem *e;
    u8 *src;

    Collider_SetBaseToActor(a0, jnt, init);
    jnt->count = init->count;
    jnt->elements = ZeldaArena_Malloc(init->count << 6);
    if (jnt->elements == 0) {
        jnt->count = 0;
        return 0;
    }
    e = jnt->elements;
    src = init->elements;
    for (; e < jnt->elements + jnt->count; e++, src += 0x24) {
        Collider_InitJntSphElement(a0, e);
        func_800E0850(a0, e, src);
    }
    return 1;
}
