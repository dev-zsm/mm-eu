#include "types.h"

typedef struct {
    u8 unk0;
    u8 pad1[0x3F];
    void *unk40;
} Obj;

extern void func_801706A4(Obj *obj, s32 arg1);
extern void ZeldaArena_Free(void *ptr);

void func_80170E50(Obj *obj) {
    if (obj->unk0 == 1) {
        func_801706A4(obj, 1);
    }
    if (obj->unk40 != NULL) {
        ZeldaArena_Free(obj->unk40);
        obj->unk40 = NULL;
    }
}
