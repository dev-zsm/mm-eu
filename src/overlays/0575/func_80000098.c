// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5C34(s32, s8);                         /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80BBA430(u8 *, s32);                     /* extern */
M2C_UNK func_80BBA5C8(u8 *);                      /* extern */
M2C_UNK func_80BBA73C(u8 *);                      /* extern */
M2C_UNK func_80BBA888(u8 *);                      /* extern */
M2C_UNK func_80BBAA04(u8 *);                      /* extern */
extern M2C_UNK D_6000F28;
extern M2C_UNK D_80BBAAB0;

void func_80000098(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80BBAAB0);
    func_800CABA0(arg0, 0);
    func_800CABC4(arg1, arg0, &D_6000F28);
    if (!(((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 8) & 1)) {
        if (func_80BBA430(arg0, arg1) != 0) {
            func_80BBA73C(arg0);
            return;
        }
        func_80BBA5C8(arg0);
        return;
    }
    if (func_800B5C34(arg1, M2C_FIELD(arg0, s8 *, 3)) != 0) {
        func_80BBAA04(arg0);
        return;
    }
    func_80BBA888(arg0);
}
