#include "types.h"
typedef struct { s16 a0; u8 pad0[0x2]; s16 a4; } R;
typedef struct { u8 pad0[0x25E]; s16 a25E; s16 a260; } A;
s32 func_80000968(s32 play, s32 limb, s32 c, s32 d, R *rot, A *thisx) {
    A *this = thisx;
    if (limb == 0xF) {
        rot->a0 += this->a260;
        rot->a4 += this->a25E;
    }
    return 0;
}
