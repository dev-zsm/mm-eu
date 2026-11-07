#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x258]; s16 f258; s16 f25A; } T;

s32 func_80001404(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x10) {
        rot->x += this->f25A;
        rot->z += this->f258;
    }
    return 0;
}
