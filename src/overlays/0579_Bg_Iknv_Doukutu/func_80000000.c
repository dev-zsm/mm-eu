// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_doukutu.h"

void BgIknvDoukutu_Init(Actor* thisx, PlayState* play) {
    BgIknvDoukutu* this = (BgIknvDoukutu*)thisx;
    CollisionHeader* colHeader = NULL;
    s32 pad;

    Actor_SetScale(&this->dyna.actor, 0.1f);
    this->actionFunc = BgIknvDoukutu_DoNothing;
    this->unk_15C = 0;

    switch (BGIKNVDOUKUTU_GET_TYPE(&this->dyna.actor)) {
        case BGIKNVDOUKUTU_INTERIOR:
            this->actionFunc = BgIknvDoukutu_Cursed;
            this->cueType = CS_CMD_ACTOR_CUE_516;
            this->opacity = 1.0f;
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_IKANA_SPRING_RESTORED) ||
                CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE)) {
                this->dyna.actor.draw = BgIknvDoukutu_DrawPurified;
                this->actionFunc = BgIknvDoukutu_DoNothing;
                play->envCtx.lightSettingOverride = 25;
            } else {
                play->envCtx.lightSettingOverride = 24;
            }
            break;

        case BGIKNVDOUKUTU_STREAM:
            Actor_SetScale(&this->dyna.actor, 1.0f);
            this->dyna.actor.draw = BgIknvDoukutu_DrawStream;
            this->cueType = CS_CMD_ACTOR_CUE_516;
            DynaPolyActor_Init(&this->dyna, 0);
            CollisionHeader_GetVirtual(&gIkanaStreamCol, &colHeader);
            this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
            if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_IKANA_SPRING_RESTORED)) {
                Actor_Kill(&this->dyna.actor);
            }
            break;

        case BGIKNVDOUKUTU_SPRING_WATER:
            this->cueType = CS_CMD_ACTOR_CUE_516;
            this->dyna.actor.draw = BgIknvDoukutu_DrawSpringWater;
            DynaPolyActor_Init(&this->dyna, 0);
            CollisionHeader_GetVirtual(&gIkanaCaveSpringWaterCol, &colHeader);
            this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_IKANA_SPRING_RESTORED)) {
                this->opacity = 1.0f;
                this->dyna.actor.world.pos.y += 68.0f;
            } else {
                this->actionFunc = BgIknvDoukutu_Dry;
                this->opacity = 0.0f;
            }
            break;

        default:
            Actor_Kill(&this->dyna.actor);
            break;
    }
}
