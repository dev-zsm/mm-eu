// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

ObjBean* ref_func_809374F8(ObjBean* this, PlayState* play) {
    Actor* bgActor = play->actorCtx.actorLists[ACTORCAT_BG].first;
    s32 switchFlag = OBJBEAN_GET_SWITCH_FLAG_2(&this->dyna.actor, 0);

    while (bgActor != NULL) {
        if (bgActor->id == ACTOR_OBJ_BEAN) {
            s32 params2 = OBJBEAN_GET_C000(bgActor);

            if (!params2 && (bgActor->room == this->dyna.actor.room) && !OBJBEAN_GET_80(bgActor) &&
                (switchFlag == OBJBEAN_GET_SWITCH_FLAG_1(bgActor, 0)) &&
                (Math3D_Vec3fDistSq(&bgActor->world.pos, &this->dyna.actor.world.pos) < SQ(10.0f))) {
                break;
            }
        }
        bgActor = bgActor->next;
    }

    return (ObjBean*)bgActor;
}
