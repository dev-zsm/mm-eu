// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_wiz_brock.h"

void EnWizBrock_Init(Actor* thisx, PlayState* play) {
    EnWizBrock* this = (EnWizBrock*)thisx;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&this->dyna, 0);
    CollisionHeader_GetVirtual(&gWizrobePlatformCol, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    this->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->dyna.actor.colChkInfo.health = 3;
    this->unk_1A6 = 0;
    Actor_SetScale(&this->dyna.actor, 0.01f);
    this->platformIndex = sPlatformIndex++;
    this->actionFunc = EnWizBrock_SetupUpdateStatus;
    this->dyna.actor.scale.x = this->dyna.actor.scale.y = this->dyna.actor.scale.z = 0.01f;
    this->alpha = 255.0f;
}
