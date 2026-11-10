// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1C]; s16 unk1C; s8 unk1E; u8 pad1F[0x119]; void *unk138; u8 pad13C[0x18]; f32 unk154; u8 pad158[0x4]; f32 unk15C; u8 pad160[0x194]; s8 unk2F4; u8 pad2F5[0x2B]; f32 unk320; } S_arg0;

M2C_UNK func_800B6490();                      /* extern */
M2C_UNK func_800B6580();                 /* extern */
s32 func_8012FA08();                         /* extern */
M2C_UNK func_80136ED0(); /* extern */
M2C_UNK func_80B28C3C();                      /* extern */
M2C_UNK func_80B29014();                      /* extern */
M2C_UNK func_80B291EC();                 /* extern */
M2C_UNK func_80B294F0();                 /* extern */
M2C_UNK func_80B29DB0();                            /* extern */
M2C_UNK func_80B29E9C();                      /* extern */
M2C_UNK func_80B2C0B0();                      /* extern */
M2C_UNK func_80B2C298();                      /* extern */
M2C_UNK func_80B2C43C();                      /* extern */
extern M2C_UNK D_6001D80;
extern M2C_UNK D_6004E50;
extern u16 D_801E6EFC;
extern M2C_UNK D_80B2CA60;
extern s32 D_80B33670;
extern f32 D_80B33BC8;

void func_800041FC(S_arg0 *arg0, s32 arg1) {
    if (func_8012FA08(arg1 + 0x17D88, arg0->unk2F4) != 0) {
        arg0->unk1E = (s8) arg0->unk2F4;
        func_800B6580(arg1, arg0);
        func_80B29DB0();
        arg0->unk138 = &D_80B2CA60;
        func_80136ED0(arg1, (u8 *)arg0 + 0x144, &D_6004E50, &D_6001D80, (u8 *)arg0 + 0x188, (u8 *)arg0 + 0x212, 0xE);
        arg0->unk15C = (f32) ((f32) (arg0->unk1C & 7) * arg0->unk154 * 0.125f);
        func_80B291EC(arg0, arg1);
        func_80B29014(arg0);
        func_80B294F0(arg0, arg1);
        func_80B28C3C(arg0);
        func_80B29E9C(arg0);
        if ((D_80B33670 == 1) || ((s32) D_801E6EFC < 0x1AD8)) {
            func_80B2C0B0(arg0);
            return;
        }
        if (D_80B33670 == 2) {
            if (D_80B33BC8 <= arg0->unk320) {
                func_80B2C43C(arg0);
                return;
            }
            func_80B2C298(arg0);
            return;
        }
        func_800B6490(arg0);
    }
}
