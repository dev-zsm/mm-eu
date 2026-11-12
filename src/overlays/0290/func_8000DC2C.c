#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0x1C]; f32 unk24; u8 pad28[0x4]; f32 unk2C; u8 pad30[0x2]; s16 unk32; u8 pad34[0x8A]; s16 unkBE; u8 padC0[0x84]; void *unk144; u8 pad148[0x14]; s16 unk15C; u8 pad15E[0xAA6A]; s32 unkABC8; u8 padABCC[0x4]; s16 unkABD0; } S_arg0;

M2C_UNK func_80137934(); /* extern */
f32 func_801811BC(f32, f32);                        /* extern */
extern M2C_UNK D_600AE40;
extern M2C_UNK D_809E737C;
extern f32 D_809ED35C;

void func_8000DC2C(S_arg0 *arg0, M2C_UNK arg1) {
    s32 temp_f8;

    arg0->unk144 = &D_809E737C;
    func_80137934((u8 *)arg0 + 0x190, &D_600AE40, 0xC1200000, arg0);
    temp_f8 = (s32) (func_801811BC(-arg0->unk2C, -arg0->unk24) * D_809ED35C);
    arg0->unkBE = (s16) temp_f8;
    arg0->unk32 = (s16) temp_f8;
    arg0->unkABD0 = 0;
    arg0->unkABC8 = 0;
    arg0->unk4 = (s32) (arg0->unk4 & ~1);
    arg0->unk15C = 0x14;
}
