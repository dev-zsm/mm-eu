// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
M2C_UNK func_808CFFA0(u8 *);                      /* extern */
extern M2C_UNK D_6009DB0;
extern M2C_UNK D_808D1E34;

void func_80002080(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6009DB0, arg0);
    M2C_FIELD(arg0, s16 *, 0x18E) = 0;
    M2C_FIELD(arg0, s16 *, 0x194) = 0x5DC;
    M2C_FIELD(arg0, s16 *, 0x1C) = 0x40;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_808CFFA0(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D1E34;
}
