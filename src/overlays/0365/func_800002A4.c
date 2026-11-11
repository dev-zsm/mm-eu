#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B02EC(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E0FAC(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E1C28(M2C_UNK, s32);                /* extern */
M2C_UNK func_801A10E8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_801A3D9C();                            /* extern */

void func_800002A4(u8 *arg0, M2C_UNK arg1) {
    u8 *this = arg0;
    func_800E0FAC(arg1, this + 0xEF4);
    func_800E1C28(arg1, this + 0xF40);
    func_800E1C28(arg1, this + 0xFC0);
    func_800B02EC(arg1, M2C_FIELD(this, s32 *, 0x380));
    func_800B02EC(arg1, M2C_FIELD(this, s32 *, 0x384));
    func_801A10E8(0x7F, 0);
    func_801A3D9C();
}
