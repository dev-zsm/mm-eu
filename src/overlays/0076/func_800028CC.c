#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0076.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_600ABD0;
extern M2C_UNK D_8089C738;

void func_800028CC(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_600ABD0, arg0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    func_800B8C4C(arg0, 0x382D);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089C738;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
