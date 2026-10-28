// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_800E0FAC(s32, u8 *);                 /* extern */
M2C_UNK func_800E1574(s32, u8 *);                 /* extern */
M2C_UNK func_800E1F64(s32, u8 *);                 /* extern */
M2C_UNK func_80102484(s32, s32, s32);               /* extern */
M2C_UNK func_801A818C(u8 *);                      /* extern */

void func_80000400(u8 *arg0, s32 arg1) {
    s32 var_s0;
    u8 *var_s1;

    func_80102484(arg1, arg1 + 0x818, M2C_FIELD(arg0, s32 *, 0x470));
    func_800E09D8(arg1, arg0 + 0x484);
    func_800E0FAC(arg1, arg0 + 0x964);
    var_s0 = 0;
    var_s1 = arg0 + 0x262C;
    do {
        func_800E1574(arg1, var_s1);
        var_s0 += 0x90;
        var_s1 += 0x90;
    } while (var_s0 != 0xB40);
    func_800E1F64(arg1, arg0 + 0x37B8);
    func_801A818C(arg0 + 0x458);
    func_801A818C(arg0 + 0x464);
}
