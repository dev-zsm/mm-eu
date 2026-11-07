// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808BAE9C(DoorWarp1* this, PlayState* play) {
    s32 pad;
    s32 pad2;
    s32 sp94 = play->state.frames * 10;
    f32 sp90;
    f32 sp8C;
    f32 phi_f12;
    f32 sp84;

    if (this->unk_1A4 >= 1.0f) {
        sp90 = 0.0f;
    } else {
        sp90 = 1.0f - this->unk_1A4;
    }

    if (this->unk_1A8 >= 1.0f) {
        sp8C = 0.0f;
    } else {
        sp8C = 1.0f - this->unk_1A8;
    }

    OPEN_DISPS(play->state.gfxCtx);

    sp84 = 1.0f - ((2.0f - this->unk_1A4) / 1.7f);
    this->unk_1AC += sp84 * 15.0f;
    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255.0f * sp84, 255, 255, (u8)this->unk_1B4);
    gDPSetEnvColor(POLY_XLU_DISP++, 0, 255.0f * sp84, 255, 255);

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y + 1.0f, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    phi_f12 = 1.0f;
    if (this->unk_203 != 0) {
        phi_f12 = this->unk_204 * phi_f12;
    }
    Matrix_Scale(phi_f12, phi_f12, phi_f12, MTXMODE_APPLY);

    gSPSegment(POLY_XLU_DISP++, 0x0A, Matrix_Finalize(play->state.gfxCtx));
    Matrix_Push();
    gSPSegment(POLY_XLU_DISP++, 0x08,
               Gfx_TwoTexScroll(play->state.gfxCtx, 0, sp94 & 0xFF, -(TRUNCF_BINANG(2.0f * this->unk_1AC) & 0x1FF),
                                0x100, 0x100, 1, sp94 & 0xFF, -(TRUNCF_BINANG(2.0f * this->unk_1AC) & 0x1FF), 0x100,
                                0x100));

    Matrix_Translate(0.0f, this->unk_1A4 * 230.0f, 0.0f, MTXMODE_APPLY);
    Matrix_Scale(((this->unk_1C6 * sp90) / 100.0f) + 1.0f, 1.0f, ((this->unk_1C6 * sp90) / 100.0f) + 1.0f,
                 MTXMODE_APPLY);

    gSPSegment(POLY_XLU_DISP++, 0x09, Matrix_Finalize(play->state.gfxCtx));
    gSPDisplayList(POLY_XLU_DISP++, gWarpPortalDL);

    Matrix_Pop();

    if (this->unk_1B0 > 0.0f) {
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255.0f * sp84, 255, 255, (u8)this->unk_1B0);
        gDPSetEnvColor(POLY_XLU_DISP++, 0, 255.0f * sp84, 255, 255);

        sp94 *= 2;
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   Gfx_TwoTexScroll(play->state.gfxCtx, 0, sp94 & 0xFF, -(TRUNCF_BINANG(this->unk_1AC) & 0x1FF), 0x100,
                                    0x100, 1, sp94 & 0xFF, -(TRUNCF_BINANG(this->unk_1AC) & 0x1FF), 0x100, 0x100));

        Matrix_Translate(0.0f, this->unk_1A8 * 60.0f, 0.0f, MTXMODE_APPLY);
        Matrix_Scale(((this->unk_1C8 * sp8C) / 100.0f) + 1.0f, 1.0f, ((this->unk_1C8 * sp8C) / 100.0f) + 1.0f,
                     MTXMODE_APPLY);

        gSPSegment(POLY_XLU_DISP++, 0x09, Matrix_Finalize(play->state.gfxCtx));
        gSPDisplayList(POLY_XLU_DISP++, gWarpPortalDL);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
