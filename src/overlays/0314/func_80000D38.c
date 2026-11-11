#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x24]; s32 unk24; f32 unk28; s32 unk2C; u8 pad30[0x1D8]; s16 unk208; s16 unk20A; u8 pad20C[0x6]; s16 unk212; u8 pad214[0xA0]; f32 unk2B4; u8 pad2B8[0xC]; f32 unk2C4; u8 pad2C8[0x8]; s16 unk2D0; s16 unk2D2; } S_arg0;

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800C9F3C(s32, s32, s32, s32, u8 *, M2C_UNK *); /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

void func_80000D38(S_arg0 *arg0, s32 arg1) {
    M2C_UNK sp2C;
    if (arg0->unk208 > 0) {
        arg0->unk208 = (s16) (arg0->unk208 - 2);
    } else {
        arg0->unk208 = 0;
    }
    if (func_800C9F3C(arg1, arg1 + 0x830, arg0->unk24, arg0->unk2C, (u8 *)arg0 + 0x2B4, &sp2C) != 0) {
        if ((arg0->unk2B4 - 100.0f) < arg0->unk28) {
            arg0->unk212 = (s16) (arg0->unk212 + 0xBB8);
            arg0->unk2C4 = (f32) (2.0f * func_800FEB84(arg0->unk212));
        }
        func_800FFBF8((u8 *)arg0 + 0x28, (arg0->unk2B4 - 16.0f) + arg0->unk2C4, 0x3F000000, 0x40000000);
        func_800FFCBC((u8 *)arg0 + 0x34, 0x7700, 0x12C, 0x3E8, 0x3E8);
    }
    if ((arg0->unk20A == 0) && (arg0->unk208 == 0)) {
        arg0->unk2D2 = 1;
    }
    if (arg0->unk2D2 != 0) {
        func_800FFCBC((u8 *)arg0 + 0x2D0, 0, 1, 0xF, 0x32);
        if (arg0->unk2D0 < 2) {
            func_800B6490(arg0);
        }
    }
}
