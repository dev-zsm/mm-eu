// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_wind.h"

void ObjWind_Update(Actor* thisx, PlayState* play) {
    ObjWind* this = (ObjWind*)thisx;
    ObjWindStruct* entry = &ref_D_80B2448C[OBJ_WIND_GET_TYPE(thisx)];
    Player* player;
    InfiniteLine line;
    Vec3f nearestPoint;
    Vec3f sp54;
    f32 upXZ; 
    f32 distToNearestPoint;

    if (ref_D_80B245CC != DREG(85)) {
        if ((DREG(85) >= 0) && (DREG(85) < ARRAY_COUNT(ref_D_80B2448C))) {
            DREG(80) = ref_D_80B2448C[DREG(85)].unk_0;
            DREG(81) = ref_D_80B2448C[DREG(85)].unk_2;
            DREG(82) = ref_D_80B2448C[DREG(85)].unk_4;
            DREG(83) = ref_D_80B2448C[DREG(85)].unk_6;
            DREG(84) = ref_D_80B2448C[DREG(85)].unk_8;
            ref_D_80B245CC = DREG(85);
        }
    } else {
        ref_D_80B2448C[DREG(85)].unk_0 = DREG(80);
        ref_D_80B2448C[DREG(85)].unk_2 = DREG(81);
        ref_D_80B2448C[DREG(85)].unk_4 = DREG(82);
        ref_D_80B2448C[DREG(85)].unk_6 = DREG(83);
        ref_D_80B2448C[DREG(85)].unk_8 = DREG(84);
    }

    if ((OBJ_WIND_GET_SWITCH_FLAG(thisx) == 0x7F) || !Flags_GetSwitch(play, OBJ_WIND_GET_SWITCH_FLAG(thisx))) {
        player = GET_PLAYER(play);
        Math_Vec3f_Copy(&line.point, &this->actor.world.pos);
        line.dir.y = Math_CosS(this->actor.shape.rot.x);
        upXZ = Math_SinS(this->actor.shape.rot.x);
        line.dir.x = Math_SinS(this->actor.shape.rot.y) * upXZ;
        line.dir.z = Math_CosS(this->actor.shape.rot.y) * upXZ;
        distToNearestPoint = Math3D_LineClosestToPoint(&line, &player->actor.world.pos, &nearestPoint);
        if ((distToNearestPoint >= 0.0f) && (distToNearestPoint < entry->unk_0)) {
            upXZ = Math_Vec3f_DistXYZAndStoreDiff(&player->actor.world.pos, &nearestPoint, &sp54);
            if (upXZ < entry->unk_2) {
                f32 var_fa0;
                f32 windSpeedXZ = 1.0f; 
                f32 windMagnitude;
                f32 temp_ft0;
                f32 windSpeedX;
                f32 windSpeedY;
                f32 windSpeedZ;

                var_fa0 = 1.0f - distToNearestPoint / entry->unk_0;
                windMagnitude = ((f32)entry->unk_4 / 100.0f) *
                                ((var_fa0 * (1.0f - upXZ / entry->unk_2)) + ((f32)entry->unk_8 / 100.0f));
                if ((distToNearestPoint / entry->unk_0) > 0.8f) {
                    var_fa0 = windSpeedXZ - 1.0f;
                }
                temp_ft0 = ((f32)entry->unk_6 / 100.0f) * (upXZ / entry->unk_2 * var_fa0);
                if (upXZ != 0.0f) {
                    
                    if (1) {}
                    upXZ = 1.0f / upXZ;
                }
                temp_ft0 *= upXZ;
                windSpeedX = (line.dir.x * windMagnitude) + (sp54.x * temp_ft0);
                windSpeedY = (line.dir.y * windMagnitude) + (sp54.y * temp_ft0);
                windSpeedZ = (line.dir.z * windMagnitude) + (sp54.z * temp_ft0);
                player->windSpeed = sqrtf(SQ(windSpeedX) + SQ(windSpeedY) + SQ(windSpeedZ));
                player->windAngleY = Math_Atan2S_XY(windSpeedZ, windSpeedX);

                windSpeedXZ = sqrtf(SQ(windSpeedX) + SQ(windSpeedZ));
                player->windAngleX = Math_Atan2S_XY(windSpeedXZ, windSpeedY);
            }
        }
    }
    this->actor.scale.x = (f32)entry->unk_2 / 50.0f;
    this->actor.scale.z = (f32)entry->unk_2 / 50.0f;
    this->actor.scale.y = (f32)entry->unk_0 / 400.0f;
}
