// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Init(Actor* thisx, PlayState* play) {
    s32 pad; 
    ObjMine* this = (ObjMine*)thisx;
    s32 pathIndex = OBJMINE_GET_PATH_INDEX(&this->actor);
    Path* path;
    s32 bgId; 
    s32 type = OBJMINE_GET_TYPE(&this->actor);

    Actor_ProcessInitChain(&this->actor, sInitChain);

    this->actor.shape.rot.z = 0;
    this->actor.world.rot.z = 0;

    Collider_InitJntSph(play, &this->collider);
    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, this->colliderElements);

    if (type == OBJMINE_TYPE_PATH) {
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 45.0f);
        this->actor.shape.shadowAlpha = 140;
        this->pathSpeed = sPathSpeeds[OBJMINE_GET_PATH_SPEED(&this->actor)]; 
        if (pathIndex == 0xFF) {
            ObjMine_Path_SetupStationary(this);
        } else {
            path = &play->setupPathList[pathIndex];

            this->waypointIndex = 0;
            this->waypointCount = path->count - 1;
            this->waypoints = (Vec3s*)Lib_SegmentedToVirtual(path->points);

            ObjMine_Path_MoveToWaypoint(this, this->waypointIndex);
            ObjMine_Path_SetupMove(this);
        }
        Matrix_SetTranslateRotateYXZ(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z,
                                     &this->actor.shape.rot);
        Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
        Collider_UpdateSpheres(0, &this->collider);
        this->actor.floorHeight = BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId,
                                                              &this->actor, &this->actor.world.pos);
    } else {
        s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);

        this->actor.update = ObjMine_AirWater_Update;
        this->actor.cullingVolumeScale = 150.0f + (linkCount * (LINK_SIZE * 1.75f));
        this->actor.cullingVolumeDownward = 150.0f + (linkCount * (LINK_SIZE * 1.75f));
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 45.0f);
        this->actor.shape.shadowAlpha = 140;

        if (type == OBJMINE_TYPE_AIR) {
            this->actor.draw = ObjMine_Air_Draw;
            ObjMine_Air_InitChain(this, linkCount);
            this->actor.world.pos.y = -ATTACH_OFFSET - (linkCount * LINK_SIZE) + this->actor.home.pos.y;
            ObjMine_Air_InitCollider(this, linkCount);
            ref_func_800B4AEC(play, &this->actor, 0.0f);
            if (linkCount == 0) {
                ObjMine_Air_SetupStationary(this);
            } else {
                ObjMine_Air_SetupChained(this);
            }
        } else {
            this->actor.draw = ObjMine_Water_Draw;
            ObjMine_Water_InitChain(this, linkCount);
            this->actor.world.pos.y = ATTACH_OFFSET + (linkCount * LINK_SIZE) + this->actor.home.pos.y;
            ObjMine_Water_InitCollider(this, linkCount);
            if (linkCount == 0) {
                ObjMine_Water_SetupStationary(this);
            } else {
                ObjMine_Water_SetupChained(this);
            }
        }
    }
}
