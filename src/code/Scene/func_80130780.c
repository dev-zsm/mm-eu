// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_SetSpec(u8, void *);                  /* extern */
s32 AudioSeq_GetActiveSeqId(M2C_UNK);                         /* extern */
extern u8 D_801EAE06;

void Scene_CommandSoundSettings(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u8 *, 0x814) = (u8) M2C_FIELD(arg1, u8 *, 7);
    M2C_FIELD(arg0, u8 *, 0x815) = (u8) M2C_FIELD(arg1, u8 *, 6);
    if ((D_801EAE06 == 0xFF) || (AudioSeq_GetActiveSeqId(0) == 0x57)) {
        Audio_SetSpec(M2C_FIELD(arg1, u8 *, 1), arg1);
    }
}
