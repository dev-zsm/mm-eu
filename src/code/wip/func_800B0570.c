#include "types.h"

typedef struct {
    u8 *start;
    s32 unk4;
    s32 size;
} EffectSsInfo;

typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[8];
} Entry;

extern EffectSsInfo D_801AF260;
extern Entry D_801AF37C[];
extern s32 D_801AF370;
extern u8 *THA_AllocTailAlign16();
extern void EffectSs_Reset();

void EffectSs_InitInfo(s32 a0, s32 a1) {
    u8 *p;
    s32 i;

    D_801AF260.start = THA_AllocTailAlign16(a0 + 0x74, a1 * 0x60, a0);
    D_801AF260.unk4 = 0;
    p = D_801AF260.start;
    D_801AF260.size = a1;
    for (; p < D_801AF260.start + D_801AF260.size * 0x60; p += 0x60) {
        EffectSs_Reset(p);
    }
    D_801AF370 = 0;
    for (i = 0; i < 38; i++) {
        D_801AF37C[i].unk10 = 0;
    }
}
