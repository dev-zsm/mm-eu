// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 func_800897D0(s32, s32);
s32 func_800FEA90(s16 *, s32, s32);
s32 SysFlashrom_Read(s32, s32, s32);
extern s32 D_801C7CA8;
extern s32 D_801C7CAC;
extern s32 D_801C7CD0;
extern s32 D_801C7CD4;
extern s16 D_801EAE30;

void func_801469D8(s32 arg0, u8 *arg1) {
    u16 sp1C[2];

    func_800897D0(*(s32 *)(arg1 + 4), 0x4000);
    sp1C[0] = 0;
    if ((SysFlashrom_Read(*(s32 *)(arg1 + 4), D_801C7CA8, D_801C7CD0) != 0) && (SysFlashrom_Read(*(s32 *)(arg1 + 4), D_801C7CAC, D_801C7CD4) != 0)) {
        sp1C[0] = 1;
    }
    if (sp1C[0] != 0) {
        D_801EAE30 = 0xFF;
        return;
    }
    func_800FEA90(&D_801EAE30, *(s32 *)(arg1 + 4), 6);
}
