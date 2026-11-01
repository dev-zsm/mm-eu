#include "types.h"

typedef struct {
    u32 w[2];
} TunedSample;

typedef struct {
    u8 pad0[1];
    u8 loPitch;
    u8 hiPitch;
    u8 pad3[5];
    TunedSample lo;
    TunedSample mid;
    TunedSample hi;
} Instrument;

TunedSample *AudioPlayback_GetInstrumentTunedSample(Instrument *instrument, s32 semitone) {
    if (semitone < instrument->loPitch) {
        return &instrument->lo;
    }
    if (instrument->hiPitch >= semitone) {
        return &instrument->mid;
    }
    return &instrument->hi;
}
