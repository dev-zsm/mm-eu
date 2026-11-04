// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_grass_carry.h"

void ObjGrassCarry_Main(ObjGrassCarry* this, PlayState* play) {
    Actor* thisx = &this->actor;

    if (Actor_HasParent(thisx, play)) {
        ObjGrassCarry_SetupLiftedUp(this);
        if (this->grassElem != NULL) {
            this->grassElem->flags |= OBJ_GRASS_ELEM_REMOVED;
        }
        thisx->draw = ObjGrassCarry_Draw;
        thisx->shape.shadowDraw = ActorShadow_DrawCircle;
        thisx->shape.shadowAlpha = 60;
        thisx->shape.shadowScale = 1.0f;
        this->grassManager->activeGrassCarry ^= 1;
        thisx->room = -1;
        SoundSource_PlaySfxAtFixedWorldPos(play, &thisx->world.pos, 20, NA_SE_PL_PULL_UP_PLANT);
    } else if (this->grassManager->carryGrassElem != NULL) {
        Player* player = GET_PLAYER(play);

        this->grassElem = this->grassManager->carryGrassElem;
        Math_Vec3f_Copy(&thisx->world.pos, &this->grassElem->pos);
        thisx->shape.rot.y = thisx->world.rot.y = this->grassElem->rotY;
        this->dropTable = this->grassElem->dropTable;
        thisx->xzDistToPlayer = Actor_WorldDistXZToActor(&this->actor, &player->actor);
        thisx->playerHeightRel = Actor_HeightDiff(&this->actor, &player->actor);
        thisx->xyzDistToPlayerSq = SQ(thisx->xzDistToPlayer) + SQ(thisx->playerHeightRel);
        thisx->yawTowardsPlayer = Actor_WorldYawTowardActor(&this->actor, &player->actor);
        Actor_OfferCarry(&this->actor, play);
    }
}
