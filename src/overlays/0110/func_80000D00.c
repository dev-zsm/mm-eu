#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BBB30(s32, u8 *, u8 *, M2C_UNK, s32, f32, s32, s32, s32); /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_808CFFA0(u8 *);                      /* extern */
extern M2C_UNK D_6009520;
extern M2C_UNK D_808D0B28;

void func_80000D00(u8 *arg0, s32 arg1) {
    func_80137788(arg0 + 0x144, &D_6009520, 0x40400000, 0, (f32) func_80134AE8(&D_6009520), 2, -3.0f);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    func_808CFFA0(arg0);
    func_800BBB30(arg1, arg0, arg0 + 0x24, 0x41700000, 6, 20.0f, 0x12C, 0x64, 1);
    func_800B8C4C(arg0, 0x3930);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D0B28;
}
