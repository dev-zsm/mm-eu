#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x1A];
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 pad1C;
    /* 0x1E */ s16 unk1E;
} Quake;

extern f32 Math_SinS(s16);
extern f32 func_8008704C(void);
extern void Quake_UpdateShakeInfo(Quake *, s32, f32, f32);

s32 Quake_CallbackType1(Quake *a0, s32 a1) {
    f32 f;
    s32 v = a0->unk1E;

    if (v > 0) {
        f = Math_SinS(a0->unk1A * v);
        Quake_UpdateShakeInfo(a0, a1, f, func_8008704C() * f);
        a0->unk1E--;
        v = a0->unk1E;
    }
    return v;
}
