#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x234]; s16 f234; s16 f236; s16 f238; } T;

s32 func_80000B80(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 2) {
        rot->x += this->f234;
        rot->y += this->f236;
        rot->z += this->f238;
    }
    return 0;
}
