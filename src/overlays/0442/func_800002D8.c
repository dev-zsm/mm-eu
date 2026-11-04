// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray2.h"

void MirRay2_Update(Actor* thisx, PlayState* play) {
    MirRay2* this = (MirRay2*)thisx;

    if (this->unk1A4 & 1) {
        if (Flags_GetSwitch(play, MIRRAY2_GET_SWITCH_FLAG(thisx))) {
            this->unk1A4 &= ~1;
        }
    } else {
        ref_func_80AF3FE0(this, play);
        if (MIRRAY2_GET_F(thisx) != 1) {
            Actor_UpdateBgCheckInfo(play, &this->actor, 10.0f, 10.0f, 10.0f, UPDBGCHECKINFO_FLAG_4);
            this->actor.shape.shadowAlpha = 0x50;
        } else {
            ref_func_80AF3F70(this);
        }
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider.base);
    }
}
