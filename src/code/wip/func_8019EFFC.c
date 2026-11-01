#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ f32 distance;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ u16 flags;
    /* 0x22 */ u8 pad22[0x0E];
} SfxEntry; // size = 0x30

extern SfxEntry *D_801D3DA8[];
extern f32 D_801D857C;
extern f32 D_801D8580;
extern f32 D_801D8584;
extern f32 D_801D8588;
extern f32 D_801D858C;
extern f32 D_801D85B0;
extern f32 D_801D85B4;
extern f32 D_801D85B8;
extern f32 D_801D85BC;

f32 AudioSfx_ComputeVolume(u8 bankId, u8 entryIdx) {
    SfxEntry *entry = &D_801D3DA8[bankId][entryIdx];
    f32 maxDist;
    f32 nearDist;
    f32 minVol;
    f32 volRange;
    f32 fadeStart;
    f32 vol;

    if (entry->flags & 0x2000) {
        return 1.0f;
    }
    maxDist = D_801D857C;
    if (maxDist < entry->distance) {
        return 0.0f;
    }
    if (entry->flags & 4) {
        minVol = D_801D8580;
        volRange = D_801D8584;
    } else {
        minVol = D_801D8588;
        volRange = D_801D858C;
    }
    switch (entry->flags & 7) {
        case 0:
            nearDist = 500.0f;
            break;
        case 1:
            nearDist = D_801D85B0;
            break;
        case 2:
            nearDist = D_801D85B4;
            break;
        case 3:
            nearDist = D_801D85B8;
            break;
        case 4:
            nearDist = 1000.0f;
            break;
        case 5:
            nearDist = D_801D85BC;
            break;
        case 6:
            nearDist = 500.0f;
            break;
        case 7:
            nearDist = 400.0f;
            break;
    }
    fadeStart = nearDist / 5.0f;
    if (entry->distance < fadeStart) {
        vol = 1.0f;
    } else if (entry->distance < nearDist) {
        vol = ((nearDist - fadeStart) - (entry->distance - fadeStart)) / (nearDist - fadeStart) * volRange + minVol;
    } else {
        vol = (1.0f - (entry->distance - nearDist) / (maxDist - nearDist)) * minVol;
    }
    return vol * vol;
}
