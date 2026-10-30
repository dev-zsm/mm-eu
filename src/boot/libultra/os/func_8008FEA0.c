// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

s32 __osEPiRawReadIo(OSPiHandle *handle, u32 devAddr, u32 *data) {
    register u32 stat;
    u32 domain;

    stat = IO_READ(PI_STATUS_REG);
    while (stat & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
        stat = IO_READ(PI_STATUS_REG);
    }
    domain = handle->domain;
    if (D_80098080[domain]->type != handle->type) {
        OSPiHandle *cHandle = D_80098080[domain];

        if (domain == 0) {
            if (cHandle->latency != handle->latency) {
                IO_WRITE(PI_BSD_DOM1_LAT_REG, handle->latency);
            }
            if (cHandle->pageSize != handle->pageSize) {
                IO_WRITE(PI_BSD_DOM1_PGS_REG, handle->pageSize);
            }
            if (cHandle->relDuration != handle->relDuration) {
                IO_WRITE(PI_BSD_DOM1_RLS_REG, handle->relDuration);
            }
            if (cHandle->pulse != handle->pulse) {
                IO_WRITE(PI_BSD_DOM1_PWD_REG, handle->pulse);
            }
        } else {
            if (cHandle->latency != handle->latency) {
                IO_WRITE(PI_BSD_DOM2_LAT_REG, handle->latency);
            }
            if (cHandle->pageSize != handle->pageSize) {
                IO_WRITE(PI_BSD_DOM2_PGS_REG, handle->pageSize);
            }
            if (cHandle->relDuration != handle->relDuration) {
                IO_WRITE(PI_BSD_DOM2_RLS_REG, handle->relDuration);
            }
            if (cHandle->pulse != handle->pulse) {
                IO_WRITE(PI_BSD_DOM2_PWD_REG, handle->pulse);
            }
        }
        cHandle->type = handle->type;
        cHandle->latency = handle->latency;
        cHandle->pageSize = handle->pageSize;
        cHandle->relDuration = handle->relDuration;
        cHandle->pulse = handle->pulse;
    }
    *data = IO_READ((handle->baseAddress | devAddr) | K1BASE);
    return 0;
}
