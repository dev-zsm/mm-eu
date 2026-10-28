// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809C7490(u8 *, M2C_UNK, u8 *);     /* extern */
extern M2C_UNK D_809C99C0;

void func_800024D4(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_809C99C0;
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 30.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 25.0f;
    func_809C7490(arg0 + 0xEC, 0x3941, arg0);
}
