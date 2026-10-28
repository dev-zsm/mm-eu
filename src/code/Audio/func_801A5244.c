// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4BEF;
void AudioSeq_QueueSeqCmd(u32 a);
void Audio_SetSfxVolumeExceptSystemAndOcarinaBanks(u8 a) {
    u8 i;
    int new_var;
    u32 v;
    if (D_801F4BEF == 0) {
        i = 0;
        v = 0;
        new_var = 0xB;
        do {
            if (((new_var != v) && (v != 0xC)) && (v != 0xD)) {
                AudioSeq_QueueSeqCmd(((i << 8) | 0x620A0000) | a);
            }
            i++;
            v = i;
        } while (i < 0x10);
    }
}
