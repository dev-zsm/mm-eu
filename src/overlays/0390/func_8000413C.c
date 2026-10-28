// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80A9AC9C(u8 *);                      /* extern */
M2C_UNK func_80A9DA2C(u8 *);                      /* extern */
extern u8 D_801E7DF4;

void func_8000413C(u8 *arg0, s32 arg1) {
    func_80A9AC9C(arg0);
    if (func_800B8254(arg0, arg1) != 0) {
        func_80A9DA2C(arg0);
    } else if ((M2C_FIELD(arg0, u8 *, 0x114) != 0) || (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f)) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
    if (D_801E7DF4 & 8) {
        func_800B6490(arg0);
    }
}
