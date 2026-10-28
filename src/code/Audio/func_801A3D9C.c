#include "types.h"

extern u16 D_801CEFFC;
extern u8 D_801CF030[];
extern u16 D_801F4C78;
u16 AudioSeq_GetActiveSeqId(s32 arg0);
void AudioSeq_QueueSeqCmd(s32 arg0);
void func_801A3D9C(void) {
    u16 *p = &D_801CEFFC;
    if ((AudioSeq_GetActiveSeqId(0) != 0xFFFF) && (D_801CF030[(u8) AudioSeq_GetActiveSeqId(0)] & 8)) {
        if (((*(&D_801CEFFC)) == 0xFFFF) || ((*(&D_801CEFFC)) == 0)) {
            AudioSeq_QueueSeqCmd(0x100000FF);
        } else {
            if ((*(&D_801CEFFC)) == 1) {
                *(&D_801CEFFC) = D_801F4C78;
            }
            AudioSeq_QueueSeqCmd((*(&D_801CEFFC)) + 0x8000);
        }
        D_801CEFFC = 0xFFFF;
    }
}
