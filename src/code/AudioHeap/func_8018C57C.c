#include "types.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[4];
    s32 unkC;
} Struct_8018C57C;

extern void* AudioHeap_Alloc(Struct_8018C57C* heap);

void* AudioHeap_TestAlloc(Struct_8018C57C* arg0) {
    s32 saved = arg0->unk4;
    void* ptr = AudioHeap_Alloc(arg0);

    if (ptr != NULL) {
        arg0->unk4 = saved;
        arg0->unkC = arg0->unkC - 1;
    }
    return ptr;
    // unused label: needed for the ROM's epilogue layout
dummy_label:;
}
