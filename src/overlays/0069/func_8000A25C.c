// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B89FC(M2C_UNK, u8 *);                 /* extern */
M2C_UNK func_800B8A20(M2C_UNK, u8 *, s32);        /* extern */
s32 func_800B8A70(M2C_UNK, u8 *);                 /* extern */
M2C_UNK func_8087CE7C(u8 *, M2C_UNK);             /* extern */
s32 func_80887584(u8 *, M2C_UNK);                 /* extern */

void func_8000A25C(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    temp_v0 = func_80887584(arg0, arg1);
    if ((temp_v0 != 0) && !(M2C_FIELD(arg0, s32 *, 0x1E8) & 0x10000)) {
        func_800B8A20(arg1, arg0, temp_v0);
    }
    if ((M2C_FIELD(arg0, s32 *, 0x208) == 0) && (func_800B89FC(arg1, arg0) == 1)) {
        M2C_FIELD(arg0, s32 *, 0x148) = 0x1A;
        M2C_FIELD(arg0, s32 *, 0x14C) = 0x1A;
        M2C_FIELD(arg0, s32 *, 0x208) = 1;
        func_8087CE7C(arg0, arg1);
        return;
    }
    if ((M2C_FIELD(arg0, s32 *, 0x208) == 1) && (func_800B8A70(arg1, arg0) == 1)) {
        M2C_FIELD(arg0, s32 *, 0x148) = 0x23;
        M2C_FIELD(arg0, s32 *, 0x14C) = 0x23;
        M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E8) & 0xFFFEFFFF);
        M2C_FIELD(arg0, s32 *, 0x208) = 0;
        func_8087CE7C(arg0, arg1);
    }
}
