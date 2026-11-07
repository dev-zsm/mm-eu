// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_Init(Actor* thisx, PlayState* play) {
    EnBat* this = (EnBat*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);
    Collider_InitAndSetSphere(play, &this->collider, thisx, &sSphereInit);
    this->collider.dim.worldSphere.radius = sSphereInit.dim.modelSphere.radius;
    CollisionCheck_SetInfo(&thisx->colChkInfo, &sDamageTable, &sColChkInfoInit);
    ActorShape_Init(&thisx->shape, 2000.0f, ActorShadow_DrawCircle, 25.0f);

    this->animationFrame = Rand_ZeroOne() * 9.0f;

    this->paramFlags = BAD_BAT_GET_PARAMFLAGS(thisx);
    this->switchFlag = BAD_BAT_GET_SWITCH_FLAG(thisx);
    thisx->params = BAD_BAT_GET_TYPE(thisx);

    thisx->depthInWater = BGCHECK_Y_MIN;
    Actor_SetFocus(thisx, 20.0f);

    if (sAlreadySpawned) {
        Actor_Kill(thisx);
    } else if (EnBat_IsGraveyardOnSecondDay(play)) {
        if (Flags_GetSwitch(play, this->switchFlag)) {
            Actor_Kill(thisx);
        } else {
            this->actor.room = -1;
        }
    }

    if (this->paramFlags & BAD_BAT_PARAMFLAG_PERCH) {
        thisx->params = 0;
        EnBat_SetupPerch(this);
    } else {
        if (thisx->params == 0x1F) {
            thisx->params = 0;
        }
        EnBat_SetupFlyIdle(this);
        while (BAD_BAT_GET_NUMBER_TO_SPAWN(thisx) > 1) {
            Actor_SpawnAsChildAndCutscene(
                &play->actorCtx, play, ACTOR_EN_BAT, thisx->world.pos.x + Rand_CenteredFloat(200.0f),
                thisx->world.pos.y + Rand_CenteredFloat(100.0f), thisx->world.pos.z + Rand_CenteredFloat(200.0f),
                Rand_CenteredFloat(0x2000), 0xFFFF * Rand_ZeroOne(), 0,
                BAD_BAT_PARAMS(this->switchFlag, this->paramFlags, 0), CS_ID_NONE, thisx->halfDaysBits, NULL);
            BAD_BAT_GET_NUMBER_TO_SPAWN(thisx)--;
        }
    }
}
