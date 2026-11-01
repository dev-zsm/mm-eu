#include "types.h"

extern u16 D_801CEFFC;
extern u8 D_801CF030[];
s32 AudioSeq_GetActiveSeqId(s32 a);
void Audio_SetSequenceMode(s32 a);
void AudioSeq_QueueSeqCmd(u32 cmd);
void AudioSeq_SetVolumeScale(s32 a, s32 b, s32 c, s32 d);

void func_801A3D04(u16 arg0) {
    u16 cur;
    s32 tmp;

    tmp = AudioSeq_GetActiveSeqId(0);
    cur = tmp;
    if (tmp == 0xFFFF) {
        cur = 0;
    }
    if (cur != arg0) {
        Audio_SetSequenceMode(3);
        if (!(D_801CF030[cur] & 8)) {
            D_801CEFFC = cur;
        }
        AudioSeq_QueueSeqCmd(arg0 + 0x8000);
        AudioSeq_SetVolumeScale(0, 3, 0x7F, 0);
    }
}
