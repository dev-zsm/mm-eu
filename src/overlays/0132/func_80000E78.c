// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

void ObjOshihiki_OnActor(ObjOshihiki* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);
    DynaPolyActor* dyna;
    s32 sp20 = false;

    this->stateFlags |= PUSHBLOCK_ON_ACTOR;
    Actor_MoveWithGravity(&this->dyna.actor);

    if (ObjOshihiki_CheckFloor(this, play)) {
        if (this->floorBgIds[this->highestFloor] == BGCHECK_SCENE) {
            ObjOshihiki_SetupOnScene(this, play);
        } else {
            dyna = DynaPoly_GetActor(&play->colCtx, this->floorBgIds[this->highestFloor]);
            if (dyna != NULL) {
                DynaPolyActor_SetActorOnTop(dyna);
                DynaPolyActor_SetSwitchPressed(dyna);
                if ((this->timer <= 0) && (fabsf(this->dyna.pushForce) > 0.001f) &&
                    ObjOshihiki_StrongEnough(this, play) && ObjOshihiki_NoSwitchPress(this, dyna, play) &&
                    !ObjOshihiki_CheckWall(play, this->dyna.yRotation, this->dyna.pushForce, this)) {
                    this->direction = this->dyna.pushForce;
                    ObjOshihiki_SetupPush(this, play);
                    sp20 = true;
                }
            } else {
                ObjOshihiki_SetupOnScene(this, play);
            }
        }
    } else if (this->floorBgIds[this->highestFloor] == BGCHECK_SCENE) {
        ObjOshihiki_SetupFall(this, play);
    } else {
        dyna = DynaPoly_GetActor(&play->colCtx, this->floorBgIds[this->highestFloor]);
        if ((dyna != NULL) && (dyna->transformFlags & DYNA_TRANSFORM_POS)) {
            DynaPolyActor_SetActorOnTop(dyna);
            DynaPolyActor_SetSwitchPressed(dyna);
            this->dyna.actor.world.pos.y = this->dyna.actor.floorHeight;
        } else {
            ObjOshihiki_SetupFall(this, play);
        }
    }

    if (!sp20 && (fabsf(this->dyna.pushForce) > 0.001f)) {
        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
    }
}
