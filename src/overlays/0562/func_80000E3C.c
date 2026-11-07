#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x258]; s16 f258; s16 f25A; s16 f25C; } T;

s32 func_80000E3C(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x10) {
        rot->x += this->f25A;
        rot->y += this->f258;
        rot->z += this->f25C;
    }
    return 0;
}
