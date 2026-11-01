#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ u8 unk34;
    /* 0x35 */ u8 pad35[3];
    /* 0x38 */ u8 unk38;
    /* 0x39 */ u8 pad39[0xF];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ u8 pad50[0x18];
    /* 0x68 */ u8 unk68_hi : 4;
    /* 0x68 */ u8 unk68_lo : 4;
    /* 0x69 */ u8 pad69[0xF];
    /* 0x78 */ f32 unk78;
    /* 0x7C */ u8 pad7C[0x5C];
    /* 0xD8 */ u8 flag80 : 1;
    /* 0xD8 */ u8 flag40 : 1;
    /* 0xD8 */ u8 flag20 : 1;
    /* 0xD8 */ u8 unkD8_rest : 5;
} Note;

void AudioPlayback_NoteDisable(Note *note) {
    if (note->flag40 == 1) {
        note->flag40 = 0;
    }
    note->unk34 = 0;
    note->flag80 = 0;
    note->unk38 = 0;
    note->flag20 = 0;
    note->unk48 = -1;
    note->unk4C = -1;
    note->unk68_lo = 0;
    note->unk78 = 0.0f;
}
