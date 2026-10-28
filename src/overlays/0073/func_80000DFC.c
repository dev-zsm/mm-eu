// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6000A14;
extern M2C_UNK D_80893D58;

void func_80000DFC(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6000A14, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x2B4) = &D_80893D58;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
}
