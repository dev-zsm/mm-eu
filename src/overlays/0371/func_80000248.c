// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80000248(PlayState* play, EnTrt* this) {
    s16 screenPosX;
    s16 screenPosY;
    f32 xOffset = 0.0f;
    f32 yOffset = 17.0f;

    Actor_GetScreenPos(play, &this->items[this->cursorIndex]->actor, &screenPosX, &screenPosY);
    this->cursorPos.x = screenPosX + xOffset;
    this->cursorPos.y = screenPosY + yOffset;
    this->cursorPos.z = 1.2f;
}
