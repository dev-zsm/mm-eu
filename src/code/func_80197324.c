// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioList_Remove(s32);                         /* extern */
s32 AudioList_FindNodeWithPrioLessThan(s32, u8);                         /* extern */
M2C_UNK AudioPlayback_NoteReleaseAndTakeOwnership(s32, void *);                 /* extern */
M2C_UNK AudioList_PushBack(s32, s32);                    /* extern */

s32 AudioPlayback_AllocNoteFromDecaying(s32 arg0, void *arg1) {
    s32 temp_v0;

    temp_v0 = AudioList_FindNodeWithPrioLessThan(arg0 + 0x10, M2C_FIELD(M2C_FIELD(arg1, void **, 0x60), u8 *, 5));
    if (temp_v0 != 0) {
        AudioPlayback_NoteReleaseAndTakeOwnership(temp_v0, arg1);
        AudioList_Remove(temp_v0);
        AudioList_PushBack(arg0 + 0x20, temp_v0);
    }
    return temp_v0;
}
