#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0478.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */

void func_800006B0(u8 *arg0, s32 arg1) {
    func_800B680C(arg0);
    func_800FF30C(arg0 + 0x3C, arg0 + 0x24);
    M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + 10.0f);
    func_800B763C(arg1, arg0, 0.0f, 0.0f, 0.0f, 4);
}
