// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vr_box.h"

s32 Skybox_CalculateFace128(SkyboxContext* skyboxCtx, Vtx* roomVtx, s32 roomVtxStartIndex, s32 xStart, s32 yStart,
                            s32 zStart, s32 innerIncrVal, s32 outerIncrVal, s32 faceNum) {
    s32 i;
    s32 j;
    s32 k;
    s16 uls;
    s16 m;
    s32 outerIncr;
    u16 index;
    s16 ult;
    s16 l;
    s16 vtxIndex;
    s32 innerIncr;
    s32 xPoints[5 * 5];
    s32 yPoints[5 * 5];
    s32 zPoints[5 * 5];
    s32 tcS[5 * 5];
    s32 tcT[5 * 5];
    s32 pad;

    
    switch (faceNum) {
        case 0: 
        case 1:
            outerIncr = yStart;

            for (i = 0, k = 0; k < 25; i++) {
                innerIncr = xStart;
                for (j = 0; j < 5; j++, k++) {
                    zPoints[k] = zStart;
                    xPoints[k] = innerIncr;
                    yPoints[k] = outerIncr;
                    tcS[k] = sSkybox128TexSCoords[j];
                    tcT[k] = sSkybox128TexTCoords[i];
                    innerIncr += innerIncrVal;
                }
                outerIncr += outerIncrVal;
            }
            break;

        case 2: 
        case 3:
            outerIncr = yStart;

            for (i = 0, k = 0; k < 25; i++) {
                innerIncr = zStart;
                for (j = 0; j < 5; j++, k++) {
                    xPoints[k] = xStart;
                    yPoints[k] = outerIncr;
                    zPoints[k] = innerIncr;
                    tcS[k] = sSkybox128TexSCoords[j];
                    tcT[k] = sSkybox128TexTCoords[i];
                    innerIncr += innerIncrVal;
                }
                outerIncr += outerIncrVal;
            }
            break;

        case 4: 
        case 5:
            outerIncr = zStart;

            for (i = 0, k = 0; k < 25; i++) {
                innerIncr = xStart;
                for (j = 0; j < 5; j++, k++) {
                    yPoints[k] = yStart;
                    xPoints[k] = innerIncr;
                    zPoints[k] = outerIncr;
                    tcS[k] = sSkybox128TexSCoords[j];
                    tcT[k] = sSkybox128TexTCoordsXZ[i];
                    innerIncr += innerIncrVal;
                }
                outerIncr += outerIncrVal;
            }
            break;

        default:
            break;
    }

    
    skyboxCtx->gfx = &skyboxCtx->dListBuf[2 * faceNum][0];

    
    for (i = 0; i < ARRAY_COUNT(sSkybox128VtxBufIndices); i++) {
        index = sSkybox128VtxBufIndices[i];

        roomVtx[roomVtxStartIndex + i].v.ob[0] = xPoints[index];
        roomVtx[roomVtxStartIndex + i].v.ob[1] = yPoints[index];
        roomVtx[roomVtxStartIndex + i].v.ob[2] = zPoints[index];
        roomVtx[roomVtxStartIndex + i].v.flag = 0;
        roomVtx[roomVtxStartIndex + i].v.tc[0] = tcS[index];
        roomVtx[roomVtxStartIndex + i].v.tc[1] = tcT[index];
        roomVtx[roomVtxStartIndex + i].v.cn[1] = 0;
        roomVtx[roomVtxStartIndex + i].v.cn[2] = 0;
        roomVtx[roomVtxStartIndex + i].v.cn[0] = 255;
    }
    gSPVertex(skyboxCtx->gfx++, &roomVtx[roomVtxStartIndex], 32, 0);
    roomVtxStartIndex += i; 

    
    gSPCullDisplayList(skyboxCtx->gfx++, 0, 15);

    
    if ((faceNum == 4) || (faceNum == 5)) {
        
        ult = 0;
        for (vtxIndex = 0, l = 0; l < 4; l++, ult += 31) {
            for (uls = 0, m = 0; m < 4; m++, uls += 31, vtxIndex += 4) {
                gDPLoadMultiTile(skyboxCtx->gfx++,
                                 (uintptr_t)skyboxCtx->staticSegments[0] + sSkybox128TexOffsets[faceNum], 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, uls, ult, uls + 31, ult + 31, 0,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(
                    skyboxCtx->gfx++, (uintptr_t)skyboxCtx->staticSegments[1] + sSkybox128TexOffsets[faceNum], 0x80, 1,
                    G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, uls, ult, uls + 31, ult + 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                    G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->gfx++, sSkybox128VtxIndices[vtxIndex + 1], sSkybox128VtxIndices[vtxIndex + 2],
                               sSkybox128VtxIndices[vtxIndex + 3], sSkybox128VtxIndices[vtxIndex + 0], 3);
            }
        }
    } else {
        
        ult = 0;
        for (vtxIndex = 0, l = 0; l < 2; l++, ult += 31) {
            for (uls = 0, m = 0; m < 4; m++, uls += 31, vtxIndex += 4) {
                gDPLoadMultiTile(skyboxCtx->gfx++,
                                 (uintptr_t)skyboxCtx->staticSegments[0] + sSkybox128TexOffsets[faceNum], 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, uls, ult, uls + 31, ult + 31, 0,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(
                    skyboxCtx->gfx++, (uintptr_t)skyboxCtx->staticSegments[1] + sSkybox128TexOffsets[faceNum], 0x80, 1,
                    G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, uls, ult, uls + 31, ult + 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                    G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->gfx++, sSkybox128VtxIndices[vtxIndex + 1], sSkybox128VtxIndices[vtxIndex + 2],
                               sSkybox128VtxIndices[vtxIndex + 3], sSkybox128VtxIndices[vtxIndex + 0], 3);
            }
        }
        ult -= 31;
        for (l = 0; l < 2; l++, ult -= 31) {
            for (uls = 0, m = 0; m < 4; m++, uls += 31, vtxIndex += 4) {
                gDPLoadMultiTile(skyboxCtx->gfx++,
                                 (uintptr_t)skyboxCtx->staticSegments[0] + sSkybox128TexOffsets[faceNum], 0,
                                 G_TX_RENDERTILE, G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, uls, ult, uls + 31, ult + 31, 0,
                                 G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP,
                                 G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadMultiTile(
                    skyboxCtx->gfx++, (uintptr_t)skyboxCtx->staticSegments[1] + sSkybox128TexOffsets[faceNum], 0x80, 1,
                    G_IM_FMT_CI, G_IM_SIZ_8b, 128, 0, uls, ult, uls + 31, ult + 31, 0, G_TX_NOMIRROR | G_TX_WRAP,
                    G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gSP1Quadrangle(skyboxCtx->gfx++, sSkybox128VtxIndices[vtxIndex + 1], sSkybox128VtxIndices[vtxIndex + 2],
                               sSkybox128VtxIndices[vtxIndex + 3], sSkybox128VtxIndices[vtxIndex + 0], 3);
            }
        }
    }

    gSPEndDisplayList(skyboxCtx->gfx++);
    return roomVtxStartIndex;
}
