// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B844C(s32, s32, u8 *);            /* extern */
M2C_UNK func_800FEC70(s32, s16, M2C_UNK);           /* extern */
M2C_UNK func_809B1B10(u8 *, s32);                 /* extern */
extern M2C_UNK D_809B24AC;

void func_8000092C(u8 *arg0, s32 arg1) {
    func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0x444);
    func_809B1B10(arg0, arg1);
    if (M2C_FIELD(arg0, s16 *, 0x92) == M2C_FIELD(arg0, s16 *, 0xBE)) {
        func_800B844C(M2C_FIELD(arg0, s32 *, 0x2B0), arg1, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809B24AC;
    }
}
