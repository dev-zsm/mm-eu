// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    u8 pad0[0x22];
    u16 sfxId;
    u8 pad24[5];
    u8 next;
    u8 pad2A[6];
} SfxEntry;
extern SfxEntry *D_801D3DA8[];
s32 AudioSfx_IsPlaying(u32 sfxId) {
    u8 bank = (sfxId & 0xF000) >> 12;
    SfxEntry *entries = D_801D3DA8[bank];
    if (sfxId) {
    }
    for (bank = entries[0].next; bank != 0xFF; bank = entries[bank].next) {
        if (entries[bank].sfxId == sfxId) {
            return 1;
        }
    }

    return 0;
}
