// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SysFlashrom_IsInit();                                /* extern */
s32 func_80187FC4(s32);                             /* extern */

s32 SysFlashrom_EraseSector(s32 arg0) {
    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    return func_80187FC4(arg0);
}
