#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0063.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60066B4;
extern M2C_UNK D_8086BE4C;

void func_80002940(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_60066B4, arg0);
    M2C_FIELD(arg0, u8 *, 0x394) = (u8) (M2C_FIELD(arg0, u8 *, 0x394) & 0xFFFE);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086BE4C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
