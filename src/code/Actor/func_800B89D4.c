// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Actor_SetClosestSecretDistance(struct Actor *actor, struct PlayState *play) {
    f32 temp_f0;
    void *temp_v0;

    temp_v0 = M2C_FIELD(play, void **, 0x1CCC);
    temp_f0 = M2C_FIELD(actor, f32 *, 0x94);
    if (temp_f0 < M2C_FIELD(temp_v0, f32 *, 0xAA0)) {
        M2C_FIELD(temp_v0, f32 *, 0xAA0) = temp_f0;
    }
}
