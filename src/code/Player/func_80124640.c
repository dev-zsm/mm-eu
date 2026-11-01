// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Player_MeleeWeaponFromIA(s8, void *);                  /* extern */

void Player_GetMeleeWeaponHeld(void *arg0) {
    Player_MeleeWeaponFromIA(M2C_FIELD(arg0, s8 *, 0x147), arg0);
}
