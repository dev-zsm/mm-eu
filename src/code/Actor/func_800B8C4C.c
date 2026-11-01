#include "types.h"
#include "code_funcs.h"


void Actor_PlaySfx(u8 *actor, u16 sfxId) {
    Audio_PlaySfx_AtPos(actor + 0xEC, sfxId);
}
