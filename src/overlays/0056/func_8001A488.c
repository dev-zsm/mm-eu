#include "types.h"
typedef struct { u8 pad0[0x388]; s16* a388; } P;
extern u16 *D_80862264;
s32 func_8001A488(P *p) {
    return p->a388 != NULL && *p->a388 == 0x224 && ~(*D_80862264 | ~0x8000) == 0;
}
