#include "types.h"
extern void Math_Vec3f_Copy(void *a0);
extern void EffectSs_Spawn(void *a0, s32 a1, s32 a2, void *a3);
void EffectSsGFire_Spawn(void *a0) {
    u8 buf[0xC];
    Math_Vec3f_Copy(buf);
    EffectSs_Spawn(a0, 0xC, 0x80, buf);
}
