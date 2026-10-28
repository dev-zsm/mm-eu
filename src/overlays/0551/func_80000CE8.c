// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800A8248(s32, M2C_UNK, u8 *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B695C(u8 *);                      /* extern */
M2C_UNK func_80B9D574(u8 *, s32);                 /* extern */
extern f32 D_80B9E574;

void func_80000CE8(u8 *arg0, s32 arg1) {
    func_800B695C(arg0);
    if (M2C_FIELD(arg0, s16 *, 0x204) == 0) {
        func_80B9D574(arg0, arg1);
        func_800B6490(arg0);
        if (func_8008704C() < D_80B9E574) {
            func_800A8248(arg1, 0, arg0 + 0x24, 0x60);
        }
    }
}
