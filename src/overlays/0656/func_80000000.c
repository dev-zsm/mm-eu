#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80C08088(u8 *);                      /* extern */
extern M2C_UNK D_60011C0;
extern M2C_UNK D_6007908;
extern M2C_UNK D_800B3F30;

void func_80000000(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
    func_80136ED0(arg1, arg0 + 0x144, &D_6007908, &D_60011C0, arg0 + 0x188, arg0 + 0x200, 0x14);
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41C80000);
    func_80C08088(arg0);
}
