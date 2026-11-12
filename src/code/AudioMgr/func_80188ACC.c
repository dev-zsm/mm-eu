// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x19];
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ u8 pad1C[0x2D0 - 0x1C];
} Reverb; /* size 0x2D0 */

extern struct {
    /* 0x0000 */ u8 pad0;
    /* 0x0001 */ s8 unk1;
    /* 0x0002 */ u8 pad2[0xE];
    /* 0x0010 */ s32 unk10;
    /* 0x0014 */ u8 pad14[0x2878 - 0x14];
    /* 0x2878 */ s16 unk2878;
    /* 0x287A */ s16 unk287A;
    /* 0x287C */ s16 unk287C;
    /* 0x287E */ s16 unk287E;
} D_801F84B0;

void func_801886B0(s32, s32, s32);
void func_80188A44(s32);
s32 AudioSynth_ProcessSamples(s32, s32, s32, s32);
void AudioScript_ProcessSequences(s32);

s32 func_80188ACC(s32 arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 j;
    s32 chunk;
    s32 cmd;
    s32 buf;

    cmd = arg0;
    for (i = D_801F84B0.unk2878; i > 0; i--) {
        AudioScript_ProcessSequences(i - 1);
        func_80188A44(D_801F84B0.unk2878 - i);
    }
    buf = arg2;
    D_801F84B0.unk10 = 0;
    for (i = D_801F84B0.unk2878; i > 0; i--) {
        if (i == 1) {
            chunk = arg3;
        } else {
            s32 avg = arg3 / i;
            if (avg >= D_801F84B0.unk287C) {
                chunk = D_801F84B0.unk287C;
            } else if (D_801F84B0.unk287E >= avg) {
                chunk = D_801F84B0.unk287E;
            } else {
                chunk = D_801F84B0.unk287A;
            }
        }
        for (j = 0; j < D_801F84B0.unk1; j++) {
            if (((Reverb *)&D_801F84B0)[j].unk19 != 0) {
                func_801886B0(chunk, D_801F84B0.unk2878 - i, j);
            }
        }
        cmd = AudioSynth_ProcessSamples(buf, chunk, cmd, D_801F84B0.unk2878 - i);
        arg3 -= chunk;
        buf += chunk * 4;
    }
    for (j = 0; j < D_801F84B0.unk1; j++) {
        if (((Reverb *)&D_801F84B0)[j].unk1A != 0) {
            ((Reverb *)&D_801F84B0)[j].unk1A--;
        }
        ((Reverb *)&D_801F84B0)[j].unk1B ^= 1;
    }
    *arg1 = (cmd - arg0) >> 3;
    return cmd;
}
