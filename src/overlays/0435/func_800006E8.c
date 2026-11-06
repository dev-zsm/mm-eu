// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ref_func_80AE9258(ObjBigicicle* this, PlayState* play) {
    Actor* itemAction;
    f32 temp_f0;
    ObjIcePoly* icePoly;

    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);

    itemAction = play->actorCtx.actorLists[ACTORCAT_ITEMACTION].first;

    while (itemAction != NULL) {
        if (itemAction->id == ACTOR_OBJ_ICE_POLY) {
            icePoly = (ObjIcePoly*)itemAction;
            temp_f0 = this->actor.world.pos.y - icePoly->actor.world.pos.y;
            if ((temp_f0 < icePoly->colliders1[0].dim.height) && (temp_f0 > 0.0f) &&
                (Actor_WorldDistXZToActor(&this->actor, &icePoly->actor) < icePoly->colliders1[0].dim.radius)) {
                Flags_SetSwitch(play, OBJBIGICLE_GET_SWITCH_FLAG(&this->actor));
                this->actionFunc = ref_func_80AE939C;
                return;
            }
        }
        itemAction = itemAction->next;
    }

    if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
        this->actionFunc = ref_func_80AE939C;
    } else {
        Collider_UpdateCylinder(&this->actor, &this->collider1);
        Collider_UpdateCylinder(&this->actor, &this->collider2);
    }
}
