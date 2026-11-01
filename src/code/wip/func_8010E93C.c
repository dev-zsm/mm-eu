#include "types.h"
typedef struct {
    u8 pad0[0x3DD0]; u8 b3DD0; u8 pad3DD1[6]; u8 b3DD7; u8 pad3DD8[8];
    s64 q3DE0; u8 pad3DE8[0x30]; s64 q3E18; u8 pad3E20[0x68]; s64 q3E88; u8 pad3E90[0x30];
    s64 q3EC0; u8 pad3EC8[0x30]; s16 h3EF8; u8 pad3EFA[0xC]; s16 h3F06;
} G;
extern G D_801E6EF0;
extern s16 D_801C0434;
void func_8010E93C(s16 a, s16 b) {
    s64 v;
    D_801E6EF0.h3EF8 = 0x73;
    D_801E6EF0.h3F06 = 0x50;
    D_801C0434 = b;
    D_801E6EF0.q3DE0 = a * 100; D_801E6EF0.q3E18 = D_801E6EF0.q3DE0; v = D_801E6EF0.q3E18;
    if (v != 0) {
        D_801E6EF0.b3DD7 = 0;
    } else {
        D_801E6EF0.b3DD7 = 1;
    }
    D_801E6EF0.b3DD0 = 0xD;
    D_801E6EF0.q3E88 = 0;
    D_801E6EF0.q3EC0 = 0;
}
