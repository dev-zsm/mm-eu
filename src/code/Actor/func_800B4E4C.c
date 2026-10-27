#include "types.h"

extern void SkinMatrix_Vec3fMtxFMultXYZW(void *mf, void *src, void *dest, f32 *invW);

void Actor_GetProjectedPos(u8 *play, void *pos, void *projectedPos, f32 *invW) {
    SkinMatrix_Vec3fMtxFMultXYZW(play + 0x187B0, pos, projectedPos, invW);
    if (*invW < 1.0f) {
        *invW = 1.0f;
    } else {
        *invW = 1.0f / *invW;
    }
}
