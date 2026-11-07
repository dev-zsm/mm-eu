// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray3.h"

void MirRay3_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    MirRay3* this = (MirRay3*)thisx;

    ActorShape_Init(&this->actor.shape, 0.0f, NULL, 0.0f);
    Actor_SetScale(&this->actor, 1.0f);

    this->unk_218[0].x = -536.0f;
    this->unk_218[0].y = -939.0f;

    this->unk_218[1].x = -1690.0f;
    this->unk_218[1].y = 0.0f;

    this->unk_218[2].x = -536.0f;
    this->unk_218[2].y = 938.0f;

    this->unk_218[3].x = 921.0f;
    this->unk_218[3].y = 0.0f;

    this->unk_218[4].x = 758.0f;
    this->unk_218[4].y = 800.0f;

    this->unk_218[5].x = 758.0f;
    this->unk_218[5].y = -800.0f;

    Collider_InitQuad(play, &this->colliderQuad);
    Collider_SetQuad(play, &this->colliderQuad, &this->actor, &sQuadInit);
    Collider_InitCylinder(play, &this->colliderCylinder);
    Collider_SetCylinder(play, &this->colliderCylinder, &this->actor, &sCylinderInit);
    this->actor.world.rot.x = this->actor.shape.rot.x = 0;
}
