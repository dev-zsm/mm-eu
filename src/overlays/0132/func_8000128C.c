// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808FC5DC();                            /* extern */
extern M2C_UNK D_808FD064;

void func_8000128C(u8 *arg0) {
    M2C_FIELD(arg0, u16 *, 0x160) = (u16) (M2C_FIELD(arg0, u16 *, 0x160) | 0x80);
    M2C_FIELD(arg0, f32 *, 0x6C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x64) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    func_808FC5DC();
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_808FD064;
}
