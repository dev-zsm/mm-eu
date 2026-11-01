// FLAGS: -O2 -g3 -mips2
// STATUS: automatic draft, 6/43 instructions differ
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ActorShape_Init(u8 *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK Collider_InitAndSetCylinder(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK Collider_UpdateCylinder(u8 *, u8 *);              /* extern */
M2C_UNK Actor_ProcessInitChain(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_801AED40;
extern M2C_UNK D_801AED6C;
extern M2C_UNK EnAObj_Idle;
extern M2C_UNK ActorShadow_DrawCircle;

void func_800A5FE0(u8 *arg0, s32 arg1) {
    u8 *sp20;
    s16 temp_v0;
    u8 *temp_a1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    M2C_FIELD(arg0, s16 *, 0x116) = (s16) (((temp_v0 >> 8) & 0xFF) | 0x300);
    M2C_FIELD(arg0, s16 *, 0x1C) = (s16) ((temp_v0 & 0xFF) - 9);
    Actor_ProcessInitChain(arg0, &D_801AED6C);
    ActorShape_Init(arg0 + 0xBC, 0, &ActorShadow_DrawCircle, 0x41400000);
    temp_a1 = arg0 + 0x148;
    sp20 = temp_a1;
    Collider_InitAndSetCylinder(arg1, temp_a1, arg0, &D_801AED40);
    Collider_UpdateCylinder(arg0, temp_a1);
    M2C_FIELD(arg0, s8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &EnAObj_Idle;
}
