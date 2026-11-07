#include "types.h"
typedef struct { u8 pad0[0xACC]; s16 aCC; } S;
s32 func_8082E37C();
s32 func_80001490(S *p) {
    return func_8082E37C(p) != 0 && p->aCC != 0;
}
