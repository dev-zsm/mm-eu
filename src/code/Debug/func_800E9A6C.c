#include "types.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[10];
} Line;

typedef struct {
    u8 r, g, b, a;
} Col;

extern Line D_801BBBC4[];
extern Col D_801BBC0C[];
extern u8 D_801D5690[];

void func_80085A9C(s32 arg0, s32 x, s32 y);
void func_80085A2C(s32 arg0, u8 r, u8 g, u8 b, u8 a);
void func_80086148(s32 arg0, u8 *fmt, u8 *s);

void Debug_DrawScreenText(s32 arg0) {
    Line *l = D_801BBBC4;
    s32 y;

    for (y = 0x14; y != 0x1A; y++) {
        func_80085A9C(arg0, 0x1A, y);
        func_80085A2C(arg0, D_801BBC0C[l->unk0].r, D_801BBC0C[l->unk0].g, D_801BBC0C[l->unk0].b, D_801BBC0C[l->unk0].a);
        func_80086148(arg0, D_801D5690, &l->unk1);
        l->unk1 = 0;
        l++;
    }
}
