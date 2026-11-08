// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

M2C_UNK func_800C625C(s32, s32, s32, u8 *);       /* extern */
M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_800E1574(s32, u8 *);                 /* extern */

void ObjSwitch_Destroy(Actor *thisx, PlayState *play) {
    s32 pad;
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x1C) & 7;
    if ((temp_v0 == 0) || (temp_v0 == 1) || (temp_v0 == 5)) {
        sp1C = temp_v0;
        func_800C625C(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144), thisx);
    }
    switch (temp_v0) {                              /* irregular */
    case 1:
    case 2:
        func_800E1574(play, (u8 *)thisx + 0x178);
        return;
    case 3:
    case 4:
        func_800E09D8(play, (u8 *)thisx + 0x178);
        return;
    }
}
