// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ObjIceblock_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjIceblock* this = (ObjIceblock*)thisx;
    Actor* parent = this->dyna.actor.parent;

    if (parent != NULL) {
        if ((parent->update == NULL) || (&this->dyna.actor != parent->child)) {
            this->dyna.actor.parent = NULL;
            parent = NULL;
        }
    }

    if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        if (this->unk_1B0 & 0x20) {
            this->unk_1B0 &= ~0x40;
        } else {
            this->unk_1B0 |= 0x40;
            this->unk_1B0 |= 0x20;
        }
    } else if (this->unk_1B0 & 0x20) {
        this->unk_1B0 |= 0x40;
        this->unk_1B0 &= ~0x20;
    } else {
        this->unk_1B0 &= ~0x40;
    }

    if ((this->unk_2B0 == 1) || (this->unk_2B0 == 2) || (this->unk_2B0 == 3)) {
        if (this->meltTimer > 0) {
            this->meltTimer--;
        }
    }

    if (((this->collider.base.acFlags & AC_HIT) && (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x800)) ||
        (this->meltTimer == 0)) {
        this->meltTimer = -1;
        this->unk_2B0 = 4;
        this->unk_1B0 &= ~0x100;
        if (this->unk_1B0 & 1) {
            this->unk_1B0 &= ~1;
            Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_END);
        }
        ref_func_80A266C4(this);
    }

    
    if (this->spawnCutsceneTimer > 0) {
        this->spawnCutsceneTimer--;
        if (this->spawnCutsceneTimer == 0) {
            CutsceneManager_Stop(this->dyna.actor.csId);
        }
    }

    this->actionFunc(this, play);
    if (this->dyna.actor.update == NULL) {
        if (parent != NULL) {
            parent->child = NULL;
            parent->shape.rot.x = this->unk_254.x + this->dyna.actor.home.rot.x;
            parent->shape.rot.y = this->unk_254.y + this->dyna.actor.home.rot.y;
            parent->shape.rot.z = this->unk_254.z + this->dyna.actor.home.rot.z;
            this->dyna.actor.parent = NULL;
        }
        return;
    }

    this->collider.base.ocFlags1 &= ~OC1_HIT;
    this->collider.base.acFlags &= ~AC_HIT;
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);

    if (this->unk_1B0 & 0x10) {
        if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor) && (this->unk_2B4 > 0.0f)) {
            this->collider.base.ocFlags1 &= ~OC1_NO_PUSH;
            this->collider.base.ocFlags1 |= (OC1_TYPE_2 | OC1_TYPE_1 | OC1_TYPE_PLAYER);
            this->collider.elem.acDmgInfo.dmgFlags |=
                (0x800000 | 0x400000 | 0x10000 | 0x2000 | 0x1000 | 0x800 | 0x200 | 0x100 | 0x80 | 0x20 | 0x10 | 0x2);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        }
    } else {
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }

    if (this->unk_1B0 & 0x100) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }

    ref_func_80A25440(this);
    Actor_SetFocus(&this->dyna.actor, this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y);
    this->unk_1B0 &= ~0x2;

    if (parent) {}
}
