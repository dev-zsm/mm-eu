#include "types.h"

typedef struct {
    u16 *start;
    u16 *cur;
    u8 pad8[0x20];
    u32 flags;
} Sub;

extern s32 BgCheck_CheckLineAgainstSSList();

s32 BgCheck_CheckLineInSubdivision(Sub *s) {
    s32 ret = 0;

    if (s->flags & 2) {
        if (s->start[0] != 0xFFFF) {
            s->cur = s->start;
            ret = 0; // matching: keeps the ROM store to the stack slot
            if (BgCheck_CheckLineAgainstSSList(s) != 0) {
                ret = 1;
            }
        }
    }
    if (s->flags & 1) {
        if (s->start[1] != 0xFFFF) {
            s->cur = s->start + 1;
            if (BgCheck_CheckLineAgainstSSList(s) != 0) {
                ret = 1;
            }
        }
    }
    if (s->flags & 4) {
        if (s->start[2] != 0xFFFF) {
            s->cur = s->start + 2;
            if (BgCheck_CheckLineAgainstSSList(s) != 0) {
                ret = 1;
            }
        }
    }
    return ret;
}
