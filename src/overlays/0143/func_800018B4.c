#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0143.h"

f32 func_8008704C();                                /* extern */
extern M2C_UNK D_8090DA08;
extern s16 D_8090DFF0;
extern s16 D_8090DFF4;
extern s16 D_8090DFF8;
extern s16 D_8090DFFC;
extern f32 D_8090E130;
extern f32 D_8090E134;

void func_800018B4(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x194) = 0x50;
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xB4;
    D_8090DFF0 = (s16) (s32) ((func_8008704C() - D_8090E130) * D_8090E134);
    D_8090DFF8 = (s16) (s32) ((func_8008704C() - 0.5f) * 2000.0f);
    D_8090DFF4 = 0;
    D_8090DFFC = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8090DA08;
}
