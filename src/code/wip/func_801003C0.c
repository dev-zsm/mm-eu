// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s16 r, g, b;
    s16 tr, tg, tb;
} HeartColor;

typedef struct {
    s16 f0E, f10;
    u8 pad12[0xC];
    s16 f1E, f20, f22, f24, f26, f28, f2A, f2C, f2E, f30, f32, f34, f36, f38, f3A, f3C;
} Meter;

typedef struct {
    u8 pad0[0x16C0E];
    Meter m;
} Play;

extern s16 D_801E6F26;
extern HeartColor D_801EC7D0;
extern HeartColor D_801EC7E0;

void LifeMeter_Init(Play *play) {
    Meter *m = &play->m;

    m->f38 = 0x140;
    m->f0E = 0;
    m->f10 = 0;
    m->f36 = D_801E6F26;
    m->f3A = m->f0E;
    m->f3C = m->f10;
    m->f1E = 0xFF;
    m->f22 = 0x46;
    m->f26 = 0x32;
    m->f2A = 0x32;
    m->f2E = 0x28;
    m->f32 = 0x3C;
    m->f20 = 0xFF;
    m->f24 = 0x46;
    m->f28 = 0x32;
    m->f2C = 0x32;
    m->f30 = 0x28;
    m->f34 = 0x3C;
    D_801EC7D0.tr = 0xFF;
    D_801EC7D0.tg = 0xFF;
    D_801EC7D0.tb = 0xFF;
    D_801EC7E0.tr = 0xC8;
    D_801EC7E0.tg = 0;
    D_801EC7E0.tb = 0;
    D_801EC7D0.r = D_801EC7D0.tr;
    D_801EC7D0.g = D_801EC7D0.tg;
    D_801EC7D0.b = D_801EC7D0.tb;
    D_801EC7E0.r = D_801EC7E0.tr;
    D_801EC7E0.g = D_801EC7E0.tg;
    D_801EC7E0.b = D_801EC7E0.tb;
}
