// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Player_MeleeWeaponFromIA(s8, void *);                  /* extern */

s32 Player_GetMeleeWeaponHeld(struct Player *player) {
    Player_MeleeWeaponFromIA(M2C_FIELD(player, s8 *, 0x147), player);
}
