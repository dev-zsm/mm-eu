// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(s32);                         /* extern */
extern s8 D_801CEFD8;

void Audio_SetFileSelectSettings(s8 arg0) {
    s8 sp1F;

    switch (arg0) {                                 /* irregular */
    case 0:
        sp1F = 0;
        D_801CEFD8 = 0;
        break;
    case 1:
        sp1F = 3;
        D_801CEFD8 = 3;
        break;
    case 2:
        sp1F = 1;
        D_801CEFD8 = 1;
        break;
    case 3:
        sp1F = 4;
        D_801CEFD8 = 2;
        break;
    }
    AudioSeq_QueueSeqCmd(sp1F | 0xE0000000);
}
