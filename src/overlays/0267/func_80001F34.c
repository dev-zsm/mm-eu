#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600EF44;
extern M2C_UNK D_80998E28;

void func_80001F34(u8 *arg0, M2C_UNK arg1, s16 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_80998E28;
    func_80137828(arg0 + 0x194, &D_600EF44, 0xC0000000, arg0);
    if (func_8008704C() < 0.5f) {
        M2C_FIELD(arg0, s16 *, 0x15A) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + arg2);
        M2C_FIELD(arg0, s16 *, 0x186) = 0x3800;
    } else {
        M2C_FIELD(arg0, s16 *, 0x15A) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) - arg2);
        M2C_FIELD(arg0, s16 *, 0x186) = -0x3800;
    }
    if (arg2 == 0x4000) {
        M2C_FIELD(arg0, s16 *, 0x15C) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x15C) = 0x800;
    }
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x14;
}
