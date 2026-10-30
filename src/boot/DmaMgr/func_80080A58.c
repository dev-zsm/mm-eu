// FLAGS: -O2 -g3 -mips2
#include "dbg.h"
#include "yaz0.h"

void DmaMgr_ProcessRequest(DmaRequest *req) {
    u32 vrom = req->vromAddr;
    void *ram = req->dramAddr;
    u32 size = req->size;
    u32 romStart;
    u32 romSize;
    DmaEntry *dmaEntry;
    s32 index;

    index = DmaMgr_FindDmaIndex(vrom);
    if (index >= 0 && index < D_8009B68C) {
        dmaEntry = &D_8009FC80[index];
        if (dmaEntry->romEnd == 0) {
            if (dmaEntry->vromEnd < vrom + size) {
                Fault_AddHungupAndCrash(D_80098454, 0x1F3);
            }
            func_800807E0(D_8009FC80[index].romStart + vrom - D_8009FC80[index].vromStart, ram, size);
            return;
        }
        romSize = dmaEntry->romEnd - dmaEntry->romStart;
        romStart = dmaEntry->romStart;
        if (vrom != dmaEntry->vromStart) {
            Fault_AddHungupAndCrash(D_80098464, 0x206);
        }
        if (size != D_8009FC80[index].vromEnd - D_8009FC80[index].vromStart) {
            Fault_AddHungupAndCrash(D_80098474, 0x20D);
        }
        osSetThreadPri(NULL, 10);
        Yaz0_Decompress(romStart, ram, romSize);
        osSetThreadPri(NULL, 0x11);
        return;
    }
    Fault_AddHungupAndCrash(D_80098484, 0x22E);
}
