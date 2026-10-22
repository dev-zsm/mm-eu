// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Cutscene_StepTimer(s32, void *, M2C_UNK);            /* extern */
M2C_UNK func_8010EE64(M2C_UNK);                     /* extern */
M2C_UNK ShrinkWindow_Letterbox_SetSizeTarget(M2C_UNK);                     /* extern */
M2C_UNK Audio_SetCutsceneFlag(M2C_UNK);                     /* extern */

void CutsceneHandler_StartManual(s32 arg0, void *arg1) {
    func_8010EE64(1);
    ShrinkWindow_Letterbox_SetSizeTarget(0x20);
    if (Cutscene_StepTimer(arg0, arg1, 0x3F800000) != 0) {
        Audio_SetCutsceneFlag(1);
        M2C_FIELD(arg1, u8 *, 8) = (u8) (M2C_FIELD(arg1, u8 *, 8) + 1);
    }
}
