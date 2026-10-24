// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 a, b, c; u8 d[0x29]; } E2;
typedef struct { u8 a, b, c, d; } Ent;
void func_80085A2C(s32, u8, u8, u8, s32);
void func_80085A9C(s32, u8, u8);
void func_80086148(s32, u8 *, u8 *);
extern s16 D_801BBC2C;
extern Ent D_801BBC30[];
extern u8 D_801D5694[];
extern E2 D_801EB800[];
void func_800E9C04(s32 arg0) {
    s32 i;
    for (i = 0; i < D_801BBC2C; i++) {
        func_80085A2C(arg0, D_801BBC30[D_801EB800[i].c].a, D_801BBC30[D_801EB800[i].c].b, D_801BBC30[D_801EB800[i].c].c, D_801BBC30[D_801EB800[i].c].d);
        func_80085A9C(arg0, D_801EB800[i].a, D_801EB800[i].b);
        func_80086148(arg0, D_801D5694, D_801EB800[i].d);
    }
}
