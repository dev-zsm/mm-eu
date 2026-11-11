#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *);              /* extern */
M2C_UNK func_808E62E8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808E7438(u8 *);                      /* extern */
extern M2C_UNK D_6007790;
extern M2C_UNK D_808E7BAC;

void func_8000348C(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6007790);
    func_808E62E8(arg0, 0x3965);
    func_808E62E8(arg0, 0x3963);
    func_800B8C4C(arg0, 0x392E);
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0;
    M2C_FIELD(arg0, u8 *, 0x688) = (u8) (M2C_FIELD(arg0, u8 *, 0x688) & 0xFFFE);
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    func_808E7438(arg0);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0x2D0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E7BAC;
}
