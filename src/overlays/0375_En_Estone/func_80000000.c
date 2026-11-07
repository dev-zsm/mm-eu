// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_estone.h"

void EnEstone_Init(Actor* thisx, PlayState* play) {
    EnEstone* this = (EnEstone*)thisx;
    Vec3f accel;
    Vec3f velocity;
    f32 scale;
    s32 i;
    s32 pad;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 15.0f);
    this->rotVel.x = this->rotVel.y = this->rotVel.z = Rand_CenteredFloat(1.0f) * 20.0f;
    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->actor.world.rot.y += TRUNCF_BINANG(Rand_CenteredFloat(0x2710));
    this->actor.shape.rot.y = this->actor.world.rot.y;

    if (this->actor.params == ENESTONE_TYPE_LARGE) {
        this->actor.speed = Rand_ZeroFloat(5.0f) + 2.0f;
        this->scale = (Rand_ZeroFloat(1.0f) * 0.005f) + 0.005f;
        this->actor.velocity.y = Rand_ZeroFloat(10.0f) + 15.0f;
        this->actor.gravity = -2.0f;
    } else { 
        this->actor.speed = Rand_ZeroFloat(3.0f) + 1.0f;
        this->scale = (Rand_ZeroFloat(1.0f) * 0.003f) + 0.003f;
        this->actor.velocity.y = Rand_ZeroFloat(5.0f) + 7.0f;
        this->actor.gravity = -1.0f;
    }

    this->collider.dim.radius = this->scale * 3000.0f;
    this->collider.dim.height = this->scale * 3000.0f;
    this->collider.dim.yShift = this->scale * -1300.0f;

    for (i = 0; i < 7; i++) {
        accel.x = 0.5f * (Rand_ZeroOne() - 0.5f);
        accel.y = -1.0f;
        accel.z = 0.5f * (Rand_ZeroOne() - 0.5f);

        velocity.x = 2.0f * (Rand_ZeroOne() - 0.5f);
        velocity.y = 8.0f + (Rand_ZeroOne() * 10.0f);
        velocity.z = 2.0f * (Rand_ZeroOne() - 0.5f);

        scale = (Rand_ZeroFloat(1.0f) * 0.001f) + 0.001f;

        EnEstone_SpawnEffect(this, &this->actor.world.pos, &velocity, &accel, scale, 70);
    }
    this->timer = 5;
    this->inactive = false;
    Actor_SetScale(&this->actor, 1.0f);
    this->actionFunc = EnEstone_Active;
}
