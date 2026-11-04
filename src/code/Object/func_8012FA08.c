#include "types.h"
typedef struct ObjEntry { u8 pad0[0xC]; s16 unkC; u8 pad1[0x44 - 0xE]; } ObjEntry;
s32 Object_IsLoaded(ObjEntry *a0, s32 a1) {
    if (a0[a1].unkC > 0) {
        return 1;
    }
    return 0;
}
