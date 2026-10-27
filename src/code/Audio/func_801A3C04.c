// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioSeq_QueueSeqCmd(s32);
extern u8 D_801CF030[];
void func_801A3C04(u8 arg0) {
    int new_var;
    new_var = (char) (arg0 & 0xFF);
    if (D_801CF030[new_var] & 2) {
        AudioSeq_QueueSeqCmd(0x110000FF);
        return;
    }
    if (D_801CF030[new_var] & 4) {
        AudioSeq_QueueSeqCmd(0x110000FF);
        return;
    }
    if (D_801CF030[new_var] & 0x80) {
        AudioSeq_QueueSeqCmd(0x130000FF);
        return;
    }
    AudioSeq_QueueSeqCmd(0x100000FF);
}
