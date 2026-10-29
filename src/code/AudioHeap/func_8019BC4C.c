// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x4B40];
    u8 unk4B40;
    u8 pad4B41[0x5F];
    s32 unk4BA0;
} S1;
void AudioScript_InitLayerFreelist(void);
void func_8019BB7C(u8 *);
extern S1 D_801F84B0[];
extern u8 D_801FB1B0[];
extern u8 D_801FC910[];
extern u8 D_801FCFF0[];
void func_8019BC4C(void) {
    S1 *p;
    u8 *q;
    AudioScript_InitLayerFreelist();
    p = D_801F84B0; do {
        p->unk4BA0 = 0;
        p->unk4B40 &= 0xFF7F;
        p = (S1 *) (((u8 *) p) + 0x90);
        } while (((u8 *) p) < D_801FB1B0); q = D_801FC910; do { func_8019BB7C(q); q += 0x160; } while (q != D_801FCFF0);
}
