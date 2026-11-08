// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void *AnimTaskQueue_NewTask(s32, M2C_UNK);                  /* extern */
extern s32 D_801ED330;

void AnimTaskQueue_AddInterp(struct PlayState *play, s32 vecCount, struct Vec3s *base, struct Vec3s *mod, f32 weight) {
    void *temp_v0;

    temp_v0 = AnimTaskQueue_NewTask((u8 *)play + 0x17104, 2);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8 *, 4) = (s8) D_801ED330;
        M2C_FIELD(temp_v0, s8 *, 5) = (s8) vecCount;
        M2C_FIELD(temp_v0, s32 *, 8) = base;
        M2C_FIELD(temp_v0, s32 *, 0xC) = mod;
        M2C_FIELD(temp_v0, f32 *, 0x10) = weight;
    }
}
