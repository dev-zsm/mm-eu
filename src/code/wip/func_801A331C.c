#include "types.h"

void AudioSeq_QueueSeqCmd(s32 a);
s32 AudioSeq_GetActiveSeqId(u8 a);
void AudioSeq_SetVolumeScale(s32 a, s32 b, u8 c, s32 d);

void func_801A331C(u8 arg0, u8 arg1) {

    u32 mask = 0;
    u8 vol = 0;
    s32 ret;

    switch (arg1) {
        case 0:
            vol = 0x7F;
            break;
        case 1:
            mask = 0xFFFF;
            break;
        case 2:
            vol = 0xFF;
            break;
    }
    if (vol != 0xFF) {
        
        AudioSeq_QueueSeqCmd((arg0 << 24) | 0xA0000000 | mask);
        AudioSeq_SetVolumeScale(0, 3, vol, 1);
        return;
    }
    AudioSeq_SetVolumeScale(0, 3, 0x7F, 0);
    ret = AudioSeq_GetActiveSeqId(arg0);
    mask = ret & 0xFFFF;
    if (ret != 0xFFFF) {
        AudioSeq_QueueSeqCmd((arg0 << 24) | mask);
    }
}
