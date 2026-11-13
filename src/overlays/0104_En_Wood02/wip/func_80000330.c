// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnWood02_Init), score 9.00 (13 differ, size +3)
#include "generated/mm/z_en_wood02.h"

void func_80000330(Actor* thisx, PlayState* play) {
    s16 spawnType = 0;
    f32 actorScale = 1.0f;
    EnWood02* this = (EnWood02*)thisx;
    s32 pad;
    CollisionPoly* outPoly;
    s32 bgId;
    f32 floorY;
    s16 extraRot;

    this->actor.world.rot.z = 0;
    this->unk_144 = ENWOOD02_GET_FF00(&this->actor);
    this->unk_146 = -1;
    this->actor.shape.rot.z = this->actor.world.rot.z;

    if (this->unk_144 & 0x80) {
        this->unk_144 = -1;
    }

    this->actor.params &= 0xFF;
    this->unk_148 = this->actor.home.rot.z;

    Actor_ProcessInitChain(&this->actor, sInitChain);

    if ((this->actor.params < WOOD_BUSH_GREEN_SMALL) || (this->actor.params == WOOD_TREE_SPECIAL)) {
        Collider_InitCylinder(play, &this->collider);
        Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    }

    if ((this->actor.params == WOOD_TREE_SPECIAL) && !gSaveContext.save.isNight && (this->unk_144 != -1) &&
        !Flags_GetCollectible(play, this->unk_144)) {
        this->actor.child =
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EN_ANI, this->actor.world.pos.x,
                               this->actor.world.pos.y + 120.0f, this->actor.world.pos.z - 15.0f, 0, 0, 0, 1);
        if (this->actor.child != NULL) {
            this->actor.child->csId = this->actor.csId;
        }
        this->unk_151 = 1;
    } else {
        this->actor.child = NULL;
        this->unk_151 = 0;
    }

    switch (this->actor.params) {
        case WOOD_BUSH_GREEN_LARGE_SPAWNER:
        case WOOD_BUSH_BLACK_LARGE_SPAWNER:
            spawnType = 1;
            FALLTHROUGH;
        case WOOD_BUSH_GREEN_LARGE_SPAWNED:
        case WOOD_BUSH_BLACK_LARGE_SPAWNED:
            spawnType++;
            FALLTHROUGH;
        case WOOD_TREE_CONICAL_LARGE:
        case WOOD_BUSH_GREEN_LARGE:
        case WOOD_BUSH_BLACK_LARGE:
        case WOOD_TREE_SPECIAL:
            actorScale = 1.5f;
            this->actor.cullingVolumeDistance = 4000.0f;
            this->actor.cullingVolumeScale = 2000.0f;
            this->actor.cullingVolumeDownward = 2400.0f;
            break;

        case WOOD_TREE_CONICAL_SPAWNER:
        case WOOD_TREE_OVAL_YELLOW_SPAWNER:
        case WOOD_TREE_OVAL_GREEN_SPAWNER:
        case WOOD_BUSH_GREEN_SMALL_SPAWNER:
        case WOOD_BUSH_BLACK_SMALL_SPAWNER:
            spawnType = 1;
            FALLTHROUGH;
        case WOOD_TREE_CONICAL_SPAWNED:
        case WOOD_TREE_OVAL_YELLOW_SPAWNED:
        case WOOD_TREE_OVAL_GREEN_SPAWNED:
        case WOOD_BUSH_GREEN_SMALL_SPAWNED:
        case WOOD_BUSH_BLACK_SMALL_SPAWNED:
            spawnType++;
            FALLTHROUGH;
        case WOOD_TREE_CONICAL_MEDIUM:
        case WOOD_TREE_OVAL_GREEN:
        case WOOD_TREE_KAKARIKO_ADULT:
        case WOOD_BUSH_GREEN_SMALL:
        case WOOD_BUSH_BLACK_SMALL:
            this->actor.cullingVolumeDistance = 4000.0f;
            this->actor.cullingVolumeScale = 800.0f;
            this->actor.cullingVolumeDownward = 1800.0f;
            break;

        case WOOD_TREE_CONICAL_SMALL:
            actorScale = 0.6f;
            this->actor.cullingVolumeDistance = 4000.0f;
            this->actor.cullingVolumeScale = 400.0f;
            this->actor.cullingVolumeDownward = 1000.0f;
            break;

        case WOOD_LEAF_GREEN:
        case WOOD_LEAF_YELLOW:
            this->unk_14A[0] = 75;
            actorScale = 0.02f;
            this->actor.velocity.x = Rand_CenteredFloat(6.0f);
            this->actor.velocity.z = Rand_CenteredFloat(6.0f);
            this->actor.velocity.y = (Rand_ZeroOne() * 1.25f) + -3.1f;
            break;

        default:
            break;
    }

    if (this->actor.params < WOOD_TREE_OVAL_GREEN) {
        this->drawType = WOOD_DRAW_TREE_CONICAL;
    } else if (this->actor.params < WOOD_TREE_KAKARIKO_ADULT) {
        this->drawType = WOOD_DRAW_TREE_OVAL;
    } else if (this->actor.params < WOOD_BUSH_GREEN_SMALL) {
        this->drawType = WOOD_DRAW_TREE_KAKARIKO_ADULT;
    } else if (this->actor.params < WOOD_BUSH_BLACK_SMALL) {
        this->drawType = WOOD_DRAW_BUSH_GREEN;
    } else if (this->actor.params < WOOD_LEAF_YELLOW) {
        this->drawType = WOOD_DRAW_4;
    } else if (this->actor.params == WOOD_TREE_SPECIAL) {
        this->drawType = WOOD_DRAW_TREE_CONICAL;
    } else {
        this->drawType = WOOD_DRAW_LEAF_YELLOW;
    }

    Actor_SetScale(&this->actor, actorScale);
    this->spawnType = spawnType;

    if (spawnType != WOOD_SPAWN_NORMAL) {
        extraRot = 0;
        if (this->actor.params == WOOD_BUSH_GREEN_LARGE_SPAWNER) {
            extraRot = 0x4000;
        }

        if (spawnType == WOOD_SPAWN_SPAWNER) {
            EnWood02_SpawnOffspring(this, play);
            sWood02SpawnCos = Math_CosS(sWood02SpawnAngle[5] + this->actor.world.rot.y + extraRot);
            sWood02SpawnSin = Math_SinS(sWood02SpawnAngle[5] + this->actor.world.rot.y + extraRot);
            this->actor.world.pos.x += sWood02SpawnSin * sWood02SpawnDistance[5];
            this->actor.world.pos.z += sWood02SpawnCos * sWood02SpawnDistance[5];
        } else {
            this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
            this->unk_151 = 2;
        }

        
        this->actor.world.pos.y += 200.0f;
        floorY = BgCheck_EntityRaycastFloor5(&play->colCtx, &outPoly, &bgId, &this->actor, &this->actor.world.pos);

        if (floorY > BGCHECK_Y_MIN) {
            this->actor.world.pos.y = floorY;
        } else {
            Actor_Kill(&this->actor);
            return;
        }
    }

    ActorShape_Init(&this->actor.shape, 0.0f, NULL, 0.0f);
    this->actor.home.rot.y = 0;
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
}
