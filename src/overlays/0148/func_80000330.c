// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_InitFlame(EnHonotrap* this, PlayState* play) {
    s32 pad[2];
    s32 params = this->actor.params;

    Actor_SetScale(&this->actor, 0.0001f);
    Collider_InitCylinder(play, &this->collider.cyl);
    Collider_SetCylinder(play, &this->collider.cyl, &this->actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->actor, &this->collider.cyl);
    this->actor.terminalVelocity = -1.0f;
    CollisionCheck_SetInfo(&this->actor.colChkInfo, NULL, &sColChkInfoInit);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
    this->actor.shape.shadowAlpha = 128;
    this->targetPos = GET_PLAYER(play)->actor.world.pos;
    this->targetPos.y += 10.0f;
    this->flameScroll = Rand_ZeroOne() * 511.0f;
    Actor_PlaySfx(&this->actor, NA_SE_EV_FLAME_IGNITION);
    if (params == HONOTRAP_TYPE_FLAME_DROP) {
        this->actor.room = -1;
        this->collider.cyl.dim.radius = 12;
        this->collider.cyl.dim.height = 30;
        this->actor.shape.yOffset = -1000.0f;
    }
    EnHonotrap_SetupFlameGrow(this);
}
