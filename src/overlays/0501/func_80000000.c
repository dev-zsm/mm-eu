// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5C34(s32, s8);                         /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80B529C8(u8 *);                      /* extern */
M2C_UNK func_80B52BB0(u8 *);                      /* extern */
extern M2C_UNK D_6001588;
extern M2C_UNK D_80B52CD0;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80B52CD0);
    func_800CABA0(thisx, 1);
    func_800CABC4(play, thisx, &D_6001588);
    if (func_800B5C34(play, M2C_FIELD(thisx, s8 *, 3)) != 0) {
        func_80B52BB0(thisx);
        return;
    }
    func_80B529C8(thisx);
}
