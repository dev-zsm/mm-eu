#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
s32 func_800B8254(u8 *a, u8 *b);
void func_80B2A33C(u8 *a, u8 *b, s32 c);
void func_80B2FAE8(u8 *a);
void func_800B8398(u8 *a, u8 *b, f32 c);

void func_800073B0(Actor *thisx, u8 *play) {
    if (func_800B8254(thisx, play) != 0) {
        func_80B2A33C(thisx, play, 0x3331);
        func_80B2FAE8(thisx);
    } else {
        func_800B8398(thisx, play, 2000.0f);
    }
}
