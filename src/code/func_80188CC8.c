#include "types.h"

typedef struct {
    u32 active : 1;
    u32 locked : 1;
    u32 unk0_2 : 30;
    u8 pad4[0x1C];
} Entry;
typedef struct {
    u8 pad0[0x14];
    Entry *entries;
    u8 pad18[0x2878 - 0x18];
    s16 count;
    u8 pad287A[0x28B8 - 0x287A];
    u32 stride;
} Table;
extern Table D_801F84B0;
void func_80188CC8(s32 first, s32 column) {
    s32 i = first + 1;
    u32 *new_var;
    Entry *entry;
    while (i < D_801F84B0.count) {
        entry = &D_801F84B0.entries[((*(new_var = &D_801F84B0.stride)) * i) + column];
        if (entry->locked) {
            break;
        }
        entry->active = 0;
        i++;
    }

}
