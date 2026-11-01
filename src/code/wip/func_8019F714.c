#include "types.h"

typedef struct {
    u8 pad0[8];
    f32 *unk8;
    u8 pad_c[0xC];
    f32 unk18;
    u8 pad_1c[4];
    u16 flags;
    u8 pad_22[2];
    u8 flags24;
} SurroundSource;

extern f32 D_801D861C;
extern f32 D_801D8620;

u8 AudioSfx_ComputeSurroundSoundFilter(f32 arg0, SurroundSource *src, s32 arg2) {
    s32 group = 0;
    f32 scale;
    f32 amount;
    u8 offset = 0;

    if (*src->unk8 < arg0) {
        group = 0;
    }
    if (src->flags & 0x200) {
        group = 0xF;
    }
    switch (src->flags & 7) {
        case 0:
            scale = 15.0f;
            break;
        case 1:
            scale = 12.0f;
            break;
        case 2:
            scale = 9.0f;
            break;
        case 3:
            scale = 6.0f;
            break;
        case 4:
            scale = 18.0f;
            break;
        case 5:
            scale = 21.0f;
            break;
        case 6:
            scale = 24.0f;
            break;
        case 7:
            scale = 27.0f;
            break;
    }
    if (!(src->flags24 & 0x20)) {
        if (D_801D861C < src->unk18) {
            amount = D_801D861C;
        } else {
            amount = src->unk18;
        }
        offset = scale * amount / D_801D8620;
    }
    return (group << 4) + offset;
}
