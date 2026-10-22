// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8008F3E0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
s32 SysFlashrom_CheckFlashType();                                /* extern */
M2C_UNK func_80187A18();                            /* extern */
extern M2C_UNK D_801F3650;
extern M2C_UNK D_801F3668;
extern s32 D_801F366C;

s32 SysFlashrom_InitFlash(void) {
    func_8008F3E0(&D_801F3650, &D_801F3668, 1);
    func_80187A18();
    D_801F366C = 1;
    if (SysFlashrom_CheckFlashType() != 0) {
        D_801F366C = 0;
        return -1;
    }
    return 0;
}
