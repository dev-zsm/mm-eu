#include "types.h"
typedef struct { s16 a0; s16 a2; } R;
typedef struct { u8 pad0[0x1CC]; s16 a1CC; s16 a1CE; } A;
s32 func_80005054(s32 play, s32 limb, s32 c, s32 d, R *rot, A *thisx) {
    A *this = thisx;
    if (limb == 0x20) {
        rot->a0 += this->a1CC;
        rot->a2 += this->a1CE;
    }
    return 0;
}
