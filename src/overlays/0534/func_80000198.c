// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ref_func_80B9C5E8(ObjHunsui* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 temp_f10;
    f32 temp_f16;
    Vec3f sp40;
    s16 sp3E;
    f32 sp38;
    f32 sp34;

    if ((this->dyna.actor.xzDistToPlayer < (45.0f * this->dyna.actor.scale.x * 10.0f)) &&
        (this->dyna.actor.playerHeightRel < -21.0f)) {
        if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
            this->unk_172 &= ~8;
            this->unk_19C = 0.0f;
            this->unk_1A0 = 0.0f;

            this->unk_18C++;
            if (this->unk_18C >= 3) {
                this->unk_18C = 0;
                Math_Vec3f_Copy(&sp40, &player->actor.world.pos);

                sp40.x += Rand_CenteredFloat(10.0f);
                sp40.z += Rand_CenteredFloat(10.0f);
                sp40.y += Rand_ZeroFloat(2.0f);

                EffectSsGSplash_Spawn(play, &sp40, NULL, NULL, 2.0f * Rand_ZeroOne(), 1);
            }
        } else {
            this->unk_172 |= 8;

            this->unk_18C++;
            if (this->unk_18C >= 3) {
                Math_Vec3f_Copy(&sp40, &player->actor.world.pos);
                this->unk_18C = 0;

                sp40.x += Rand_CenteredFloat(10.0f);
                sp40.z += Rand_CenteredFloat(10.0f);
                sp40.y += Rand_ZeroFloat(45.0f);

                EffectSsGSplash_Spawn(play, &sp40, NULL, NULL, 1, 1);
            }

            sp3E = BINANG_ROT180(player->actor.world.rot.y - this->dyna.actor.yawTowardsPlayer);
            player->actor.gravity = 0.0f;
            player->actor.velocity.y = 0.0f;

            if ((this->unk_160 != OBJHUNSUI_F000_5) && (this->unk_160 != OBJHUNSUI_F000_6)) {
                Math_SmoothStepToF(&player->actor.world.pos.y, this->dyna.actor.world.pos.y, 0.5f, 4.0f, 1.0f);
            }

            if ((sp3E < 0x4000) && (sp3E > -0x4000)) {
                this->unk_1A4 = BINANG_ROT180(player->actor.world.rot.y);
                sp34 = this->dyna.actor.xzDistToPlayer / (45.0f * this->dyna.actor.scale.x * 10.0f);
                if (1) {}
                sp38 = this->dyna.actor.xzDistToPlayer / (45.0f * this->dyna.actor.scale.x * 10.0f);

                if (sp38 > 1.0f) {
                    sp38 = sp34;
                }

                player->speedXZ *= sp38;

                if ((this->unk_160 == OBJHUNSUI_F000_5) || (this->unk_160 == OBJHUNSUI_F000_6)) {
                    Math_ApproachF(&this->unk_1A0, 4.5f, 2.0f, 1.0f);
                    Math_ApproachF(&this->unk_19C, this->unk_1A0, 2.0f, 0.3f * sp38);
                } else {
                    Math_ApproachF(&this->unk_1A0, 3.0f, 1.0f, 1.0f);
                    Math_ApproachF(&this->unk_19C, this->unk_1A0, 1.0f, 0.3f * sp38);
                }
            } else {
                this->unk_1A4 = player->actor.world.rot.y;
                player->speedXZ *= 0.5f;
                Math_ApproachF(&this->unk_1A0, 3.0f, 1.0f, 1.0f);
                Math_ApproachF(&this->unk_19C, this->unk_1A0, 1.0f, 0.1f);
            }
            player->pushedYaw = this->unk_1A4;
            player->pushedSpeed = this->unk_19C;
        }
    } else {
        if (this->unk_172 & 8) {
            player->speedXZ = this->unk_19C + player->speedXZ;
            player->yaw = this->unk_1A4;
        }
        this->unk_1A0 = 0.0f;
        this->unk_19C = 0.0f;
        this->unk_172 &= ~8;
    }
}
