// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0638.h"

M2C_UNK func_8018125C();                            /* extern */

s32 DemoMoonend_PostLimbDraw(PlayState *play, void *kfSkelAnime, s32 limbIndex, void *dList, u8 *flags, void *thisx, Vec3f *scale, Vec3s *rot, Vec3f *pos) {
    if (limbIndex == 8) {
        func_8018125C();
    }
    return 1;
}
