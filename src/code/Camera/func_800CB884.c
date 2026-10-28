#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
typedef struct {
    u8 pad0[0xBEC];
    Vec3f pos;
} Act;
typedef struct {
    u8 pad0[0x1CCC];
    Act *player;
} Play;
typedef struct {
    u8 pad0[0x8C];
    Play *play;
    Act *target;
} Cam;
extern void Actor_GetWorldPosShapeRot(Vec3f *out, Act *a);
Vec3f Camera_GetFocalActorPos(Cam *cam) {
    s32 pad[2];
    Vec3f v;
    Act *a = cam->target;
    Act *b;
    b = a;
    if (a == cam->play->player) {
        a++;
        a--;
        return b->pos;
    }
    Actor_GetWorldPosShapeRot(&v, a);
    return v;
}
