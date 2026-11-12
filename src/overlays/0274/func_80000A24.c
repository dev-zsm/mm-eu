#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x1CCC]; void *unk1CCC; u8 pad1CD0[0x14B5E]; u8 unk1682E; u8 pad1682F[0x18E]; u8 unk169BD; u8 pad169BE[0x1EB7]; s8 unk18875; u8 pad18876[0x4]; s16 unk1887A; u8 pad1887C[0x3]; s8 unk1887F; } S_arg1;
typedef struct { u8 pad0[0x14B]; u8 unk14B; } S_sp1C;

s16 func_80130B24();                 /* extern */
s32 func_801529DC();                          /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000A24(s32 arg0, S_arg1 *arg1) {
    S_sp1C *sp1C;

    sp1C = arg1->unk1CCC;
    if ((arg1->unk169BD == 0) && ((arg1->unk1682E == 0) || (func_801529DC((u8 *)arg1 + 0x4908) == 6))) {
        arg1->unk1887A = func_80130B24(6, arg1);
        M2C_FIELD(&D_801E6EF0, s16 *, 0x3F4A) = 0;
        arg1->unk18875 = 0x14;
        arg1->unk1887F = 0x56;
        M2C_FIELD(&D_801E6EF0, s8 *, 0x3F55) = 3;
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF43) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF43) & 0xBF);
        if (sp1C->unk14B == 4) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4C) | 0x80);
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF45) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF45) & 0xFD);
            return;
        }
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF41) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF41) | 0x20);
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF4D) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4D) & 0xFE);
    }
}
