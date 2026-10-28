// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
s32 func_8012FA08(s32, s16);                        /* extern */
M2C_UNK func_8090B6D0(u8 *);                      /* extern */
extern M2C_UNK D_8090BE24;

void func_800009A4(u8 *arg0, s32 arg1) {
    func_800B680C(arg0);
    func_800B763C(arg1, arg0, 0x41900000, 0x41700000, 0.0f, 0x45);
    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, s16 *, 0x196)) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_8090BE24;
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s16 *, 0x196);
        func_8090B6D0(arg0);
    }
}
