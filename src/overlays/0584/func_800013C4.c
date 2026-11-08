// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0584.h"

s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8398(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80BC1EF4(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80BC1F80(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BC2230(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BC2310;

void func_800013C4(Actor *thisx, s32 arg1) {
    func_80BC2230(thisx, arg1);
    if (func_800B8254(thisx, arg1) != 0) {
        M2C_FIELD(thisx, M2C_UNK **, 0x618) = &D_80BC2310;
        func_80BC1F80(thisx, arg1);
        return;
    }
    if (func_80BC1EF4(thisx, arg1) != 0) {
        func_800B8398(thisx, arg1, 0x43340000);
    }
}
