// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_SetAmbienceChannelIO(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK Audio_PlayAmbience(u8, void *);                  /* extern */
s32 AudioSeq_GetActiveSeqId(M2C_UNK, void *);                 /* extern */
extern u16 D_801E6EFC;

void Environment_PlayStormNatureAmbience(void *arg0) {
    u8 temp_a0;

    if (((M2C_FIELD(arg0, u8 *, 0x814) != 0x7F) && (M2C_FIELD(arg0, u8 *, 0x815) == 0x13)) || (AudioSeq_GetActiveSeqId(0, arg0) == 0x57)) {
        Audio_PlayAmbience(7U, arg0);
    } else if (M2C_FIELD(arg0, u8 *, 0x814) != 0x7F) {
        temp_a0 = M2C_FIELD(arg0, u8 *, 0x815);
        if ((temp_a0 != 0x13) && ((s32) D_801E6EFC >= 0x4000) && ((s32) D_801E6EFC < 0xC000)) {
            Audio_PlayAmbience(temp_a0, arg0);
        }
    }
    Audio_SetAmbienceChannelIO(0xE, 1, 1);
    Audio_SetAmbienceChannelIO(0xF, 1, 1);
}
