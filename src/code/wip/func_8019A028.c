#include "types.h"

typedef struct {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 pad1[0x25];
    /* 0x26 */ s16 instId;
    /* 0x28 */ u8 pad28[0x24];
    /* 0x4C */ s32 instType;
    /* 0x50 */ u8 pad50[0x30];
    /* 0x80 */ u8 unk80[1];
} Layer;

s16 AudioScript_GetInstrument(void *l, s32 id, s32 *b, void *c);

void AudioScript_SetInstrument(Layer *l, s32 arg1) {
    s16 id = arg1 & 0xFF;
    if (id >= 0x80) {
        l->instId = id;
        l->instType = 0;
    } else if (id == 0x7F) {
        l->instId = 0;
        l->instType = 1;
    } else if (id == 0x7E) {
        l->instId = 1;
        l->instType = 2;
    } else {
        l->instId = AudioScript_GetInstrument(l, id, &l->instType, l->unk80);
        if (l->instId == 0) {
            l->flags &= ~8;
            return;
        }
    }
    l->flags |= 8;
}
