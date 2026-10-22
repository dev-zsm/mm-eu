// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019BDB0();                            /* extern */
M2C_UNK AudioOcarina_PlayControllerInput(M2C_UNK);                     /* extern */
extern s8 D_801CF8E4;
extern s8 D_801CF910;
extern s32 D_801CF91C;
extern s16 D_801CF928;
extern s32 D_801F4C90;
extern s32 D_801F4C94;
extern s32 D_801F4C98;
extern s32 D_801F4C9C;

void AudioOcarina_ResetAndReadInput(void) {
    D_801F4C90 = 0;
    D_801F4C98 = 0;
    D_801F4C9C = 0;
    D_801F4C94 = 0xFFFF;
    AudioOcarina_PlayControllerInput(1);
    D_801CF910 = 0;
    D_801CF928 = 0;
    D_801CF8E4 = 0;
    D_801CF91C = 0;
    D_801F4C90 = 0;
    func_8019BDB0();
    D_801F4C94 = D_801F4C90;
}
