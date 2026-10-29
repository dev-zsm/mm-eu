// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4C50[];
extern u8 D_801F4C60[];
extern f32 D_801F4C6C;
extern u8 D_801F4C70;
extern u8 D_801F4C71;
extern u8 D_801F4C73;
extern void Audio_StopSequenceAtPos();
extern void Audio_StartSubBgmAtPos(s32, u8 *, u8, s32, f32, f32, f32);

void Audio_UpdateSubBgmAtPos(void) {
    if (D_801F4C73 != 0) {
        if (D_801F4C71 & 2) {
            Audio_StartSubBgmAtPos(3, D_801F4C50, D_801F4C70, 0x20, 100.0f, D_801F4C6C, 1.0f);
        } else {
            Audio_StartSubBgmAtPos(3, D_801F4C60, D_801F4C70, 0x28, 100.0f, D_801F4C6C, 1.0f);
        }
        D_801F4C73--;
        if (D_801F4C73 == 0) {
            Audio_StopSequenceAtPos(3, 10);
        }
        D_801F4C71 = 0;
    }
}
