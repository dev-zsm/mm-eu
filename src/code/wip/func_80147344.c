// FLAGS: -O1 -g0 -mips2
// STATUS: automatic draft, 6/12 instructions differ
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_SetFileSelectSettings(s8);                          /* extern */
extern M2C_UNK D_801E6EF0;

void func_80147344(s32 arg0, M2C_UNK arg1) {
    Audio_SetFileSelectSettings(M2C_FIELD(&D_801E6EF0, s8 *, 0x3F43));
}
