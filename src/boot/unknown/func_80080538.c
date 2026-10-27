// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_800803B0(void);
extern void osCreatePiManager(s32, void *, void *, s32);
extern void StackCheck_Init(void *, void *, void *, s32, s32, void *);
extern void func_80080310(s32);
extern void osCreateThread(void *, s32, void (*)(s32), s32, void *, s32);
extern void osStartThread(void *);
extern void osSetThreadPri(s32, s32);

extern s32 D_8009B290;
extern s32 D_8009B2B0;
extern s32 D_8009B378;
extern u8 D_8009A990[0x900]; /* thread stack, ends at D_8009B290 */
extern s32 D_8009A7E0;
extern s32 D_80098438;

void func_80080538(s32 arg0) {
    func_800803B0();
    osCreatePiManager(0x96, &D_8009B378, &D_8009B2B0, 0x32);
    StackCheck_Init(&D_8009B290, &D_8009A990, D_8009A990 + sizeof(D_8009A990), 0, 0x400, &D_80098438);
    osCreateThread(&D_8009A7E0, 3, func_80080310, arg0, &D_8009B290, 0xC);
    osStartThread(&D_8009A7E0);
    osSetThreadPri(0, 0);
    for (;;) {}
}
