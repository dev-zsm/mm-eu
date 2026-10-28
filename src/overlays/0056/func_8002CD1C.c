// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80837F08(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80858534(s32, u8 *, M2C_UNK *);      /* extern */
extern M2C_UNK D_400DCA8;

void func_8002CD1C(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    func_80837F08(arg1, 0x215);
    func_80858534(arg0, arg1, &D_400DCA8);
    M2C_FIELD(arg1, s32 *, 0xA70) = (s32) (M2C_FIELD(arg1, s32 *, 0xA70) & 0xFEFFFFFF);
}
