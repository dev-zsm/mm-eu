#include "types.h"
extern void SoundSource_PlaySfxAtFixedWorldPos(void *a0, void *a1, s32 a2, s32 a3);
void Enemy_StartFinishingBlow(u8 *a0, u8 *a1) {
    *(u8 *)(a0 + 0x1CA0) = 5;
    SoundSource_PlaySfxAtFixedWorldPos(a0, a1 + 0x24, 0x14, 0x388B);
}
