// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A8FC5C(u8 *, s32);                 /* extern */
extern s8 D_801E6F10;

void func_8000036C(Actor *thisx, PlayState *play) {
    func_80137070((u8 *)thisx + 0x144);
    M2C_FIELD(thisx, s32 *, 0x2F0) = (s32) M2C_FIELD(thisx, s32 *, 0x2F0);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x290)(thisx, play);
    if (func_800B877C(thisx, play) == 0) {
        func_800B87A0(thisx, play, 0x4C, 0x41F00000, 80.0f);
    } else {
        D_801E6F10 = 4;
        func_800B6490(thisx);
    }
    func_80A8FC5C(thisx, play);
}
