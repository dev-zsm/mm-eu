// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D140[];
extern s32 D_8009D150;
extern s32 D_8009D158;
extern s32 D_8009D160;
extern s32 D_8009D168;
extern s32 D_8009D16C;
extern s32 D_8009D170;
extern s32 D_8009D178;

void bcopy(s32 a0, void *dst, s32 size);
s32 osVirtualToPhysical(s32 arg0);

void *_VirtualToPhysicalTask(s32 arg0) {
    s32 temp_a0;

    bcopy(arg0, D_8009D140, 0x40);
    if (D_8009D150 != 0) {
        D_8009D150 = osVirtualToPhysical(D_8009D150);
    }
    if (D_8009D158 != 0) {
        D_8009D158 = osVirtualToPhysical(D_8009D158);
    }
    if (D_8009D160 != 0) {
        D_8009D160 = osVirtualToPhysical(D_8009D160);
    }
    if (D_8009D168 != 0) {
        D_8009D168 = osVirtualToPhysical(D_8009D168);
    }
    if (D_8009D16C != 0) {
        D_8009D16C = osVirtualToPhysical(D_8009D16C);
    }
    if (D_8009D170 != 0) {
        D_8009D170 = osVirtualToPhysical(D_8009D170);
    }
    temp_a0 = D_8009D178;
    if (temp_a0 != 0) {
        D_8009D178 = osVirtualToPhysical(temp_a0);
    }
    return D_8009D140;
}
