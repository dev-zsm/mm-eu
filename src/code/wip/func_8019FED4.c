#include "types.h"

typedef struct {
    u8 pad0[4];
    f32 freq;
    u8 pad8[2];
    s8 stereoBits;
    u8 padB[5];
} SfxEntry;

typedef struct {
    u8 pad0[1];
    u8 flags;
    u8 pad2[0x3A];
    f32 freq;
    u8 pad40[0x98];
    s8 stereoBits;
} SfxChannel;

extern SfxEntry D_801F4AE8[];

void AudioSfx_SetFreqAndStereoBits(u8 arg0, SfxChannel *arg1) {
    SfxEntry *entry = &D_801F4AE8[arg0];

    arg1->stereoBits = entry->stereoBits;
    arg1->flags |= 0x80;
    arg1->freq = entry->freq;
}
