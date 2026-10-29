#include "types.h"

extern s32 D_801BA93C;
extern s32 D_801BA940;
extern void func_80161D98();
extern void ShrinkWindow_Letterbox_SetSizeTarget();
extern void func_8010EE64();

void Camera_UpdateInterface(s32 flags) {
    s32 t;
    s32 v;

    if ((flags & 0xF000) != 0xF000) {
        switch (flags & 0x7000) {
            case 0x1000:
                D_801BA940 = 0x1A;
                break;
            case 0x2000:
                D_801BA940 = 0x1B;
                break;
            case 0x3000:
                D_801BA940 = 0x20;
                break;
            default:
                D_801BA940 = 0;
                break;
        }
        if (flags & 0x8000) {
            func_80161D98(D_801BA940, flags);
        } else {
            ShrinkWindow_Letterbox_SetSizeTarget(D_801BA940, flags);
        }
    }
    t = flags & 0xF00;
    if (t != 0xF00) {
        v = t >> 8;
        if (v == 0) {
            v = 0x32;
        }
        if (v != D_801BA93C) {
            D_801BA93C = v;
            func_8010EE64(*(u16 *)((u8 *)&D_801BA93C + 2), flags);
        }
    }
}
