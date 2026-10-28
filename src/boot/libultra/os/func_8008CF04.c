// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
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
    u8 unk65;
} Ctx;

typedef struct {
    u32 repaired;
    u32 random;
    u64 serialMid;
    u64 serialLo;
    u16 deviceid;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 inverted_checksum;
} PackId;

s32 __osPfsSelectBank(void *a, s32 b);
s32 __osContRamRead(s32 a, s32 b, u16 c, void *d);
void __osIdCheckSum(void *a, u16 *b, u16 *c);
s32 __osRepairPackId(void *a, void *b, void *c);
s32 __osCheckPackId(void *a, void *b);
void bcopy(void *a, void *b, s32 c);

s32 __osGetId(Ctx *arg0) {
    u16 sum;
    u16 isum;
    u8 temp[32];
    PackId newid;
    PackId *id;
    s32 ret;

    if (arg0->unk65 != 0) {
        ret = __osPfsSelectBank(arg0, 0);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(arg0->unk4, arg0->unk8, 1, temp);
    if (ret != 0) {
        return ret;
    }
    __osIdCheckSum(temp, &sum, &isum);
    id = (PackId *)temp;
    if (id->checksum != sum || id->inverted_checksum != isum) {
        ret = __osCheckPackId(arg0, id);
        if (ret == 0xA) {
            ret = __osRepairPackId(arg0, id, &newid);
            if (ret != 0) {
                return ret;
            }
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }
    if (!(id->deviceid & 1)) {
        ret = __osRepairPackId(arg0, id, &newid);
        if (ret != 0) {
            return ret;
        }
        id = &newid;
        if (!(id->deviceid & 1)) {
            return 0xB;
        }
    }
    bcopy(id, arg0->unkC, 0x20);
    arg0->unk4C = id->version;
    arg0->unk64 = id->banks;
    arg0->unk60 = arg0->unk64 * 2 + 3;
    arg0->unk50 = 0x10;
    arg0->unk54 = 8;
    arg0->unk58 = arg0->unk54 + arg0->unk64 * 8;
    arg0->unk5C = arg0->unk58 + arg0->unk64 * 8;
    ret = __osContRamRead(arg0->unk4, arg0->unk8, 7, arg0->unk2C);
    if (ret != 0) {
        return ret;
    }
    return 0;
}
