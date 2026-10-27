// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 vromAddr;
    void *dramAddr;
    u32 size;
} DmaRequest;

typedef struct {
    u32 vromStart;
    u32 vromEnd;
    u32 romStart;
    u32 romEnd;
} DmaEntry;

extern u16 D_8009B68C;
extern DmaEntry D_8009FC80[];
extern u8 D_80098454[];
extern u8 D_80098464[];
extern u8 D_80098474[];
extern u8 D_80098484[];
s32 DmaMgr_FindDmaIndex(u32 vrom);
void func_800807E0(u32 rom, void *ram, u32 size);
void Fault_AddHungupAndCrash(void *file, s32 line);
void Yaz0_Decompress(u32 romStart, void *dst, u32 size);
void osSetThreadPri(void *t, s32 pri);

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
        osSetThreadPri(0, 10);
        Yaz0_Decompress(romStart, ram, romSize);
        osSetThreadPri(0, 0x11);
        return;
    }
    Fault_AddHungupAndCrash(D_80098484, 0x22E);
}
