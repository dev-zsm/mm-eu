#include "types.h"
extern void func_808CA280(void);
typedef struct { u8 pad0[0x70]; f32 f70; u8 pad74[0x48]; s16 s; u8 pad[0x84]; void (*fn)(void); } S;
void func_80000AE0(S *a) {
    a->s = 0;
    a->fn = func_808CA280;
    a->f70 = 0.0f;
}
