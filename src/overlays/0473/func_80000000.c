// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_botihasira.h"

void BgBotihasira_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgBotihasira* this = (BgBotihasira*)thisx;
    CollisionHeader* colHeader = NULL;

    if (this->dyna.actor.params == 0) {
        DynaPolyActor_Init(&this->dyna, 0);
        CollisionHeader_GetVirtual(&object_botihasira_Colheader_001BD8, &colHeader);
        this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    } else {
        Collider_InitAndSetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    }
    this->actionFunc = BgBotihasira_DoNothing;
    this->dyna.actor.scale.z = this->dyna.actor.scale.y = this->dyna.actor.scale.x = 0.1f;
}
