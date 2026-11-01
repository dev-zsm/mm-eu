#include "types.h"
#include "code_funcs.h"
void Enemy_StartFinishingBlow(u8 *a0, u8 *a1) {
    *(u8 *)(a0 + 0x1CA0) = 5;
    SoundSource_PlaySfxAtFixedWorldPos(a0, a1 + 0x24, 0x14, 0x388B);
}
