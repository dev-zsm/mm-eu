#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x300]; s16 f300; s16 f302; } T;

s32 func_80000A40(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0xB) {
        rot->x += this->f302;
        rot->z += this->f300;
    }
    return 0;
}
