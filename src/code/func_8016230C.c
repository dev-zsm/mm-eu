#include "types.h"
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; u8 pad0C[4]; u8 unk10[0x2D]; u8 unk3D; u8 pad3E[0x2F]; u8 unk6D; u8 pad6E[0xE]; s32 unk7C; } S;
extern S *D_801EE3E0;
void func_80096A20(u8 *, s32, s32);
s32 func_8016230C(s32 a0, S *a1) {
    a1->unk7C = a0;
    a1->unkA = 0;
    a1->unk8 = a1->unkA;
    a1->unk2 = 0;
    a1->unk0 = -1;
    a1->unk4 = 1;
    a1->unk6 = 0;

    D_801EE3E0 = a1;
    func_80096A20(a1->unk10, 0, 0x30);
    func_80096A20((u8 *)a1 + 0x40, 0, 0x30);
    a1->unk3D = a1->unk6D = 7;
    return 1;
}
