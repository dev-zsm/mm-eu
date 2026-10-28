// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
extern M2C_UNK D_8091A854;
extern s16 D_8091B190;
extern s16 D_8091B194;
extern s16 D_8091B198;
extern s16 D_8091B19C;

void func_80001308(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8091A854;
    D_8091B190 = -0xBB8;
    D_8091B198 = (s16) (s32) ((func_8008704C() - 0.5f) * 1600.0f);
    D_8091B194 = 0;
    D_8091B19C = 0;
    M2C_FIELD(arg0, s8 *, 0x194) = 0;
}
