#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x3CC]; s16 f3CC; s16 f3CE; } T;

s32 func_80004990(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x3) {
        rot->x += this->f3CC;
        rot->z += this->f3CE;
    }
    return 0;
}
