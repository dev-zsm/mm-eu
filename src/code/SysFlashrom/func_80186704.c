#include "types.h"

int SysFlashrom_IsInit();
s32 func_80187C00(s32 *, s32 *);
extern s32 D_801F3670;
s32 SysFlashrom_CheckFlashType(void) {
    s32 sp1C;
    s32 sp18;
    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    func_80187C00(&sp1C, &sp18);
    if (0) { }
    D_801F3670 = sp18;
    if (sp1C == 0x11118001) {
        if (((((sp18 == 0xC20000) || (sp18 == 0xC20001)) || (sp18 == 0xC2001E)) || (sp18 == 0x3200F1)) || (sp18 == 0xC2001D)) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}
