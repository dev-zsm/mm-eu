// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
M2C_UNK func_808C4BC0(u8 *);                      /* extern */
extern M2C_UNK D_600B508;
extern M2C_UNK D_808C5FFC;

void func_80001938(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_600B508, 0xC0400000, arg0);
    M2C_FIELD(arg0, s16 *, 0x2EC) = 0x1F;
    M2C_FIELD(arg0, s16 *, 0x2EE) = 0x1E;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_808C4BC0(arg0);
    M2C_FIELD(arg0, s8 *, 0x18C) = 1;
    M2C_FIELD(arg0, s8 *, 0x190) = -3;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808C5FFC;
}
