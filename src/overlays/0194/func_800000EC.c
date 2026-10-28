// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5C88(s32, s8);                         /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
M2C_UNK func_8016B084(s32);                         /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern u8 D_801EACC4;
extern M2C_UNK D_80958B20;

void func_800000EC(u8 *arg0, s32 arg1) {
    if (func_800B5C88(arg1, M2C_FIELD(arg0, s8 *, 3)) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x1C) != 0x1FF) {
            D_801EACC4 = 5;
        }
        func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80958B20;
        return;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x1C) != 0x1FF) && (D_801EACC4 == 0)) {
        func_8019FF78(0x5801);
        func_8016B084(arg1);
        func_800B6490(arg0);
    }
}
