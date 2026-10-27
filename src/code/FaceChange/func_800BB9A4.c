#include "types.h"
typedef struct { s16 unk0; s16 unk2; } FaceChange;
extern f32 func_8008704C(void);
extern s16 Rand_S16Offset(s16 base, s16 range);
s16 FaceChange_UpdateRandomSet(FaceChange *a, s16 b, s16 c, s16 d) {
    s16 t;
    if (a->unk2 == 0) {
        t = 0;
    } else {
        a->unk2--;
        t = a->unk2;
    }
    if (t == 0) {
        a->unk2 = Rand_S16Offset(b, c);
        a->unk0++;
        if ((a->unk0 % 3) == 0) {
            a->unk0 = (s32)(func_8008704C() * d) * 3;
        }
    }
    return a->unk0;
}
