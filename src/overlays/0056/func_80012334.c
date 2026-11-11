#include "types.h"
#include "m2c_compat.h"

s32 func_80123960(u8 *);                          /* extern */
s32 func_80124640(u8 *);                          /* extern */
M2C_UNK func_8082D1C8(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_80832E0C(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_400DBE8;
extern s32 D_80862268;

s32 func_80012334(u8 *arg0, s32 arg1) {
    if ((func_80123960(arg0) == 0) && (func_80124640(arg0) != 0) && (M2C_FIELD(arg0, u8 *, 0x14B) != 2) && (D_80862268 != 0)) {
        func_80832E0C(arg0, 0xC);
        func_8082D1C8(arg1, arg0, &D_400DBE8);
        M2C_FIELD(arg0, s8 *, 0xAE7) = 1;
        M2C_FIELD(arg0, s8 *, 0xADA) = 0xC;
        M2C_FIELD(arg0, s16 *, 0xAD4) = (s16) (M2C_FIELD(arg0, s16 *, 0xAB4) + M2C_FIELD(arg0, s16 *, 0xBE));
        M2C_FIELD(arg0, s8 *, 0xADD) = 0;
        return 1;
    }
    return 0;
}
