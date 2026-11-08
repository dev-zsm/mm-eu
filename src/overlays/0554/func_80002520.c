// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0554.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B83C0(u8 *, s32);                 /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80BA272C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80BA3DBC;

void func_80002520(Actor *thisx, PlayState *play) {
    if (func_800B8254(thisx, play) != 0) {
        func_80151DF4(play, 0x23A, thisx);
        M2C_FIELD(thisx, M2C_UNK **, 0x18C) = &D_80BA3DBC;
    } else if (M2C_FIELD(thisx, u8 *, 0x114) != 0) {
        func_800B83C0(thisx, play);
    }
    func_80BA272C(thisx, play);
}
