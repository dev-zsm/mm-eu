// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ObjFlowerpot_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjFlowerpot* this = (ObjFlowerpot*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);

    if (this->actor.shape.rot.y == 0) {
        this->actor.shape.rot.y = this->actor.world.rot.y = Rand_Next() >> 0x10;
    }

    Collider_InitJntSph(play, &this->collider);
    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);
    Matrix_SetTranslateRotateYXZ(this->actor.home.pos.x, this->actor.home.pos.y, this->actor.home.pos.z,
                                 &this->actor.shape.rot);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    Collider_UpdateSpheres(0, &this->collider);
    Collider_UpdateSpheres(1, &this->collider);

    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->unk_1EC = this->actor.room;
    ref_func_80A1C818(this);

    if (ref_D_80A1D404) {
        ref_D_80A1DA38 = Rand_Next() >> 0x10;
        ref_D_80A1DA3A = Rand_Next() >> 0x10;
        ref_D_80A1DA3C = Rand_Next() >> 0x10;
        ref_D_80A1DA3E = Rand_Next() >> 0x10;
        ref_D_80A1DA40 = Rand_Next() >> 0x10;
        ref_D_80A1D404 = false;
        ref_func_80A1B3D0();
        ref_D_80A1D830 = play->gameplayFrames;
    }
    this->unk_1EB = ref_D_80A1D400 & 7;
    ref_D_80A1D400++;
}
