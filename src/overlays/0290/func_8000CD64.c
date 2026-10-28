// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801667DC(s16, u8 *);                 /* extern */
extern u8 *D_801EB7E0;
extern M2C_UNK D_809E6480;
extern f32 D_809ED338;

void func_8000CD64(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809E6480;
    M2C_FIELD(arg0, f32 *, 0x24) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x28) = 300.0f;
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) D_809ED338;
    M2C_FIELD(arg0, s16 *, 0x160) = (s16) (M2C_FIELD(D_801EB7E0, s16 *, 0xA6A) + 0x96);
    func_801667DC(M2C_FIELD(arg0, s16 *, 0x160), arg0);
}
