// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_danpei_movebg.h"

void ref_func_80AF6EA8(BgDanpeiMovebg* this, PlayState* play) {
    Actor* thisx = &this->dyna.actor;

    if (SubS_IsObjectLoaded(this->objectSlot, play)) {
        gSegments[6] = OS_K0_TO_PHYSICAL(play->objectCtx.slots[this->objectSlot].segment);
        this->dyna.actor.objectSlot = this->objectSlot;
        this->dyna.actor.draw = ref_func_80AF74CC;
        Actor_ProcessInitChain(thisx, sInitChain);
        DynaPolyActor_LoadMesh(play, &this->dyna, ref_D_80AF7538[BGDANPEIMOVEBG_GET_TYPE(thisx)]);
        this->dList = ref_D_80AF7534[BGDANPEIMOVEBG_GET_TYPE(thisx)];

        if (BGDANPEIMOVEBG_GET_TYPE(thisx) == 0) {
            this->dyna.actor.gravity = 0.0f;
            this->dyna.actor.speed = 1.0f;
            SubS_ActorPathing_Init(play, &thisx->world.pos, thisx, &this->actorPath, play->setupPathList,
                                   BGDANPEIMOVEBG_GET_PATH_INDEX(thisx), 0, 0, 0, 0);
            this->actionFunc = ref_func_80AF70FC;
        }
    }
}
