#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0455.h"

M2C_UNK func_800E2500(s32, s32, s32);               /* extern */
M2C_UNK func_800E26E8(s32, s32, s32);               /* extern */
M2C_UNK func_80AF2CD8(s32);                         /* extern */

void func_800092B8(s32 arg0, s32 arg1) {
    s32 sp1C;
    s32 sp18;
    s32 temp_a1;
    s32 temp_a2;

    func_80AF2CD8(arg0);
    temp_a2 = arg0 + 0x484;
    temp_a1 = arg1 + 0x18884;
    sp18 = temp_a2;
    sp1C = temp_a1;
    func_800E2500(arg1, temp_a1, temp_a2);
    func_800E26E8(arg1, temp_a1, temp_a2);
}
