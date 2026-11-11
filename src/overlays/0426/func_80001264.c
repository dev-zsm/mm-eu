#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0x18]; f32 unk28; u8 pad2C[0x3C]; f32 unk68; u8 pad6C[0x26C]; void *unk2D8; u8 pad2DC[0x68]; s16 unk344; u8 pad346[0x6]; s16 unk34C; u8 pad34E[0x12]; f32 unk360; s16 unk364; u8 pad366[0x2]; s16 unk368; } S_arg0;

M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, f32); /* extern */
M2C_UNK func_8013C01C(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_80AC10AC;
extern M2C_UNK D_80AC26C0;
extern f32 D_80AC29B4;

void func_80001264(S_arg0 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    temp_f0 = arg0->unk360;
    arg0->unk344 = (s16) (arg0->unk344 + arg0->unk364);
    if (temp_f0 >= 1.0f) {
        arg0->unk360 = 1.0f;
        arg0->unk68 = 5.0f;
    } else {
        arg0->unk68 = 5.0f;
        arg0->unk360 = (f32) (temp_f0 + D_80AC29B4);
    }
    if ((arg0->unkC + 200.0f) < arg0->unk28) {
        func_800FFBF8((u8 *)arg0 + 0x68, 0.0f, 0x3E4CCCCD, 1.0f);
        arg0->unk34C = 0xA;
        func_8013C01C((u8 *)arg0 + 0x144, &D_80AC26C0, 0xA);
        arg0->unk368 = 0;
        arg0->unk2D8 = &D_80AC10AC;
    }
}
