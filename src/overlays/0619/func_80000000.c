// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6490(u8 *, s32);                 /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, s32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_80BEB3CC(u8 *, s32);                 /* extern */
M2C_UNK func_80BEB4DC(u8 *);                      /* extern */
extern u8 D_801E7E32;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800B6564(thisx, 0x3E99999A);
    M2C_FIELD(thisx, s16 *, 0x194) = (s16) ((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0xF000) >> 0xC);
    M2C_FIELD(thisx, s8 *, 0x1F) = 0;
    M2C_FIELD(thisx, f32 *, 0xC4) = 25.0f;
    M2C_FIELD(thisx, f32 *, 0x40) = (f32) (M2C_FIELD(thisx, f32 *, 0x40) + 10.0f);
    if (M2C_FIELD(thisx, s16 *, 0x194) == 0) {
        M2C_FIELD(thisx, s8 *, 0xB7) = 0;
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 9);
        func_80BEB3CC(thisx, play);
        return;
    }
    if (!(D_801E7E32 & 0x40)) {
        if (D_801E7E32 & 0x80) {
            func_800BA9E4((u8 *)play + 0x1CA0, play, 1, M2C_FIELD(thisx, s32 *, 0x24), M2C_FIELD(thisx, f32 *, 0x28), M2C_FIELD(thisx, f32 *, 0x2C), 0, 0, 0, -1);
        }
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & ~1);
        func_80BEB4DC(thisx);
        return;
    }
    func_800B6490(thisx, play);
}
