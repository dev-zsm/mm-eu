#include "types.h"
typedef struct { s16 x, y, z; } R;
typedef struct { u8 p[0x286]; s16 a; } T;
s32 func_8000154C(s32 play, s32 limb, void *d, void *pos, R *rot, T *this) { if (limb == 12) { rot->y += -1 * this->a; } return 0; }
