#include "types.h"
#include "generated/overlays/0329.h"
extern s16 D_801EC702;
void func_800014D8(Actor *thisx, PlayState *play) {
    s32 t;
    t = (*(s16 *)((u8 *)thisx + 0x1C) >> 10) * 100;
    if (t > 0) {
        D_801EC702 = t;
    }
}
