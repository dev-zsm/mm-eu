#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"
void func_80B12B28(u8 *a, s32 b);
void func_80B12F08(u8 *a);

void func_80001A90(u8 *a, s32 b) {
    M2C_FIELD(a, f32 *, 0xC) += 2.0f;
    func_80B12B28(a, 0x14);
    if (M2C_FIELD(a, u8 *, 0x197) == 0xFF) {
        func_80B12F08(a);
    }
}
