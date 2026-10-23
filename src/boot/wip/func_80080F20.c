// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_8009BDE8[];
extern u8 *D_8009C1E8;
extern u32 D_8009C1EC;
extern u32 D_8009C1F0;
extern u8 *D_8009C1F4;
extern u8 D_800984A0[];

void func_800807E0(u32 a, void *b, u32 c);
void bcopy(void *a, void *b, u32 c);
s32 osGetThreadPri(s32 a);
void osSetThreadPri(s32 a, s32 b);
void func_8008198C(void *a);

u8 *Yaz0_NextDMA(u8 *curSrcPos) {
    u8 *dst;
    u32 restSize = (u32)D_8009C1E8 - (u32)curSrcPos;
    u32 dmaSize;
    s32 prio;

    if (restSize & 7) {
        dst = D_8009BDE8 - (restSize & 7) + 8;
    } else {
        dst = D_8009BDE8;
    }
    bcopy(curSrcPos, dst, restSize);
    dmaSize = D_8009C1E8 - dst - restSize;
    if (D_8009C1F0 < dmaSize) {
        dmaSize = D_8009C1F0;
    }
    if (dmaSize != 0) {
        func_800807E0(D_8009C1EC, dst + restSize, dmaSize);
        D_8009C1EC += dmaSize;
        D_8009C1F0 -= dmaSize;
        if (D_8009C1F0 == 0) {
            D_8009C1F4 = dst + restSize + dmaSize;
        }
    } else {
        prio = osGetThreadPri(0);
        osSetThreadPri(0, 0x7F);
        func_8008198C(D_800984A0);
        osSetThreadPri(0, prio);
    }
    return dst;
}
