// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0x0C];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x0C];
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
} PreRender;

void PreRender_SetValues(PreRender *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unk0 = arg1;
    arg0->unk2 = arg2;
    arg0->unk10 = arg3;
    arg0->unk1C = arg4;
    arg0->unk2C = 0;
    arg0->unk2E = 0;
    arg0->unk30 = arg1 - 1;
    arg0->unk32 = arg2 - 1;
}
