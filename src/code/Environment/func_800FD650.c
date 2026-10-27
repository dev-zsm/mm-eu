// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_SetAmbienceChannelIO(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK, void *);             /* extern */
s32 AudioSeq_GetActiveSeqId(M2C_UNK, void *);                 /* extern */
extern u16 D_801E6EFC;

void Environment_StopStormNatureAmbience(void *arg0) {
    if (((M2C_FIELD(arg0, u8 *, 0x814) != 0x7F) && (M2C_FIELD(arg0, u8 *, 0x815) == 0x13)) || (AudioSeq_GetActiveSeqId(0, arg0) == 0x57)) {
        AudioSeq_QueueSeqCmd(0x141400FF, arg0);
    } else if ((M2C_FIELD(arg0, u8 *, 0x814) != 0x7F) && (M2C_FIELD(arg0, u8 *, 0x815) != 0x13) && ((s32) D_801E6EFC >= 0x4000) && ((s32) D_801E6EFC < 0xC000)) {
        AudioSeq_QueueSeqCmd(0x141400FF, arg0);
    }
    Audio_SetAmbienceChannelIO(0xE, 1, 0);
    Audio_SetAmbienceChannelIO(0xF, 1, 0);
}
