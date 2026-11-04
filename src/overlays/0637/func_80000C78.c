// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

s32 DemoSyoten_OverrideLimbDraw(PlayState* play, KFSkelAnimeFlex* kfSkelAnime, s32 limbIndex, Gfx** dList, u8* flags,
                                void* thisx, Vec3f* scale, Vec3s* rot, Vec3f* pos) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;
    DemoSyoten* this = (DemoSyoten*)thisx;

    OPEN_DISPS(gfxCtx);

    switch (limbIndex) {
        case 2:
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 240, 140, (s32)(this->unk_3D8 * 150.0f));
            break;

        case 4:
        case 12:
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 240, 190, (s32)(this->unk_3D8 * 200.0f));
            break;

        case 6:
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 240, 150, (s32)(this->unk_3D8 * 150.0f));
            break;

        case 8:
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 240, 180, (s32)(this->unk_3D8 * 200.0f));
            break;

        case 10:
        case 14:
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 240, 170, (s32)(this->unk_3D8 * 150.0f));
            break;

        case 16:
            gDPPipeSync(POLY_XLU_DISP++);
            gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 240, 160, (s32)(this->unk_3D8 * 200.0f));
            break;
    }

    CLOSE_DISPS(gfxCtx);
    return true;
}
