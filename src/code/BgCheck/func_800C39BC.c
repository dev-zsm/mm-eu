// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

struct CollisionHeader * BgCheck_GetCollisionHeader(struct CollisionContext *colCtx, s32 bgId) {
    if (bgId == 0x32) {
        return *(s32 *)colCtx;
    }
    if ((bgId < 0) || (bgId >= 0x33)) {
        return 0;
    }
    if (!(*(u16 *)((s32)colCtx + (bgId * 2) + 0x13DC) & 1)) {
        return 0;
    }
    return *(s32 *)((s32)colCtx + (bgId * 0x64) + 0x58);
}
