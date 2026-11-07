#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x2F6]; s16 f2F6; s16 f2F8; } T;

s32 func_800019F4(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x9) {
        rot->x += this->f2F8;
        rot->y += this->f2F6;
    }
    return 0;
}
