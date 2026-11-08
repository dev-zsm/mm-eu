// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0185.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_8094FB90(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_8094FBF4;

void EnOkarinaEffect_Init(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(play, u8 *, 0x170F7) != 0) {
        func_800B6490(thisx);
    }
    func_8094FB90(thisx, &D_8094FBF4);
}
