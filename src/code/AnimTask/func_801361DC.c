// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
typedef struct { u8 pad0[0x24]; f32 unk24, unk28, unk2C; u8 pad30[0x58 - 0x30]; f32 unk58, unk5C, unk60; u8 pad64[0xBE - 0x64]; s16 unkBE; } Skel;
typedef struct { Skel *unk0; s32 unk4; f32 unk8; } Task;
extern void SkelAnime_UpdateTranslation(s32, f32 *, s16, void *);
void AnimTask_ActorMovement(s32 arg0, Task *arg1) {
    Skel *sp28;
    Skel *sk;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    sk = arg1->unk0;
    sp28 = sk; // redundant copy, only to match the stack spill
    SkelAnime_UpdateTranslation(arg1->unk4, &sp1C, sk->unkBE, arg1);
    sp28->unk24 = sp28->unk24 + (sp1C * sp28->unk58 * arg1->unk8);
    sp28->unk28 = sp28->unk28 + (sp20 * sp28->unk5C * arg1->unk8);
    sp28->unk2C = sp28->unk2C + (sp24 * sp28->unk60 * arg1->unk8);
}
