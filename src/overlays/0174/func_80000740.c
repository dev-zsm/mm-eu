// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0174.h"

s32 func_800B8400(u8 *, s32);                     /* extern */
M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
M2C_UNK func_8093F5C0(u8 *, s32);                 /* extern */
M2C_UNK func_8093F698(u8 *);                      /* extern */
extern M2C_UNK D_8093F60C;

void func_80000740(Actor *thisx, PlayState *play) {
    if (func_800B8400(thisx, play) != 0) {
        func_801A9868(0x110000FF);
        if (!(M2C_FIELD(thisx, s16 *, 0x3DA) & 0x3F)) {
            func_8093F5C0(thisx, play);
        } else {
            M2C_FIELD(thisx, u16 *, 0x3E8) = (u16) (M2C_FIELD(thisx, u16 *, 0x3E8) & 0xFFFD);
            func_8093F698(thisx);
            M2C_FIELD(thisx, M2C_UNK **, 0x410) = &D_8093F60C;
        }
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & 0xFFFEFFFF);
    }
}
