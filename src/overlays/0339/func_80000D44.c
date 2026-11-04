// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void EnMkk_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    Player* player;
    EnMkk* this = (EnMkk*)thisx;

    if (this->primColorSelect > 0) {
        this->primColorSelect--;
    } else if ((Rand_ZeroOne() < 0.075f) && (this->actor.params != 1)) {
        this->primColorSelect = 6;
    }
    ref_func_80A4EBBC(this, play);
    this->actionFunc(this, play);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 20.0f, 20.0f, 20.0f,
                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 |
                                UPDBGCHECKINFO_FLAG_10);
    if (this->actor.params == 0) {
        ref_func_80A4E84C(this);
    }
    if (Actor_IsFacingPlayer(&this->actor, 0x3000)) {
        player = GET_PLAYER(play);
        this->actor.shape.rot.x = Actor_WorldPitchTowardPoint(&this->actor, &player->actor.focus.pos);
        this->actor.shape.rot.x = CLAMP(this->actor.shape.rot.x, -0x1800, 0x1800);
    }
    Actor_SetFocus(&this->actor, 10.0f);
    this->collider.dim.worldSphere.center.x = this->actor.focus.pos.x;
    this->collider.dim.worldSphere.center.y = this->actor.focus.pos.y;
    this->collider.dim.worldSphere.center.z = this->actor.focus.pos.z;
    if (this->collider.base.atFlags & AT_ON) {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    }
    if (this->collider.base.acFlags & AC_ON) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}
