// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A26BF8(ObjIceblock* this, PlayState* play) {
    s32 pad[2];
    ObjIceBlockUnkStruct* ptr;
    s32 i;
    Vec3s sp70;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    sp70.z = 0;

    for (i = 0; i < ARRAY_COUNT(this->unk_1B4); i++) {
        ptr = &this->unk_1B4[i];
        sp70.x = ptr->unk_00;
        sp70.y = ptr->unk_02;
        Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                     this->dyna.actor.world.pos.z, &sp70);
        Matrix_Scale(ptr->unk_04, ptr->unk_08, ptr->unk_0C, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gIceBlockCubeDL);
    }

    if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor) && (this->unk_2B4 > 0.0f)) {
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gIceBlockIceBergSublimatingAirTexAnim));
        Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y - 20.0f,
                                     this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
        Matrix_Scale(this->unk_2B4, this->unk_2B4, this->unk_2B4, MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gIceBlockIceBergDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
