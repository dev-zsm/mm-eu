#include "types.h"

typedef struct {
    u8 pad0[7];
    u8 r;
    u8 g;
    u8 b;
    s16 near;
    s16 far;
} LightFog;

void LightContext_SetFog(LightFog *fog, u8 r, u8 g, u8 b, s16 near, s16 far) {
    fog->r = r;
    fog->g = g;
    fog->b = b;
    fog->near = near;
    fog->far = far;
}
