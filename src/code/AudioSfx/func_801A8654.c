// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x0 */ f32 target;
    /* 0x4 */ f32 cur;
    /* 0x8 */ f32 step;
    /* 0xC */ u16 time;
    /* 0xE */ u16 pad;
} BankLerp;

extern BankLerp D_801F74D0[];

void AudioSfx_SetBankLerp(u8 bank, u8 val, u16 time) {
    BankLerp *e;

    if (time == 0) {
        time++;
    }
    e = &D_801F74D0[bank];
    e->cur = val / 127.0f;
    e->time = time;
    e->step = (e->target - e->cur) / time;
}
