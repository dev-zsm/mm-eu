#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 params; } A;
typedef struct { void *p; u8 pad[0x1C]; } E32;
extern E32 D_8090E028[];
void func_800BDD44();
void func_80001EF0(A *thisx, s32 play2) {
    s32 play = play2;
    A *this = thisx;
    func_800BDD44(play, D_8090E028[(this->params >> 7) & 3].p);
}
