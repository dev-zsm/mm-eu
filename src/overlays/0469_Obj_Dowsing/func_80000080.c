// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0469.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_80B08A80(s32);                             /* extern */

s32 ObjDowsing_CheckValidSpawn(ObjDowsing *this) {
    if (func_80B08A80(this) != 0) {
        func_800B6490(this);
        return 1;
    }
    return 0;
}
