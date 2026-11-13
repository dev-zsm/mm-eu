#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1CCC]; void *unk1CCC; } S_arg1;
typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x4]; f32 unk2C; u8 pad30[0x62]; s16 unk92; u8 pad94[0x4]; f32 unk98; u8 pad9C[0x164]; void *unk200; u8 pad204[0x6]; s16 unk20A; } S_arg0;
typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x4]; f32 unk2C; } S_sp2C;

s32 func_80087010();                                /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6001360;
extern M2C_UNK D_80B470EC;

void func_80000D04(S_arg0 *arg0, S_arg1 *arg1) {
    S_sp2C *sp2C;
    f32 sp28;
    s16 sp26;
    f32 temp_f0;
    f32 temp_f18;

    sp2C = arg1->unk1CCC;
    temp_f0 = arg0->unk98;
    if (temp_f0 < 200.0f) {
        sp28 = 200.0f;
    } else {
        sp28 = temp_f0;
    }
    sp26 = (func_80087010() >> 0x14) + arg0->unk92;
    func_800B8C4C(arg0, 0x3873);
    func_801378E0((u8 *)arg0 + 0x144, &D_6001360);
    arg0->unk20A = 0x2000;
    arg0->unk24 = (f32) ((func_800FEB84(sp26) * sp28) + sp2C->unk24);
    arg0->unk2C = (f32) ((func_800FEB44(sp26) * sp28) + sp2C->unk2C);
    arg0->unk200 = &D_80B470EC;
}
