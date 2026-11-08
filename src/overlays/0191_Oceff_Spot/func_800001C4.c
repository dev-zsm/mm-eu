// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0191.h"

M2C_UNK func_800B6490();                            /* extern */
extern s16 D_801EAE48;
extern u8 *D_801EB7E0;
extern f32 D_809581C4;

void OceffSpot_End(OceffSpot *this, PlayState *play) {
    f32 temp_f0;

    temp_f0 = M2C_FIELD(this, f32 *, 0x16C);
    if (temp_f0 > 0.0f) {
        M2C_FIELD(this, f32 *, 0x16C) = (f32) (temp_f0 - D_809581C4);
        return;
    }
    func_800B6490();
    if ((M2C_FIELD(D_801EB7E0, s16 *, 0x32) != 0x190) && (M2C_FIELD(play, s16 *, 0x16952) == 0)) {
        if ((M2C_FIELD(play, u16 *, 0x16938) != 0x39) || (M2C_FIELD(play, u16 *, 0x16936) != 0xA)) {
            D_801EAE48 = 1;
        }
    } else {
        M2C_FIELD(play, u16 *, 0x16936) = 4U;
    }
}
