// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 mode;
    u8 unk1;
    u8 unk2;
    u8 pad3[4];
    u8 unk7;
    s16 unk8;
} TransitionFade;

void TransitionFade_Start(TransitionFade *a0) {
    switch (a0->mode) {
    case 0:
        break;
    case 1:
        a0->unk8 = 0;
        if (a0->unk2 != 0) {
            a0->unk7 = 0xFF;
        } else {
            a0->unk7 = 0;
        }
        break;
    case 2:
        a0->unk7 = 0;
        break;
    }
    a0->unk1 = 0;
}
