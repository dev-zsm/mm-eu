#include "types.h"
typedef struct { u8 pad0[0x2]; s16 a2; s16 a4; } R;
typedef struct { u8 pad0[0x29C]; s16 a29C; u8 pad1[0x2]; s16 a2A0; } A;
s32 func_80000388(s32 play, s32 limb, s32 c, s32 d, R *rot, A *thisx) {
    A *this = thisx;
    if (limb == 4 || limb == 0xD) {
        rot->a2 += this->a29C;
        rot->a4 += this->a2A0;
    }
    return 0;
}
