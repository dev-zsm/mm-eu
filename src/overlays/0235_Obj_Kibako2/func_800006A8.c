// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0235.h"

M2C_UNK func_800C604C(s32, s32, s32);               /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_800F0308(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8097336C(u8 *, s32);                 /* extern */
s32 func_809738B8(u8 *);                          /* extern */
extern M2C_UNK D_80973A60;

void ObjKibako2_Idle(ObjKibako2 *this, PlayState *play) {
    if (func_809738B8(this) != 0) {
        func_8097336C(this, play);
        func_800F0308(play, (u8 *)this + 0x24, 0x14, 0x28AA);
        M2C_FIELD(this, s32 *, 4) = (s32) (M2C_FIELD(this, s32 *, 4) | 0x10);
        func_800C604C(play, (u8 *)play + 0x880, M2C_FIELD(this, s32 *, 0x144));
        M2C_FIELD(this, s32 *, 0x13C) = 0;
        M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80973A60;
        return;
    }
    if (M2C_FIELD(this, f32 *, 0x98) < 600.0f) {
        func_800E2500(play, (u8 *)play + 0x18884, (u8 *)this + 0x15C);
    }
}
