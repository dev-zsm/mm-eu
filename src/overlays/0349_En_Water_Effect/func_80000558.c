// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void EnWaterEffect_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnWaterEffect* this = (EnWaterEffect*)thisx;
    Player* player = GET_PLAYER(play);
    EnWaterEffectStruct* ptr = &this->unk_144[0];
    s16 i;
    s16 j;
    s32 phi_v0;
    Vec3f spA4;
    Vec3f sp98;
    u8 phi_v1;
    Vec3f sp88;

    if (!Flags_GetSwitch(play, this->actor.params)) {
        this->unk_DC4++;
        if ((this->unk_DC4 % 32) == 0) {
            if (Rand_ZeroOne() < 0.5f) {
                Actor_UpdateBgCheckInfo(play, &this->actor, 20.0f, 10.0f, 40.0f, UPDBGCHECKINFO_FLAG_4);
                sp88.x = Rand_CenteredFloat(50.0f) + this->actor.world.pos.x;
                sp88.y = this->actor.world.pos.y;
                sp88.z = Rand_CenteredFloat(50.0f) + this->actor.world.pos.z;
                if ((this->actor.world.pos.y + this->actor.depthInWater) <= this->actor.floorHeight) {
                    phi_v1 = 0;
                } else {
                    phi_v1 = 1;
                    this->actor.floorHeight = this->actor.world.pos.y + this->actor.depthInWater;
                }
                ref_func_80A587A0(this, &sp88, phi_v1);
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_144) / 2; i++, ptr++) {
        if (ptr->unk_00 != 0) {
            ptr->unk_01++;

            ptr->unk_04.x += ptr->unk_10.x;
            ptr->unk_04.y += ptr->unk_10.y;
            ptr->unk_04.z += ptr->unk_10.z;
            ptr->unk_10.y += ptr->unk_1C.y;

            Math_ApproachF(&ptr->unk_38, (ptr->unk_01 & 6) ? 80.0f : 200.0f, 1.0f, 80);

            if (ptr->unk_00 == 1) {
                ptr->unk_2C.z += 0.15f;
                Math_ApproachF(&ptr->unk_2C.x, 0.03f, 0.5f, 0.005f);
                Math_ApproachF(&ptr->unk_2C.y, 0.5f, 0.5f, 0.02f);

                if (ptr->unk_2C.y > 0.15f) {
                    ptr->unk_1C.y = -1.0f;
                    if (ptr->unk_10.y < -20.0f) {
                        ptr->unk_10.y = -20.0f;
                    }
                }

                if ((fabsf(ptr->unk_04.x - player->actor.world.pos.x) < 15.0f) &&
                    (fabsf(ptr->unk_04.z - player->actor.world.pos.z) < 15.0f) &&
                    (player->actor.world.pos.y < ptr->unk_04.y) &&
                    ((ptr->unk_04.y - player->actor.world.pos.y) < 40.0f)) {
                    phi_v0 = true;
                } else {
                    phi_v0 = false;
                }

                if ((ptr->unk_04.y <= this->actor.floorHeight) || phi_v0) {

                    if (phi_v0) {
                        ptr->unk_00 = 0;
                        SoundSource_PlaySfxAtFixedWorldPos(play, &ptr->unk_04, 30, NA_SE_EV_BOMB_DROP_WATER);
                    } else {
                        ptr->unk_04.y = this->actor.floorHeight;
                        if (ptr->unk_2A == 0) {
                            SoundSource_PlaySfxAtFixedWorldPos(play, &ptr->unk_04, 30, NA_SE_EV_WATERDROP_GRD);
                            ptr->unk_00 = 3;
                            ptr->unk_2C.x = 0.1f;
                            ptr->unk_2C.y = 0.6f;
                            ptr->unk_10 = sZeroVec;
                            ptr->unk_1C = sZeroVec;
                            ptr->unk_3C = 200;
                            ptr->unk_28 = 9;
                            Math_Vec3f_Copy(&sp98, &ptr->unk_04);
                            sp98.y += 3.0f;
                            EffectSsGSplash_Spawn(play, &sp98, NULL, NULL, 1, 100);
                        } else {
                            ptr->unk_00 = 0;
                            SoundSource_PlaySfxAtFixedWorldPos(play, &ptr->unk_04, 30, NA_SE_EV_WATERDROP);
                            EffectSsGRipple_Spawn(play, &ptr->unk_04, 70, 500, 0);
                            EffectSsGRipple_Spawn(play, &ptr->unk_04, 70, 500, 10);
                            Math_Vec3f_Copy(&sp98, &ptr->unk_04);
                            sp98.y += 10.0f;
                            EffectSsGSplash_Spawn(play, &sp98, NULL, NULL, 1, 300);
                        }
                    }

                    for (j = 0; j < 12; j++) {
                        Matrix_RotateYF((2.0f * (j * M_PIf)) / 5.5f, MTXMODE_NEW);
                        Matrix_MultVecZ(Rand_ZeroFloat(1.5f) + 1.5f, &spA4);
                        spA4.y = Rand_ZeroFloat(4.0f) + 2.0f;
                        ref_func_80A58908(this, &ptr->unk_04, &spA4, ptr->unk_2A);
                    }
                }
            } else if (ptr->unk_00 == 2) {
                ptr->unk_2C.z += 0.15f;
                if (ptr->unk_10.y < -8.0f) {
                    ptr->unk_10.y = -8.0f;
                }

                if (ptr->unk_10.y < 0.0f) {
                    if (ptr->unk_04.y <= this->actor.floorHeight) {
                        ptr->unk_04.y = this->actor.floorHeight;
                        if (ptr->unk_2A == 0) {
                            ptr->unk_00 = 3;
                            ptr->unk_2C.x = 0.05f;
                            ptr->unk_2C.y = 0.2f;
                            ptr->unk_10 = sZeroVec;
                            ptr->unk_1C = sZeroVec;
                            ptr->unk_3C = 150;
                            ptr->unk_28 = Rand_ZeroFloat(5.0f) + 7.0f;
                        } else {
                            EffectSsGRipple_Spawn(play, &ptr->unk_04, 0, 200, 0);
                            ptr->unk_00 = 0;
                        }
                    }
                }
            } else if (ptr->unk_00 == 3) {
                Math_ApproachF(&ptr->unk_2C.x, ptr->unk_2C.y, 0.1f, 0.6f);
                ptr->unk_3C -= ptr->unk_28;
                if (ptr->unk_3C <= 0) {
                    ptr->unk_3C = 0;
                    ptr->unk_00 = 0;
                }
            }
        }
    }
}
