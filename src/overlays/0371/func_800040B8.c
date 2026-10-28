// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80A705E4(u8 *, s32);                 /* extern */
M2C_UNK func_80A70A50(s32, u8 *);                 /* extern */
M2C_UNK func_80A730D8(u8 *);                      /* extern */
M2C_UNK func_80A73158(u8 *);                      /* extern */
M2C_UNK func_80A73224(u8 *);                      /* extern */
M2C_UNK func_80A74544(u8 *, s32);                 /* extern */

void func_800040B8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *), 0x3DC)(arg0);
    func_80A70A50(arg1, arg0);
    func_80A730D8(arg0);
    func_80A73224(arg0);
    func_80A73158(arg0);
    func_80A74544(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x144)(arg0, arg1);
    func_800B64E0(arg0, 0x42B40000);
    func_80137070(arg0 + 0x14C);
    func_80A705E4(arg0, arg1);
}
