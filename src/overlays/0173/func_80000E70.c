#include "types.h"
typedef struct { u8 pad0[0x2]; s16 a2; s16 a4; } R;
typedef struct { u8 pad0[0x270]; s16 a270; s16 a272; } A;
s32 func_80000E70(s32 play, s32 limb, s32 c, s32 d, R *rot, A *thisx) {
    A *this = thisx;
    if (limb == 0xB) {
        rot->a2 -= this->a272;
        rot->a4 += this->a270;
    }
    return 0;
}
