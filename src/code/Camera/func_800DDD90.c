#include "types.h"

typedef struct {
    u8 pad0[0x186E3];
    u8 mode;
} Parent;

typedef struct {
    u8 pad0[0x8C];
    Parent *parent;
    u8 pad90[0xB2];
    s16 unk142;
    u8 pad144[0x10];
    s16 unk154;
} Obj;

extern void Camera_UnsetStateFlag();
extern void Camera_ChangeSettingFlags(void *, s16, s32);
extern void Camera_SetStateFlag();

void func_800DDD90(Obj *o) {
    Parent *p = o->parent;
    s32 one = 1;
    Obj *q = (Obj *)((u8 *)p + 0x220);

    if (o != q) {
        o->unk142 = 0xA;
        o->unk154 = o->unk142;
        Camera_UnsetStateFlag(o, 4);
        return;
    }
    switch (p->mode) {
    case 1:
        o->unk154 = 0x11;
        Camera_ChangeSettingFlags(o, 0x11, 2);
        break;
    case 0:
        o->unk154 = one;
        Camera_ChangeSettingFlags(o, one, 2);
        break;
    case 2:
        o->unk154 = 0x3F;
        Camera_ChangeSettingFlags(o, 0x3F, 2);
        break;
    default:
        o->unk154 = one;
        Camera_ChangeSettingFlags(o, one, 2);
        break;
    }
    Camera_SetStateFlag(o, 4);
}
