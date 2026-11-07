// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_danpei_movebg.h"

u16 ref_func_80AF705C(BgDanpeiMovebg* this, u16 flags) {
    u16 newFlags = flags & ~(DANPEI_MOVEBG_FLAG_4 | DANPEI_MOVEBG_FLAG_8 | DANPEI_MOVEBG_FLAG_10);

    if (DynaPolyActor_IsActorOnTop(&this->dyna) && (this->flags & DANPEI_MOVEBG_FLAG_1)) {
        newFlags |= DANPEI_MOVEBG_FLAG_4;
    }
    if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        if (gSaveContext.save.playerForm == PLAYER_FORM_DEKU) {
            newFlags |= DANPEI_MOVEBG_FLAG_8;
        } else {
            newFlags |= DANPEI_MOVEBG_FLAG_10;
        }
    }
    return newFlags;
}
