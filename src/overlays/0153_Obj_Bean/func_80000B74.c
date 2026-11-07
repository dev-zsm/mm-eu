// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ObjBean_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjBean* this = (ObjBean*)thisx;
    s32 sp2C = OBJBEAN_GET_C000(&this->dyna.actor);

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->unk_1FE = 0;
    this->unk_1B8 = 0.1f;
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS | DYNA_TRANSFORM_ROT_Y);
    Collider_InitCylinder(play, &this->collider);

    if ((sp2C == ENOBJBEAN_GET_C000_1) || (sp2C == ENOBJBEAN_GET_C000_2)) {
        this->dyna.actor.update = ref_func_80938C1C;
        this->dyna.actor.textId = 0xFD;
        if (sp2C == ENOBJBEAN_GET_C000_1) {
            Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit2);
            Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
        }
        this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        ref_func_80937C10(this);
        if (!ref_func_80936D58(this, play)) {
            Actor_Kill(&this->dyna.actor);
            return;
        }

        Actor_ChangeCategory(play, &play->actorCtx, &this->dyna.actor, ACTORCAT_ITEMACTION);
        ref_func_80937DD8(this);
    } else {
        s32 pathIndex = OBJBEAN_GET_PATH_INDEX(&this->dyna.actor);
        Path* path = &play->setupPathList[pathIndex];

        this->unk_1DE = OBJBEAN_GET_3(&this->dyna.actor);
        this->dyna.actor.world.rot.z = 0;
        this->dyna.actor.home.rot.z = 0;
        this->dyna.actor.shape.rot.z = 0;
        this->unk_1FE |= 2;

        DynaPolyActor_LoadMesh(play, &this->dyna, &object_mamenoki_Colheader_0004BC);
        Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit1);
        Collider_UpdateCylinder(&this->dyna.actor, &this->collider);

        this->pathPoints = Lib_SegmentedToVirtual(path->points);

        ref_func_80937268(this, play);
        ref_func_809372A8(this);
        ref_func_80937238(this);
        ActorShape_Init(&this->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 8.8f);
        ref_func_80936CF0(this, play);

        if (!OBJBEAN_GET_80(&this->dyna.actor) &&
            Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_1(&this->dyna.actor, 0)) &&
            !Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_1(&this->dyna.actor, 1)) && ref_func_800FE9B4(play)) {
            Flags_SetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_1(&this->dyna.actor, 1));
        }

        if (OBJBEAN_GET_80(&this->dyna.actor) ||
            Flags_GetSwitch(play, OBJBEAN_GET_SWITCH_FLAG_1(&this->dyna.actor, 1))) {
            ref_func_80938804(this);
        } else {
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            ref_func_80938704(this);
        }
    }
}
