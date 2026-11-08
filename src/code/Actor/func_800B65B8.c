#include "types.h"

typedef struct Fn800B65B8Act {
    u8 pad0[0x1E];
    s8 unk1E;
    u8 unk1F;
    u8 pad20[4];
    f32 unk24[3];
    u8 pad30[0x48];
    f32 unk78;
    u8 pad7C[9];
    u8 unk85;
    u8 pad86[0xE];
    f32 unk94;
    u8 pad98[8];
    f32 unkA0[3];
    u8 padAC[0x10];
    f32 unkBC[3];
    u8 padC8[0x34];
    f32 unkFC;
    f32 unk100;
    f32 unk104;
    f32 unk108[3];
    u8 pad114[0xB];
    u8 unk11F;
    u8 pad120[0x10];
    void (*unk130)(struct Fn800B65B8Act *, void *);
} Fn800B65B8Act;

extern f32 D_801D4AE4;
extern void ActorShape_Init(f32 *, f32, s32, f32);
extern void Actor_SetWorldToHome(Fn800B65B8Act *);
extern void Actor_SetFocus(Fn800B65B8Act *, f32);
extern void Actor_SetShapeRotToWorld(Fn800B65B8Act *);
extern void Actor_SetScale(Fn800B65B8Act *, f32);
extern void Actor_SetObjectDependency(void *, Fn800B65B8Act *);
extern void CollisionCheck_InitInfo(f32 *);
extern void Math_Vec3f_Copy(f32 *, f32 *);
extern s32 Object_IsLoaded(u8 *, s8);

void Actor_Init(Fn800B65B8Act *arg0, u8 *arg1) {
    Actor_SetWorldToHome(arg0);
    Actor_SetShapeRotToWorld(arg0);
    Actor_SetFocus(arg0, 0);
    Math_Vec3f_Copy(arg0->unk108, arg0->unk24);
    Actor_SetScale(arg0, 0.01f);
    arg0->unk1F = 3;
    arg0->unk78 = -20.0f;
    arg0->unk94 = D_801D4AE4;
    arg0->unkFC = 1000.0f;
    arg0->unk100 = 350.0f;
    arg0->unk104 = 700.0f;
    arg0->unk11F = 0xFF;
    CollisionCheck_InitInfo(arg0->unkA0);
    arg0->unk85 = 0x32;
    ActorShape_Init(arg0->unkBC, 0.0f, 0, 0.0f);
    if (Object_IsLoaded(arg1 + 0x17D88, arg0->unk1E) != 0) {
        Actor_SetObjectDependency(arg1, arg0);
        arg0->unk130(arg0, arg1);
        arg0->unk130 = NULL;
    }
}
