// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void EnMkk_Init(Actor* thisx, PlayState* play) {
    EnMkk* this = (EnMkk*)thisx;
    s32 paramsFF00;
    s32 params2;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitAndSetSphere(play, &this->collider, &this->actor, &sSphereInit);
    this->collider.dim.worldSphere.radius = sSphereInit.dim.modelSphere.radius;
    CollisionCheck_SetInfo(&this->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    ActorShape_Init(&this->actor.shape, 1000.0f, NULL, 0.0f);

    this->primColorSelect = 0;
    this->unk_149 = 0;
    this->unk_152 = (this->actor.shape.rot.x >= 0) ? this->actor.shape.rot.x : this->actor.shape.rot.x * -0x50;

    this->unk_14C = CLAMP(this->actor.shape.rot.z, 0, 16);

    this->actor.shape.rot.z = 0;
    this->actor.world.rot.z = 0;
    this->actor.shape.rot.x = 0;
    this->actor.world.rot.x = 0;

    Math_Vec3f_Copy(&this->unk_154, &this->actor.world.pos);
    Math_Vec3f_Copy(&this->unk_160, &this->actor.world.pos);
    this->unk_14B = ENMKK_GET_4(thisx) ? 8 : 0;

    paramsFF00 = ENMKK_GET_FF00(&this->actor);
    params2 = ENMKK_GET_2(&this->actor);
    this->actor.params &= 1;

    if (this->actor.params == 1) {
        this->actor.hintId = TATL_HINT_ID_WHITE_BOE;
    } else {
        this->actor.hintId = TATL_HINT_ID_BLACK_BOE;
    }

    if ((paramsFF00 == 0) || (paramsFF00 == 255)) {
        ref_func_80A4E0CC(this);
        this->unk_178 = 30000.0f;
        if (params2 > 0) {
            this->unk_14B |= 4;
        }
    } else {
        this->unk_178 = paramsFF00 * 40.0f * 0.1f;
        ref_func_80A4EDF0(this);
        this->unk_14E = 0;
    }
}
