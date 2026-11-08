// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8091F978(u8 *);                      /* extern */
M2C_UNK func_8091F9B4(u8 *);                      /* extern */
M2C_UNK func_80920F50(u8 *);                      /* extern */
extern f32 D_809219A0;
extern f32 D_809219A4;

void ObjSwitch_LargeFloorSwitchPushDown(ObjSwitch *this, PlayState *play) {
    M2C_FIELD(this, f32 *, 0x5C) = (f32) (M2C_FIELD(this, f32 *, 0x5C) - D_809219A0);
    if (M2C_FIELD(this, f32 *, 0x5C) <= D_809219A4) {
        func_8091F9B4(this);
        func_8013F090(M2C_FIELD(this, f32 *, 0x94), 0x78, 0x14, 0xA);
        func_8091F978(this);
        func_80920F50(this);
    }
}
