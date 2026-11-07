// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_egblock.h"

void EnEgblock_Init(Actor* thisx, PlayState* play) {
    EnEgblock* this = (EnEgblock*)thisx;
    CollisionHeader* colHeader = NULL;
    s32 pad;

    DynaPolyActor_Init(&this->dyna, 0);
    CollisionHeader_GetVirtual(&gEyegoreBlockCol, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    this->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->inactive = false;
    Actor_SetScale(&this->dyna.actor, 0.5f);
    this->type = EGBLOCK_GET_TYPE(&this->dyna.actor);
    this->paramF80 = EGBLOCK_GET_PARAM_F80(&this->dyna.actor);
    this->param7F = EGBLOCK_GET_PARAM_7F(&this->dyna.actor);
    if (this->type == EGBLOCK_TYPE_ACTIVE) {
        this->dyna.actor.colChkInfo.health = 1;
        this->actionFunc = EnEgblock_Active;
    } else {
        this->actionFunc = EnEgblock_DoNothing;
    }
}
