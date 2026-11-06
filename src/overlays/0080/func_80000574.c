// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

void EnBubble_Fly(EnBubble* this, PlayState* play) {
    CollisionPoly* poly;
    Actor* bumpActor;
    Vec3f sp84;
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f normal;
    Vec3f bounceDirection;
    f32 bounceSpeed;
    s32 bgId;
    u8 bounceCount;

    if (this->colliderSphere.elements[1].base.acElemFlags & ACELEM_HIT) {
        bumpActor = this->colliderSphere.base.ac;
        this->normalizedBumpVelocity = bumpActor->velocity;
        EnBubble_Vec3fNormalize(&this->normalizedBumpVelocity);
        this->velocityFromBump.x += this->normalizedBumpVelocity.x * 3.0f;
        this->velocityFromBump.y += this->normalizedBumpVelocity.y * 3.0f;
        this->velocityFromBump.z += this->normalizedBumpVelocity.z * 3.0f;
    }
    this->yVelocity -= 0.1f;
    if (this->yVelocity < this->actor.terminalVelocity) {
        this->yVelocity = this->actor.terminalVelocity;
    }
    bounceDirection.x = this->velocityFromBounce.x + this->velocityFromBump.x;
    bounceDirection.y = this->velocityFromBounce.y + this->velocityFromBump.y + this->yVelocity;
    bounceDirection.z = this->velocityFromBounce.z + this->velocityFromBump.z;
    EnBubble_Vec3fNormalize(&bounceDirection);

    sp78.x = this->actor.world.pos.x;
    sp78.y = this->actor.world.pos.y + this->actor.shape.yOffset;
    sp78.z = this->actor.world.pos.z;
    sp6C = sp78;

    sp6C.x += (bounceDirection.x * 24.0f);
    sp6C.y += (bounceDirection.y * 24.0f);
    sp6C.z += (bounceDirection.z * 24.0f);
    if (BgCheck_EntityLineTest1(&play->colCtx, &sp78, &sp6C, &sp84, &poly, true, true, true, false, &bgId)) {
        normal.x = COLPOLY_GET_NORMAL(poly->normal.x);
        normal.y = COLPOLY_GET_NORMAL(poly->normal.y);
        normal.z = COLPOLY_GET_NORMAL(poly->normal.z);
        EnBubble_Vec3fNormalizedReflect(&bounceDirection, &normal, &bounceDirection);
        this->bounceDirection = bounceDirection;
        bounceCount = this->bounceCount;
        this->bounceCount = ++bounceCount;
        if (bounceCount > TRUNCF_BINANG(Rand_ZeroOne() * 10.0f)) {
            this->bounceCount = 0;
        }
        bounceSpeed = (this->bounceCount == 0) ? 3.6000001f : 3.0f;
        this->velocityFromBump.x = this->velocityFromBump.y = this->velocityFromBump.z = 0.0f;
        this->velocityFromBounce.x = this->bounceDirection.x * bounceSpeed;
        this->velocityFromBounce.y = this->bounceDirection.y * bounceSpeed;
        this->velocityFromBounce.z = this->bounceDirection.z * bounceSpeed;
        this->yVelocity = 0.0f;
        Actor_PlaySfx(&this->actor, NA_SE_EN_AWA_BOUND);
        this->modelRotSpeed = 128.0f;
        this->modelEllipticity = 0.48f;
    } else if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER) && (bounceDirection.y < 0.0f)) {
        normal.x = normal.z = 0.0f;
        normal.y = 1.0f;
        EnBubble_Vec3fNormalizedReflect(&bounceDirection, &normal, &bounceDirection);
        this->bounceDirection = bounceDirection;
        bounceCount = this->bounceCount;
        this->bounceCount = ++bounceCount;
        if (bounceCount > TRUNCF_BINANG(Rand_ZeroOne() * 10.0f)) {
            this->bounceCount = 0;
        }
        bounceSpeed = (this->bounceCount == 0) ? 3.6000001f : 3.0f;
        this->velocityFromBump.x = this->velocityFromBump.y = this->velocityFromBump.z = 0.0f;
        this->velocityFromBounce.x = (this->bounceDirection.x * bounceSpeed);
        this->velocityFromBounce.y = (this->bounceDirection.y * bounceSpeed);
        this->velocityFromBounce.z = (this->bounceDirection.z * bounceSpeed);
        this->yVelocity = 0.0f;
        Actor_PlaySfx(&this->actor, NA_SE_EN_AWA_BOUND);
        this->modelRotSpeed = 128.0f;
        this->modelEllipticity = 0.48f;
    }
    this->actor.velocity.x = this->velocityFromBounce.x + this->velocityFromBump.x;
    this->actor.velocity.y = this->velocityFromBounce.y + this->velocityFromBump.y + this->yVelocity;
    this->actor.velocity.z = this->velocityFromBounce.z + this->velocityFromBump.z;
    Math_ApproachF(&this->velocityFromBump.x, 0.0f, 0.3f, 0.1f);
    Math_ApproachF(&this->velocityFromBump.y, 0.0f, 0.3f, 0.1f);
    Math_ApproachF(&this->velocityFromBump.z, 0.0f, 0.3f, 0.1f);
}
