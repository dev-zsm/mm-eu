#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} S_arg0;
typedef struct {
    u8 pad0[0x10C];
    s32 unk10C;
} S_temp_v0;
typedef struct {
    u8 pad0[0x10C];
    s32 unk10C;
} S_temp_v0_2;
typedef struct {
    u8 pad0[0x10C];
    s32 unk10C;
} S_temp_v0_3;
extern char D_801E6EF0;
void func_80000474(S_arg0 *arg0) {
    S_temp_v0 *temp_v0;
    S_temp_v0_2 *temp_v0_2;
    S_temp_v0_3 *temp_v0_3;
    temp_v0 = (&D_801E6EF0) + (arg0->unkA4 * 0x1C);
    temp_v0->unk10C = (s32) (temp_v0->unk10C | 1);
    if ((((s32) (*((s32 *) (((s8 *) (&D_801E6EF0)) + 0x18)))) % 5) == 1) {
        temp_v0_2 = (&D_801E6EF0) + (arg0->unkA4 * 0x1C);
        if (1) {
            temp_v0_2->unk10C = (s32) (temp_v0_2->unk10C | 2);
        }
        return;
    }
    temp_v0_3 = (&D_801E6EF0) + (arg0->unkA4 * 0x1C);
    temp_v0_3->unk10C = (s32) (temp_v0_3->unk10C & (~2));
}
