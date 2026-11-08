// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void *AnimTaskQueue_NewTask(s32, M2C_UNK);                  /* extern */
extern s32 D_801ED330;

void AnimTaskQueue_AddCopyUsingMap(struct PlayState *play, s32 vecCount, struct Vec3s *dest, struct Vec3s *src, u8 *limbCopyMap) {
    void *temp_v0;

    temp_v0 = AnimTaskQueue_NewTask((u8 *)play + 0x17104, 3);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8 *, 4) = (s8) D_801ED330;
        M2C_FIELD(temp_v0, s8 *, 5) = (s8) vecCount;
        M2C_FIELD(temp_v0, s32 *, 8) = dest;
        M2C_FIELD(temp_v0, s32 *, 0xC) = src;
        M2C_FIELD(temp_v0, s32 *, 0x10) = limbCopyMap;
    }
}
