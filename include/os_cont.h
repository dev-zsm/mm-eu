#ifndef OS_CONT_H
#define OS_CONT_H

#include "ultra64.h"
#include "os_sp.h"  /* SI registers and the SI access functions */

/* Serial interface (SI): the controllers and Controller Paks are reached through the PIF RAM. */
#define MAXCONTROLLERS 4

/* Commands of a PIF RAM channel. */
#define CONT_CMD_REQUEST_STATUS 0x00
#define CONT_CMD_READ_BUTTON 0x01
#define CONT_CMD_READ_MEMPACK 0x02
#define CONT_CMD_WRITE_MEMPACK 0x03
#define CONT_CMD_READ36_VOICE 0x09
#define CONT_CMD_WRITE20_VOICE 0x0A
#define CONT_CMD_READ2_VOICE 0x0B
#define CONT_CMD_WRITE4_VOICE 0x0C
#define CONT_CMD_CHANNEL_RESET 0xFD
#define CONT_CMD_END 0xFE

typedef struct {
    /* 0x0 */ u16 type;
    /* 0x2 */ u8 status;
    /* 0x3 */ u8 errno;
} OSContStatus;

typedef struct {
    /* 0x0 */ u16 button;
    /* 0x2 */ s8 stick_x;
    /* 0x3 */ s8 stick_y;
    /* 0x4 */ u8 errno;
} OSContPad;

/* The 64 bytes exchanged with the PIF. */
typedef struct {
    /* 0x00 */ u32 ramarray[15];
    /* 0x3C */ u32 pifstatus;
} OSPifRam;

/* Layouts of one channel inside the PIF RAM. */
typedef struct {
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u8 typeh;
    /* 0x5 */ u8 typel;
    /* 0x6 */ u8 status;
    /* 0x7 */ u8 dummy1;
} __OSContRequestFormat;

typedef struct {
    /* 0x0 */ u8 txsize;
    /* 0x1 */ u8 rxsize;
    /* 0x2 */ u8 cmd;
    /* 0x3 */ u8 typel;
    /* 0x4 */ u8 typeh;
    /* 0x5 */ u8 status;
} __OSContRequestFormatShort;

typedef struct {
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u16 button;
    /* 0x6 */ s8 stick_x;
    /* 0x7 */ s8 stick_y;
} __OSContReadFormat;

/* Read or write of one 32-byte block of a Controller Pak. */
typedef struct {
    /* 0x00 */ u8 dummy;
    /* 0x01 */ u8 txsize;
    /* 0x02 */ u8 rxsize;
    /* 0x03 */ u8 cmd;
    /* 0x04 */ u8 addrh;
    /* 0x05 */ u8 addrl;
    /* 0x06 */ u8 data[32];
    /* 0x26 */ u8 datacrc;
    /* 0x27 */ u8 end;
} __OSContRamFormat;

/* Controller PIF RAM, the number of controllers polled and the last command sent. */
extern OSPifRam D_8009D2A0;
extern u8 D_8009D2E0;   /* last command packed in D_8009D2A0 */
extern u8 D_8009D2E1;   /* number of channels in use */
extern s32 D_80098030;  /* osContInit already ran */
/* Controller Pak PIF RAM and the command and channel it was last filled for. */
extern OSPifRam D_8009E9A0;
extern s32 D_800981A0;  /* channel of the last Pak command */
/* Rumble Pak PIF RAM images, one of 0x40 bytes per channel. */
extern u8 D_8009D180[];
extern OSMesgQueue D_8009D308;  /* serial interface access queue */
extern OSMesg D_8009D320[1];

s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *data);
s32 osContStartQuery(OSMesgQueue *mq);
void osContGetQuery(OSContStatus *data);
s32 osContStartReadData(OSMesgQueue *mq);
void osContGetReadData(OSContPad *data);
s32 osContSetCh(u8 channels);

void __osContGetInitData(u8 *pattern, OSContStatus *data);
void __osPackRequestData(u8 cmd);
void __osPackReadData(void);
s32 __osContChannelReset(OSMesgQueue *mq, s32 channels);
u8 __osContAddressCrc(u16 addr);
u8 __osContDataCrc(u8 *data);
s32 __osContRamRead(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer);
s32 __osContRamWrite(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer, s32 force);
void __osMakeMotorData(s32 channel, u8 *buf);


#endif
