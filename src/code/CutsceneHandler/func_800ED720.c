// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x1F28];
    s32 unk1F28;
} Ctx720;

typedef struct {
    u8 pad0[0x10];
    u16 unk10;
} Cut720;

extern s32 D_801E6EF8;
void Cutscene_ProcessScript(void *, void *, s32);

void CutsceneHandler_RunScript(Ctx720 *arg0, Cut720 *arg1) {
    if (D_801E6EF8 >= 0xFFF0) {
        arg1->unk10 = arg1->unk10 + 1;
        Cutscene_ProcessScript(arg0, arg1, arg0->unk1F28);
    }
}
