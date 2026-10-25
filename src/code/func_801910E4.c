#include "types.h"

typedef struct {
    u8 pad0[0x10];
    s32 realIndex;
    s32 unk14;
} TableEntry;

extern u8 *AudioLoad_GetLoadTable(s32 arg0);

s32 AudioLoad_GetRealTableIndex(s32 arg0, s32 arg1) {
    TableEntry *entry = (TableEntry *)(AudioLoad_GetLoadTable(arg0) + arg1 * 16);

    if (entry->unk14 == 0) {
        arg1 = entry->realIndex;
    }
    return arg1;
}
