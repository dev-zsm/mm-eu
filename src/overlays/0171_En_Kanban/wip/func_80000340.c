// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKanban_Update), score 6.00 (6 differ, size +3)
#include "generated/mm/z_en_kanban.h"

void func_80000340(Actor* thisx, PlayState* play) {
    u8 bounced = false;
    EnKanban* this = (EnKanban*)thisx;
    s32 pad;
    FloorType floorType;
    f32 phi_f0;
    Player* player = GET_PLAYER(play);
    Vec3f offset;
    EnKanban* piece;
    EnKanban* signpost;

    this->frameCount++;

    switch (this->actionState) {
        case ENKANBAN_SIGN:
            if (this->invincibilityTimer != 0) {
                this->invincibilityTimer--;
            }

            if (this->zTargetTimer != 0) {
                this->zTargetTimer--;
            }

            if (DECR(this->unk_1A0) == 0) {
                this->unk_19C = NULL;
            }

            if (this->zTargetTimer == 1) {
                this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
            }

            if (this->partFlags == 0xFFFF) {
                ref_func_80954BE8(this, play);
            }

            if ((this->invincibilityTimer == 0) && (this->collider.base.acFlags & AC_HIT)) {
                this->collider.base.acFlags &= ~AC_HIT;
                if (this->unk_19C != this->collider.base.ac) {
                    this->unk_19C = this->collider.base.ac;
                    this->unk_1A0 = 3;
                    this->invincibilityTimer = 6;

                    piece = (EnKanban*)Actor_SpawnAsChild(
                        &play->actorCtx, &this->actor, play, ACTOR_EN_KANBAN, this->actor.world.pos.x,
                        this->actor.world.pos.y, this->actor.world.pos.z, this->actor.shape.rot.x,
                        this->actor.shape.rot.y, this->actor.shape.rot.z, ENKANBAN_PIECE);
                    if (piece != NULL) {
                        ColliderElement* acHitElem = this->collider.elem.acHitElem;
                        s16 yawDiff = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
                        u8 i;

                        if (acHitElem->atDmgInfo.dmgFlags & 0x200) {
                            this->cutType = sCutTypes[player->meleeWeaponAnimation];
                        } else if (acHitElem->atDmgInfo.dmgFlags & 0x10) {
                            this->invincibilityTimer = 0;
                            this->cutType = this->unk_19A + 3;
                            this->unk_19A = 1 - this->unk_19A;
                            if (this->unk_199 == 0) {
                                this->unk_199++;
                                Item_DropCollectibleRandom(play, NULL, &this->actor.focus.pos, 0x60);
                            }
                        } else {
                            this->cutType = 0;
                        }

                        if ((ABS_ALT(yawDiff) > 0x4000) && !(acHitElem->atDmgInfo.dmgFlags & 0x10)) {
                            if (this->cutType == 4) {
                                this->cutType = 3;
                            } else if (this->cutType == 1) {
                                this->cutType = 5;
                            }
                        }

                        piece->partFlags = sCutFlags[this->cutType] & this->partFlags;
                        if (piece->partFlags == 0) {
                            Actor_Kill(&piece->actor);
                            return;
                        }

                        piece->partCount = 0;
                        for (i = 0; i < 11; i++) {
                            if (sPartFlags[i] & piece->partFlags) {
                                piece->partCount++;
                            }
                        }

                        this->partFlags &= ~sCutFlags[this->cutType];
                        if ((this->partFlags & 0x3FF) == 0) {
                            this->zTargetTimer = 10;
                        }

                        if ((piece->partFlags & PART_UPPER_SIDE_LEFT) && (piece->partFlags & PART_LOWER_SIDE_RIGHT)) {
                            piece->pieceType = PIECE_WHOLE_SIGN;
                        } else if ((piece->partFlags & PART_LEFT_SIDE_UPPER) &&
                                   (piece->partFlags & PART_RIGHT_SIDE_UPPER)) {
                            piece->pieceType = PIECE_UPPER_HALF;
                        } else if ((piece->partFlags & PART_LEFT_SIDE_LOWER) &&
                                   (piece->partFlags & PART_RIGHT_SIDE_LOWER)) {
                            piece->pieceType = PIECE_LOWER_HALF;
                        } else if ((piece->partFlags & PART_UPPER_SIDE_RIGHT) &&
                                   (piece->partFlags & PART_LOWER_SIDE_RIGHT)) {
                            piece->pieceType = PIECE_RIGHT_HALF;
                        } else if ((piece->partFlags & PART_UPPER_SIDE_LEFT) &&
                                   (piece->partFlags & PART_LOWER_SIDE_LEFT)) {
                            piece->pieceType = PIECE_LEFT_HALF;
                        } else if ((piece->partFlags & PART_UPPER_SIDE_LEFT) &&
                                   (piece->partFlags & PART_LEFT_SIDE_UPPER)) {
                            piece->pieceType = PIECE_2ND_QUAD;
                        } else if ((piece->partFlags & PART_UPPER_SIDE_RIGHT) &&
                                   (piece->partFlags & PART_RIGHT_SIDE_UPPER)) {
                            piece->pieceType = PIECE_1ST_QUAD;
                        } else if ((piece->partFlags & PART_LEFT_SIDE_LOWER) &&
                                   (piece->partFlags & PART_LOWER_SIDE_LEFT)) {
                            piece->pieceType = PIECE_3RD_QUAD;
                        } else if ((piece->partFlags & PART_RIGHT_SIDE_LOWER) &&
                                   (piece->partFlags & PART_LOWER_SIDE_RIGHT)) {
                            piece->pieceType = PIECE_4TH_QUAD;
                        } else if (piece->partFlags & PART_UPPER_SIDE_LEFT) {
                            piece->pieceType = PIECE_UPPER_SIDE_LEFT;
                        } else if (piece->partFlags & PART_LEFT_SIDE_UPPER) {
                            piece->pieceType = PIECE_LEFT_SIDE_UPPER;
                        } else if (piece->partFlags & PART_LEFT_SIDE_LOWER) {
                            piece->pieceType = PIECE_LEFT_SIDE_LOWER;
                        } else if (piece->partFlags & PART_LOWER_SIDE_LEFT) {
                            piece->pieceType = PIECE_LOWER_SIDE_LEFT;
                        } else if (piece->partFlags & PART_UPPER_SIDE_RIGHT) {
                            piece->pieceType = PIECE_UPPER_SIDE_RIGHT;
                        } else if (piece->partFlags & PART_RIGHT_SIDE_UPPER) {
                            piece->pieceType = PIECE_RIGHT_SIDE_UPPER;
                        } else if (piece->partFlags & PART_RIGHT_SIDE_LOWER) {
                            piece->pieceType = PIECE_RIGHT_SIDE_LOWER;
                        } else if (piece->partFlags & PART_LOWER_SIDE_RIGHT) {
                            piece->pieceType = PIECE_LOWER_SIDE_RIGHT;
                        } else if (piece->partFlags & PART_POST_UPPER) {
                            piece->pieceType = PIECE_POST_UPPER;
                        } else if (piece->partFlags & PART_POST_LOWER) {
                            piece->pieceType = PIECE_POST_LOWER;
                        } else {
                            piece->pieceType = PIECE_OTHER;
                        }

                        if (piece->pieceType == PIECE_OTHER) {
                            piece->pieceType = PIECE_WHOLE_SIGN;
                        }

                        Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_NEW);
                        Matrix_MultVec3f(&sPieceOffsets[piece->pieceType], &offset);
                        piece->actor.world.pos.x += offset.x;
                        piece->actor.world.pos.y += offset.y;
                        piece->actor.world.pos.z += offset.z;

                        piece->offset.x = -sPieceOffsets[piece->pieceType].x / this->actor.scale.x;
                        piece->offset.y = -sPieceOffsets[piece->pieceType].y / this->actor.scale.x;
                        piece->offset.z = -sPieceOffsets[piece->pieceType].z / this->actor.scale.x;

                        piece->pieceWidth = sPieceSizes[piece->pieceType].x;
                        piece->pieceHeight = sPieceSizes[piece->pieceType].y;
                        piece->actionState = ENKANBAN_AIR;
                        piece->actor.gravity = -1.0f;
                        piece->actor.world.rot.y =
                            BINANG_ROT180((s32)Rand_CenteredFloat(0x4000) + this->actor.yawTowardsPlayer);

                        if ((acHitElem->atDmgInfo.dmgFlags & 0x10) || (acHitElem->atDmgInfo.dmgFlags & 8) ||
                            (acHitElem->atDmgInfo.dmgFlags & 0x80000000)) {
                            piece->actor.velocity.y = Rand_ZeroFloat(3.0f) + 6.0f;
                            piece->actor.speed = Rand_ZeroFloat(4.0f) + 6.0f;
                        } else {
                            piece->actor.velocity.y = Rand_ZeroFloat(2.0f) + 3.0f;
                            piece->actor.speed = Rand_ZeroFloat(2.0f) + 3.0f;
                        }

                        if (piece->partCount >= 4) {
                            piece->bounceX = Rand_ZeroFloat(10.0f) + 6.0f;
                            piece->bounceZ = Rand_ZeroFloat(10.0f) + 6.0f;
                        } else {
                            piece->bounceX = Rand_ZeroFloat(7.0f) + 3.0f;
                            piece->bounceZ = Rand_ZeroFloat(7.0f) + 3.0f;
                        }

                        piece->spinVel.y = Rand_CenteredFloat(0x1800);

                        if (Rand_ZeroOne() < 0.5f) {
                            piece->direction = 1;
                        } else {
                            piece->direction = -1;
                        }
                        piece->airTimer = 100;
                        piece->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
                        piece->actor.flags |= ACTOR_FLAG_UPDATE_DURING_OCARINA;
                        this->cutMarkTimer = 5;
                        Actor_PlaySfx(&this->actor, NA_SE_IT_SWORD_STRIKE);
                    }
                }
            }

            this->actor.focus.pos = this->actor.world.pos;
            this->actor.focus.pos.y += 44.0f;

            Collider_UpdateCylinder(&this->actor, &this->collider);
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);

            if (this->actor.xzDistToPlayer > 500.0f) {
                this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
                this->partFlags = 0xFFFF;
            }

            if (this->cutMarkTimer != 0) {
                if (this->cutMarkTimer >= 5) {
                    this->cutMarkAlpha += 255;
                    if (this->cutMarkAlpha > 255) {
                        this->cutMarkAlpha = 255;
                    }
                } else {
                    this->cutMarkAlpha -= 65;
                    if (this->cutMarkAlpha < 0) {
                        this->cutMarkAlpha = 0;
                    }
                }
                this->cutMarkTimer--;
            }
            break;

        case ENKANBAN_AIR:
        case ENKANBAN_UNUSED: {
            f32 tempX;
            f32 tempY;
            f32 tempZ;
            f32 tempWaterDepth;
            s32 pad2;
            u16 bgCheckFlags;

            if (this->unk_198 != 0) {
                this->actor.velocity.y = -2.0f;
                Actor_UpdatePos(&this->actor);
            } else {
                Actor_MoveWithGravity(&this->actor);
            }

            Actor_UpdateBgCheckInfo(play, &this->actor, 30.0f, 10.0f, 50.0f,
                                    UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);

            tempX = this->actor.world.pos.x;
            tempY = this->actor.world.pos.y;
            tempZ = this->actor.world.pos.z;
            bgCheckFlags = this->actor.bgCheckFlags;
            tempWaterDepth = this->actor.depthInWater;
            this->actor.world.pos.z += ((this->actor.world.pos.y - this->actor.floorHeight) * -50.0f) / 100.0f;

            Actor_UpdateBgCheckInfo(play, &this->actor, 10.0f, 10.0f, 50.0f, UPDBGCHECKINFO_FLAG_4);
            ref_func_80954960(this);

            this->actor.world.pos.x = tempX;
            this->actor.world.pos.y = tempY;
            this->actor.world.pos.z = tempZ;
            this->actor.bgCheckFlags = bgCheckFlags;
            this->actor.depthInWater = tempWaterDepth;

            if (1) {
                u8 onGround = (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND);

                if (this->spinXFlag != 0) {
                    this->spinRot.x += this->spinVel.x;
                    this->spinVel.x -= 0x800;
                    if ((this->spinRot.x <= 0) && onGround) {
                        this->spinRot.x = 0;
                        this->spinVel.x = 0;
                    }
                } else {
                    this->spinRot.x -= this->spinVel.x;
                    this->spinVel.x -= 0x800;
                    if ((this->spinRot.x >= 0) && onGround) {
                        this->spinRot.x = 0;
                        this->spinVel.x = 0;
                    }
                }

                if (this->spinVel.x < -0xC00) {
                    this->spinVel.x = -0xC00;
                }

                if (this->spinZFlag != 0) {
                    this->spinRot.z += this->spinVel.z;
                    this->spinVel.z -= 0x800;
                    if ((this->spinRot.z <= 0) && onGround) {
                        this->spinRot.z = 0;
                        this->spinVel.z = 0;
                    }
                } else {
                    this->spinRot.z -= this->spinVel.z;
                    this->spinVel.z -= 0x800;
                    if ((this->spinRot.z >= 0) && onGround) {
                        this->spinRot.z = 0;
                        this->spinVel.z = 0;
                    }
                }

                if (this->spinVel.z < -0xC00) {
                    this->spinVel.z = -0xC00;
                }

                if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
                    if (!(this->actor.bgCheckFlags & BGCHECKFLAG_GROUND)) {
                        Actor_PlaySfx(&this->actor, NA_SE_EV_WOODPLATE_BOUND);
                    }
                    this->actor.speed *= -0.5f;
                }

                if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) {
                    this->actionState = ENKANBAN_WATER;
                    Actor_PlaySfx(&this->actor, NA_SE_EV_BOMB_DROP_WATER);
                    this->bounceX = this->bounceZ = 0;
                    this->actor.world.pos.y += this->actor.depthInWater;
                    EffectSsGSplash_Spawn(play, &this->actor.world.pos, NULL, NULL, 0, (this->partCount * 20) + 300);
                    EffectSsGRipple_Spawn(play, &this->actor.world.pos, 150, 650, 0);
                    EffectSsGRipple_Spawn(play, &this->actor.world.pos, 300, 800, 5);
                    this->actor.velocity.y = 0.0f;
                    this->actor.gravity = 0.0f;
                    break;
                }

                if (onGround) {
                    floorType = SurfaceType_GetFloorType(&play->colCtx, this->actor.floorPoly, this->actor.floorBgId);

                    if ((floorType == FLOOR_TYPE_15) || (floorType == FLOOR_TYPE_14)) {
                        this->unk_197 = 1;
                    } else if (floorType == FLOOR_TYPE_5) {
                        this->unk_197 = -1;
                    }

                    if (this->bounceCount <= 0) {
                        this->bounceCount++;
                        if (this->unk_197 != 0) {
                            this->actor.velocity.y = 0.0f;
                        } else {
                            this->actor.velocity.y *= -0.3f;
                            this->actor.world.rot.y += TRUNCF_BINANG(Rand_CenteredFloat(0x4000));
                        }
                        bounced = true;
                    } else {
                        this->actor.velocity.y = 0.0f;
                    }

                    if (this->unk_197 != 0) {
                        Vec3f spC8;

                        if (this->unk_197 > 0) {
                            this->actor.speed = 0.0f;
                        } else if ((this->floorRot.x > 0.1f) || (this->floorRot.z > 0.1f)) {
                            this->airTimer = 10;
                            if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
                                this->actionState = ENKANBAN_GROUND;
                                this->actor.speed = 0.0f;
                                goto nextCase;
                            }

                            Matrix_RotateXFNew(this->floorRot.x);
                            Matrix_RotateZF(this->floorRot.z, MTXMODE_APPLY);
                            Matrix_MultVecY(KREG(20) + 10.0f, &spC8);
                            Math_ApproachF(&this->actor.velocity.x, spC8.x, 0.5f, (KREG(21) * 0.01f) + 0.1f);
                            Math_ApproachF(&this->actor.velocity.z, spC8.z, 0.5f, (KREG(21) * 0.01f) + 0.3f);
                            this->actor.world.rot.y = Math_Atan2S(spC8.x, spC8.z);
                            this->unk_198 = 1;
                            this->actor.speed = sqrtf(SQXZ(this->actor.velocity));
                        } else {
                            this->unk_198 = 0;
                            Math_ApproachZeroF(&this->actor.speed, 1, 0.1f);
                        }
                    } else {
                        this->actor.speed *= 0.7f;
                    }

                    if (this->spinRot.x == 0) {
                        if (this->bounceX != 0) {
                            bounced = true;
                            if (this->unk_197 != 0) {
                                this->spinRot.x = 0;
                                this->bounceX = 0;
                            } else {
                                this->spinVel.x = this->bounceX << 9;
                                if (this->bounceX != 0) {
                                    this->bounceX -= 5;
                                    if (this->bounceX <= 0) {
                                        this->bounceX = 0;
                                    }
                                }

                                if (Rand_ZeroOne() < 0.5f) {
                                    this->spinXFlag = 1;
                                } else {
                                    this->spinXFlag = 0;
                                }
                            }
                        }
                    }

                    if (this->spinRot.z == 0) {
                        if (this->bounceZ != 0) {
                            bounced = 1;
                            if (this->unk_197 != 0) {
                                this->spinRot.z = 0;
                                this->bounceZ = 0;
                            } else {
                                this->spinVel.z = this->bounceZ << 9;
                                if (this->bounceZ != 0) {
                                    this->bounceZ -= 5;
                                    if (this->bounceZ <= 0) {
                                        this->bounceZ = 0;
                                    }
                                }

                                if (Rand_ZeroOne() < 0.5f) {
                                    this->spinZFlag = 1;
                                } else {
                                    this->spinZFlag = 0;
                                }
                            }
                        }
                    }

                    Math_ApproachS(&this->actor.shape.rot.x, this->direction * 0x4000, 1, 0x2000);
                } else {
                    this->actor.shape.rot.y += this->spinVel.y;
                    this->actor.shape.rot.x += this->direction * 0x7D0;
                }
            }

            if (bounced) {
                if (this->unk_197 > 0) {
                    Actor_PlaySfx(&this->actor, NA_SE_PL_WALK_GROUND + SURFACE_SFX_OFFSET_SNOW);
                } else {
                    Actor_PlaySfx(&this->actor, NA_SE_EV_WOODPLATE_BOUND);
                }
            }

            if (bounced && (this->unk_197 >= 0)) {
                static Color_RGBA8 ref_D_80957548 = { 185, 140, 70, 255 };
                static Color_RGBA8 ref_D_8095754C = { 255, 255, 255, 255 };
                s16 dustCount;
                s16 j;
                Vec3f velocity = { 0.0f, 0.0f, 0.0f };
                Vec3f accel;
                Vec3f pos;
                Color_RGBA8 primColor;
                Color_RGBA8 envColor;
                s32 pad3;

                if (this->unk_197 != 0) {
                    primColor = ref_D_8095754C;
                    envColor = ref_D_8095754C;
                } else {
                    primColor = ref_D_80957548;
                    envColor = ref_D_80957548;
                }

                accel.x = 0.0f;
                accel.y = 0.1f;
                accel.z = 0.0f;

                pos.y = this->actor.floorHeight + 3.0f;
                dustCount = this->partCount * 0.5f;

                for (j = 0; j < dustCount + 3; j++) {
                    pos.x = Rand_CenteredFloat((this->partCount * 0.5f) + 20.0f) + this->actor.world.pos.x;
                    pos.z = Rand_CenteredFloat((this->partCount * 0.5f) + 20.0f) + this->actor.world.pos.z;
                    ref_func_800B0F18(play, &pos, &velocity, &accel, &primColor, &envColor, 100, 5,
                                  Rand_ZeroFloat(5.0f) + 14.0f);
                }
            }

            if (DECR(this->airTimer) == 0) {
                this->actionState = ENKANBAN_GROUND;
            }
        }
        nextCase:;
            FALLTHROUGH;
        case ENKANBAN_GROUND:
        case ENKANBAN_WATER:
            signpost = (EnKanban*)this->actor.parent;

            if (signpost->partFlags == 0xFFFF) {
                Actor_Kill(&this->actor);
            }

            phi_f0 = 0.0f;
            if (this->unk_197 > 0) {
                phi_f0 = -150.0f;
            }

            Math_ApproachF(&this->actor.shape.yOffset, 100.0f + phi_f0, 1.0f, 5.0f);

            if (this->actionState == ENKANBAN_WATER) {
                s16 rippleDelay;
                s32 rippleScale;

                if ((player->actor.speed > 0.0f) && (player->actor.world.pos.y < this->actor.world.pos.y) &&
                    (this->actor.xyzDistToPlayerSq < SQ(50.0f))) {
                    Math_ApproachF(&this->actor.speed, player->actor.speed, 1.0f, 0.2f);
                    if (this->actor.speed > 1.0f) {
                        this->actor.speed = 1.0f;
                    }

                    if (Math_SmoothStepToS(&this->actor.world.rot.y, BINANG_ROT180(this->actor.yawTowardsPlayer), 1,
                                           0x1000, 0) > 0) {
                        this->spinVel.y = this->actor.speed * 1000.0f;
                    } else {
                        this->spinVel.y = this->actor.speed * -1000.0f;
                    }
                }

                if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
                    this->actor.speed = 0.0f;
                }

                Actor_MoveWithGravity(&this->actor);

                if (this->actor.speed != 0.0f) {
                    Actor_UpdateBgCheckInfo(play, &this->actor, 10.0f, 10.0f, 50.0f,
                                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4);
                    if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
                        this->actor.speed *= -0.5f;
                        if (this->spinVel.y > 0) {
                            this->spinVel.y = -2000;
                        } else {
                            this->spinVel.y = 2000;
                        }
                    }
                    Math_ApproachZeroF(&this->actor.speed, 1.0f, 0.15f);
                }
                this->actor.shape.rot.y += this->spinVel.y;
                Math_ApproachS(&this->spinVel.y, 0, 1, 0x3A);
                Math_ApproachS(&this->actor.shape.rot.x, this->direction * 0x4000, 2, 0x1000);
                Math_ApproachS(&this->spinRot.x, Math_SinS(this->frameCount * 2500) * 500.0f, 2, 0x1000);
                Math_ApproachS(&this->spinRot.z, Math_CosS(this->frameCount * 3000) * 500.0f, 2, 0x1000);
                Math_ApproachZeroF(&this->floorRot.x, 0.5f, 0.2f);
                Math_ApproachZeroF(&this->floorRot.z, 0.5f, 0.2f);

                if (fabsf(this->actor.speed) > 1.0f) {
                    rippleDelay = 0;
                } else if (fabsf(this->actor.speed) > 0.5f) {
                    rippleDelay = 3;
                } else {
                    rippleDelay = 7;
                }

                if (!(this->frameCount & rippleDelay)) {
                    if (this->partCount < 3) {
                        rippleScale = 0;
                    } else if (this->partCount < 6) {
                        rippleScale = 100;
                    } else {
                        rippleScale = 200;
                    }
                    EffectSsGRipple_Spawn(play, &this->actor.world.pos, rippleScale, rippleScale + 500, 0);
                }
            } else if ((play->actorCtx.unk2 != 0) && (this->actor.xyzDistToPlayerSq < SQ(100.0f))) {
                f32 hammerStrength = (100.0f - sqrtf(this->actor.xyzDistToPlayerSq)) * 0.05f;

                this->actionState = ENKANBAN_AIR;
                this->actor.gravity = -1.0f;
                this->actor.world.rot.y = Rand_CenteredFloat(0x10000);
                if (this->partCount >= 4) {
                    this->bounceX = Rand_ZeroFloat(10.0f) + 6.0f;
                    this->bounceZ = Rand_ZeroFloat(10.0f) + 6.0f;
                    this->actor.velocity.y = 2.0f + hammerStrength;
                    this->actor.speed = Rand_ZeroFloat(1.0f);
                } else {
                    this->bounceX = Rand_ZeroFloat(7.0f) + 3.0f;
                    this->bounceZ = Rand_ZeroFloat(7.0f) + 3.0f;
                    this->actor.velocity.y = 3.0f + hammerStrength;
                    this->actor.speed = Rand_ZeroFloat(1.5f);
                }

                this->spinVel.y = Rand_CenteredFloat(0x1800);

                if (Rand_ZeroOne() < 0.5f) {
                    this->direction = 1;
                } else {
                    this->direction = -1;
                }
                this->airTimer = 70;
            }

            if (this->bounceX == 0) {
                Actor* explosive = play->actorCtx.actorLists[ACTORCAT_EXPLOSIVES].first;
                f32 dx;
                f32 dy;
                f32 dz;

                while (explosive != NULL) {
                    if (explosive->params != 1) {
                        explosive = explosive->next;
                        continue;
                    }

                    dx = this->actor.world.pos.x - explosive->world.pos.x;
                    dy = this->actor.world.pos.y - explosive->world.pos.y;
                    dz = this->actor.world.pos.z - explosive->world.pos.z;

                    if (sqrtf(SQ(dx) + SQ(dy) + SQ(dz)) < 100.0f) {
                        f32 bombStrength = (100.0f - sqrtf(SQ(dx) + SQ(dy) + SQ(dz))) * 0.05f;

                        this->actionState = ENKANBAN_AIR;
                        this->actor.gravity = -1.0f;
                        this->actor.world.rot.y = Math_Atan2S(dx, dz);

                        if (this->partCount >= 4) {
                            this->bounceX = Rand_ZeroFloat(10.0f) + 6.0f;
                            this->bounceZ = Rand_ZeroFloat(10.0f) + 6.0f;
                            this->actor.velocity.y = 2.5f + bombStrength;
                            this->actor.speed = 3.0f + bombStrength;
                        } else {
                            this->bounceX = Rand_ZeroFloat(7.0f) + 3.0f;
                            this->bounceZ = Rand_ZeroFloat(7.0f) + 3.0f;
                            this->actor.velocity.y = 5.0f + bombStrength;
                            this->actor.speed = 4.0f + bombStrength;
                        }

                        this->spinVel.y = Rand_CenteredFloat(0x1800);

                        if (Rand_ZeroOne() < 0.5f) {
                            this->direction = 1;
                        } else {
                            this->direction = -1;
                        }
                        this->airTimer = 70;
                    }

                    explosive = explosive->next;
                }
            }

            switch (this->ocarinaFlag) {
                case 0:
                    if (play->msgCtx.ocarinaMode == OCARINA_MODE_ACTIVE) {
                        this->ocarinaFlag = 1;
                    }
                    break;

                case 1:
                    if ((play->msgCtx.ocarinaMode == OCARINA_MODE_END) &&
                        (play->msgCtx.lastPlayedSong == OCARINA_SONG_HEALING)) {
                        this->actionState = ENKANBAN_REPAIR;
                        this->bounceX = 1;
                        Audio_PlaySfx(NA_SE_SY_TRE_BOX_APPEAR);
                    }
                    break;

                default:
                    break;
            }
            break;

        case ENKANBAN_REPAIR: {
            f32 distX;
            f32 distY;
            f32 distZ;
            s16 pDiff;
            s16 yDiff;
            s16 rDiff;

            signpost = (EnKanban*)this->actor.parent;
            signpost->invincibilityTimer = 5;

            if (signpost->partFlags == 0xFFFF) {
                Actor_Kill(&this->actor);
            }

            Matrix_RotateYS(signpost->actor.shape.rot.y, MTXMODE_NEW);
            Matrix_MultVec3f(&sPieceOffsets[this->pieceType], &offset);
            distX =
                Math_SmoothStepToF(&this->actor.world.pos.x, signpost->actor.world.pos.x + offset.x, 1.0f, 3.0f, 0.0f);
            distY =
                Math_SmoothStepToF(&this->actor.world.pos.y, signpost->actor.world.pos.y + offset.y, 1.0f, 3.0f, 0.0f);
            distZ =
                Math_SmoothStepToF(&this->actor.world.pos.z, signpost->actor.world.pos.z + offset.z, 1.0f, 3.0f, 0.0f);
            pDiff = Math_SmoothStepToS(&this->actor.shape.rot.x, signpost->actor.shape.rot.x, 1, 0x200, 0);
            yDiff = Math_SmoothStepToS(&this->actor.shape.rot.y, signpost->actor.shape.rot.y, 1, 0x200, 0);
            rDiff = Math_SmoothStepToS(&this->actor.shape.rot.z, signpost->actor.shape.rot.z, 1, 0x200, 0);
            Math_ApproachS(&this->spinRot.x, 0, 1, 0x200);
            Math_ApproachS(&this->spinRot.z, 0, 1, 0x200);
            Math_ApproachZeroF(&this->floorRot.x, 1.0f, 0.05f);
            Math_ApproachZeroF(&this->floorRot.z, 1.0f, 0.05f);
            Math_ApproachZeroF(&this->actor.shape.yOffset, 1.0f, 2.0f);
            if (((distX + distY + distZ) == 0.0f) &&
                ((pDiff + yDiff + rDiff + this->spinRot.x + this->spinRot.z) == 0) && (this->floorRot.x == 0.0f) &&
                (this->floorRot.z == 0.0f)) {
                signpost->partFlags |= this->partFlags;
                signpost->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
                Actor_Kill(&this->actor);
                return;
            }
            break;
        }

        default:
            break;
    }
}
