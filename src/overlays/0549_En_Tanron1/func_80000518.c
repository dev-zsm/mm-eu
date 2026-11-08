// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tanron1.h"

void ref_func_80BB5318(EnTanron1* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    EnTanron1Struct* ptr = NULL;
    f32 phi_f28 = 0.0f;
    Vec3f* phi_s2 = NULL;
    Vec3f temp;
    s16 spBA = 0;
    s16 spB8 = 0;
    Vec3f* spB4 = NULL;
    f32 spB0;
    Vec3f spA4;
    WaterBox* waterBox;
    f32 sp9C;
    CollisionPoly* sp98;
    Actor* temp_v0;
    s16 i;
    f32 temp_f30 = this->unk_15C;

    if (player->unk_ADC != 0) {
        phi_s2 = &player->meleeWeaponInfo[0].tip;
        if (player->meleeWeaponAnimation >= PLAYER_MWA_SPIN_ATTACK_1H) {
            phi_f28 = 2500.0f;
        } else {
            phi_f28 = 400.0f;
        }
    }

    temp_v0 = play->actorCtx.actorLists[ACTORCAT_EXPLOSIVES].first;
    while (temp_v0 != NULL) {
        if (temp_v0->params != 1) {
            temp_v0 = temp_v0->next;
            continue;
        }
        phi_s2 = &temp_v0->world.pos;
        phi_f28 = 40000.0f;
        break;
    }

    ptr = &this->unk_160[0];
    for (i = 0; i < this->actor.params; i++, ptr++) {
        if (ptr->unk_24 != 0) {
            ptr->unk_26++;
            ptr->unk_00.x += ptr->unk_0C.x;
            ptr->unk_00.y += ptr->unk_0C.y;
            ptr->unk_00.z += ptr->unk_0C.z;

            if (ptr->unk_24 == 0) {
            } else {
                spB4 = &ptr->unk_00;
                if (ptr->unk_28 == 0) {
                    spBA++;
                    ptr->unk_2C = Math_SinS(ptr->unk_26 * 0x5000) * 1.2f;
                    if ((ptr->unk_26 & 3) == 0) {
                        temp.x = ptr->unk_30 + (this->unk_14C.x - ptr->unk_00.x);
                        temp.y = ptr->unk_34 + (this->unk_14C.y - ptr->unk_00.y);
                        temp.z = ptr->unk_38 + (this->unk_14C.z - ptr->unk_00.z);

                        ptr->unk_20 = Math_Atan2S(temp.x, temp.z);
                        ptr->unk_1E = Math_Atan2S(temp.y, sqrtf(SQXZ(temp)));
                        if ((ptr->unk_26 & 0xF) == 0) {
                            ptr->unk_30 = Rand_CenteredFloat(temp_f30);
                            ptr->unk_34 = Rand_CenteredFloat(temp_f30 * 0.5f);
                            ptr->unk_38 = Rand_CenteredFloat(temp_f30);
                        }

                        temp.x = player->actor.world.pos.x - ptr->unk_00.x;
                        temp.y = (player->actor.world.pos.y + 40.0f) - ptr->unk_00.y;
                        temp.z = player->actor.world.pos.z - ptr->unk_00.z;

                        if ((SQXYZ(temp) < 400.0f) && (player->transformation != PLAYER_FORM_DEKU)) {
                            ref_func_800B8D10(play, &this->actor, 0.0f, 0, 0.0f, 1, 1);
                        }
                    }

                    Math_ApproachS(&ptr->unk_1A, ptr->unk_20, 2, this->unk_158);
                    Math_ApproachS(&ptr->unk_18, ptr->unk_1E, 2, this->unk_158);
                    Matrix_RotateYS(ptr->unk_1A, MTXMODE_NEW);
                    Matrix_RotateXS(-ptr->unk_18, MTXMODE_APPLY);
                    Matrix_MultVecZ(6.0f, &ptr->unk_0C);

                    if (phi_s2 != NULL) {
                        temp.x = phi_s2->x - ptr->unk_00.x;
                        temp.y = phi_s2->y - ptr->unk_00.y;
                        temp.z = phi_s2->z - ptr->unk_00.z;

                        if (SQXYZ(temp) < phi_f28) {
                            ptr->unk_20 = Math_Atan2S(temp.x, temp.z);
                            ptr->unk_1E = Math_Atan2S(temp.y, sqrtf(SQXZ(temp)));

                            Matrix_RotateYS(ptr->unk_20, MTXMODE_NEW);
                            Matrix_RotateXS(-ptr->unk_1E, MTXMODE_APPLY);
                            Matrix_MultVecZ(-20.0f, &ptr->unk_0C);

                            if (phi_f28 >= 100000.0f) {
                                ptr->unk_28 = 1;
                            } else {
                                ptr->unk_28 = 6;
                            }
                            ptr->unk_24 = 2;
                            spB8++;
                        }
                    }
                } else if (ptr->unk_28 < 9) {
                    ptr->unk_18 += 0x3000;
                    ptr->unk_1A += 0x5000;
                    ptr->unk_30 = 0.0f;
                    ptr->unk_34 = 0.0f;
                    ptr->unk_28++;
                } else {
                    ptr->unk_1A += ptr->unk_2A;
                    Math_ApproachS(&ptr->unk_18, 0, 0xA, 0x1000);
                    Matrix_RotateYS(ptr->unk_1A, MTXMODE_NEW);
                    Matrix_MultVecZ(ptr->unk_30, &spA4);

                    ptr->unk_0C.x = spA4.x;
                    ptr->unk_0C.z = spA4.z;
                    ptr->unk_0C.y = -2.0f;

                    if (phi_s2 != NULL) {
                        temp.x = phi_s2->x - ptr->unk_00.x;
                        temp.y = phi_s2->y - ptr->unk_00.y;
                        temp.z = phi_s2->z - ptr->unk_00.z;

                        if (SQXYZ(temp) < phi_f28) {
                            ptr->unk_20 = Math_Atan2S(temp.x, temp.z);
                            ptr->unk_1E = Math_Atan2S(temp.y, sqrtf(SQXZ(temp)));

                            Matrix_RotateYS(ptr->unk_20, MTXMODE_NEW);
                            Matrix_RotateXS(-ptr->unk_1E, MTXMODE_APPLY);
                            Matrix_MultVecZ(-20.0f, &ptr->unk_0C);

                            ptr->unk_3C = ptr->unk_00.y - 1000.0f;
                            ptr->unk_30 = 5.0f;
                        }
                    }

                    if (ptr->unk_00.y <= (ptr->unk_3C + 5.0f)) {
                        ptr->unk_00.y = (ptr->unk_3C + 5.0f);
                        Math_ApproachZeroF(&ptr->unk_30, 1.0f, 0.3f);
                        Math_ApproachS(&ptr->unk_2A, 0, 1, 0x100);
                        ptr->unk_28++;
                        if (ptr->unk_28 > 50) {
                            ptr->unk_24 = 0;
                        }
                    } else {
                        Math_ApproachF(&ptr->unk_30, ptr->unk_34, 1.0f, 0.5f);
                        if ((ptr->unk_26 & 0xF) == 0) {
                            if (Rand_ZeroOne() < 0.5f) {
                                ptr->unk_34 = Rand_CenteredFloat(12.0f);
                            }
                            ptr->unk_3C = BgCheck_EntityRaycastFloor1(&play->colCtx, &sp98, &ptr->unk_00);
                            sp9C = ptr->unk_00.y;
                            BgCheck_GetWaterSurfaceNoBgIdAlt(play, &play->colCtx, ptr->unk_00.x, ptr->unk_00.z, &sp9C,
                                                             &waterBox);
                            if ((sp9C < ptr->unk_00.y) && (ptr->unk_3C < sp9C)) {
                                ptr->unk_3C = sp9C;
                            }
                        }
                    }
                }
            }
        }
    }

    if (spB4 != NULL) {
        SkinMatrix_Vec3fMtxFMultXYZW(&play->viewProjectionMtxF, spB4, &this->unk_3360, &spB0);
        if (spB8 >= (s16)(KREG(39) + 20)) {
            Audio_PlaySfx_AtPos(&this->unk_3360, NA_SE_EN_MB_MOTH_DEAD);
        } else if (spBA >= 20) {
            Audio_PlaySfx_AtPos(&this->unk_3360, NA_SE_EN_MB_MOTH_FLY - SFX_FLAG);
        }
    }
}
