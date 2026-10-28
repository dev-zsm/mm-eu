// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082DCE4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DFD0;
extern M2C_UNK D_80850AE0;

void func_8000DCD4(s32 arg0, u8 *arg1, s16 arg2) {
    func_80830B44(arg0, arg1, &D_80850AE0, 0);
    func_8082DCE4(arg0, arg1, &D_400DFD0);
    M2C_FIELD(arg1, s16 *, 0xBE) = arg2;
    M2C_FIELD(arg1, s16 *, 0xAD4) = arg2;
}
