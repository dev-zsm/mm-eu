// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 flags;
    s32 unk4;
    s32 unk8;
    u8 padC[0x50];
    s32 unk5C;
    s32 unk60;
    u8 unk64;
} Obj;

s32 func_8008BEC4(Obj *obj, u16 *tbl, s32 n, s32 *cnt, u8 i, s32 *p1, s32 *p2);
s32 func_8008D184(Obj *obj, void *buf, s32 zero, u8 i);
s32 func_8008D610(Obj *obj, u16 val, s32 a2, void *a3, void *p5, s32 *p7);
s32 func_80087E00(Obj *obj, s32 *out);
void func_80091460(void *a0, void *a1, s32 size);
s32 func_80093F40(s32 a0, s32 a1, u16 a2, void *a3, s32 a4);

s32 func_8008BB90(Obj *obj, s32 a1, s32 a2, void *a3, void *p5, s32 n, s32 *p7) {
    u8 buf[0x100];
    u16 tbl[0x80];
    u8 pair[2];
    u8 blk70[0x10];
    u8 blk60[0x0C];
    s32 sp6C;
    s32 p1;
    s32 p2;
    s32 cnt;
    s32 v54;
    s32 total;
    s32 nsub;
    s32 prev;
    u8 cur;
    s32 r;
    s32 count;
    u8 i;
    u16 val;

    val = (u16)a1;
    if (val == 0 || a2 == 0) {
        return 5;
    }
    total = (n + 0xFF) / 0x100;
    r = func_8008D610(obj, val, a2, a3, p5, p7);
    if (r != 0 && r != 5) {
        return r;
    }
    if (*p7 != -1) {
        return 9;
    }
    func_80087E00(obj, &v54);
    if (v54 < n) {
        return 7;
    }
    if (total == 0) {
        return 5;
    }
    r = func_8008D610(obj, 0, 0, 0, 0, p7);
    if (r != 0 && r != 5) {
        return r;
    }
    if (*p7 == -1) {
        return 8;
    }

    nsub = 0;
    prev = 0;
    cur = 0;
    count = obj->unk64;
    i = 0;
    while ((s32)i < count) {
        r = func_8008D184(obj, tbl, 0, i);
        if (r != 0) {
            return r;
        }
        r = func_8008BEC4(obj, tbl, total, &cnt, i, &p1, &p2);
        if (r != 0) {
            return r;
        }
        if (cnt != -1) {
            if (nsub != 0) {
                ((u8 *)buf)[prev * 2] = i;
                ((u8 *)buf)[prev * 2 + 1] = cnt;
                r = func_8008D184(obj, buf, 1, cur);
                if (r != 0) {
                    return r;
                }
            } else {
                pair[1] = cnt;
                pair[0] = i;
            }
            if (p1 < total) {
                func_80091460(tbl, buf, 0x100);
                prev = p2;
                cur = i;
                nsub++;
                total -= p1;
            } else {
                total = 0;
                r = func_8008D184(obj, tbl, 1, i);
                if (r == 0) {
                    break;
                }
                return r;
            }
        }
        i++;
        count = obj->unk64;
    }

    if (total > 0 || cnt == -1) {
        return 3;
    }
    func_80091460(a3, blk70, 0x10);
    func_80091460(p5, &sp6C, 4);
    *(s32 *)blk60 = a2;
    *(u16 *)(blk60 + 4) = val;
    *(u16 *)(blk60 + 6) = *(u16 *)pair;
    *(u16 *)(blk60 + 10) = 0;
    return func_80093F40(obj->unk4, obj->unk8, (u16)(*p7 + obj->unk5C), blk60, 0);
}
