// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// best attempt: ROM keeps &data in a saved register (s0) across the calls in cases 2-4; frame size already equal
#include "types.h"

typedef struct {
    s32 mq;
    s32 channel;
    s32 mode;
    u8 cmdStatus;
} OSVoiceHandle;

typedef struct {
    u16 warning;
    u16 answerNum;
    u16 voiceLevel;
    u16 voiceSn;
    u16 voiceTime;
    u16 answer[5];
    u16 distance[5];
} OSVoiceData;

extern s32 __osVoiceGetStatus();
extern s32 __osVoiceContRead2();
extern s32 __osVoiceContWrite4();
extern s32 __osVoiceContRead36();

s32 osVoiceGetReadData(OSVoiceHandle *hd, OSVoiceData *result) {
    static u8 sHandleStatus;
    s32 errorCode;
    s32 i;
    u8 status;
    u8 data[36];
    u8 *p;

    switch (hd->mode) {
        case 1:
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 1) {
                return 12;
            }
            errorCode = __osVoiceContRead2(hd->mq, hd->channel, 0, data);
            if (errorCode != 0) {
                return errorCode;
            }
            sHandleStatus = hd->cmdStatus = data[0] & 7;
            if (sHandleStatus != 0 && sHandleStatus != 7) {
                return 12;
            }
        case 2:
            hd->mode = 2;
            p = data;
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 2) {
                return 15;
            }
            *(u32 *)p = 0x600;
            errorCode = __osVoiceContWrite4(hd->mq, hd->channel, 0, p);
            if (errorCode != 0) {
                return errorCode;
            }
        case 3:
            hd->mode = 3;
            p = data;
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 1) {
                return 15;
            }
            errorCode = __osVoiceContRead36(hd->mq, hd->channel, p);
            if (errorCode != 0) {
                return errorCode;
            }
            result->warning = (p[5] << 8) + p[4];
            result->answerNum = p[6];
            result->voiceLevel = (p[9] << 8) + p[8];
            result->voiceSn = (p[11] << 8) + p[10];
            result->voiceTime = (p[13] << 8) + p[12];
            for (i = 0; i < 5; i++) {
                result->answer[i] = (p[15 + i * 4] << 8) + p[14 + i * 4];
                result->distance[i] = (p[17 + i * 4] << 8) + p[16 + i * 4];
            }
            if (result->answer[0] == 0x7FFF) {
                result->answerNum = 0;
            }
            hd->cmdStatus = p[34] & 7;
            if (sHandleStatus == 0 || hd->cmdStatus == 0) {
                break;
            }
        case 4:
            hd->mode = 4;
            p = data;
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 1) {
                return 15;
            }
            errorCode = __osVoiceContRead2(hd->mq, hd->channel, 0, p);
            if (errorCode != 0) {
                return errorCode;
            }
            hd->cmdStatus = p[0] & 7;
            if ((p[0] & 7) != 0) {
                return 15;
            }
            break;
        default:
            return 5;
    }
    hd->mode = 0;
    return errorCode;
}
