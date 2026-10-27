#include "types.h"

typedef struct { u8 pad0[0x1A]; s16 unk1A; s16 unk1C; s16 countdown; } Quake;

extern f32 Math_SinS(s16);
extern f32 func_8008704C(void);
extern void Quake_UpdateShakeInfo(Quake *, void *, f32, f32);

s32 Quake_CallbackType6(Quake *q, void *a1) {
    f32 s;

    q->countdown--;
    s = Math_SinS(q->unk1A * ((q->countdown & 0xF) + 500));
    Quake_UpdateShakeInfo(q, a1, s, func_8008704C() * s);
    return 1;
}
