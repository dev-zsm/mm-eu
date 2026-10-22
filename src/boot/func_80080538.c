// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_800803B0(void);
extern void func_8008C1C0(s32, void *, void *, s32);
extern void func_80085390(void *, void *, void *, s32, s32, void *);
extern void func_80080310(s32);
extern void func_80089FE0(void *, s32, void (*)(s32), s32, void *, s32);
extern void func_80095950(void *);
extern void func_8008FDA0(s32, s32);

extern s32 D_8009B290;
extern s32 D_8009B2B0;
extern s32 D_8009B378;
extern u8 D_8009A990[0x900]; /* thread stack, ends at D_8009B290 */
extern s32 D_8009A7E0;
extern s32 D_80098438;

void func_80080538(s32 arg0) {
    func_800803B0();
    func_8008C1C0(0x96, &D_8009B378, &D_8009B2B0, 0x32);
    func_80085390(&D_8009B290, &D_8009A990, D_8009A990 + sizeof(D_8009A990), 0, 0x400, &D_80098438);
    func_80089FE0(&D_8009A7E0, 3, func_80080310, arg0, &D_8009B290, 0xC);
    func_80095950(&D_8009A7E0);
    func_8008FDA0(0, 0);
    for (;;) {}
}
