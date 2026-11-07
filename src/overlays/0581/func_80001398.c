#include "types.h"
#include "m2c_compat.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 pad0[0x304]; s16 f304; s16 f306; } T;

s32 func_80001398(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, T *thisx) {
    T *this = thisx;

    if (limb == 0x9) {
        rot->x += this->f306;
        rot->z += this->f304;
    }
    return 0;
}
