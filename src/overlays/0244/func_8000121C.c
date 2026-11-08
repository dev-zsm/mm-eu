#include "types.h"
typedef struct { s16 a0; s16 a2; } R;
typedef struct { u8 pad0[0x268]; s16 a268; s16 a26A; } A;
s32 func_8000121C(s32 play, s32 limb, s32 *dl, s32 d, R *rot, A *thisx) {
    A *this = thisx;
    if (limb == 2) {
        rot->a2 += this->a26A;
        rot->a0 += this->a268;
    }
    if (limb == 5) {
        *dl = 0;
    }
    return 0;
}
