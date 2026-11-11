#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0x14]; s16 unk1C; u8 pad1E[0x6]; f32 unk24; f32 unk28; f32 unk2C; u8 pad30[0x2]; s16 unk32; u8 pad34[0x83]; s8 unkB7; u8 padB8[0x6]; s16 unkBE; u8 padC0[0x1C9]; s8 unk289; u8 pad28A[0x6]; s16 unk290; u8 pad292[0x2]; f32 unk294; u8 pad298[0xA5]; u8 unk33D; u8 unk33E; } S_arg0;
typedef struct { f32 unk0; f32 unk4; f32 unk8; } S_arg1;

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_80AFC100(u8 *);                      /* extern */

void func_80001F28(S_arg0 *arg0, S_arg1 *arg1, s32 arg2) {

    arg0->unk4 = (s32) (arg0->unk4 | 1);
    func_800B6564(arg0, 0x3C23D70A);
    arg0->unkBE = (s16) arg2;
    arg0->unk289 = 0;
    arg0->unk32 = (s16) arg0->unkBE;
    arg0->unkB7 = 2;
    arg0->unk294 = 1.0f;
    arg0->unk24 = (f32) ((func_800FEB84((s16) arg2) * 40.0f) + arg1->unk0);
    arg0->unk28 = (f32) arg1->unk4;
    arg0->unk2C = (f32) ((func_800FEB44((s16) arg2) * 40.0f) + arg1->unk8);
    arg0->unk290 = 0x258;
    arg0->unk1C = 2;
    arg0->unk4 = (s32) (arg0->unk4 & ~0x400);
    arg0->unk33E = (u8) (arg0->unk33E | 1);
    arg0->unk33D = (u8) (arg0->unk33D & 0xFFFE);
    func_80AFC100(arg0);
}
