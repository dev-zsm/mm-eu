#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80C0AAE0(u8 *);                      /* extern */
extern M2C_UNK D_6009120;
extern M2C_UNK D_6009220;
extern M2C_UNK D_800B3F30;

void func_80000054(u8 *arg0, s32 arg1) {
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136ED0(arg1, arg0 + 0x190, &D_6009220, &D_6009120, 0, 0, 0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    func_80C0AAE0(arg0);
}
