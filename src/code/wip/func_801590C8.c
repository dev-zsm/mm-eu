#include "types.h"

typedef struct {
    /* 0x00000 */ u8 pad0[0x11F28];
    /* 0x11F28 */ u8 arr[0x174];
    /* 0x1209C */ f32 unk1209C;
} Msg;

typedef struct {
    /* 0x0000 */ u8 pad0[0x4908];
    /* 0x4908 */ Msg msg;
} Play;

extern void func_800F4D14(Play *, u8, s32);

void func_801590C8(Play *a0, u8 a1, s32 *a2, f32 *a3, s16 a4) {
    s32 pad[2];
    s32 t = *a2;
    f32 f = *a3;
    func_800F4D14(a0, a1, t);
    a0->msg.arr[a4] = a1;
    *a2 = t + 0x80;
    *a3 = f + 16.0f * a0->msg.unk1209C;
}
