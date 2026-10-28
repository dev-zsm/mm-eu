// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FFD8(M2C_UNK);                     /* extern */
s32 func_8082D140(s32);                             /* extern */
M2C_UNK func_8082D1EC(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_8082D63C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808337B4(s32, u8 *);                 /* extern */
extern M2C_UNK D_400DD30;

s32 func_80007998(s32 arg0, u8 *arg1) {
    if ((func_8082D140(arg0) == 0) && (M2C_FIELD(arg1, s32 *, 0xA6C) & 0x80000000)) {
        func_808337B4(arg0, arg1);
        func_8082D1EC(arg0, arg1, &D_400DD30);
        func_8082D63C(arg1, 0x6807);
        func_8019FFD8(0x5803);
        return 1;
    }
    return 0;
}
