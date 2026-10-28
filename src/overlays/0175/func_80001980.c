// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8, u8 *);                  /* extern */
extern M2C_UNK D_80943B94;

void func_80001980(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38), arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80943B94;
}
