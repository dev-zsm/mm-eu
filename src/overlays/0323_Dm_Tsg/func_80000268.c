// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_tsg.h"

void DmTsg_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    DmTsg* this = (DmTsg*)thisx;
    s32 i;
    u32 j;

    if (this->canDraw) {
        for (i = 0, j = 0; i < DMTSG_UNK_SIZE; i++) {
            Matrix_Translate(this->unk_148[i].x + this->actor.world.pos.x, this->unk_148[i].y + this->actor.world.pos.y,
                             this->unk_148[i].z + this->actor.world.pos.z, MTXMODE_NEW);
            Matrix_Scale(0.3f, 0.3f, 0.3f, MTXMODE_APPLY);
            AnimatedMat_DrawStep(play, Lib_SegmentedToVirtual(object_open_obj_Matanimheader_011458), j++);
            Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
            Gfx_DrawDListXlu(play, object_open_obj_DL_002D30);
            if (j >= 10) {
                j = 0;
            }
        }
    }
}
