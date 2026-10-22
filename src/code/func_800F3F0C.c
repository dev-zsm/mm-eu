// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x24]; u8 pad24[0xE]; s16 unk32; u8 pad34[0x8A]; s16 unkBE; } Horse;
s32 Math_Vec3f_Yaw(void *, s32, s16);

void Horse_RotateToPoint(Horse *arg0, s32 arg1, s16 arg2) {
    s16 temp_a2;
    s16 temp_v1;
    s16 temp_a0;
    s32 temp_v0;

    temp_a2 = arg2;
    temp_v0 = Math_Vec3f_Yaw((u8 *)arg0 + 0x24, arg1, temp_a2);
    temp_v1 = arg0->unk32;
    temp_a0 = temp_v0 - temp_v1;
    if (temp_a2 < temp_a0) {
        arg0->unk32 = temp_v1 + temp_a2;
    } else if (temp_a0 < -temp_a2) {
        arg0->unk32 = temp_v1 - temp_a2;
    } else {
        arg0->unk32 = temp_v1 + temp_a0;
    }
    arg0->unkBE = arg0->unk32;
}
