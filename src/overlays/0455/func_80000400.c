// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_800E0FAC(s32, u8 *);                 /* extern */
M2C_UNK func_800E1574(s32, u8 *);                 /* extern */
M2C_UNK func_800E1F64(s32, u8 *);                 /* extern */
M2C_UNK func_80102484(s32, s32, s32);               /* extern */
M2C_UNK func_801A818C(u8 *);                      /* extern */

void func_80000400(Actor *thisx, PlayState *play) {
    s32 var_s0;
    u8 *var_s1;

    func_80102484(play, (u8 *)play + 0x818, M2C_FIELD(thisx, s32 *, 0x470));
    func_800E09D8(play, (u8 *)thisx + 0x484);
    func_800E0FAC(play, (u8 *)thisx + 0x964);
    var_s0 = 0;
    var_s1 = (u8 *)thisx + 0x262C;
    do {
        func_800E1574(play, var_s1);
        var_s0 += 0x90;
        var_s1 += 0x90;
    } while (var_s0 != 0xB40);
    func_800E1F64(play, (u8 *)thisx + 0x37B8);
    func_801A818C((u8 *)thisx + 0x458);
    func_801A818C((u8 *)thisx + 0x464);
}
