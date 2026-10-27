#include "types.h"
typedef struct { u8 pad[0x28C]; s32 count; s32 list[3]; } Col;
s32 func_8016B1A4(void *);
void Collider_ResetLineOC(void *, s32);
s32 CollisionCheck_SetOCLine(void *play, Col *col, s32 line) {
    s32 n;
    if (func_8016B1A4(play) != 0) {
        return -1;
    }
    Collider_ResetLineOC(play, line);
    n = col->count;
    if (n >= 3) {
        return -1;
    }
    col->list[n] = line;
    col->count++;
    return n;
}
