// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_808E62E8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_6001B08;
extern M2C_UNK D_808E6718;

void func_80002020(u8 *arg0, s32 arg1) {
    func_80137828(arg0 + 0x144, &D_6001B08, 0x40A00000);
    func_808E62E8(arg0, 0x395C);
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0;
    func_800B701C(arg1, arg0, 7);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E6718;
}
