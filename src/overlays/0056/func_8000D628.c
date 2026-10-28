// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013698C(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80830B44(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400D3E8;
extern M2C_UNK D_8084AAAC;

void func_8000D628(s32 arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_8084AAAC, 1);
    func_8013698C(arg1, arg0 + 0x240, &D_400D3E8, 0x40000000);
}
