// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0056.h"

M2C_UNK func_800FFAD8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_80136480(u8 *, s32);                     /* extern */
M2C_UNK func_8082D86C(u8 *);                      /* extern */
M2C_UNK func_8085A24C(u8 *, s32);                 /* extern */
M2C_UNK func_8085AA78(u8 *, u8 *);              /* extern */
extern f32 D_80862238;

void func_800266CC(u8 *arg0, u8 *arg1) {
    s32 pad;
    f32 sp28;
    s32 temp_a1;

    if (D_80862238 < 150.0f) {
        if (func_80136480(arg1, arg0 + 0x240) != 0) {
            if (M2C_FIELD(arg0, s16 *, 0xAE8) == 0) {
                if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
                    M2C_FIELD(arg0, f32 *, 0x250) = (f32) (M2C_FIELD(arg0, f32 *, 0x254) - 1.0f);
                    func_8082D86C(arg0);
                    M2C_FIELD(arg0, s16 *, 0xAE8) = 1;
                }
            } else {
                func_8085AA78(arg0, arg1);
            }
        }
        func_800FFAD8(arg0 + 0x68, 0x40000000, 0x3E99999A, 0x41000000, 0.5f);
    }
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) {
        temp_a1 = M2C_FIELD(arg1, s32 *, 0x1F48);
        if (temp_a1 != 0) {
            sp28 = M2C_FIELD(arg0, f32 *, 0x28);
            func_8085A24C(arg0, temp_a1);
            M2C_FIELD(arg0, f32 *, 0x28) = sp28;
        }
    }
}
