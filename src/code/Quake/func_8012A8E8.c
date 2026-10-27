#include "types.h"

typedef struct { u8 pad0[2]; s16 unk2; u8 pad4[0x16]; s16 unk1A; s16 unk1C; s16 countdown; } Quake;

extern f32 Math_SinS(s16);
extern void Quake_UpdateShakeInfo(Quake *, void *, f32, f32);

s32 Quake_CallbackType3(Quake *q, void *a1) {
    f32 s;

    if (q->countdown > 0) {
        s = Math_SinS(q->unk1A * q->countdown) * ((f32)q->countdown / (f32)q->unk2);
        Quake_UpdateShakeInfo(q, a1, s, s);
        q->countdown--;
    }
    return q->countdown;
}
