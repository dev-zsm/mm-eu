#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x31A]; s16 f31A; s16 f31C; } T;

s32 func_800031FC(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x10) {
        rot->z += this->f31A;
        rot->y += this->f31C;
    }
    return 0;
}
