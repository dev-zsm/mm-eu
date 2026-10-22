// FLAGS: -O2 -g3
#include "types.h"
typedef struct Block {
    s16 magic;
    s16 free;
    u32 size;
    struct Block *next;
    struct Block *prev;
} Block;
void ArenaImpl_Lock(s32 a0, u32 a1);
void ArenaImpl_Unlock(s32 a0);
void *func_80087394(s32 a0, u32 a1);
void free(s32 a0, void *a1);
void func_80087560(s32 a0, void *a1);
void bcopy(void *a0, void *a1, u32 a2);
void func_80096AD0(void *a0, void *a1, s32 a2, u32 a3);
void *func_8008766C(s32 a0, void *a1, u32 a2) {
    Block *hdr;
    Block *nb;
    Block *nxt;
    Block *nxt2;
    Block copy;
    u32 need;
    u32 oldsz;
    u32 diff;
    need = (a2 + 0xF) & ~0xF;
    ArenaImpl_Lock(a0, need);
    if (a1 == NULL) {
        a1 = func_80087394(a0, need);
    } else if (need == 0) {
        free(a0, a1);
        a1 = NULL;
    } else {
        hdr = (Block *)((u8 *)a1 - 0x10);
        oldsz = hdr->size;
        if (need != oldsz) {
            if (oldsz < need) {
                diff = need - oldsz;
                nxt = hdr->next;
                if (nxt == (Block *)((u8 *)hdr + oldsz + 0x10) && nxt->free != 0 && nxt->size >= diff) {
                    nxt2 = nxt->next;
                    nxt->size = nxt->size - diff;
                    if (nxt2 != NULL) {
                        nxt2->prev = (Block *)((u8 *)nxt + diff);
                    }
                    nb = (Block *)((u8 *)nxt + diff);
                    hdr->next = nb;
                    hdr->size = need;
                    func_80096AD0(nb, nxt, 0x10, need);
                } else {
                    nb = func_80087394(a0, need);
                    if (nb != NULL) {
                        bcopy(nb, a1, hdr->size);
                        func_80087560(a0, a1);
                    }
                    a1 = nb;
                }
            } else {
                nxt = hdr->next;
                if (nxt != NULL && nxt->free != 0) {
                    copy = *nxt;
                    nb = (Block *)((u8 *)hdr + need + 0x10);
                    *nb = copy;
                    nb->size = copy.size + hdr->size - need;
                    hdr->next = nb;
                    hdr->size = need;
                    nxt2 = nb->next;
                    if (nxt2 != NULL) {
                        nxt2->prev = nb;
                    }
                } else if (need + 0x10 < oldsz) {
                    nb = (Block *)((u8 *)hdr + need + 0x10);
                    nb->next = nxt;
                    nb->prev = hdr;
                    nb->size = hdr->size - (need + 0x10);
                    nb->free = 1;
                    nb->magic = 0x7373;
                    hdr->next = nb;
                    hdr->size = need;
                    nxt2 = nb->next;
                    if (nxt2 != NULL) {
                        nxt2->prev = nb;
                    }
                }
            }
        }
    }
    ArenaImpl_Unlock(a0);
    return a1;
}
