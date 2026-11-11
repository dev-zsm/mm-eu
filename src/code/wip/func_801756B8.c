// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 7.00 (12 differ, size +4)
#include "generated/mm/graph.h"

void Graph_ExecuteAndDraw(GraphicsContext* gfxCtx, GameState* gameState) {
    u32 problem;

    gameState->unk_A3 = 0;
    Graph_SetNextGfxPool(gfxCtx);

    GameState_Update(gameState);

    OPEN_DISPS(gfxCtx);

    gSPEndDisplayList(WORK_DISP++);
    gSPEndDisplayList(POLY_OPA_DISP++);
    gSPEndDisplayList(POLY_XLU_DISP++);
    gSPEndDisplayList(OVERLAY_DISP++);
    gSPEndDisplayList(DEBUG_DISP++);

    CLOSE_DISPS(gfxCtx);

    {
        Gfx* gfx = gGfxMasterDL->taskStart;

        gSPSegment(gfx++, 0x0E, gGfxMasterDL);
        gSPDisplayList(gfx++, &ref_D_0E000000.disps[3]);
        gSPDisplayList(gfx++, &ref_D_0E000000.disps[0]);
        gSPDisplayList(gfx++, &ref_D_0E000000.disps[1]);
        gSPDisplayList(gfx++, &ref_D_0E000000.disps[2]);
        gSPDisplayList(gfx++, &ref_D_0E000000.debugDisp[0]);

        gDPPipeSync(gfx++);
        gDPFullSync(gfx++);
        gSPEndDisplayList(gfx++);
    }

    problem = false;

    {
        GfxPool* pool = &gGfxPools[gfxCtx->gfxPoolIdx % 2];

        if (pool->headMagic != GFXPOOL_HEAD_MAGIC) {
            Fault_AddHungupAndCrash("../graph.c", LN1(1046, 1054));
        }
        if (pool->tailMagic != GFXPOOL_TAIL_MAGIC) {
            Fault_AddHungupAndCrash("../graph.c", LN1(1058, 1066));
        }
    }

    if (THGA_IsCrash(&gfxCtx->polyOpa)) {
        PRINTF(T("POLY_OPA領域死亡\n", "POLY_OPA area death\n"));
        problem = true;
    }
    if (THGA_IsCrash(&gfxCtx->polyXlu)) {
        PRINTF(T("POLY_XLU領域死亡\n", "POLY_XLU area death\n"));
        problem = true;
    }
    if (THGA_IsCrash(&gfxCtx->overlay)) {
        PRINTF(T("OVERLAY領域死亡\n", "OVERLAY area death\n"));
        problem = true;
    }
    if (THGA_IsCrash(&gfxCtx->work)) {
        PRINTF(T("WORK領域死亡\n", "WORK area death\n"));
        problem = true;
    }
    if (THGA_IsCrash(&gfxCtx->debug)) {
        PRINTF(T("DEBUG領域死亡\n", "DEBUG area death\n"));
        problem = true;
    }

    if (!problem) {
        Graph_TaskSet00(gfxCtx, gameState);
        gfxCtx->gfxPoolIdx++;
        gfxCtx->framebufferIndex++;
    }

    {
        OSTime time = osGetTime();

        gRSPGfxTimeTotal = gRSPGfxTimeAcc;
        gRSPAudioTimeTotal = gRSPAudioTimeAcc;
        gRDPTimeTotal = gRDPTimeAcc;
        gRSPGfxTimeAcc = 0;
        gRSPAudioTimeAcc = 0;
        gRDPTimeAcc = 0;

        if (sGraphPrevUpdateEndTime != 0) {
            gGraphUpdatePeriod = time - sGraphPrevUpdateEndTime;
        }
        sGraphPrevUpdateEndTime = time;
    }
}
