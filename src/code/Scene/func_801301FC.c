// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x18760];
    u8 unk18760;
    u8 pad18761[3];
    s32 unk18764;
} PlayState30;

s32 func_80100304(s32, void *);
void MapDisp_InitTransitionActorData(void *, u8, s32);

void Scene_CommandTransitionActorList(PlayState30 *arg0, u8 *arg1) {
    arg0->unk18760 = arg1[1];
    arg0->unk18764 = func_80100304(*(s32 *)(arg1 + 4), arg1);
    MapDisp_InitTransitionActorData(arg0, arg0->unk18760, arg0->unk18764);
}
