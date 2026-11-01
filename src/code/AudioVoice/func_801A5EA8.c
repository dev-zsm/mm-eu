// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80092460(M2C_UNK *);                   /* extern */
s32 PadMgr_VoiceAcquireSerialEventQueue();                                /* extern */
M2C_UNK PadMgr_VoiceReleaseSerialEventQueue(s32);                         /* extern */
M2C_UNK AudioVoice_InitWord(M2C_UNK);                     /* extern */
s32 func_801A60F8(M2C_UNK *);                       /* extern */
M2C_UNK func_801A62B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK AudioVoice_InitWordImplAlt(M2C_UNK);                     /* extern */
extern M2C_UNK D_801D1510;
extern u8 D_801D176C;
extern M2C_UNK D_801F4DF8;

void AudioVoice_ResetWord(void) {
    s32 sp24;
    s32 sp20;

    AudioVoice_InitWordImplAlt(0xFFFF);
    if (D_801D176C != 0) {
        sp20 = PadMgr_VoiceAcquireSerialEventQueue();
        func_80092460(&D_801F4DF8);
        PadMgr_VoiceReleaseSerialEventQueue(sp20);
        sp24 = func_801A60F8(&D_801D1510);
        AudioVoice_InitWordImplAlt(0xFFFF);
        if (sp24 == 0) {
            func_801A62B8(0x320, 2, 0x400, 0x1F4, 0x7D0);
            D_801D176C = 1;
        }
        AudioVoice_InitWord(5);
        AudioVoice_InitWord(1);
    }
}
