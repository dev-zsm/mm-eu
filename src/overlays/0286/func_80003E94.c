// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600B014;
extern M2C_UNK D_809CB370;

void func_80003E94(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_809CB370;
    func_80137934(arg0 + 0x148, &D_600B014, 0xC1700000, arg0);
    M2C_FIELD(arg0, s16 *, 0x534) = 0;
    M2C_FIELD(arg0, s32 *, 0x530) = 0;
}
