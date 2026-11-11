// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0437.h"

u32 func_80AD377C(u8 *);                          /* extern */
M2C_UNK func_80AD38B8(u8 *, s32);                 /* extern */
M2C_UNK func_80AD3D78(u8 *, s32);                 /* extern */
M2C_UNK func_80AD3E8C(u8 *, s32);                 /* extern */
M2C_UNK func_80AD3EF4(u8 *, s32);                 /* extern */
M2C_UNK func_80AD3F50(u8 *, s32);                 /* extern */

void func_80002674(u8 *arg0, s32 arg1) {
    u32 sp24;
    u32 temp_v0;

    temp_v0 = func_80AD377C(arg0);
    sp24 = temp_v0;
    if (temp_v0 != M2C_FIELD(arg0, u32 *, 0x2D0)) {
        switch (temp_v0) {
        case 0:
            func_80AD3F50(arg0, arg1);
            break;
        case 1:
            func_80AD3D78(arg0, arg1);
            break;
        case 2:
            func_80AD38B8(arg0, arg1);
            break;
        case 3:
            func_80AD3E8C(arg0, arg1);
            break;
        case 4:
            func_80AD3EF4(arg0, arg1);
            break;
        }
        M2C_FIELD(arg0, u32 *, 0x2D0) = sp24;
    }
}
