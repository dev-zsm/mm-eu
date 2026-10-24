#include "types.h"

typedef struct {
    u8 pad0[0x3F20];
    u16 unk3F20;
    u16 unk3F22;
    u16 unk3F24;
} Struct_801E6EF0;

extern Struct_801E6EF0 D_801E6EF0;

void func_8010EE64(u16 arg0) {
    if (D_801E6EF0.unk3F22 != arg0) {
        D_801E6EF0.unk3F22 = arg0;
        D_801E6EF0.unk3F20 = arg0;
        D_801E6EF0.unk3F24 = 1;
    }
}
