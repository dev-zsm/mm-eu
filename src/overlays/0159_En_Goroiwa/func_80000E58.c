// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

s32 ref_func_8093F6F8(EnGoroiwa* this, PlayState* play) {
    f32 temp_f14;
    Vec3s* sp80 = &this->pathPoints[this->unk_1D8];
    f32 sp7C = sp80->y;
    f32 sp78;
    f32 temp_f2;

    Math_StepToF(&this->actor.velocity.y, -18.367346f, 1.0f);
    this->actor.velocity.y *= 0.98f;
    this->actor.world.pos.x = sp80->x;
    this->actor.world.pos.z = sp80->z;
    sp78 = this->actor.world.pos.y;
    this->actor.world.pos.y += this->actor.velocity.y;

    if ((this->actor.velocity.y < 0.0f) && (this->actor.world.pos.y <= sp7C)) {
        if (this->unk_1CA == 0) {
            if (this->actor.xzDistToPlayer < 400.0f) {
                s16 quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);

                Quake_SetSpeed(quakeIndex, 17232);
                Quake_SetPerturbations(quakeIndex, 3, 0, 0, 0);
                Quake_SetDuration(quakeIndex, 7);
            }

            this->unk_1C4 = 0.0f;

            if (!(this->unk_1E5 & 0x20)) {
                CollisionPoly* poly;
                Vec3f sp60;
                s32 pad[2];
                s32 bgId;
                Vec3f sp48;

                sp60.x = this->actor.world.pos.x;
                sp60.y = this->actor.world.pos.y + 50.0f;
                sp60.z = this->actor.world.pos.z;

                temp_f14 = BgCheck_EntityRaycastFloor5_2(play, &play->colCtx, &poly, &bgId, &this->actor, &sp60);
                temp_f2 = temp_f14 - this->actor.world.pos.y;

                if (fabsf(temp_f2) < (fabsf(this->actor.velocity.y) + 0.01f)) {
                    if (this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
                        sp48.x = this->actor.world.pos.x;
                        sp48.y = temp_f14 + 10.0f;
                        sp48.z = this->actor.world.pos.z;

                        ref_func_8093EF54(play, &sp48, &ref_D_80942E30[ENGOROIWA_GET_C000(&this->actor)],
                                      &ref_D_80942E3C[ENGOROIWA_GET_C000(&this->actor)], this->actor.scale.x);
                    }
                    Actor_PlaySfx(&this->actor, NA_SE_EV_BIGBALL_BOUND);
                }
            }
        }

        if (this->unk_1CA > 0) {
            this->unk_1E5 |= 0x40;
            return true;
        }

        this->unk_1CA++;
        this->actor.velocity.y *= -0.3f;
        this->actor.world.pos.y = sp7C - ((this->actor.world.pos.y - sp7C) * 0.3f);
    }

    if (this->unk_1CA == 0) {
        WaterBox* waterBox;
        f32 waterSurface;

        if (BgCheck_GetWaterSurfaceNoBgId(play, &play->colCtx, this->actor.world.pos.x, this->actor.world.pos.z,
                                          &waterSurface, &waterBox)) {
            if ((this->actor.world.pos.y + this->unk_1DC) <= waterSurface) {
                this->unk_1E5 |= 0x20;
                if (waterSurface < (this->unk_1DC + sp78)) {
                    if (this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
                        Vec3f sp34;

                        sp34.x = this->actor.world.pos.x;
                        sp34.y = waterSurface;
                        sp34.z = this->actor.world.pos.z;
                        ref_func_8093F198(play, &sp34, this->actor.scale.x);
                    }
                    this->actor.velocity.y *= 0.2f;
                }

                if (this->actor.velocity.y < -8.0f) {
                    this->actor.velocity.y = -8.0f;
                }
            }
        }
    }

    this->unk_1E5 &= ~0x40;
    return false;
}
