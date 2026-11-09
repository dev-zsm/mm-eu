#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0x2A]; s16 unk32; u8 pad34[0x378]; void *unk3AC; s16 unk3B0; s16 unk3B2; u8 pad3B4[0xC]; s16 unk3C0; u8 pad3C2[0x4]; s16 unk3C6; } S_arg0;

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A2A324(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80A2BE38;

void func_80001CA0(S_arg0 *arg0) {
    if (arg0->unk3B0 != 4) {
        arg0->unk3C0 = 0x2710;
        arg0->unk3B2 = 0;
        func_80A2A324(arg0, 0, 0);
        arg0->unk3B0 = 3;
    } else {
        arg0->unk3C0 = 0x2710;
        arg0->unk32 = (s16) (arg0->unk32 + arg0->unk3C0);
    }
    arg0->unk3C6 = 0;
    arg0->unk4 = (s32) (arg0->unk4 | 0x08000000);
    func_800B8C4C(arg0, 0x3877);
    func_800FFCBC((u8 *)arg0 + 0x3C0, 0x1388, 0x64, 0x3E8, 0x3E8);
    arg0->unk32 = (s16) (arg0->unk32 + arg0->unk3C0);
    arg0->unk4 = (s32) (arg0->unk4 & ~1);
    arg0->unk3AC = &D_80A2BE38;
}
