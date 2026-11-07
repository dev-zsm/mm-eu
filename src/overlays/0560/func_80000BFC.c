#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x24C]; s16 f24C; s16 f24E; } T;

s32 func_80000BFC(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0xE) {
        rot->x += this->f24E;
        rot->z += this->f24C;
    }
    return 0;
}
