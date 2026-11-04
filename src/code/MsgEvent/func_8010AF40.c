// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_FocusToSelf(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    if (actor->child != NULL) {
        Actor_ChangeFocus(actor->child, play, actor);
    }
    return false;
}
