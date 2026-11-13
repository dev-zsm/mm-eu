#include "types.h"
#include "m2c_compat.h"

s32 func_801238D0();                                /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
s32 func_80830EC4(u8 *, s32, M2C_UNK);            /* extern */
M2C_UNK func_80838168();                            /* extern */
extern u8 *D_80862264;

s32 func_8000BAB0(u8 *arg0, s32 arg1) {
    u8 *temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0xAA5) != 0) {
        func_80838168(arg0, arg1);
        return 1;
    }
    temp_v0 = M2C_FIELD(arg0, u8 **, 0x730);
    if ((temp_v0 != NULL) && (((M2C_FIELD(temp_v0, s32 *, 4) & 0x40001) == 0x40001) || (M2C_FIELD(temp_v0, u8 *, 0x11F) != 0xFF))) {
        M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x200000);
    } else if ((M2C_FIELD(arg0, s16 *, 0xA84) == 0) && (func_801238D0() == 0) && (~(M2C_FIELD(D_80862264, u16 *, 0xC) | ~8) == 0) && (func_80830EC4(arg0, arg1, 1) == 0)) {
        func_8019FF78(0x4806);
    }
    return 0;
}
