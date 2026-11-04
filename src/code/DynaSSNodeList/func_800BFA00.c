#include "types.h"

typedef struct {
    void *nodes;
    s32 unk4;
    s32 maxNodes;
} Struct_800BFA00;

extern void *THA_AllocTailAlign(void *tha, s32 size, s32 mask);

void DynaSSNodeList_Alloc(void *arg0, Struct_800BFA00 *list, s32 count) {
    list->nodes = THA_AllocTailAlign((u8 *)arg0 + 0x74, count * 4, -2);
    list->maxNodes = count;
    list->unk4 = 0;
}
