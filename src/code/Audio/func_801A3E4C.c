// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_PlayAmbience(u8);                          /* extern */
s16 AudioSeq_GetActiveSeqId(M2C_UNK);                         /* extern */
extern s16 D_801CEFFC;

void func_801A3E4C(u8 arg0) {
    s16 temp_v0;

    temp_v0 = AudioSeq_GetActiveSeqId(0);
    if (temp_v0 != 1) {
        D_801CEFFC = temp_v0;
    }
    Audio_PlayAmbience(arg0);
}
