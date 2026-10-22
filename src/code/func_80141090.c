// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
} VisCvg;

void VisCvg_Init(VisCvg *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0xFF;
    arg0->unk9 = 0xFF;
    arg0->unkA = 0xFF;
    arg0->unkB = 0xFF;
}
