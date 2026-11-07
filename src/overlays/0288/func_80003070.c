#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 a1C; } A;
extern s32 D_809D69F0[];
void func_80182BE0();
void func_80003070(s32 a, s32 limb, s32 c, s32 d, A *this) {
    if (limb != D_809D69F0[this->a1C]) {
        func_80182BE0((u8 *)this + 0x324, limb);
    }
}
