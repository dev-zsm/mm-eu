#include "types.h"
typedef struct { u8 pad[0x1887C]; s8 v; } A;
extern u16 *D_80862264;
s32 func_80003544(A *a) {
    return a->v != 0 && (a->v < 0 || (*D_80862264 & 0xC00F) != 0);
}
