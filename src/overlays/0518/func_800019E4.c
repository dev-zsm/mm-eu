#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x2E4]; s16 f2E4; s16 f2E6; } T;

s32 func_800019E4(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x3) {
        rot->x += this->f2E6;
        rot->z += this->f2E4;
    }
    return 0;
}
