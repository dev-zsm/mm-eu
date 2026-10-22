// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80085468(M2C_UNK *);                   /* extern */
M2C_UNK func_80088070(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80089610(M2C_UNK *);                   /* extern */
s32 SysFlashrom_IsInit();                                /* extern */
extern M2C_UNK D_801F4678;
extern M2C_UNK D_801F4698;
extern s32 D_801F484C;
extern M2C_UNK D_801F485C;

s32 SysFlashrom_AwaitResult(void) {
    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    func_80088070(&D_801F485C, 0, 1);
    func_80089610(&D_801F4698);
    func_80085468(&D_801F4678);
    return D_801F484C;
}
