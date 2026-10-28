// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BE0784(M2C_UNK, u8 *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80BE1580;

void func_8000142C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x424) = 0x64;
    M2C_FIELD(arg0, M2C_UNK **, 0x430) = &D_80BE1580;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_80BE0784(arg1, arg0, 0, arg1);
}
