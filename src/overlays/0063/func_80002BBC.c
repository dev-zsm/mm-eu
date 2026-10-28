// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_600F990;
extern M2C_UNK D_8086C0BC;

void func_80002BBC(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_600F990, arg0);
    M2C_FIELD(arg0, s16 *, 0x2B6) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086C0BC;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
