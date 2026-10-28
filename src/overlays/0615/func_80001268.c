// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80BE5EDC(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80BE6080(u8 *);                      /* extern */
extern M2C_UNK D_80BE6F1C;

void func_80001268(u8 *arg0) {
    s16 temp_v0;

    func_80BE5EDC(arg0, 6, 0x3F800000);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0x2D6) = (s16) (temp_v0 + 0x8000);
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    func_80BE6080(arg0);
    func_800FF30C(arg0 + 0x2A0, arg0 + 0x24);
    M2C_FIELD(arg0, s16 *, 0x2D4) = 0;
    M2C_FIELD(arg0, s16 *, 0x2CA) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE6F1C;
}
