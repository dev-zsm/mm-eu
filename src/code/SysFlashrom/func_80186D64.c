// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SysFlashrom_IsInit();                                /* extern */
extern s32 D_801F4864;
extern s32 D_801F486C;

s32 SysFlashrom_IsBusy(void) {
    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    return D_801F4864 >= D_801F486C;
}
