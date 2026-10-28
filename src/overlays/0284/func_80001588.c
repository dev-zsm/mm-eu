// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6020AA4;
extern M2C_UNK D_809B685C;

void func_80001588(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809B685C;
    func_80137934(arg0 + 0x164, &D_6020AA4, 0xC1200000, arg0);
    M2C_FIELD(arg0, s16 *, 0x9E0) = 0;
    M2C_FIELD(arg0, s32 *, 0x9DC) = 0;
    M2C_FIELD(arg0, u8 *, 0x1C1) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C1) + 1);
    M2C_FIELD(arg0, s16 *, 0x1BE) = 0x1E;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1C8) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1C4) = 0.0f;
}
