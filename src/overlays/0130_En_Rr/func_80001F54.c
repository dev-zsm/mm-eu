// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void EnRr_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnRr* this = (EnRr*)thisx;
    Mtx* mtx = GRAPH_ALLOC(play->state.gfxCtx, 4 * sizeof(Mtx));
    Vec3f* bodyPartPos;
    s32 i;
    EnRrStruct* ptr;
    Vec3f spA4;
    f32 temp_f20;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x0C, mtx);
    gSPSegment(POLY_OPA_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, (this->unk_1E8 * 0) & 0x7F, (this->unk_1E8 * 0) & 0x3F, 0x20,
                                0x10, 1, (this->unk_1E8 * 0) & 0x3F, (this->unk_1E8 * -6) & 0x7F, 0x20, 0x10));

    Matrix_Push();
    Matrix_Scale((1.0f + this->unk_324[0].unk_10) * this->unk_324[0].unk_08, 1.0f,
                 (1.0f + this->unk_324[0].unk_10) * this->unk_324[0].unk_08, MTXMODE_APPLY);

    bodyPartPos = &this->bodyPartsPos[0];

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

    
    Matrix_MultVecZ(1842.1053f, bodyPartPos++);
    Matrix_MultVecZ(-1842.1053f, bodyPartPos++);
    Matrix_MultVecX(1842.1053f, bodyPartPos++);
    Matrix_MultVecX(-1842.1053f, bodyPartPos++);
    Matrix_Pop();

    for (i = 1; i < ARRAY_COUNT(this->unk_324); i++) {
        temp_f20 = this->unk_324[i].unk_08 * (this->unk_324[i].unk_10 + 1.0f);
        ptr = &this->unk_324[i];

        Matrix_Translate(0.0f, ptr->unk_00 + 1000.0f, 0.0f, MTXMODE_APPLY);
        Matrix_RotateZYX(ptr->unk_1A.x, ptr->unk_1A.y, ptr->unk_1A.z, MTXMODE_APPLY);
        Matrix_Push();
        Matrix_Scale(temp_f20, 1.0f, temp_f20, MTXMODE_APPLY);
        Matrix_ToMtx(mtx);

        if ((i & 1) != 0) {
            Matrix_RotateYS(0x2000, MTXMODE_APPLY);
        }

        
        
        
        
        Matrix_MultVecZ(1842.1053f, bodyPartPos++);
        Matrix_MultVecZ(-1842.1053f, bodyPartPos++);
        Matrix_MultVecX(1842.1053f, bodyPartPos++);
        Matrix_MultVecX(-1842.1053f, bodyPartPos++);
        Matrix_Pop();
        mtx++;
        if (i == 3) {
            Matrix_MultZero(&spA4);
        }
    }

    Matrix_MultZero(&this->unk_228);
    this->collider2.dim.pos.x = LERPIMP(spA4.x, this->unk_228.x, 0.85f);
    this->collider2.dim.pos.y = LERPIMP(spA4.y, this->unk_228.y, 0.85f);
    this->collider2.dim.pos.z = LERPIMP(spA4.z, this->unk_228.z, 0.85f);

    gSPDisplayList(POLY_OPA_DISP++, gLikeLikeDL);

    Actor_DrawDamageEffects(play, &this->actor, this->bodyPartsPos, LIKE_LIKE_BODYPART_MAX,
                            this->actor.scale.y * 66.66667f * this->drawDmgEffScale, this->drawDmgEffFrozenSteamScale,
                            this->drawDmgEffAlpha, this->drawDmgEffType);

    CLOSE_DISPS(play->state.gfxCtx);
}
