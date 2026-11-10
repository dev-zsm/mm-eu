#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x18875]; s8 unk18875; u8 pad18876[0x4]; s16 unk1887A; u8 pad1887C[0x3]; s8 unk1887F; } S_arg1;
typedef struct { u8 pad0[0x111A]; s16 unk111A; } S_arg0;

s16 func_80130B24(M2C_UNK);                         /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_801E6EF0;

void func_80002724(S_arg0 *arg0, S_arg1 *arg1) {
    if ((func_801529DC((u8 *)arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_80147CC4(arg1);
        arg1->unk1887A = func_80130B24(5);
        M2C_FIELD(&D_801E6EF0, s16 *, 0x3F4A) = 0;
        arg1->unk18875 = 0x14;
        arg1->unk1887F = 2;
        M2C_FIELD(&D_801E6EF0, s8 *, 0x3F55) = 3;
        arg0->unk111A = 0;
    }
}
