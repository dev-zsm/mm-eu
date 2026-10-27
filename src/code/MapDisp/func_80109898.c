#include "types.h"

typedef struct {
    u8 w;
    u8 h;
    u8 pad[8];
} MapTex;

extern MapTex D_801BFCC0[];

s32 MapDisp_GetSizeOfMapITex(s32 arg0) {
    MapTex *t = &D_801BFCC0[arg0];

    return (t->h * t->w) / 2;
}
