// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A46778();                            /* extern */
extern M2C_UNK D_80A47000;

void func_80000A50(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3A4) = 5;
    func_80A46778();
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80A47000;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
}
