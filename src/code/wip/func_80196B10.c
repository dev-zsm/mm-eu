// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x30];
    /* 0x30 */ u8 unk30;
    /* 0x31 */ u8 pad31[7];
    /* 0x38 */ f32 unk38;
    /* 0x3C */ u8 pad3C[4];
    /* 0x40 */ f32 unk40;
} Layer;

typedef struct {
    /* 0x00 */ u8 pad0[0x35];
    /* 0x35 */ u8 unk35;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 pad37[0xE8 - 0x37];
    /* 0xE8 */ s32 unkE8;
} Note;

extern s32 D_801CD4C0[];
extern f32 D_801D7D84;
extern f32 D_801D7D88;
extern f32 D_801D7D8C;
extern f32 D_801D7D90;
extern f32 D_801D7D94;
extern f32 D_801D7D98;
extern f32 D_801D7D9C;

s32 AudioPlayback_BuildSyntheticWave(Note *note, Layer *layer, s32 waveId) {
    f32 freqScale;
    f32 orig;
    f32 ratio;
    u8 index;

    index = 0;
    if (waveId < 0x80) {
        waveId = 0x80;
    }
    orig = layer->unk40;
    freqScale = orig;
    if (layer->unk30 != 0) {
        if (layer->unk38 > 0.0f) {
            freqScale *= layer->unk38 + 1.0f;
        }
    }
    if (freqScale < D_801D7D84) {
        index = 0;
        ratio = D_801D7D88;
    } else if (freqScale < D_801D7D8C) {
        index = 1;
        ratio = D_801D7D90;
    } else if (freqScale < D_801D7D94) {
        index = 2;
        ratio = D_801D7D98;
    } else {
        index = 3;
        ratio = D_801D7D9C;
    }
    layer->unk40 = orig * ratio;
    note->unk35 = waveId;
    note->unk36 = index;
    note->unkE8 = D_801CD4C0[waveId] + (index << 7);
    return index;
}
