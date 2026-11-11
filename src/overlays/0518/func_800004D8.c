#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0518.h"

u8 *func_80100304(s32, u8 *, u8 *, u8);       /* extern */

void func_800004D8(u8 *arg0, u8 *arg1) {
    u32 temp_t0;
    s32 temp_v0;
    u8 temp_a3;
    u8 *temp_a1;
    u8 *temp_v0_2;
    u8 *temp_v1;

    M2C_FIELD(arg0, s32 *, 0x2F4) = 0;
    temp_t0 = (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFC00) >> 0xA;
    if (temp_t0 != 0x3F) {
        temp_v0 = M2C_FIELD(arg1, s32 *, 0x18864);
        temp_a1 = temp_v0 + (temp_t0 * 8);
        temp_a3 = M2C_FIELD(temp_a1, u8 *, 1);
        temp_v1 = (u8 *)((s32)temp_v0 + (temp_a3 * 8));
        M2C_FIELD(arg0, u8 **, 0x2F0) = temp_v1;
        temp_v0_2 = func_80100304(M2C_FIELD(temp_v1, s32 *, 4), temp_a1, arg0, temp_a3);
        M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(temp_v0_2, s16 *, 0);
        M2C_FIELD(arg0, f32 *, 0x2C) = (f32) M2C_FIELD(temp_v0_2, s16 *, 4);
        return;
    }
    M2C_FIELD(arg0, u8 **, 0x2F0) = NULL;
}
