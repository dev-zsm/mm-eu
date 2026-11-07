// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako.h"

void ObjKibako_Thrown(ObjKibako* this, PlayState* play) {
    void* pad;
    void* pad2;
    s32 atHit;

    atHit = (this->collider.base.atFlags & AT_HIT) != 0;
    if (atHit) {
        this->collider.base.atFlags &= ~AT_HIT;
    }
    ref_func_80926394(this, play);
    if (this->timer > 0) {
        this->timer--;
    }
    if ((this->actor.bgCheckFlags & (BGCHECKFLAG_GROUND | BGCHECKFLAG_GROUND_TOUCH | BGCHECKFLAG_WALL)) || atHit ||
        (this->timer <= 0)) {
        ObjKibako_AirBreak(this, play);
        ObjKibako_SpawnCollectible(this, play);
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
        Actor_Kill(&this->actor);
    } else {
        if (this->actor.bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) {
            ObjKibako_WaterBreak(this, play);
            ObjKibako_SpawnCollectible(this, play);
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 20, NA_SE_EV_WOODBOX_BREAK);
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EV_DIVE_INTO_WATER_L);
            Actor_Kill(&this->actor);
        } else {
            if (this->actor.velocity.y < -0.05f) {
                this->actor.gravity = -2.3f;
            }
            Actor_MoveWithGravity(&this->actor);
            Math_StepToS(&ref_D_80927384, ref_D_80927380, 0xA0);
            Math_StepToS(&ref_D_8092738C, ref_D_80927388, 0xA0);
            this->actor.shape.rot.x = (s16)(this->actor.shape.rot.x + ref_D_80927384);
            this->actor.shape.rot.y = (s16)(this->actor.shape.rot.y + ref_D_8092738C);
            Actor_UpdateBgCheckInfo(play, &this->actor, 18.0f, 15.0f, 0.0f,
                                    UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_40);
            Collider_UpdateCylinder(&this->actor, &this->collider);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
        }
    }
}
