#include "types.h"
#include "m2c_compat.h"
void func_8018132C(f32 a, f32 b, s32 c, s32 d);

s32 func_800007C8(s32 a, s32 b, s32 c, s32 d, s32 e, u8 *f) {
    func_8018132C(M2C_FIELD(f, f32 *, 0x204), M2C_FIELD(f, f32 *, 0x208), M2C_FIELD(f, s32 *, 0x20C), 1);
    return 0;
}
