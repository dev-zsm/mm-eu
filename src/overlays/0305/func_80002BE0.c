// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, f32, M2C_UNK);            /* extern */
M2C_UNK func_80A08CC0(u8 *, s32);                 /* extern */
M2C_UNK func_80A09684(u8 *, s32);                 /* extern */
s32 func_80A09F68(u8 *);                          /* extern */
M2C_UNK func_80A0A14C(u8 *, s32);                 /* extern */
extern f32 D_80A0BD9C;

void func_80002BE0(u8 *arg0, s32 arg1) {
    if (func_80A09F68(arg0) != -1) {
        func_80A0A14C(arg0, arg1);
    }
    if (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0x88) - D_80A0BD9C, 0x41600000) != 0) {
        func_80A08CC0(arg0, arg1);
        func_80A09684(arg0, arg1);
    }
}
