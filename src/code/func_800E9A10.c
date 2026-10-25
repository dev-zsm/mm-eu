#include "types.h"

typedef struct {
    u8 color;
    u8 text[11];
} DebugScreenEntry;

extern s32 D_801BBBC0;
extern DebugScreenEntry D_801BBBC4[];

void Debug_ScreenText(s32 index, s32 color, u8 *text) {
    DebugScreenEntry *entry = &D_801BBBC4[index];
    u8 *dst = entry->text;

    D_801BBBC0 |= 1;
    entry->color = color;
    do {
        *dst++ = *text;
    } while (*text++ != 0);
}
