#include "types.h"

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    u8 mf[0x40];
} Struct_80123054_Entry;

typedef struct {
    u8 unk0;
    s8 unk1;
    u8 pad2[2];
    Struct_80123054_Entry entries[4];
} Struct_80123054;

void Matrix_Get(void *mf);

void func_80123054(void *arg0, Struct_80123054 *arg1, u32 arg2, s32 arg3) {
    Struct_80123054_Entry *entry;

    if (arg2 == arg1->unk0) {
        arg1->unk1--;
        if (arg1->unk1 < 0) {
            arg1->unk1 = 3;
        }
        entry = &arg1->entries[arg1->unk1];
        entry->unk0 = arg1->unk0;
        entry->unk1 = arg3;
        Matrix_Get(entry->mf);
        arg1->unk0 = 0;
    }
}
