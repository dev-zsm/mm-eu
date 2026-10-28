// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6001C68;
extern M2C_UNK D_80A0D28C;

void func_80000FC4(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6001C68, 0xC0400000);
    M2C_FIELD(arg0, s16 *, 0x29E) = 0;
    M2C_FIELD(arg0, f32 *, 0x2A8) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x2A4) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B8C4C(arg0, 0x39A2);
    func_800B8C4C(M2C_FIELD(arg0, u8 **, 0x120), 0x399F);
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80A0D28C;
}
