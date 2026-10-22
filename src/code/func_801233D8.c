// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK CutsceneManager_Queue(M2C_UNK);                     /* extern */

void func_801233D8(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 2) == 2) && !(M2C_FIELD(arg0, s32 *, 0xA6C) & 0x20A00C00) && !(M2C_FIELD(arg0, s32 *, 0xA70) & 1)) {
        if (M2C_FIELD(arg0, s8 *, 0x37C) < 0) {
            CutsceneManager_Queue(0x7C);
            return;
        }
        CutsceneManager_Queue(0x7D);
    }
}
