#include "types.h"

typedef struct {
    u8 pad0[0x24];
    f32 x;
    u8 pad28[4];
    f32 z;
    u8 pad30[2];
    s16 rot32;
    u8 padBE[0x8A];
    s16 rotBE;
    u8 pad1[0x7C];
    s32 unk13C;
    u8 pad140[0xA4];
    s32 unk1E4;
    s16 unk1E8;
} Obj;

extern s32 SubS_CopyPointFromPath();
extern s32 EnHy_FindNearestDoor();
extern void func_800F0954(void *, s32, s32, s16, s32);
extern s16 Math_Vec3f_Yaw(void *, void *, s32);
extern f32 Math_SinS(s16);
extern f32 Math_CosS(s16);

s32 func_800F0A84(Obj *obj, s32 a1, s32 a2, s16 a3, s16 a4, f32 a5) {
    s32 ret = 0;
    s16 yaw;
    s32 door;
    void *pos = &obj->x;

    if (SubS_CopyPointFromPath(obj->unk1E4, obj->unk1E8, pos) != 0) {
        door = EnHy_FindNearestDoor(obj, a1);
        if (door != 0) {
            ret = 1;
            func_800F0954(obj, a1, door, a3, a4);
            yaw = Math_Vec3f_Yaw(pos, door + 0x24, door);
            obj->x += a5 * Math_SinS(yaw);
            obj->z += a5 * Math_CosS(yaw);
            obj->rot32 = -yaw;
            obj->rotBE = -yaw;
            obj->unk13C = a2;
        }
    }
    return ret;
}
