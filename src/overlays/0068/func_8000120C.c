#include "types.h"
#include "generated/overlays/0068.h"

extern u8 D_8087A040[];

void func_8000120C(Actor *thisx) {
    *(s16 *)((u8 *)thisx + 0x190) = 1;
    *(u8 **)((u8 *)thisx + 0x188) = D_8087A040;
    *(f32 *)((u8 *)thisx + 0x70) = 0.0f;
}
