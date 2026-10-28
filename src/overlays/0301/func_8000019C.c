// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E9E74(s32, s32);                    /* extern */
s16 func_8016A64C(s32);                             /* extern */
M2C_UNK func_8016A700(s32, s16, M2C_UNK);           /* extern */
extern M2C_UNK D_80A0436C;

void func_8000019C(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x17C) = (s16) (M2C_FIELD(arg0, s16 *, 0x17C) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x17C) == 0) {
        M2C_FIELD(arg0, s8 *, 0x180) = 1;
        func_800E9E74(arg1, arg1 + 0x1F24);
        M2C_FIELD(arg0, s16 *, 0x17A) = func_8016A64C(arg1);
        func_8016A700(arg1, 0, 1);
        func_8016A700(arg1, M2C_FIELD(arg0, s16 *, 0x17A), 7);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A0436C;
    }
}
