// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ref_func_80B9D714(ObjHunsui* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);
    s16 csId;
    f32 sp28;

    if ((this->unk_16C != play->roomCtx.curRoom.num) && (this->unk_16C != play->roomCtx.prevRoom.num) &&
        (this->unk_16D != play->roomCtx.curRoom.num) && (this->unk_16D != play->roomCtx.prevRoom.num)) {
        Actor_Kill(&this->dyna.actor);
    } else {
        if (Flags_GetSwitch(play, this->switchFlag)) {
            this->unk_172 &= ~2;
            this->unk_172 |= 0x10;
            csId = this->dyna.actor.csId;

            if (this->unk_16E == 0) {
                if ((csId > CS_ID_NONE) && !CutsceneManager_IsNext(csId)) {
                    CutsceneManager_Queue(csId);
                } else if (csId > CS_ID_NONE) {
                    CutsceneManager_StartWithPlayerCs(csId, &this->dyna.actor);
                    this->unk_16E = -1;
                } else {
                    this->unk_16E = 40;
                }
            } else if (this->unk_16E < 0) {
                if (ref_func_800F22C4(csId, &this->dyna.actor) != 0) {
                    this->unk_16E = 40;
                }
            } else {
                s32 pad;

                if (Math_SmoothStepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y + 800.0f, 0.1f, 8.0f,
                                       1.0f) < 0.5f) {
                    if (DECR(this->unk_16E) == 0) {
                        Flags_UnsetSwitch(play, this->switchFlag);
                    }
                }
                this->dyna.actor.velocity.y = this->dyna.actor.world.pos.y - this->dyna.actor.prevPos.y;
            }
        } else {
            Math_StepToF(&this->dyna.actor.velocity.y, -10.0f, 4.0f);
            this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;
            if (this->dyna.actor.world.pos.y < this->dyna.actor.home.pos.y) {
                this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y;
                this->unk_172 &= ~0x10;
                this->unk_172 |= 2;
            }
        }
    }

    if (!DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        if (this->dyna.actor.xzDistToPlayer < 45.0f) {
            if ((this->dyna.actor.playerHeightRel < -this->dyna.actor.velocity.y) &&
                (this->dyna.actor.playerHeightRel >= -800.0f)) {
                sp28 = (45.0f - this->dyna.actor.xzDistToPlayer) * 0.5f;
                player->actor.world.pos.x += sp28 * Math_SinS(this->dyna.actor.yawTowardsPlayer);
                player->actor.world.pos.z += sp28 * Math_CosS(this->dyna.actor.yawTowardsPlayer);
            }
        }
    }
}
