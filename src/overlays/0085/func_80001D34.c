#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0085.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_808A53EC(u8 *);                      /* extern */
s32 func_808A5784(u8 *);                          /* extern */
M2C_UNK func_808A5800(u8 *);                      /* extern */
M2C_UNK func_808A5B08(u8 *);                      /* extern */
M2C_UNK func_808A5B88(u8 *, s32);                 /* extern */
extern M2C_UNK D_808A6324;

void func_80001D34(u8 *arg0, s32 arg1) {
    func_808A5800(arg0);
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) (M2C_FIELD(arg0, f32 *, 0x2CC) + M2C_FIELD(arg0, f32 *, 0x2D4));
    func_800B680C(arg0);
    if (func_808A5784(arg0) != 0) {
        if (M2C_FIELD(arg0, f32 *, 0x2C8) < 0.0f) {
            func_808A5B88(arg0, arg1);
        } else {
            func_808A5B08(arg0);
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808A6324;
    }
    func_808A53EC(arg0);
}
