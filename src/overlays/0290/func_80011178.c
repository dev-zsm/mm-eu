// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 *D_801EB7E0;
extern u8 D_809EA880;
extern f32 D_809ED42C;
extern f32 D_809ED430;

void func_80011178(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 **, 0x144) = &D_809EA880;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x17C) = M2C_FIELD(D_801EB7E0, s16 *, 0xC68) * D_809ED42C + D_809ED430;
    M2C_FIELD(arg0, s16 *, 0x150) = 0xC8;
}
