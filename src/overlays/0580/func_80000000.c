// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_obj.h"

void BgIknvObj_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIknvObj* this = (BgIknvObj*)thisx;
    CollisionHeader* colHeader = NULL;

    Actor_SetScale(&this->dyna.actor, 0.1f);
    this->actionFunc = BgIknvObj_DoNothing;
    switch (IKNV_OBJ_TYPE(this)) {
        case IKNV_OBJ_WATERWHEEL:
            this->dList = object_iknv_obj_DL_013058;
            this->actionFunc = BgIknvObj_UpdateWaterwheel;
            this->dyna.actor.flags |= ACTOR_FLAG_FREEZE_EXCEPTION;
            this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
            break;

        case IKNV_OBJ_RAISED_DOOR:
            this->dList = object_iknv_obj_DL_011880;
            DynaPolyActor_Init(&this->dyna, 0);
            CollisionHeader_GetVirtual(&object_iknv_obj_Colheader_0119D4, &colHeader);
            this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
            this->actionFunc = BgIknvObj_UpdateRaisedDoor;
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 120.0f;
            break;

        case IKNV_OBJ_SAKON_DOOR:
            this->dList = object_iknv_obj_DL_0129C8;
            this->actionFunc = BgIknvObj_UpdateSakonDoor;
            DynaPolyActor_Init(&this->dyna, 0);
            CollisionHeader_GetVirtual(&object_iknv_obj_Colheader_012CA4, &colHeader);
            this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
            Collider_InitAndSetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
            Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
            this->dyna.actor.colChkInfo.mass = MASS_IMMOVABLE;
            CLEAR_WEEKEVENTREG(WEEKEVENTREG_51_10);
            Actor_SetFocus(&this->dyna.actor, IREG(88));
            break;

        default:
            Actor_Kill(&this->dyna.actor);
            return;
    }
}
