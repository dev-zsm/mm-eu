// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_turret.h"

void ObjTokeiTurret_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjTokeiTurret* this = (ObjTokeiTurret*)thisx;
    s32 tier;

    tier = OBJ_TOKEI_TURRET_TIER_TYPE(thisx);
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);

    if ((tier == TURRET_TIER_BASE) || (tier == TURRET_TIER_TOP)) {
        this->dyna.actor.cullingVolumeDownward = this->dyna.actor.cullingVolumeScale = 240.0f;

        if (tier == TURRET_TIER_BASE) {
            DynaPolyActor_LoadMesh(play, &this->dyna, &gClockTownTurretBaseCol);
        } else {
            DynaPolyActor_LoadMesh(play, &this->dyna, &gClockTownTurretPlatformCol);
        }
    } else {
        this->dyna.actor.cullingVolumeDownward = this->dyna.actor.cullingVolumeScale = 1300.0f;
    }
}
