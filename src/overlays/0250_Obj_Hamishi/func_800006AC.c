// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0250.h"

M2C_UNK func_800B5B64(s32, s32);                    /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E26E8(s32, s32, u8 *);            /* extern */
M2C_UNK func_800F0308(s32, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80985CB8(u8 *);                      /* extern */
M2C_UNK func_80985E34(u8 *, s32);                 /* extern */

void ObjHamishi_Update(Actor *thisx, PlayState *play) {
    s32 pad;
    s32 sp24;
    s32 temp_v0;
    s32 temp_v0_2;
    s8 temp_v0_3;
    s8 temp_v0_4;

    temp_v0 = (M2C_FIELD(thisx, u8 *, 0x155) & 2) != 0;
    sp24 = temp_v0;
    func_80985CB8(thisx);
    if (temp_v0 != 0) {
        M2C_FIELD(thisx, s8 *, 0x1A1) = 5;
        M2C_FIELD(thisx, u8 *, 0x155) = (u8) (M2C_FIELD(thisx, u8 *, 0x155) & 0xFFFD);
    }
    if (temp_v0 != 0) {
        temp_v0_2 = *M2C_FIELD(thisx, s32 **, 0x180);
        if (temp_v0_2 & 0x80000500) {
            if (temp_v0_2 & 0x400) {
                M2C_FIELD(thisx, s8 *, 0x1A0) = 0x1A;
            } else {
                M2C_FIELD(thisx, s8 *, 0x1A0) = 0xB;
            }
            if (*M2C_FIELD(thisx, s32 **, 0x180) & 0x80000000) {
                M2C_FIELD(thisx, s16 *, 0x19E) = 2;
            } else {
                M2C_FIELD(thisx, s16 *, 0x19E) = (s16) (M2C_FIELD(thisx, s16 *, 0x19E) + 1);
            }
            if (M2C_FIELD(thisx, s16 *, 0x19E) < 2) {
                M2C_FIELD(thisx, s16 *, 0x198) = 0xF;
                M2C_FIELD(thisx, f32 *, 0x190) = 2.0f;
                M2C_FIELD(thisx, f32 *, 0x194) = 400.0f;
            } else {
                func_80985E34(thisx, play);
                func_800F0308(play, (u8 *)thisx + 0x24, 0x28, 0x2810);
                func_800B5B64(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F);
                func_800B6490(thisx);
            }
        }
    }
    if (M2C_FIELD(thisx, s32 *, 0x138) != 0) {
        temp_v0_3 = M2C_FIELD(thisx, s8 *, 0x1A1);
        if (temp_v0_3 > 0) {
            M2C_FIELD(thisx, s8 *, 0x1A1) = (s8) (temp_v0_3 - 1);
            if (M2C_FIELD(thisx, s8 *, 0x1A1) == 0) {
                M2C_FIELD(thisx, s8 *, 0x158) = 0xC;
            } else {
                M2C_FIELD(thisx, s8 *, 0x158) = 0xA;
            }
        }
        temp_v0_4 = M2C_FIELD(thisx, s8 *, 0x1A0);
        if (temp_v0_4 > 0) {
            M2C_FIELD(thisx, s8 *, 0x1A0) = (s8) (temp_v0_4 - 1);
        } else if ((M2C_FIELD(thisx, s32 *, 4) & 0x40) && (M2C_FIELD(thisx, f32 *, 0x98) < 1000.0f)) {
            func_800E2500(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x144);
        }
        if (M2C_FIELD(thisx, f32 *, 0x98) < 600.0f) {
            func_800E26E8(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x144);
        }
    }
}
