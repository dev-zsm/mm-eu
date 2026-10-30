#ifndef OS_VOICE_H
#define OS_VOICE_H

#include "ultra64.h"
#include "os_pfs.h"

/* Error codes of the voice recognition functions (the low ones are the Controller Pak codes). */
#define CONT_ERR_VOICE_MEMORY 13
#define CONT_ERR_VOICE_WORD 14
#define CONT_ERR_VOICE_NO_RESPONSE 15

typedef struct {
    /* 0x0 */ OSMesgQueue *mq;
    /* 0x4 */ s32 channel;
    /* 0x8 */ s32 mode;      /* non-zero while osVoiceStartReadData is active */
    /* 0xC */ u8 cmdStatus;  /* low bits of the last result */
} OSVoiceHandle;

/* Read of 36 bytes from the voice unit. */
typedef struct {
    /* 0x00 */ u8 dummy;
    /* 0x01 */ u8 txsize;
    /* 0x02 */ u8 rxsize;
    /* 0x03 */ u8 cmd;
    /* 0x04 */ u8 addrh;
    /* 0x05 */ u8 addrl;
    /* 0x06 */ u8 data[36];
    /* 0x2A */ u8 datacrc;
    /* 0x2B */ u8 end;
} __OSVoiceRead36Format;

/* Status request. */
typedef struct {
    /* 0x0 */ u8 dummy;
    /* 0x1 */ u8 txsize;
    /* 0x2 */ u8 rxsize;
    /* 0x3 */ u8 cmd;
    /* 0x4 */ u8 status;
    /* 0x5 */ u8 data;
} __OSVoiceStatusFormat;

extern u8 D_80098190[5];  /* register values written to the A/D converter by osVoiceInit */
extern u8 D_80098410[8];  /* gain values of osVoiceControlGain */

s32 osVoiceInit(OSMesgQueue *mq, OSVoiceHandle *hd, s32 channel);
s32 osVoiceCheckWord(u8 *word);
s32 osVoiceClearDictionary(OSVoiceHandle *hd, u8 numWords);
s32 osVoiceControlGain(OSVoiceHandle *hd, s32 analog, s32 digital);
s32 osVoiceMaskDictionary(OSVoiceHandle *hd, u8 *maskPattern, s32 size);
s32 osVoiceSetWord(OSVoiceHandle *hd, u8 *word);
s32 osVoiceStartReadData(OSVoiceHandle *hd);
s32 osVoiceStopReadData(OSVoiceHandle *hd);

s32 __osVoiceCheckResult(OSVoiceHandle *hd, u8 *status);
s32 __osVoiceGetStatus(OSMesgQueue *mq, s32 channel, u8 *status);
s32 __osVoiceSetADConverter(OSMesgQueue *mq, s32 channel, u8 data);
u8 __osVoiceContDataCrc(u8 *data, u32 bytes);
s32 __osVoiceContRead2(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer);
s32 __osVoiceContRead36(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer);
s32 __osVoiceContWrite4(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer);
s32 __osVoiceContWrite20(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer);

#endif
