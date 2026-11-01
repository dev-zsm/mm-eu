#include "types.h"
#include "generated/code_funcs.h"


f32 Actor_WorldDistXZToPoint(u8 *actor, void *point) {
    return Math_Vec3f_DistXZ(actor + 0x24, point);
}
