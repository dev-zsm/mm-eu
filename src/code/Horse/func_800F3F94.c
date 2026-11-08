// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Object_IsLoaded(s32, s8);                         /* extern */

s32 Horse_IsActive(struct PlayState *play, struct ActorContext *actorCtx) {
    void *var_s0;

    var_s0 = M2C_FIELD(actorCtx, void **, 0x20);
    if (var_s0 != NULL) {
loop_2:
        if ((M2C_FIELD(var_s0, s32 *, 0x138) != 0) && (M2C_FIELD(var_s0, s32 *, 0x130) == 0) && (Object_IsLoaded((u8 *)play + 0x17D88, M2C_FIELD(var_s0, s8 *, 0x1E)) != 0) && (M2C_FIELD(var_s0, s16 *, 0) == 0xD) && (M2C_FIELD(var_s0, s32 *, 0x144) != 1)) {
            return 1;
        }
        var_s0 = M2C_FIELD(var_s0, void **, 0x12C);
        if (var_s0 == NULL) {
            goto block_9;
        }
        goto loop_2;
    }
block_9:
    return 0;
}
