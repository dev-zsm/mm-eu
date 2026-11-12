#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
f32 func_8017A844(f32);                         /* extern */
M2C_UNK func_809E18F8(u8 *);                      /* extern */
extern M2C_UNK D_600A400;
extern M2C_UNK D_809E28D0;

void func_800091AC(u8 *arg0, M2C_UNK arg1) {
    func_80137934(arg0 + 0x190, &D_600A400, 0xC0000000);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809E28D0;
    M2C_FIELD(arg0, s16 *, 0x150) = (s16) (s32) (func_8017A844(1.0e+02f) + 150.0f);
    func_809E18F8(arg0);
}
