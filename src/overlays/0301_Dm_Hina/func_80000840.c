// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_hina.h"

void DmHina_Draw(Actor* thisx, PlayState* play) {
    DmHina* this = (DmHina*)thisx;
    f32 scale;

    if (this->isDrawn) {
        Matrix_Translate(this->actor.world.pos.x,
                         this->actor.world.pos.y + (this->unk154 * this->unk15C) + (40.0f * this->unk15C),
                         this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_RotateZYX(0, play->gameplayFrames * 0x3E8, 0, MTXMODE_APPLY);
        scale = this->unk148 * (1.0f - this->unk14C) * this->unk15C;
        Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);
        switch (this->actor.params) {
            case DMHINA_REMAINS_ODOLWA:
                GetItem_Draw(play, GID_REMAINS_ODOLWA);
                break;

            case DMHINA_REMAINS_GOHT:
                GetItem_Draw(play, GID_REMAINS_GOHT);
                break;

            case DMHINA_REMAINS_GYORG:
                GetItem_Draw(play, GID_REMAINS_GYORG);
                break;

            case DMHINA_REMAINS_TWINMOLD:
                GetItem_Draw(play, GID_REMAINS_TWINMOLD);
                break;

            default:
                break;
        }
        ref_func_80A1F9AC(this, play);
    }
}
