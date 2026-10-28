// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6013F70;
extern M2C_UNK D_809B880C;

void func_8000354C(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f6;

    func_80137934(arg0 + 0x164, &D_6013F70, 0xC0A00000, arg0);
    temp_f6 = (f32) func_80134AE8(&D_6013F70);
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809B880C;
    M2C_FIELD(arg0, s32 *, 0x9DC) = 0;
    M2C_FIELD(arg0, f32 *, 0x1A8) = temp_f6;
}
