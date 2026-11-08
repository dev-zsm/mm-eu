#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0380.h"
extern f32 D_80A8F828;
void func_800FFAD8(u8 *a, f32 b, f32 c, f32 d, f32 e);

void func_80000F14(u8 *a, s32 b) {
    func_800FFAD8(a + 0x348, 0.0f, 0.02f, 0.8f, D_80A8F828);
}
