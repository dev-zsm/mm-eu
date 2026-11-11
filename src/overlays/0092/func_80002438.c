#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0092.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60002B8;
extern M2C_UNK D_808B2EC8;

void func_80002438(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60002B8, 0xBFC00000, (f32) func_80134AE8(&D_60002B8), 0.0f, 2, -3.0f);
    M2C_FIELD(arg0, u8 *, 0x24D) = (u8) (M2C_FIELD(arg0, u8 *, 0x24D) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808B2EC8;
}
