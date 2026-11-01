// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct {
    u8 unk0;
    u8 pad1[3];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 pad10;
    s32 unk14;
    s32 unk18;
    s8 *unk1C;
    u8 pad20[0x10];
    u8 unk30[0x34];
} E;
s32 func_80088070(void *, s32, s32);
void func_80192054(E *);
void AudioLoad_DmaSlowCopy(E *, s32, s32);
void AudioLoad_DmaSlowCopyUnkMedium(s32, s32, s32, s32);
extern E D_801F84B0[];
extern E D_801F8578[];
#define SUB(p) ((E *)((u8 *)(p) + 0x1D70))
void func_801920C8(s32 arg0) {
    E *s2;
    E *s0;
    s32 n;
    s32 v;
    s2 = D_801F84B0;
    do {
        v = SUB(s2)->unk14;
        if (v != 1) {
            s0 = SUB(s2);
            if (v == 2) {
                if (s0->unk0 != 1) {
                    func_80088070(s0->unk30, 0, 1);
                }
                if (arg0 != 0) {
                    s0->unk14 = 3;
                } else {
                    goto blk;
                }
            }
        } else {
blk:
            s0 = SUB(s2);
            n = s0->unk18;
            s0->unk14 = 2;
            if (n == 0) {
                func_80192054(s0);
                s0->unk14 = 3;
                *s0->unk1C = 1;
            } else if (n < 0x400) {
                if (s0->unk0 == 1) {
                    AudioLoad_DmaSlowCopyUnkMedium(s0->unk8, s0->unkC, n, s0->unk4);
                } else {
                    AudioLoad_DmaSlowCopy(s0, n, n);
                }
                s0->unk18 = 0;
            } else {
                if (s0->unk0 == 1) {
                    AudioLoad_DmaSlowCopyUnkMedium(s0->unk8, s0->unkC, 0x400, s0->unk4);
                } else {
                    AudioLoad_DmaSlowCopy(s0, 0x400, 0x400);
                }
                s0->unk18 -= 0x400;
                s0->unkC += 0x400;
                s0->unk8 += 0x400;
            }
        }
        s2++;
    } while (s2 != D_801F8578);
}
