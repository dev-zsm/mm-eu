#include "types.h"

typedef struct {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
    /* 0x4 */ u16 unk4;
} LoadHeader;

typedef struct {
    /* 0x0 */ LoadHeader *data;
    /* 0x4 */ u32 size;
    /* 0x8 */ s8 loadType;
    /* 0x9 */ s8 medium;
    /* 0xA */ u8 padA[6];
} LoadTableEntry; // size = 0x10

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 pad4[0xC];
    /* 0x10 */ LoadTableEntry entries[1];
} LoadTable;

extern u8 *D_801FAD18;

extern s32 AudioLoad_GetRealTableIndex(s32 tableType, s32 id);
extern s32 AudioLoad_SearchCaches(s32 tableType, s32 realId);
extern LoadTable *AudioLoad_GetLoadTable(s32 tableType);
extern s32 AudioHeap_AllocPermanent(s32 tableType, s32 realId, u32 size);
extern s32 AudioHeap_AllocCached(s32 tableType, u32 size, s32 cache, s32 realId);
extern void func_80091460(void *src, s32 dst, u32 size);
extern void func_80191548(void *src, s32 dst, u32 size, s32 arg3);
extern void func_80191424(void *src, s32 dst, u32 size, s32 medium);
extern void AudioLoad_SetSeqLoadStatus(s32 realId, s32 status);
extern void AudioLoad_SetFontLoadStatus(s32 realId, s32 status);
extern void AudioLoad_SetSampleFontLoadStatusAndApplyCaches(s32 realId, s32 status);

s32 AudioLoad_SyncLoad(s32 tableType, s32 id, s32 *didAllocate) {
    s32 realId;
    s32 ramAddr;
    LoadTable *table;
    u32 size;
    s32 medium;
    s32 loadType;
    LoadHeader *romAddr;
    s32 status;
    u8 *dst;

    realId = AudioLoad_GetRealTableIndex(tableType, id);
    ramAddr = AudioLoad_SearchCaches(tableType, realId);
    if (ramAddr != 0) {
        *didAllocate = 0;
        status = 2;
    } else {
        table = AudioLoad_GetLoadTable(tableType);
        size = table->entries[realId].size;
        size = (size + 0xF) & ~0xF;
        loadType = table->entries[id].loadType;
        medium = table->entries[id].medium;
        romAddr = table->entries[realId].data;
        switch (medium) {
            case 0:
                ramAddr = AudioHeap_AllocPermanent(tableType, realId, size);
                if (ramAddr == 0) {
                    return 0;
                }
                break;
            case 1:
                ramAddr = AudioHeap_AllocCached(tableType, size, 1, realId);
                if (ramAddr == 0) {
                    return 0;
                }
                break;
            case 2:
                ramAddr = AudioHeap_AllocCached(tableType, size, 0, realId);
                if (ramAddr == 0) {
                    return 0;
                }
                break;
            case 3:
            case 4:
                ramAddr = AudioHeap_AllocCached(tableType, size, 2, realId);
                if (ramAddr == 0) {
                    return 0;
                }
                break;
        }
        *didAllocate = 1;
        if (loadType == 5) {
            if (romAddr == 0) {
                return 0;
            }
            if (tableType == 1) {
                dst = D_801FAD18 + realId * 20;
                dst[0] = romAddr->unk0;
                dst[1] = romAddr->unk2;
                *(u16 *)(dst + 4) = romAddr->unk4;
                romAddr = (LoadHeader *)((u8 *)romAddr + 0x10);
                size -= 0x10;
            }
            func_80091460(romAddr, ramAddr, size);
        } else if (loadType == 1) {
            func_80191548(romAddr, ramAddr, size, table->unk2);
        } else {
            func_80191424(romAddr, ramAddr, size, loadType);
        }
        status = 2;
        if (medium == 0) {
            status = 5;
        }
    }
    switch (tableType) {
        case 0:
            AudioLoad_SetSeqLoadStatus(realId, status);
            break;
        case 1:
            AudioLoad_SetFontLoadStatus(realId, status);
            break;
        case 2:
            AudioLoad_SetSampleFontLoadStatusAndApplyCaches(realId, status);
            break;
    }
    return ramAddr;
}
