// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/graph.h"

void Graph_TaskSet00(GraphicsContext* gfxCtx, GameState* gameState) {
    OSTask_t* task = &gfxCtx->task.list.t;
    OSScTask* scTask = &gfxCtx->task;
    OSTimer timer;
    OSMesg msg;

#if MM_VERSION >= N64_US
retry:
#endif
    osSetTimer(&timer, OS_USEC_TO_CYCLES(3 * 1000 * 1000), 0, &gfxCtx->queue, (OSMesg)666);
    osRecvMesg(&gfxCtx->queue, &msg, OS_MESG_BLOCK);
    osStopTimer(&timer);

    if (msg == (OSMesg)666) {
#if MM_VERSION >= N64_US
        static s32 sRetryCount = 10;
        s32 pad;

        osSyncPrintf("GRAPH SP TIMEOUT\n");
        if (sRetryCount >= 0) {
            sRetryCount--;
            Sched_SendGfxCancelMsg(&gScheduler);
            goto retry;
        } else {
            osSyncPrintf(T("graph.c:もうダメ！死ぬ！\n", "graph.c: I can't go on! I'm dying!\n"));
            Fault_AddHungupAndCrashImpl("RCP is HUNG UP!!", "Oh! MY GOD!!");
        }
#else
        Fault_AddHungupAndCrashImpl("RCP is HUNG UP!!", "Oh! MY GOD!!");
#endif
    }

#if MM_VERSION < N64_US
    osRecvMesg(&gfxCtx->queue, &msg, OS_MESG_NOBLOCK);
#endif

    gfxCtx->masterList = gGfxMasterDL;

    if (gfxCtx->callback != NULL) {
        gfxCtx->callback(gfxCtx, gfxCtx->callbackArg);
    }

    task->type = M_GFXTASK;
    task->flags = OS_SC_DRAM_DLIST;
    task->ucode_boot = SysUcode_GetUCodeBoot();
    task->ucode_boot_size = SysUcode_GetUCodeBootSize();
    task->ucode = SysUcode_GetUCode();
    task->ucode_data = SysUcode_GetUCodeData();
    task->ucode_size = SP_UCODE_SIZE;
    task->ucode_data_size = SP_UCODE_DATA_SIZE;
    task->dram_stack = gGfxSPTaskStack;
    task->dram_stack_size = sizeof(gGfxSPTaskStack);
    task->output_buff = gGfxSPTaskOutputBufferPtr;
    task->output_buff_size = gGfxSPTaskOutputBufferEnd;
    task->data_ptr = (u64*)gGfxMasterDL;
    task->data_size = 0;
    task->yield_data_ptr = gGfxSPTaskYieldBuffer;
    task->yield_data_size = sizeof(gGfxSPTaskYieldBuffer);

    scTask->next = NULL;
    scTask->flags = OS_SC_RCP_MASK | OS_SC_SWAPBUFFER | OS_SC_LAST_TASK;

    if (SREG(33) & 1) {
        SREG(33) &= ~1;
        scTask->flags &= ~OS_SC_SWAPBUFFER;
        gfxCtx->framebufferIndex--;
    }

    scTask->msgQ = &gfxCtx->queue;
    scTask->msg = NULL;

    {
        static s32 sCfbIndex = 0;
        CfbInfo* cfb = &sGraphCfbInfos[sCfbIndex];

        sCfbIndex = (sCfbIndex + 1) % ARRAY_COUNT(sGraphCfbInfos);

        cfb->framebuffer = gfxCtx->curFrameBuffer;
        cfb->swapBuffer = gfxCtx->curFrameBuffer;

        if (gfxCtx->updateViMode) {
            gfxCtx->updateViMode = false;
            cfb->viMode = gfxCtx->viMode;
            cfb->viFeatures = gfxCtx->viConfigFeatures;
            cfb->xScale = gfxCtx->xScale;
            cfb->yScale = gfxCtx->yScale;
        } else {
            cfb->viMode = NULL;
        }
        cfb->unk_10 = 0;
        cfb->updateRate = gameState->framerateDivisor;

        scTask->framebuffer = cfb;
    }

#if MM_VERSION >= N64_US
    while (gfxCtx->queue.validCount != 0) {
        osRecvMesg(&gfxCtx->queue, NULL, OS_MESG_NOBLOCK);
    }
#endif

    gfxCtx->schedMsgQ = &gScheduler.cmdQueue;
    osSendMesg(&gScheduler.cmdQueue, (OSMesg)scTask, OS_MESG_BLOCK);
    Sched_SendNotifyMsg(&gScheduler);
}
