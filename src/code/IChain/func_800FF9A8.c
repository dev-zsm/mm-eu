#include "types.h"

typedef struct {
    u16 unk0;
    s16 unk2;
} Entry;

void func_800FF9A8(u8 *arg0, Entry *arg1) {
    *(s16 *)(arg0 + (arg1->unk0 & 0x7FF)) = arg1->unk2;
}
