// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void ref_func_80A59C04(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnWaterEffect* this = (EnWaterEffect*)thisx;
    s16 i;
    s16 j;
    f32 temp_f0_2;
    Player* player = GET_PLAYER(play);
    Vec3f sp90;
    Actor* rotaryRoom = play->actorCtx.actorLists[ACTORCAT_BG].first;
    CollisionPoly* sp88;
    EnWaterEffectStruct* ptr = &this->unk_144[0];
    u8 phi_s5;
    Vec3f sp74;

    while (rotaryRoom != NULL) {
        if (rotaryRoom->id == ACTOR_BG_IKANA_ROTARYROOM) {
            break;
        }
        rotaryRoom = rotaryRoom->next;
    }

    if (this->unk_DC6 != 0) {
        this->unk_DC6--;
    }

    if ((rotaryRoom != NULL) && Flags_GetSwitch(play, BGIKANAROTARYROOM_GET_SWITCH_FLAG_1(rotaryRoom))) {
        this->unk_DC6 = Rand_ZeroFloat(150.0f) + 100.0f;
    } else if (!Play_InCsMode(play)) {
        this->unk_DC4++;
        if (this->unk_DC6 == 0) {
            this->unk_DC6 = Rand_ZeroFloat(150.0f) + 100.0f;
            Actor_UpdateBgCheckInfo(play, &this->actor, 20.0f, 10.0f, 40.0f, UPDBGCHECKINFO_FLAG_4);
            sp74.x = Rand_CenteredFloat(50.0f) + this->actor.world.pos.x;
            sp74.y = this->actor.world.pos.y;
            sp74.z = Rand_CenteredFloat(50.0f) + this->actor.world.pos.z;
            ref_func_80A599E8(this, &sp74, 0);
        }
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_144); i++, ptr++) {
        phi_s5 = false;

        if (ptr->unk_00 != 0) {
            ptr->unk_01++;

            ptr->unk_04.x += ptr->unk_10.x;
            ptr->unk_04.y += ptr->unk_10.y;
            ptr->unk_04.z += ptr->unk_10.z;
            ptr->unk_10.y += ptr->unk_1C.y;

            if (ptr->unk_00 == 4) {
                if (ptr->unk_2A > 0) {
                    if (ptr->unk_2A == 1) {
                        Math_ApproachF(&ptr->unk_2C.x, 0.001f, 0.5f, 0.0002f);
                    }

                    if (ptr->unk_2A & 1) {
                        Math_ApproachZeroF(&ptr->unk_38, 1.0f, 30.0f);
                        if (ptr->unk_2A == 1) {
                            ptr->unk_3C -= 20;
                        } else {
                            ptr->unk_3C -= 10;
                        }
                        if (ptr->unk_3C <= 0) {
                            ptr->unk_00 = 0;
                        }
                        Math_ApproachZeroF(&ptr->unk_10.x, 1.0f, 1.0f);
                        Math_ApproachZeroF(&ptr->unk_10.z, 1.0f, 1.0f);
                    }
                }

                if ((ptr->unk_2A % 2) == 0) {
                    if (ptr->unk_2A == 0) {
                        ref_func_80A599E8(this, &ptr->unk_04, 1);
                    } else if ((ptr->unk_01 & 1) == 0) {
                        ref_func_80A599E8(this, &ptr->unk_04, 3);
                    }

                    if (ptr->unk_10.y < -20.0f) {
                        ptr->unk_10.y = -20.0f;
                    }

                    ptr->unk_28 += 0x800;
                    if ((fabsf(ptr->unk_04.x - player->actor.world.pos.x) < 20.0f) &&
                        (fabsf(ptr->unk_04.z - player->actor.world.pos.z) < 20.0f) &&
                        (fabsf(ptr->unk_04.y - (player->actor.world.pos.y + 25.0f)) < 30.0f)) {
                        phi_s5 = true;
                        if ((player->transformation != PLAYER_FORM_GORON) && !player->bodyIsBurning) {
                            ref_func_800B8D50(play, &this->actor, 2.0f, Rand_ZeroFloat(0x10000), 0.0f, 0x10);
                            for (j = 0; j < ARRAY_COUNT(player->bodyFlameTimers); j++) {
                                player->bodyFlameTimers[j] = Rand_S16Offset(0, 200);
                            }
                            player->bodyIsBurning = true;
                            Player_PlaySfx(player, player->ageProperties->voiceSfxIdOffset + NA_SE_VO_LI_DEMO_DAMAGE);
                        }
                    }

                    Math_Vec3f_Copy(&sp90, &ptr->unk_04);
                    sp90.y += 30.0f;

                    temp_f0_2 = BgCheck_EntityRaycastFloor1(&play->colCtx, &sp88, &sp90);
                    if (fabsf(temp_f0_2 - this->actor.floorHeight) > 200.0f) {
                        phi_s5 = true;
                    }

                    if ((ptr->unk_04.y <= temp_f0_2) || (phi_s5 != 0)) {
                        if (phi_s5 == 0) {
                            ptr->unk_04.y = temp_f0_2;
                        }
                        ptr->unk_10.y = 0.0f;
                        ptr->unk_1C.y = 0.0f;
                        if (ptr->unk_2A == 0) {
                            for (j = 0; j < 5; j++) {
                                ref_func_80A599E8(this, &ptr->unk_04, 2);
                            }
                            SoundSource_PlaySfxAtFixedWorldPos(play, &ptr->unk_04, 30, NA_SE_EV_PLANT_BROKEN);
                        }
                        ptr->unk_2A++;
                    }
                }
            }
        }
    }
}
