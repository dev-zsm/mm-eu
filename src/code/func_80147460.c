// FLAGS: -O2 -g3 -mips2
#include "types.h"
void Sram_SaveEndOfCycle(u8 *);
void func_8014582C(u8 *);
void SysFlashrom_WriteSync(s32, s32, s32);
extern s32 D_801C7C88[];
extern s32 D_801C7CB0[];
extern u8 D_801E6EF0[];

void func_80147460(u8 *arg0) {
    s32 sp24;
    s32 sp20;
    u16 sp1E;

    sp24 = *(s32 *)(D_801E6EF0 + 8);
    sp1E = *(u16 *)(D_801E6EF0 + 0xC);
    sp20 = *(s32 *)(D_801E6EF0 + 0x18);
    D_801E6EF0[0xF4C] &= 0xDF;
    Sram_SaveEndOfCycle(arg0);
    func_8014582C(arg0 + 0x46B8);
    *(s32 *)(D_801E6EF0 + 0x18) = sp20;
    *(u16 *)(D_801E6EF0 + 0xC) = sp1E;
    *(s32 *)(D_801E6EF0 + 8) = sp24;
    SysFlashrom_WriteSync(*(s32 *)(arg0 + 0x46BC), D_801C7C88[*(s32 *)(D_801E6EF0 + 0x3CA0) * 2], D_801C7CB0[*(s32 *)(D_801E6EF0 + 0x3CA0) * 2]);
}
