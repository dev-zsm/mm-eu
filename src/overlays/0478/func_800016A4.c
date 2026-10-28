// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
s32 func_800C9F3C(s32, s32, s32, s32, f32 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80B16A94(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80B178E8;

void func_800016A4(u8 *arg0, s32 arg1) {
    M2C_UNK sp34;
    f32 sp30;
    s32 pad;

    func_800B680C(arg0);
    func_800FF30C(arg0 + 0x3C, arg0 + 0x24);
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + 10.0f);
    sp30 = M2C_FIELD(arg0, f32 *, 0x28);
    if (func_800C9F3C(arg1, arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), &sp30, &sp34) != 0) {
        if ((M2C_FIELD(arg0, f32 *, 0x28) + 50.0f) < sp30) {
            M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B178E8;
        }
        func_80B16A94(arg0, arg1, 0, 0xC1A00000);
        func_80B16A94(arg0, arg1, 0, 0xC1A00000);
    }
}
