// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount2.h"

void EnEncount2_Init(Actor* thisx, PlayState* play) {
    EnEncount2* this = (EnEncount2*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&this->dyna, 0);
    CollisionHeader_GetVirtual(&object_fusen_Colheader_002420, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    ActorShape_Init(&this->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    this->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
    Collider_InitAndSetJntSph(play, &this->collider, &this->dyna.actor, &sJntSphInit, &this->colElement);

    this->dyna.actor.attentionRangeType = ATTENTION_RANGE_6;
    this->dyna.actor.colChkInfo.health = 1;
    this->scale = 0.1f;
    this->switchFlag = ENCOUNT2_GET_SWITCH_FLAG(&this->dyna.actor);

    if (this->switchFlag == ENCOUNT2_SWITCH_FLAG_NONE) {
        this->switchFlag = SWITCH_FLAG_NONE;
    }

    if ((this->switchFlag > SWITCH_FLAG_NONE) && Flags_GetSwitch(play, this->switchFlag)) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    this->collider.elements[0].dim.modelSphere.radius = 57;
    this->collider.elements[0].dim.scale = 1.0f;
    this->collider.elements[0].dim.modelSphere.center.x = 0;
    this->collider.elements[0].dim.modelSphere.center.y = -4;
    this->collider.elements[0].dim.modelSphere.center.z = 0;

    this->dyna.actor.colChkInfo.damageTable = &sDamageTable;
    EnEncount2_SetupIdle(this);
}
