// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
extern M2C_UNK D_8090BBE8;
extern s16 D_8090BE70;
extern s16 D_8090BE74;
extern s16 D_8090BE78;
extern s16 D_8090BE7C;
extern f32 D_8090BF14;

void func_80000E8C(u8 *arg0) {
    f32 sp1C;
    f32 temp_f2;

    D_8090BE70 = 0;
    temp_f2 = (func_8008704C() - 0.5f) * 1000.0f;
    sp1C = temp_f2;
    D_8090BE78 = (s16) (s32) temp_f2;
    D_8090BE74 = (s16) (s32) ((func_8008704C() - 2.0f) * D_8090BF14);
    D_8090BE7C = (s16) (s32) (sp1C * 3.0f);
    M2C_FIELD(arg0, s16 *, 0x194) = 0x50;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8090BBE8;
}
