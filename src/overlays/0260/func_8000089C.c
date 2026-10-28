// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
extern M2C_UNK D_809904BC;
extern s16 D_8099093C;
extern s16 D_80990940;
extern s16 D_80990944;
extern s16 D_80990948;

void func_8000089C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x19C) = &D_809904BC;
    D_8099093C = -0xBB8;
    D_80990944 = (s16) (s32) ((func_8008704C() - 0.5f) * 1600.0f);
    D_80990940 = 0;
    D_80990948 = 0;
    M2C_FIELD(arg0, s16 *, 0x19A) = 0x3C;
}
