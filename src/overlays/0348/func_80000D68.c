// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"

typedef struct { f32 unk0; f32 unk4; f32 unk8; } S_arg1;
typedef struct { u8 pad0[0x24]; f32 unk24; f32 unk28; f32 unk2C; u8 pad30[0x1DC]; f32 unk20C; f32 unk210; f32 unk214; f32 unk218; f32 unk21C; f32 unk220; f32 unk224; f32 unk228; f32 unk22C; u8 pad230[0x24]; f32 unk254; } S_arg0;
typedef struct { f32 unk0; f32 unk4; f32 unk8; } S_arg2;

void func_80000D68(S_arg0 *arg0, S_arg1 *arg1, S_arg2 *arg2) {
    f32 temp_f0;

    temp_f0 = arg1->unk0 + arg0->unk254;
    arg2->unk0 = (f32) (arg0->unk24 + (arg0->unk224 * temp_f0) + (arg0->unk218 * arg1->unk4) + (arg0->unk20C * arg1->unk8));
    arg2->unk4 = (f32) (arg0->unk28 + (arg0->unk228 * temp_f0) + (arg0->unk21C * arg1->unk4) + (arg0->unk210 * arg1->unk8));
    arg2->unk8 = (f32) (arg0->unk2C + (arg0->unk22C * temp_f0) + (arg0->unk220 * arg1->unk4) + (arg0->unk214 * arg1->unk8));
}
