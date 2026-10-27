#include "types.h"
typedef struct { u8 pad0[0x800]; s32 unk800[4]; s16 unk810; } S;
void func_800DDE9C(s32, s32);
void Camera_ChangeSetting(s32, s16);
void func_8016ABC0(S *a0, s16 a1, s32 a2, s16 a3) {
    s32 sp1C;
    s16 v;
    if (a1 == -1) {
        v = a0->unk810;
    } else {
        v = a1;
    }
    sp1C = a0->unk800[v];
    func_800DDE9C(sp1C, a2);
    Camera_ChangeSetting(sp1C, a3);
}
