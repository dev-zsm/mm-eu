#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x24]; f32 unk24; f32 unk28; f32 unk2C; } S_arg0;

M2C_UNK func_800E2500(s32, s32, u8 *, u8 *);    /* extern */
extern u8 *D_80BB2940;

void func_80000000(S_arg0 *arg0, s32 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x21C), s16 *, 0x30) = (s16) (s32) arg0->unk24;
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x21C), s16 *, 0x32) = (s16) (s32) ((f32) M2C_FIELD(D_80BB2940, s16 *, 0x1C) + arg0->unk28);
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x21C), s16 *, 0x34) = (s16) (s32) arg0->unk2C;
    func_800E2500(arg1, arg1 + 0x18884, (u8 *)arg0 + 0x200, arg0);
}
