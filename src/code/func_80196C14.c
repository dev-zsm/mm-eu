#include "types.h"

typedef struct {
    u8 pad0[0x26];
    s16 sampleId;
} WaveSample;

typedef struct {
    u8 pad0[2];
    u8 waveId;
    u8 pad3[0x60 - 3];
    WaveSample *sample;
} WaveSource;

typedef struct {
    u8 pad0[0x36];
    u8 baseWave;
    u8 pad37[0xDE - 0x37];
    u8 waveIndex;
} WaveState;

extern s32 AudioPlayback_BuildSyntheticWave(WaveState *state, WaveSource *source, s32 id);

void AudioPlayback_InitSyntheticWave(WaveState *state, WaveSource *source) {
    s32 base; /* declared first: it gets the highest stack slot, as in the ROM */
    s32 id;
    s32 wave;

    id = source->waveId;
    if (id == 0xFF) {
        id = source->sample->sampleId;
    }
    base = state->baseWave;
    wave = AudioPlayback_BuildSyntheticWave(state, source, id);
    if (wave != base) {
        state->waveIndex = wave * 4 + base;
    }
}
