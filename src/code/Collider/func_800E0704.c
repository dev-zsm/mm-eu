// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Collider_ResetOCElement(struct PlayState *play, struct ColliderElement *elem) {
    M2C_FIELD(elem, u8 *, 0x17) = (u8) (M2C_FIELD(elem, u8 *, 0x17) & 0xFFFD);
}
