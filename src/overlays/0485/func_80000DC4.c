// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_800B87A0(u8 *, M2C_UNK, M2C_UNK, f32, f32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, f32, f32, s32, s32); /* extern */
M2C_UNK func_80B21750(u8 *);                      /* extern */
M2C_UNK func_80B219B0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B21A4C(u8 *);                      /* extern */
M2C_UNK func_80B21BF0(u8 *, M2C_UNK);             /* extern */
s32 func_80B21C90(u8 *, M2C_UNK);                 /* extern */
s32 func_80B21D74(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80B21E4C(u8 *, M2C_UNK);             /* extern */
extern u8 D_801E7DFF;

void func_80000DC4(Actor *thisx, PlayState *play) {
    f32 sp2C;
    f32 sp28;
    f32 temp_f0;
    f32 temp_f2;

    if ((func_80B21C90(thisx, play) == 0) && (func_80B21D74(thisx, play) != 0)) {
        func_80B21E4C(thisx, play);
        func_80137070((u8 *)thisx + 0x144);
        func_80B21A4C(thisx);
        func_80B21BF0(thisx, play);
    } else {
        M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(thisx, play);
        func_80137070((u8 *)thisx + 0x144);
        func_80B21A4C(thisx);
        func_80B21BF0(thisx, play);
        func_800B680C(thisx);
        func_800B763C(play, thisx, 0x41F00000, 0x41400000, 0.0f, 4);
        temp_f0 = (f32) (M2C_FIELD(thisx, s16 *, 0x1CC) + 0x32);
        temp_f2 = (f32) (M2C_FIELD(thisx, s16 *, 0x1CE) + 0x1E);
        if ((M2C_FIELD(thisx, u16 *, 0x322) & 0x400) && !(D_801E7DFF & 0x20)) {
            sp2C = temp_f0;
            sp28 = temp_f2;
            func_800B87A0(thisx, play, 0xBA, temp_f0, temp_f2);
        }
        func_8013CD14(thisx, play, temp_f0, temp_f2, 0, M2C_FIELD(thisx, u16 *, 0x322) & 7);
        func_800B64E0(thisx, 0x41F00000);
        func_80B219B0(thisx, play);
    }
    if (M2C_FIELD(thisx, u16 *, 0x322) & 0x100) {
        func_80B21750(thisx);
    }
}
