#include "types.h"

extern void Audio_PlaySfx_AtPos(void *pos, u16 sfxId);

void Actor_PlaySfx(u8 *actor, u16 sfxId) {
    Audio_PlaySfx_AtPos(actor + 0xEC, sfxId);
}
