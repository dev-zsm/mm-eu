#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0143.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(s32, u8 *, f32, f32, f32, s32); /* extern */
s32 func_8012FA08(s32, s8);                         /* extern */
M2C_UNK func_8090D4A4(u8 *);                      /* extern */

void func_80001368(u8 *arg0, s32 arg1) {
    func_800B680C(arg0);
    func_800B763C(arg1, arg0, 15.0f, 15.0f, 0.0f, 0x44);
    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, s8 *, 0x199)) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s8 *, 0x199);
        func_8090D4A4(arg0);
    }
}
