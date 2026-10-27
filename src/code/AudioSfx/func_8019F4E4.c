// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ s8 *flagPtr;
    /* 0x18 */ f32 pitch;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ u16 flags;
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u8 pad24[7];
    /* 0x2B */ u8 variation;
    /* 0x2C */ u8 pad2C[4];
} SfxEntry; // size = 0x30

extern SfxEntry *D_801D3DA8[];
extern u32 D_801FAE4C;
extern u8 D_801CF018;
extern u8 D_801CF01C;

f32 AudioSfx_ComputeFreqScale(u8 bank, u8 index) {
    SfxEntry *entry;
    s32 flags; // wider than the u16 field: selects the ROM register (a2)
    f32 scale;
    s32 active;
    f32 pitch;

    active = 0; // initialised first so entry lands in v1 like the ROM
    entry = &D_801D3DA8[bank][index];
    flags = entry->flags;
    scale = 1.0f;
    if (flags & 0x4000) {
        scale = 1.0f - (D_801FAE4C & 0xF) / 192.0f;
    }

    switch (bank) {
        case 6:
            
            if ((entry->unk22 & 0xFF) < 0x40 && D_801CF018 != 0) {
                active = 1;
            } else if ((entry->unk22 & 0xFF) >= 0x40 && D_801CF01C != 0) {
                active = 1;
            }
            break;
        case 0:
        case 1:
            if (D_801CF018 != 0) {
                active = 1;
            }
            break;
        case 2:
        case 3:
            if (((*entry->flagPtr & 0x80) != 0) | (D_801CF01C != 0)) {
                active = 1;
            }
            break;
        case 4:
        case 5:
            break;
    }

    if ((active == 1) && !(flags & 0x800)) {
        scale = scale * (1.0293 - (D_801FAE4C & 0xF) / 144.0f);
    }

    pitch = entry->pitch;
    if (!(flags & 0x2000) && !(flags & 0x8000)) {
        if (pitch >= 10000.0f) {
            scale += 0.2f;
        } else {
            scale += 0.2f * (pitch / 10000.0f);
        }
    }

    if (flags & 0xC0) {
        scale += (u32)entry->variation / 192.0f;
    }

    return scale;
}
