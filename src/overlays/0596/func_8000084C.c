#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x27C]; s16 f27C; s16 f27E; s16 f280; } T;

s32 func_8000084C(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x9) {
        rot->x += this->f27E;
        rot->y += this->f27C;
        rot->z += this->f280;
    }
    return 0;
}
