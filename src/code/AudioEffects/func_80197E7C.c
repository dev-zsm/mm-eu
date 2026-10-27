// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    u8 mode;
    u8 pad1[0xB];
} Portamento;

typedef struct {
    u8 pad0[0x14];
    u8 active;
    u8 pad15[3];
} Vibrato;

typedef struct {
    u8 pad0[0x3C];
    f32 unk3C;
    f32 unk40;
    u8 pad44[0x44];
    Portamento portamento;
    Vibrato vibrato;
} Note;

extern f32 AudioEffects_UpdatePortamento(Portamento *portamento, Note *note);
extern f32 AudioEffects_UpdateVibrato(Vibrato *vibrato, Note *note);

void AudioEffects_UpdatePortamentoAndVibrato(Note *note) {
    if (note->portamento.mode != 0) {
        note->unk3C = AudioEffects_UpdatePortamento(&note->portamento, note);
    }
    if (note->vibrato.active != 0) {
        note->unk40 = AudioEffects_UpdateVibrato(&note->vibrato, note);
    }
}
