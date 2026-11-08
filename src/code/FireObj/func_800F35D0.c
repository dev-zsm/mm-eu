#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x11A];
    s32 unk138;
    u8 pad13C[0x84];
    s32 unk1C0;
} Fn800F35D0Obj;

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    u8 padC[0x14];
    s32 unk20;
    u8 unk24;
    u8 pad25[7];
    u8 unk2C[1];
    u8 pad2D[7];
    Fn800F35D0Obj *unk34;
    u8 pad38[5];
    u8 unk3D;
    u8 pad3E[0x2A];
    u32 *unk68;
    u8 pad6C[6];
    s16 unk72;
    s16 unk74;
    s16 unk76;
    u8 unk78[1];
} Fn800F35D0Ent;

extern void CollisionCheck_SetAC(s32, s32, u8 *);
extern void FireObj_SetState(Fn800F35D0Ent *, s32, s32);
extern void FireObj_UpdateStateTransitions(s32, Fn800F35D0Ent *);
extern void FireObj_UpdateLight(s32, u8 *, Fn800F35D0Ent *);

void FireObj_Update(s32 arg0, Fn800F35D0Ent *arg1, s32 arg2) {
    s32 pad;
    Fn800F35D0Obj *sp20;

    sp20 = arg1->unk34;
    FireObj_UpdateStateTransitions(arg0, arg1);
    if (arg1->unk24 == 3) {
        if ((arg1->unk3D & 2) && (*arg1->unk68 & 0x800)) {
            FireObj_SetState(arg1, arg1->unk20, 0);
        }
    } else if ((arg1->unk3D & 2) && sp20->unk138 != 0 && *(s16 *)sp20 == 0xF) {
        sp20->unk1C = 0;
        sp20->unk1C0 = 0x800;
    }
    arg1->unk72 = arg1->unk0;
    arg1->unk74 = arg1->unk4;
    arg1->unk76 = arg1->unk8;
    CollisionCheck_SetAC(arg0, arg0 + 0x18884, arg1->unk2C);
    FireObj_UpdateLight(arg0, arg1->unk78, arg1);
}
