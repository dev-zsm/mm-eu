#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x2A8]; s16 f2A8; s16 f2AA; s16 f2AC; } T;

s32 func_80001BAC(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0xF) {
        rot->x += this->f2AC;
        rot->y += this->f2AA;
        rot->z += this->f2A8;
    }
    return 0;
}
