#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s32 func_80124664(u8 *);                          /* extern */
M2C_UNK func_8082D1EC(s32, u8 *, s32);            /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_8084C3E0;
extern u32 D_8085C650[];

void func_80013474(u8 *arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_8084C3E0, 1);
    func_8082D1EC(arg1, arg0, D_8085C650[func_80124664(arg0)]);
    M2C_FIELD(arg0, s16 *, 0xAE8) = 1;
    M2C_FIELD(arg0, f32 *, 0xB38) = 0.0f;
}
