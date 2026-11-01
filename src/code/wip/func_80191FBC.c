#include "types.h"

extern s32 *AudioPlayback_GetInstrumentInner(s32, s32);
extern s32 *AudioPlayback_GetDrum(s32, s32);
extern s32 *AudioPlayback_GetSoundEffect(s32, s32);

s32 func_80191FBC(s32 a0, s32 a1) {
    s32 *p;
    s32 v;

    if (a1 < 0x80) {
        p = AudioPlayback_GetInstrumentInner(a0, a1);
        if (p == 0) {
            return 0;
        }
        v = p[4];
    } else if (a1 < 0x100) {
        a1 -= 0x80;
        p = AudioPlayback_GetDrum(a0, a1);
        if (p == 0) {
            return 0;
        }
        v = p[1];
    } else {
        a1 -= 0x100;
        p = AudioPlayback_GetSoundEffect(a0, a1);
        if (p == 0) {
            return 0;
        }
        v = p[0];
    }
    return v;
}
