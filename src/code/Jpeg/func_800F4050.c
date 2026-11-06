// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_jpeg.h"

void Jpeg_ScheduleDecoderTask(JpegContext* jpegCtx) {
    static OSTask sJpegTask = {
        M_NJPEGTASK,                         
        0,                                   
        NULL,                                
        0,                                   
        njpgdspMainTextStart,                
        SP_UCODE_SIZE,                       
        njpgdspMainDataStart,                
        SP_UCODE_DATA_SIZE,                  
        NULL,                                
        0,                                   
        NULL,                                
        NULL,                                
        NULL,                                
        sizeof(JpegTaskData),                
        NULL,                                
        sizeof(jpegCtx->workBuf->yieldData), 
    };

    JpegWork* workBuf = jpegCtx->workBuf;
    s32 pad[2];

    workBuf->taskData.address = &workBuf->data;
    workBuf->taskData.mode = jpegCtx->mode;
    workBuf->taskData.mbCount = 4;
    workBuf->taskData.qTableYPtr = &workBuf->qTableY;
    workBuf->taskData.qTableUPtr = &workBuf->qTableU;
    workBuf->taskData.qTableVPtr = &workBuf->qTableV;

    sJpegTask.t.flags = 0;
    sJpegTask.t.ucode_boot = SysUcode_GetUCodeBoot();
    sJpegTask.t.ucode_boot_size = SysUcode_GetUCodeBootSize();
    sJpegTask.t.yield_data_ptr = (u64*)&workBuf->yieldData;
    sJpegTask.t.data_ptr = (u64*)&workBuf->taskData;

    jpegCtx->scTask.next = NULL;
    jpegCtx->scTask.flags = OS_SC_NEEDS_RSP;
    jpegCtx->scTask.msgQ = &jpegCtx->mq;
    jpegCtx->scTask.msg = NULL;
    jpegCtx->scTask.framebuffer = NULL;
    jpegCtx->scTask.list = sJpegTask;

    osSendMesg(&gScheduler.cmdQueue, (OSMesg*)&jpegCtx->scTask, OS_MESG_BLOCK);
    Sched_SendNotifyMsg(&gScheduler); 
    osRecvMesg(&jpegCtx->mq, NULL, OS_MESG_BLOCK);
}
