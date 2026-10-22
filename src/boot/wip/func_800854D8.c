// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;  /* 0x00 */
    struct Node *prev;  /* 0x04 */
    u32 start;          /* 0x08 */
    u32 end;            /* 0x0C */
    u32 fill;           /* 0x10 */
    s32 limit;          /* 0x14 */
    s32 unk18;          /* 0x18 */
} Node;

s32 func_800854D8(Node *arg0) {
    u32 p;
    u32 end;
    u32 fill;
    u32 len;
    s32 ret;

    ret = 0;
    p = arg0->start;
    end = arg0->end;
    if (p < end) {
        fill = arg0->fill;
        do {
            if (fill != *(u32 *)p) {
                break;
            }
            p += 4;
        } while (p < end);
    }
    len = p - arg0->start;
    if (len == 0) return 2;
    if (len < (u32)arg0->limit && arg0->limit != -1) { ret = 1; } else { ret = 0; }
    return ret;
}