#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x250]; s16 f250; s16 f252; } T;

s32 func_800011B8(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x3) {
        rot->x += this->f252;
        rot->z += this->f250;
    }
    return 0;
}
