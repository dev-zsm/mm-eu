#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern s32 D_80B35120;
s32 func_800BA9E4(u8 *a, u8 *b, s32 c, f32 d, f32 e, f32 f, s32 g, s32 h, s32 i, s32 j);

void func_80001B0C(u8 *a, u8 *play) {
    D_80B35120 = func_800BA9E4(play + 0x1CA0, play, 0x200, M2C_FIELD(a, f32 *, 0x24), M2C_FIELD(a, f32 *, 0x28), M2C_FIELD(a, f32 *, 0x2C), 0, 0, 0, 0x60);
}
