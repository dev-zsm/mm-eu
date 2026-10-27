// FLAGS: -O2 -g3 -mips2
#include "types.h"

s16 Actor_WorldYawTowardActor(void *a0, void *a1, s32 a2);

typedef struct {
    u8 pad0[0xBE];
    s16 unkBE;
} Sub;

typedef struct {
    u8 pad0[0x24];
    u32 *unk24;
    u8 pad1[0x40 - 0x28];
} Elem;

typedef struct {
    u8 pad0[0x8];
    Sub *unk8;
    u8 pad1[0x1C - 0x0C];
    Elem *unk1C;
} Obj;

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
} Dst;

void func_800BE350(Dst *arg0, Obj *arg1, s32 arg2) {
    Obj *temp_a3;


    temp_a3 = arg1;

    if (*((Elem *)((u8 *)temp_a3->unk1C + (arg2 << 6)))->unk24 & 0x13820) {
        arg0->unk32 = temp_a3->unk8->unkBE;
        return;
    }
    arg0->unk32 = Actor_WorldYawTowardActor(temp_a3->unk8, arg0, arg2);
}
