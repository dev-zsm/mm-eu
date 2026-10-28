// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x20];
    u8 unk2C[0x20];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    u8 unk64;
} Ctx;

typedef struct {
    u32 repaired;
    u32 random;
    u64 serialMid;
    u32 unk10;
    u32 unk14;
    u16 deviceid;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 invertedChecksum;
} Blk;

void __osSiGetAccess(void);
s32 __osSiRelAccess(void);
s32 __osPfsGetStatus(s32 a, s32 b);
void __osIdCheckSum(u8 *a, u16 *b, u16 *c);
s32 __osRepairPackId(Ctx *c, u8 *a, u8 *b);
s32 __osCheckPackId(Ctx *c, u8 *a);
s32 __osContRamRead(s32 a, s32 b, u16 c, u8 *d);
void bcopy(u8 *a, u8 *b, s32 c);
s32 __osPfsSelectBank(Ctx *c, s32 x);
s32 __osPfsCheckRamArea(Ctx *c);
s32 osPfsChecker(Ctx *c);

s32 osPfsInitPak(s32 queue, Ctx *pfs, s32 channel) {
    s32 ret;
    u16 sum;
    u16 isum;
    u8 temp[0x20];
    u8 *id;
    Blk newid;

    __osSiGetAccess();
    ret = __osPfsGetStatus(queue, channel);
    __osSiRelAccess();
    if (ret != 0) {
        return ret;
    }
    pfs->unk4 = queue;
    pfs->unk8 = channel;
    pfs->unk0 = 0;
    ret = __osPfsCheckRamArea(pfs);
    if (ret != 0) {
        return ret;
    }
    ret = __osPfsSelectBank(pfs, 0);
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(pfs->unk4, pfs->unk8, 1, temp);
    if (ret != 0) {
        return ret;
    }
    __osIdCheckSum(temp, &sum, &isum);
    id = temp;
    if (((Blk *)temp)->checksum != sum || ((Blk *)temp)->invertedChecksum != isum) {
        ret = __osCheckPackId(pfs, temp);
        if (ret != 0) {
            pfs->unk0 |= 4;
            return ret;
        }
    }
    if (!(((Blk *)temp)->deviceid & 1)) {
        ret = __osRepairPackId(pfs, temp, (u8 *)&newid);
        if (ret != 0) {
            if (ret == 0xA) {
                pfs->unk0 |= 4;
            }
            return ret;
        }
        id = (u8 *)&newid;
        if (!(newid.deviceid & 1)) {
            return 0xB;
        }
    }
    bcopy(id, pfs->unkC, 0x20);
    pfs->unk4C = id[0x1B];
    pfs->unk64 = id[0x1A];
    pfs->unk60 = pfs->unk64 * 2 + 3;
    pfs->unk50 = 0x10;
    pfs->unk54 = 8;
    pfs->unk58 = pfs->unk54 + pfs->unk64 * 8;
    pfs->unk5C = pfs->unk58 + pfs->unk64 * 8;
    ret = __osContRamRead(pfs->unk4, pfs->unk8, 7, pfs->unk2C);
    if (ret != 0) {
        return ret;
    }
    ret = osPfsChecker(pfs);
    pfs->unk0 |= 1;
    return ret;
}
