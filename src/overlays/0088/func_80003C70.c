#include "types.h"
typedef struct { u8 pad0[0x404]; s16 a404; s16 a406; } A;
void func_80181508(s16, s32);
void func_80181D88(s16, s32);
s32 func_80003C70(s32 play, s32 limb, s32 c, s32 d, s32 e, A *thisx) {
    A *this = thisx;
    if (limb == 0xF) {
        func_80181508(this->a406, 1);
        func_80181D88(this->a404, 1);
    }
    return 0;
}
