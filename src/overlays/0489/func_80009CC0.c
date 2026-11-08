// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

M2C_UNK func_800B6580(s32, u8 *);                 /* extern */
s32 func_8012FA08(s32, s8);                         /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80B29DB0();                            /* extern */
M2C_UNK func_80B2A124(u8 *, s32, s32);            /* extern */
M2C_UNK func_80B2A190(u8 *, s32, s32);            /* extern */
M2C_UNK func_80B31E8C(u8 *);                      /* extern */
M2C_UNK func_80B32114(u8 *);                      /* extern */
extern M2C_UNK D_6001674;
extern M2C_UNK D_6004E50;
extern M2C_UNK D_80B32490;

void func_80009CC0(u8 *arg0, PlayState *play) {
    s32 pad[2];
    s32 sp34;

    if (func_8012FA08((u8 *)play + 0x17D88, M2C_FIELD(arg0, s8 *, 0x2F4)) != 0) {
        sp34 = M2C_FIELD(arg0, s16 *, 0x1C) & 7;
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s8 *, 0x2F4);
        func_800B6580(play, arg0);
        func_80B29DB0();
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B32490;
        func_80136ED0(play, (u8 *)arg0 + 0x144, &D_6004E50, &D_6001674, (u8 *)arg0 + 0x188, (u8 *)arg0 + 0x212, 0xE);
        if (sp34 < 3) {
            func_80B2A124(arg0, play, sp34);
            func_80B31E8C(arg0);
            return;
        }
        func_80B2A190(arg0, play, sp34);
        func_80B32114(arg0);
    }
}
