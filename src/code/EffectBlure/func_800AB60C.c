// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_blure.h"

void EffectBlure_Draw(void* thisx, GraphicsContext* gfxCtx) {
    EffectBlure* this = (EffectBlure*)thisx;
    Vtx* vtx;
    EffectBlureElement* elem;
    s32 i;
    s32 j;
    s32 phi_t2;

    OPEN_DISPS(gfxCtx);

    gSPMatrix(POLY_XLU_DISP++, &gIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (this->numElements != 0) {
        if (this->flags == 0) {
            Gfx_SetupDL38_Xlu(gfxCtx);
            gDPPipeSync(POLY_XLU_DISP++);

            vtx = GRAPH_ALLOC(gfxCtx, 32 * sizeof(Vtx));
            if (vtx == NULL) {
            } else {
                j = 0;
                for (i = 0; i < this->numElements; i++) {
                    elem = &this->elements[i];

                    if (elem->state == 1) {
                        f32 ratio = (f32)elem->timer / (f32)this->elemDuration;

                        switch (this->calcMode) {
                            case 1:
                                vtx[j].v.ob[0] = EffectSs_LerpS16(elem->p1.x, elem->p2.x, ratio);
                                vtx[j].v.ob[1] = EffectSs_LerpS16(elem->p1.y, elem->p2.y, ratio);
                                vtx[j].v.ob[2] = EffectSs_LerpS16(elem->p1.z, elem->p2.z, ratio);
                                vtx[j + 1].v.ob[0] = elem->p2.x;
                                vtx[j + 1].v.ob[1] = elem->p2.y;
                                vtx[j + 1].v.ob[2] = elem->p2.z;
                                break;

                            case 2:
                                vtx[j].v.ob[0] = elem->p1.x;
                                vtx[j].v.ob[1] = elem->p1.y;
                                vtx[j].v.ob[2] = elem->p1.z;
                                vtx[j + 1].v.ob[0] = EffectSs_LerpS16(elem->p2.x, elem->p1.x, ratio);
                                vtx[j + 1].v.ob[1] = EffectSs_LerpS16(elem->p2.y, elem->p1.y, ratio);
                                vtx[j + 1].v.ob[2] = EffectSs_LerpS16(elem->p2.z, elem->p1.z, ratio);
                                break;

                            case 3:
                                ratio *= 0.5f;
                                vtx[j].v.ob[0] = EffectSs_LerpS16(elem->p1.x, elem->p2.x, ratio);
                                vtx[j].v.ob[1] = EffectSs_LerpS16(elem->p1.y, elem->p2.y, ratio);
                                vtx[j].v.ob[2] = EffectSs_LerpS16(elem->p1.z, elem->p2.z, ratio);
                                vtx[j + 1].v.ob[0] = EffectSs_LerpS16(elem->p2.x, elem->p1.x, ratio);
                                vtx[j + 1].v.ob[1] = EffectSs_LerpS16(elem->p2.y, elem->p1.y, ratio);
                                vtx[j + 1].v.ob[2] = EffectSs_LerpS16(elem->p2.z, elem->p1.z, ratio);
                                ratio *= 2.0f;
                                break;

                            case 0:
                            default:
                                vtx[j].v.ob[0] = elem->p1.x;
                                vtx[j].v.ob[1] = elem->p1.y;
                                vtx[j].v.ob[2] = elem->p1.z;
                                vtx[j + 1].v.ob[0] = elem->p2.x;
                                vtx[j + 1].v.ob[1] = elem->p2.y;
                                vtx[j + 1].v.ob[2] = elem->p2.z;
                                break;
                        }

                        vtx[j].v.flag = 0;
                        vtx[j].v.tc[0] = 0;
                        vtx[j].v.tc[1] = 0;
                        vtx[j].v.cn[0] = EffectSs_LerpU8(this->p1StartColor[0], this->p1EndColor[0], ratio);
                        vtx[j].v.cn[1] = EffectSs_LerpU8(this->p1StartColor[1], this->p1EndColor[1], ratio);
                        vtx[j].v.cn[2] = EffectSs_LerpU8(this->p1StartColor[2], this->p1EndColor[2], ratio);
                        vtx[j].v.cn[3] = EffectSs_LerpU8(this->p1StartColor[3], this->p1EndColor[3], ratio);
                        j++;

                        vtx[j].v.flag = 0;
                        vtx[j].v.tc[0] = 0;
                        vtx[j].v.tc[1] = 0;
                        vtx[j].v.cn[0] = EffectSs_LerpU8(this->p2StartColor[0], this->p2EndColor[0], ratio);
                        vtx[j].v.cn[1] = EffectSs_LerpU8(this->p2StartColor[1], this->p2EndColor[1], ratio);
                        vtx[j].v.cn[2] = EffectSs_LerpU8(this->p2StartColor[2], this->p2EndColor[2], ratio);
                        vtx[j].v.cn[3] = EffectSs_LerpU8(this->p2StartColor[3], this->p2EndColor[3], ratio);
                        j++;
                    }
                }

                phi_t2 = 0;
                j = 0;

                gSPVertex(POLY_XLU_DISP++, vtx, 32, 0);

                for (i = 0; i < this->numElements; i++) {
                    elem = &this->elements[i];

                    if (elem->state == 0) {
                        phi_t2 = 0;
                    } else {
                        if (phi_t2 == 0) {
                            phi_t2 = 1;
                        } else {
                            gSP1Quadrangle(POLY_XLU_DISP++, j - 2, j - 1, j + 1, j, 0);

                            if (this->unkFlag == 1) {
                                phi_t2 = 0;
                            }
                        }
                        j += 2;
                    }
                }
            }
        } else if (this->drawMode <= EFF_BLURE_DRAW_MODE_SIMPLE_ALT_COLORS) {
            EffectBlure_DrawSimple(this, gfxCtx);
        } else {
            EffectBlure_DrawSmooth(this, gfxCtx);
        }
    }

    CLOSE_DISPS(gfxCtx);
}
