#include "types.h"
#include "actor.h"
#include "generated/overlays/0103.h"
extern u8 D_808C32A0[];
extern void func_800FF8DC();
void BgKeikokuSpr_Init(Actor *thisx, PlayState *play) { func_800FF8DC(thisx, D_808C32A0); }
