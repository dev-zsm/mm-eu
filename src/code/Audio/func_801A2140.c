// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_SetSequenceProperties(u8, M2C_UNK *, s16, s32, f32, f32, f32); /* extern */
s32 AudioSeq_GetActiveSeqId(u8);                              /* extern */
s32 AudioSeq_IsSeqCmdNotQueued(s32, M2C_UNK);                    /* extern */
extern u8 D_801F4C18;
extern u8 D_801F4C2C;
extern M2C_UNK D_801F4C30;
extern s16 D_801F4C3C;
extern s32 D_801F4C40;
extern f32 D_801F4C44;
extern f32 D_801F4C48;
extern f32 D_801F4C4C;

void Audio_UpdateObjSoundProperties(void) {
    if (D_801F4C2C != 0xFF) {
        if ((AudioSeq_GetActiveSeqId(D_801F4C2C) != 0x57) && (AudioSeq_IsSeqCmdNotQueued((D_801F4C2C << 0x18) + 0x57, 0xFF0000FF) != 0) && (D_801F4C18 == 0)) {
            Audio_SetSequenceProperties(D_801F4C2C, &D_801F4C30, D_801F4C3C, D_801F4C40, D_801F4C44, D_801F4C48, D_801F4C4C);
        }
        D_801F4C2C = 0xFF;
    }
}
