// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B02EC(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E0FAC(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_800E1C28(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_800FE290();                            /* extern */
M2C_UNK func_80102AE0(s32);                         /* extern */

void func_80000804(u8 *arg0, M2C_UNK arg1) {
    func_800B02EC(arg1, M2C_FIELD(arg0, s32 *, 0x73C));
    func_800B02EC(arg1, M2C_FIELD(arg0, s32 *, 0x740));
    func_800B02EC(arg1, M2C_FIELD(arg0, s32 *, 0x744));
    func_800E0FAC(arg1, arg0 + 0x518);
    func_800E0FAC(arg1, arg0 + 0x6E4);
    func_800E1C28(arg1, arg0 + 0x564);
    func_800E1C28(arg1, arg0 + 0x5E4);
    func_800E1C28(arg1, arg0 + 0x664);
    func_80102AE0(M2C_FIELD(arg0, s32 *, 0x23C));
    func_800FE290();
}
