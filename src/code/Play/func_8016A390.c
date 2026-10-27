#include "types.h"

typedef struct {
    u32 start;
    u32 end;
} FileRange;

extern void *THA_AllocTailAlign16(s32 a0, u32 size);
extern void func_80080CE0(void *dst, u32 start, u32 size, FileRange *range);

void *Play_LoadFile(s32 a0, FileRange *range) {
    u32 size = range->end - range->start;
    void *buf = THA_AllocTailAlign16(a0 + 0x74, size);

    func_80080CE0(buf, range->start, size, range);
    return buf;
}
