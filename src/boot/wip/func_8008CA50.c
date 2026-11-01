// best attempt: 24/212 differ (j=0 hoisted before osGetCount in ROM; hoisting here spills badid)
// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 pad0[4];
    s32 queue;
    s32 channel;
    u8 pad0C[0x65 - 0x0C];
    u8 activebank;
} Pfs;

typedef struct {
    s32 repaired;
    s32 random;
    u64 serialMid;
    u64 serial3;
    u16 deviceid;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 inverted_checksum;
} Id;

extern s32 osGetCount();
extern s32 __osPfsSelectBank(Pfs *p, u8 b);
extern s32 __osContRamRead();
extern s32 __osContRamWrite();
extern s32 __osIdCheckSum();

s32 __osRepairPackId(Pfs *pfs, Id *badid, Id *newid) {
    s32 ret = 0;
    u8 buf[32];
    u8 comp[32];
    u8 mask = 0;
    s32 i = 0;
    s32 j = 0;
    u16 index[4];

    newid->repaired = -1;
    newid->random = osGetCount();
    newid->serialMid = badid->serialMid;
    newid->serial3 = badid->serial3;

    if (pfs->activebank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }

    for (j = 0; j < 62;) {
        ret = __osPfsSelectBank(pfs, j);
        if (ret != 0) {
            return ret;
        }
        ret = __osContRamRead(pfs->queue, pfs->channel, 0, buf);
        if (ret != 0) {
            return ret;
        }
        buf[0] = j | 0x80;
        for (i = 1; i < 32; i++) {
            buf[i] = ~buf[i];
        }
        ret = __osContRamWrite(pfs->queue, pfs->channel, 0, buf, 0);
        if (ret != 0) {
            return ret;
        }
        ret = __osContRamRead(pfs->queue, pfs->channel, 0, comp);
        if (ret != 0) {
            return ret;
        }
        for (i = 0; i < 32; i++) {
            if (comp[i] != buf[i]) {
                break;
            }
        }
        if (i != 32) {
            break;
        }
        if (j > 0) {
            ret = __osPfsSelectBank(pfs, 0);
            if (ret != 0) {
                return ret;
            }
            ret = __osContRamRead(pfs->queue, pfs->channel, 0, buf);
            if (ret != 0) {
                return ret;
            }
            if (buf[0] != 0x80) {
                break;
            }
        }
        j++;
    }

    if (pfs->activebank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    if (j > 0) {
        mask = 1;
    } else {
        mask = 0;
    }
    newid->deviceid = (badid->deviceid & 0xFFFE) | mask;
    newid->banks = j;
    newid->version = badid->version;
    __osIdCheckSum(newid, &newid->checksum, &newid->inverted_checksum);

    index[0] = 1;
    index[1] = 3;
    index[2] = 4;
    index[3] = 6;
    for (i = 0; i < 4; i++) {
        ret = __osContRamWrite(pfs->queue, pfs->channel, index[i], newid, 1);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, buf);
    if (ret != 0) {
        return ret;
    }
    for (i = 0; i < 32; i++) {
        if (buf[i] != ((u8 *)newid)[i]) {
            return 11;
        }
    }
    return 0;
}
