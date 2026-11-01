#include "types.h"

typedef struct {
    s16 id;
    u8 pad2[2];
    void* segment;
    u8 pad8[0x44 - 8];
} ObjSlot;

typedef struct {
    u8 pad0[8];
    u8 num;
    u8 pad9[3];
    ObjSlot slots[1];
} ObjCtx;

typedef struct {
    u32 vromStart;
    u32 vromEnd;
} ObjEntry;

extern ObjEntry D_801C3400[];
extern void func_80080CE0(void* dst, u32 vrom, u32 size);

void Object_LoadAll(ObjCtx* objectCtx) {
    s32 i;
    u32 vromStart;
    u32 size;

    for (i = 0; i < objectCtx->num; i++) {
        vromStart = D_801C3400[objectCtx->slots[i].id].vromStart;
        size = D_801C3400[objectCtx->slots[i].id].vromEnd - vromStart;
        if (size != 0) {
            func_80080CE0(objectCtx->slots[i].segment, vromStart, size);
        }
    }
}
