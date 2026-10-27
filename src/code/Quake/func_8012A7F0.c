#include "types.h"

typedef struct {
    u8 pad0[0x1A];
    s16 unk1A;
    u8 pad1C[2];
    s16 unk1E;
} QuakeRequest;

f32 Math_SinS(s16);
void Quake_UpdateShakeInfo(QuakeRequest *, void *, f32, f32);

s16 Quake_CallbackType5(QuakeRequest *req, void *shake) {
    if (req->unk1E > 0) {
        f32 s = Math_SinS(req->unk1A * req->unk1E);

        Quake_UpdateShakeInfo(req, shake, s, s);
        req->unk1E--;
    }
    return req->unk1E;
}
