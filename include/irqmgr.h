#ifndef IRQMGR_H
#define IRQMGR_H

#include "ultra64.h"

/* A message queue that receives the messages of the manager; the clients form a singly linked list. */
typedef struct IrqMgrClient {
    /* 0x00 */ struct IrqMgrClient *next;
    /* 0x04 */ OSMesgQueue *queue;
} IrqMgrClient;

typedef struct {
    /* 0x000 */ u8 retraceMsg[0x20];
    /* 0x020 */ u8 prenmiMsg[0x20];
    /* 0x040 */ u8 prenmi450Msg[0x20];
    /* 0x060 */ OSMesgQueue irqQueue;
    /* 0x078 */ OSMesg irqBuffer[8];
    /* 0x098 */ OSThread thread;
    /* 0x248 */ IrqMgrClient *clients;
    /* 0x24C */ u8 resetStatus;
    /* 0x250 */ OSTime resetTime;
    /* 0x258 */ OSTimer timer;
    /* 0x278 */ OSTime retraceTime;
} IrqMgr;

extern volatile s32 D_80096D00;   /* reset status, 0 until the pre-NMI event */
extern volatile OSTime D_80096D08;  /* time of the pre-NMI event */
extern volatile OSTime D_80096D10;  /* duration of the first frame */
extern s32 D_80096D18;            /* retrace count */

OSIntMask osSetIntMask(OSIntMask mask);
void osAfterPreNMI(void);

void IrqMgr_AddClient(IrqMgr *irqMgr, IrqMgrClient *client, OSMesgQueue *queue);
void IrqMgr_RemoveClient(IrqMgr *irqMgr, IrqMgrClient *client);
void IrqMgr_SendMesgToClients(IrqMgr *irqMgr, OSMesg msg);
void IrqMgr_JamMesgToClients(IrqMgr *irqMgr, OSMesg msg);
void IrqMgr_HandlePreNMI(IrqMgr *irqMgr);
void IrqMgr_CheckStacks(void);
void IrqMgr_HandlePRENMI450(IrqMgr *irqMgr);
void IrqMgr_HandlePRENMI480(IrqMgr *irqMgr);
void IrqMgr_HandlePRENMI500(IrqMgr *irqMgr);
void IrqMgr_HandleRetrace(IrqMgr *irqMgr);

#endif
