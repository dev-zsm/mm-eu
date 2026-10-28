// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800BAE44(s32, u8 *, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s8 func_8012F9A8(s32, M2C_UNK);                     /* extern */
extern M2C_UNK D_80B2CCD8;
extern M2C_UNK D_80B33964;

void func_80002B70(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80B33964);
    M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B2CCD8;
    func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 0x200, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0x30);
    M2C_FIELD(arg0, s8 *, 0x2F4) = func_8012F9A8(arg1 + 0x17D88, 0x146);
    if (M2C_FIELD(arg0, s8 *, 0x2F4) < 0) {
        func_800B6490(arg0);
    }
}
