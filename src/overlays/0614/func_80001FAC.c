// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BE3234(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80BE33FC(u8 *);                      /* extern */
extern M2C_UNK D_80BE4F08;

void func_80001FAC(u8 *arg0) {
    func_80BE33FC(arg0);
    func_80BE3234(arg0, 0, 0x3F800000);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BE4F08;
}
