#include "types.h"

typedef struct {
    u16 key;
    u8 pad2;
    u8 unk3[5];
    s32 value;
    u8 pad_c[8];
} PendingEntry; // size = 0x14

typedef struct {
    s32 value;
    u8 pad4[0x1E];
    u16 key;
    u8 pad_24[8];
    u8 unk2C;
} PendingQuery;

extern u8 D_801D3DA0;
extern u8 D_801D3DA4;
extern PendingEntry D_801F6000[];

void AudioSfx_RemoveMatchingRequests(u8 type, PendingQuery *query) {
    u8 i = D_801D3DA4;
    s32 found;

    while (i != D_801D3DA0) {
        found = 0;
        switch (type) {
            case 0:
                if ((query->key & 0xF000) == (D_801F6000[i].key & 0xF000)) {
                    found = 1;
                }
                break;
            case 1:
                if ((query->key & 0xF000) == (D_801F6000[i].key & 0xF000)) {
                    if (query->value == D_801F6000[i].value) {
                        found = 1;
                    }
                }
                break;
            case 2:
                if (query->value == D_801F6000[i].value) {
                    found = 1;
                }
                break;
            case 3:
                if (query->value == D_801F6000[i].value) {
                    if (query->key == D_801F6000[i].key) {
                        found = 1;
                    }
                }
                break;
            case 4:
                if (query->unk2C == D_801F6000[i].pad2) {
                    if (query->key == D_801F6000[i].key) {
                        found = 1;
                    }
                }
                break;
            case 5:
                if (query->key == D_801F6000[i].key) {
                    found = 1;
                }
                break;
        }
        if (found) {
            D_801F6000[i].key = 0;
        }
        i++;
    }
}
