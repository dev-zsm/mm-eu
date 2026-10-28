// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[2];
    u16 unk2;
    u16 unk4;
    u8 pad6[0x2A];
} Cue;

typedef struct {
    u8 pad0[0x10];
    u16 unk10;
    u8 pad12[0x16];
    Cue *cues[1];
} Actor;

void func_80091460(void *, s32 *, s32, void *);

void Cutscene_SetActorCue(Actor *arg0, Cue **arg1, s16 arg2) {
    Cue *c;
    s32 sp30;
    s32 i;

    func_80091460(*arg1, &sp30, 4, arg1);
    *arg1 = (Cue *)((u8 *)*arg1 + 4);
    for (i = 0; i < sp30; i++) {
        c = *arg1;
        if (arg0->unk10 >= c->unk2 && arg0->unk10 < c->unk4) {
            arg0->cues[arg2] = c;
        }
        *arg1 = (Cue *)((u8 *)*arg1 + 0x30);
    }
}
