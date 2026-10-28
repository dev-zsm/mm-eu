// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_600805C;
extern M2C_UNK D_80BEC9E0;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80BEC9E0);
    func_800B6564(arg0, 0x3DCCCCCD);
    func_800CABA0(arg0, 0);
    func_800CABC4(arg1, arg0, &D_600805C);
    if (M2C_FIELD(arg0, s32 *, 0x144) == 0x32) {
        func_800B6490(arg0);
    }
}
