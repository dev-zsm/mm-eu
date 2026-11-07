// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2AAB8(BgDblueMovebg* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 sp18;

    if (this->unk_180-- <= 0) {
        CutsceneManager_Stop(this->csIdList[0]);
    }

    sp18 = false;
    if ((this->unk_1D0 > 0) && ((sCsIdList[0] >= 0) || (sCsIdList[1] >= 0))) {
        if (CutsceneManager_GetCurrentCsId() != CS_ID_NONE) {
            sp18 = true;
        }
    }

    if (!sp18 && (this->unk_180 <= 0)) {
        this->unk_1D0--;

        if (this->unk_1D0 == 1) {
            this->dyna.pushForce = 0.0f;
            player->stateFlags1 |= PLAYER_STATE1_20;
            player->stateFlags2 &= ~PLAYER_STATE2_10;
        }

        if (this->unk_1D0 <= 0) {
            player->stateFlags1 &= ~PLAYER_STATE1_20;
            this->actionFunc = ref_func_80A2A714;
        }
    }
}
