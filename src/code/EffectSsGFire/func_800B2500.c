#include "types.h"
#include "code_funcs.h"
extern void Math_Vec3f_Copy(void *a0);
void EffectSsGFire_Spawn(void *a0) {
    u8 buf[0xC];
    Math_Vec3f_Copy(buf);
    EffectSs_Spawn(a0, 0xC, 0x80, buf);
}
