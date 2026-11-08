// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0572.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1B24(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_80BB90DC(u8 *);                      /* extern */

void ObjHgdoor_PlayCutscene(ObjHgdoor *this, PlayState *play) {
    if (func_800F1984(M2C_FIELD(this, s16 *, 0x160)) != 0) {
        func_800F1B24(M2C_FIELD(this, s16 *, 0x160), this);
        func_80BB90DC(this);
        func_80BB90DC(M2C_FIELD(this, u8 **, 0x124));
        return;
    }
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
    }
    func_800F1944(M2C_FIELD(this, s16 *, 0x160));
}
