// FLAGS: -O2 -g3 -mips2
#include "types.h"
void func_80145A58(u8 *, s32);
void SysFlashrom_WriteSync(s32, s32, s32, u8 *);
extern s32 D_801C7C88[];
extern s32 D_801C7CD8[];
extern u8 D_801E6EF0[];
extern s32 D_801EAB90;

void func_801473EC(u8 *arg0) {
    u8 *a3 = arg0 + 0x46B8;
    s32 pad[2]; // frame padding

    D_801E6EF0[5] = 1;
    D_801E6EF0[0x23] = 0;
    func_80145A58(a3, (s32)arg0);
    SysFlashrom_WriteSync(*(s32 *)(a3 + 4), D_801C7C88[D_801EAB90 * 2], D_801C7CD8[D_801EAB90 * 2], a3);
}
