// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 byte3;
    /* 0x04 */ s32 word4;
} Instrument;

typedef struct {
    /* 0x00 */ u8 byte0;
    /* 0x01 */ u8 pad1[3];
    /* 0x04 */ s32 word4;
} InstrumentInfo;

extern Instrument *AudioPlayback_GetInstrumentInner(s32 arg0, u8 arg1, Instrument **arg2, InstrumentInfo *arg3);

u8 AudioScript_GetInstrument(u8 *state, u8 index, Instrument **instOut, InstrumentInfo *info) {
    Instrument *inst;

    inst = AudioPlayback_GetInstrumentInner(state[7], index, instOut, info);
    if (inst == NULL) {
        *instOut = NULL;
        return 0;
    }
    index += 2;
    info->word4 = inst->word4;
    info->byte0 = inst->byte3;
    *instOut = inst;
    return index;
}
