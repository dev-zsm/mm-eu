// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0620.h"

void func_800002F0(ObjMuPict *this, PlayState *play) {
    u8 *var_v0;

    var_v0 = M2C_FIELD(play, u8 **, 0x1CE4);
    if (var_v0 != NULL) {
loop_1:
        if (M2C_FIELD(var_v0, s16 *, 0) == 0x251) {
            M2C_FIELD(this, u8 **, 0x120) = var_v0;
            return;
        }
        var_v0 = M2C_FIELD(var_v0, u8 **, 0x12C);
        if (var_v0 == NULL) {

        } else {
            goto loop_1;
        }
    }
}
