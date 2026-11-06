// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B84928(BgDblueWaterfall* this, PlayState* play) {
    s32 pad;
    s32 sp30 = ref_func_80B83D04(this, play);
    s32 sp2C = (this->collider.base.acFlags & AC_HIT) != 0;
    s32 sp28 = false;

    if (sp2C) {
        this->collider.base.acFlags &= ~AC_HIT;
    }

    if ((sp30 == 0) && (this->collider.base.ocFlags2 & OC2_HIT_PLAYER)) {
        ref_func_80B84610(this, play);
    }

    if (this->unk_19C > 0) {
        this->unk_19C--;
        if (this->unk_19C == 0) {
            if (sp30 != 0) {
                ref_func_80B83D94(this, play);
                ref_func_80B84EF0(this, play);
            } else {
                ref_func_80B83E1C(this, play);
                ref_func_80B84B9C(this, play);
            }
            sp28 = true;
        }
    }

    if (!sp28) {
        if (sp2C) {
            if (sp30 != 0) {
                ref_func_80B83EA4(this, play);
                if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x800) {
                    this->csId = this->actor.csId;
                    ref_func_80B84AD4(this, play);
                }
            } else {
                ref_func_80B841A0(this, play);
                if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x1000) {
                    this->csId = CutsceneManager_GetAdditionalCsId(this->actor.csId);
                    ref_func_80B84AD4(this, play);
                }
            }
        } else {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        }
    }
}
