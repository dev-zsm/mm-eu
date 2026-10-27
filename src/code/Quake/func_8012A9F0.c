#include "types.h"

typedef struct {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[0x1A];
    s16 unk1E;
} QuakeReq;

extern f32 Quake_Random(void);
extern void Quake_UpdateShakeInfo(QuakeReq* req, s32 a1, f32 a2, f32 a3);
extern f32 func_8008704C(void);

s16 Quake_CallbackType4(QuakeReq* req, s32 arg1) {
    f32 y;

    if (req->unk1E > 0) {
        y = Quake_Random() * ((f32)req->unk1E / (f32)req->unk2);
        Quake_UpdateShakeInfo(req, arg1, y, func_8008704C() * y);
        req->unk1E--;
    }
    return req->unk1E;
}
