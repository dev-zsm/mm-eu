// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_800FFEA4(M2C_UNK);                     /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
s32 func_8016A23C(s32);                             /* extern */
s32 func_80B702CC(s32, u8 *, u8 *, s16, s32, f32, f32); /* extern */
M2C_UNK func_80B70AB0(u8 *);                      /* extern */
extern M2C_UNK D_80B71A5C;

void func_800016E8(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x194);
    if ((func_80B702CC(arg1, arg0, arg0 + 0x3C, M2C_FIELD(arg0, s16 *, 0xBE), 0x4000, 720.0f, M2C_FIELD(arg0, f32 *, 0x2FC)) != 0) && ((M2C_FIELD(arg0, s16 *, 0x1C) & 0x1F) != 0x1F) && (func_8016A23C(arg1) == 0)) {
        func_800B701C(arg1, arg0, 0x1A);
        func_800FFEA4(0x482C);
        func_80151DF4(arg1, 0x1194, arg0);
        M2C_FIELD(arg0, s8 *, 0x300) = 0x32;
        func_80B70AB0(arg0);
    }
    if (M2C_FIELD(arg0, f32 *, 0x9C) < -150.0f) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B71A5C;
}
