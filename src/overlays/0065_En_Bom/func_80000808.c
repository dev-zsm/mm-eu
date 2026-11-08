// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom.h"

void EnBom_Explode(EnBom* this, PlayState* play) {
    static s16 ref_D_80872E8C[] = { 100, 200 };
    static Color_RGBA8 ref_D_80872E90 = { 185, 140, 70, 255 };
    static Color_RGBA8 ref_D_80872E94 = { 255, 255, 255, 255 };
    s32 i;
    FloorType floorType;
    f32 temp_f20;
    s32 pad;
    f32 spCC;
    Vec3f spC0;
    Vec3f spB4;
    CollisionPoly* spB0;
    s32 bgId;
    Vec3f spA0;
    Vec3f sp94;
    Vec3f sp88;
    Color_RGBA8 sp84;
    Color_RGBA8 sp80;

    if (this->collider2.elements[0].dim.modelSphere.radius == 0) {
        this->actor.flags |= ACTOR_FLAG_DRAW_CULLING_DISABLED;
        Rumble_Request(this->actor.xzDistToPlayer, 255, 20, 150);
    }

    this->collider2.elements[0].dim.worldSphere.radius = ref_D_80872E8C[this->isPowderKeg];
    if (this->timer == 7) {
        this->collider2.base.atFlags &= ~AT_TYPE_ENEMY;
    }

    if (this->actor.params == BOMB_TYPE_EXPLOSION) {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider2.base);
    }

    if (play->envCtx.adjLightSettings.light1Color[0] != 0) {
        play->envCtx.adjLightSettings.light1Color[0] -= 25;
    }

    if (play->envCtx.adjLightSettings.light1Color[1] != 0) {
        play->envCtx.adjLightSettings.light1Color[1] -= 25;
    }

    if (play->envCtx.adjLightSettings.light1Color[2] != 0) {
        play->envCtx.adjLightSettings.light1Color[2] -= 25;
    }

    if (play->envCtx.adjLightSettings.ambientColor[0] != 0) {
        play->envCtx.adjLightSettings.ambientColor[0] -= 25;
    }

    if (play->envCtx.adjLightSettings.ambientColor[1] != 0) {
        play->envCtx.adjLightSettings.ambientColor[1] -= 25;
    }

    if (play->envCtx.adjLightSettings.ambientColor[2] != 0) {
        play->envCtx.adjLightSettings.ambientColor[2] -= 25;
    }

    if (this->timer == 0) {
        ref_func_80123590(play, &this->actor);
        Actor_Kill(&this->actor);
    }

    if ((this->timer & 1) == 0) {
        spCC = Rand_ZeroFloat(M_PIf);

        for (i = 0; i < 15; i++) {
            Matrix_RotateYF(((2.0f * (i * M_PIf)) / 15.0f) + spCC, MTXMODE_NEW);
            Matrix_MultVecZ((10 - this->timer) * 300.0f * 0.1f, &spC0);
            spB4.x = this->actor.world.pos.x + spC0.x;
            spB4.y = this->actor.world.pos.y + 500.0f;
            spB4.z = this->actor.world.pos.z + spC0.z;
            if (BgCheck_EntityRaycastFloor3(&play->colCtx, &spB0, &bgId, &spB4) != BGCHECK_Y_MIN) {
                floorType = SurfaceType_GetFloorType(&play->colCtx, spB0, bgId);
                temp_f20 = BgCheck_EntityRaycastFloor1(&play->colCtx, &spB0, &spB4);

                if ((floorType == FLOOR_TYPE_4) || (floorType == FLOOR_TYPE_15) || (floorType == FLOOR_TYPE_14)) {
                    if (floorType == FLOOR_TYPE_4) {
                        sp84 = ref_D_80872E90;
                        sp80 = ref_D_80872E90;
                    } else {
                        sp84 = ref_D_80872E94;
                        sp80 = ref_D_80872E94;
                    }
                    Matrix_MultVecZ(5.0f, &sp94);
                    sp88.x = sp88.z = 0.0f;
                    sp94.y = 2.0f;
                    sp88.y = 0.2f;

                    spA0.x = spB4.x;
                    spA0.y = temp_f20;
                    spA0.z = spB4.z;

                    temp_f20 = Rand_ZeroFloat(250.0f);
                    ref_func_800B0F18(play, &spA0, &sp94, &sp88, &sp84, &sp80, temp_f20 + 950.0f, 10,
                                  Rand_ZeroFloat(5.0f) + 14.0f);
                }
            }
        }
    }
}
