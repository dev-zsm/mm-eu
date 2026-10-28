// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80A4E83C(u8 *);                      /* extern */
M2C_UNK func_80A4EA40(u8 *);                      /* extern */
extern M2C_UNK D_80A4F320;
extern f32 D_80A507C4;

void func_80001D68(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x36A) >= 0x65) {
        M2C_FIELD(arg0, f32 *, 0x35C) = (f32) (func_8008704C() + 1.0f);
    } else {
        M2C_FIELD(arg0, f32 *, 0x35C) = (f32) ((func_8008704C() * D_80A507C4) + 1.5f);
    }
    M2C_FIELD(arg0, s16 *, 0x368) = func_800FF250(0xA, 0x1E);
    if (M2C_FIELD(arg0, s32 *, 0x34C) == 0) {
        func_80A4EA40(arg0);
    } else {
        func_80A4E83C(arg0);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_80A4F320;
}
