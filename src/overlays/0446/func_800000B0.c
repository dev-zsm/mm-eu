// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_snowwd.h"

void EnSnowwd_Idle(EnSnowwd* this, PlayState* play) {
    static Vec3f sAccel = { 0.0f, 0.0f, 0.0f };
    static Vec3f sVelocity = { 0.0f, -4.0f, 0.0f };
    static Color_RGBA8 sPrimColor = { 255, 255, 255, 255 };
    static Color_RGBA8 sEnvColor = { 200, 200, 220, 0 };
    s32 pad;
    Actor* thisx = &this->actor;
    f32 wobbleAmplitude;
    Vec3f pos;

    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;
        Actor_PlaySfx(thisx, NA_SE_IT_REFLECTION_WOOD);
    }
    if (thisx->home.rot.y != 0) {
        this->timer = 21;
        thisx->home.rot.y = 0;
        if (!SNOWWD_DROPPED_COLLECTIBLE(&this->actor)) {
            if (SNOWWD_GET_DROP_TABLE(&this->actor) < 16) {
                pos = thisx->world.pos;
                pos.y += 200.0f;
                Item_DropCollectibleRandom(play, NULL, &pos, SNOWWD_GET_DROP_TABLE(&this->actor) * DROP_TABLE_SIZE);
            }
            SNOWWD_DROPPED_COLLECTIBLE(&this->actor) = true;
        }
    }
    if (thisx->xzDistToPlayer < 600.0f) {
        Collider_UpdateCylinder(thisx, &this->collider);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }

    
    if (this->timer > 0) {
        this->timer--;
        wobbleAmplitude = Math_SinS((this->timer ^ 0xFFFF) * 0x3332) * 250.0f;
        thisx->shape.rot.x = Math_CosS(thisx->yawTowardsPlayer - thisx->shape.rot.y) * wobbleAmplitude;
        thisx->shape.rot.z = Math_SinS(thisx->yawTowardsPlayer - thisx->shape.rot.y) * wobbleAmplitude;
        pos = thisx->world.pos;
        pos.x += Rand_CenteredFloat(80.0f);
        pos.y += 100.0f + Rand_ZeroFloat(30.0f);
        pos.z += Rand_CenteredFloat(80.0f);
        ref_func_800B0EB0(play, &pos, &sVelocity, &sAccel, &sPrimColor, &sEnvColor, 200, 10, 20);
    }
}
