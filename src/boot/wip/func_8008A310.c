// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    s32 mq;
    s32 channel;
    s32 mode;
    u8 cmdStatus;
} VoiceHandle;

typedef struct {
    u16 warning;
    u16 answerNum;
    u16 voiceLevel;
    u16 voiceSn;
    u16 voiceTime;
    u16 answer[5];
    u16 distance[5];
} VoiceData;

extern u8 D_8009D330;

s32 __osVoiceGetStatus(s32 mq, s32 channel, u8 *status);
s32 __osVoiceContRead2(s32 mq, s32 channel, s32 address, u8 *buffer);
s32 __osVoiceContWrite4(s32 mq, s32 channel, s32 address, u8 *buffer);
s32 __osVoiceContRead36(s32 mq, s32 channel, s32 address, u8 *buffer);

s32 osVoiceGetReadData(VoiceHandle *hd, VoiceData *result) {
    s32 errorCode;
    u8 data[36];
    u8 status;
    s32 i;

    switch (hd->mode) {
        case 1:
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 1) {
                return 0xC;
            }
            errorCode = __osVoiceContRead2(hd->mq, hd->channel, 0, data);
            if (errorCode != 0) {
                return errorCode;
            }
            hd->cmdStatus = data[0] & 7;
            D_8009D330 = hd->cmdStatus;
            if (hd->cmdStatus != 0 && hd->cmdStatus != 7) {
                return 0xC;
            }
        case 2:
            hd->mode = 2;
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 2) {
                return 0xF;
            }
            *(u32 *)data = 0x600;
            errorCode = __osVoiceContWrite4(hd->mq, hd->channel, 0, data);
            if (errorCode != 0) {
                return errorCode;
            }
        case 3:
            hd->mode = 3;
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 1) {
                return 0xF;
            }
            errorCode = __osVoiceContRead36(hd->mq, hd->channel, 0, data);
            if (errorCode != 0) {
                return errorCode;
            }
            result->warning = (data[5] << 8) + data[4];
            result->answerNum = data[6];
            result->voiceLevel = (data[9] << 8) + data[8];
            result->voiceSn = (data[11] << 8) + data[10];
            result->voiceTime = (data[13] << 8) + data[12];
            for (i = 0; i < 5; i++) {
                result->answer[i] = (data[15 + i * 4] << 8) + data[14 + i * 4];
                result->distance[i] = (data[17 + i * 4] << 8) + data[16 + i * 4];
            }
            if (result->answer[0] == 0x7FFF) {
                result->answerNum = 0;
            }
            hd->cmdStatus = data[0x22] & 7;
            if (D_8009D330 == 0 || hd->cmdStatus == 0) {
                hd->mode = 0;
                return errorCode;
            }
        case 4:
            hd->mode = 4;
            errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
            if (errorCode != 0) {
                return errorCode;
            }
            if (status & 1) {
                return 0xF;
            }
            errorCode = __osVoiceContRead2(hd->mq, hd->channel, 0, data);
            if (errorCode != 0) {
                return errorCode;
            }
            hd->cmdStatus = data[0] & 7;
            if (hd->cmdStatus == 0) {
                hd->mode = 0;
                return errorCode;
            }
            return 0xF;
        default:
            return 5;
    }
}
