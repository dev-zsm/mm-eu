#include "types.h"

extern f32 Math_Vec3f_DistXZ(void *a, void *b);

f32 Actor_WorldDistXZToPoint(u8 *actor, void *point) {
    return Math_Vec3f_DistXZ(actor + 0x24, point);
}
