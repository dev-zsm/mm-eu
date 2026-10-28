// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_8012C78C(s32);                         /* extern */
M2C_UNK func_80134760(s32 *, s32, s32, u8, s32, s32, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_809FDAD0(u8 *, s32 *);               /* extern */
extern M2C_UNK D_809FD2CC;

void func_80001CC8(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_8012C78C(*arg1);
    func_80134760(arg1, M2C_FIELD(arg0, s32 *, 0x160), M2C_FIELD(arg0, s32 *, 0x17C), M2C_FIELD(arg0, u8 *, 0x15E), 0, 0, &D_809FD2CC, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x3C6) == 4) {
        func_809FDAD0(arg0, arg1);
    }
}
