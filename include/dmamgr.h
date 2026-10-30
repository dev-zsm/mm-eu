#ifndef DMAMGR_H
#define DMAMGR_H

#include "ultra64.h"
#include "stackcheck.h"

/* One row of the ROM table D_8009FC80, which ends with a row whose vromEnd is 0.
 * romEnd == 0: the file is stored uncompressed (romStart is the ROM address of vromStart); otherwise it is
 * compressed in [romStart, romEnd). */
typedef struct {
    /* 0x00 */ u32 vromStart;
    /* 0x04 */ u32 vromEnd;
    /* 0x08 */ u32 romStart;
    /* 0x0C */ u32 romEnd;
} DmaEntry;

typedef struct {
    /* 0x00 */ u32 vromAddr;
    /* 0x04 */ void *dramAddr;
    /* 0x08 */ u32 size;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ OSMesgQueue *notifyQueue;  /* receives notifyMsg once the transfer is done; may be NULL */
    /* 0x1C */ OSMesg notifyMsg;
} DmaRequest;

extern DmaEntry D_8009FC80[];
extern u16 D_8009B68C;           /* number of rows of D_8009FC80 */
extern OSMesgQueue D_8009B690;   /* requests for the DMA thread */
extern OSMesg D_8009B6A8[32];
extern StackEntry D_8009B670;    /* stack check entry of the DMA thread */
extern u8 D_8009B8D8[0x500];     /* stack of the DMA thread */
extern u8 D_8009BDD8[];          /* end of that stack (stack top) */
extern OSThread D_8009B728;
extern char D_80098450[];        /* "??" */
extern char D_80098454[];        /* "../z_std_dma.c", once per Fault_AddHungupAndCrash call */
extern char D_80098464[];
extern char D_80098474[];
extern char D_80098484[];
extern char D_80098494[];        /* "dmamgr" */
extern u8 D_1A8D0[];             /* ROM start of the table */
extern u8 D_20C20[];             /* ROM end of the table */

s32 func_800807E0(u32 romStart, void *ramStart, u32 size);  /* ROM to RAM copy through the Pi */

DmaEntry *DmaMgr_FindDmaEntry(u32 vrom);
s32 DmaMgr_TranslateVromToRom(u32 vrom);
s32 DmaMgr_FindDmaIndex(u32 vrom);
const char *func_80080A44(u32 vrom);
void DmaMgr_ProcessRequest(DmaRequest *req);
void DmaMgr_ThreadEntry(void *arg);
s32 DmaMgr_RequestAsync(DmaRequest *req, void *ram, u32 vrom, u32 size, u32 unused, OSMesgQueue *queue, OSMesg msg);
s32 DmaMgr_RequestSync(void *ram, u32 vrom, u32 size);
void DmaMgr_Init(void);
void DmaMgr_Stop(void);

#endif
