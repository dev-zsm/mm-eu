// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D1EC(s32, u8 *, M2C_UNK *);      /* extern */
s32 func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DD30;
extern M2C_UNK D_8084B860;

void func_80006010(u8 *arg0, s32 arg1) {
    if (func_80830B44(arg1, arg0, &D_8084B860, 0) != 0) {
        func_8082D1EC(arg1, arg0, &D_400DD30);
        M2C_FIELD(arg0, s16 *, 0xAE8) = 1;
    }
    if (M2C_FIELD(arg0, u8 *, 0xAA5) != 4) {
        M2C_FIELD(arg0, u8 *, 0xAA5) = 0U;
    }
}
