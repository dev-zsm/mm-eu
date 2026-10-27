#include "types.h"

extern u16 AudioSeq_GetActiveSeqId(s32);
extern u8 D_801CF030[];
extern u8 D_801CF000;
extern s8 D_801FCA6B;

void Audio_UpdateSceneSequenceResumePoint(void) {
    u16 seqId = AudioSeq_GetActiveSeqId(0);

    if (seqId != 0xFFFF) {
        // the redundant (u8) cast on the masked index is needed to match register allocation
        if (D_801CF030[(u8)(seqId & 0xFF)] & 0x10) {
            if (D_801CF000 != 0xC0) {
                D_801CF000 = D_801FCA6B;
            } else {
                D_801CF000 = 0;
            }
        }
    }
}
