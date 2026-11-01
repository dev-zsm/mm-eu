// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0x299C];
    u32 unk299C;
    u8 pad29A0[0x49E0 - 0x29A0];
    u8 unk49E0;
    u8 pad49E1[0x4A14 - 0x49E1];
    f32 unk4A14;
} Sys;
extern Sys D_801F84B0;
extern f64 D_801D8740;
extern s32 AudioThread_NextRandom(u8 a);
s32 Audio_SetAmbienceRandomBend(u8 a0, s32 a1) {
    s32 r;

    D_801F84B0.unk49E0 |= 1;
    if (a0 == 0 || a0 == 0xFF) {
        D_801F84B0.unk4A14 = 1.0f;
    } else {
        r = AudioThread_NextRandom(a0);
        D_801F84B0.unk4A14 = D_801D8740 - (D_801F84B0.unk299C & 0xF) / 144.0f;
    }
    return r;
}
