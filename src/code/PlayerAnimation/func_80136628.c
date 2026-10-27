#include "types.h"
typedef struct { u8 pad0[0xA2]; u8 unkA2; } A;
typedef struct { u8 pad0[0x14]; f32 unk14; f32 unk18; f32 unk1C; } S;
void PlayerAnimation_AnimateFrame();
s32 PlayerAnimation_Loop(A *a, S *s) {
    f32 t = (f32)(s32)a->unkA2 * 0.5f;
    s->unk18 += s->unk1C * t;
    if (s->unk18 < 0.0f) {
        s->unk18 += s->unk14;
    } else if (s->unk14 <= s->unk18) {
        s->unk18 -= s->unk14;
    }
    PlayerAnimation_AnimateFrame();
    return 0;
}
