// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0106.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800A7C50(s32, s32, M2C_UNK);           /* extern */
extern f32 D_808CB6D0;
extern s32 D_808CB920;

void func_800001B8(Vec3f *arg0, PlayState *play) {
    if ((D_808CB920 == 0) && (func_8008704C() < D_808CB6D0)) {
        if (func_8008704C() < 0.5f) {
            func_800A7C50(play, arg0, 5);
        } else {
            func_800A7C50(play, arg0, 0xE);
        }
        D_808CB920 = 0x320;
    }
}
