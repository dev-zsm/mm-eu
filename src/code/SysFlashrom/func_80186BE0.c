#include "types.h"

typedef struct {
    s32 cmd;
    s32 ret;
    s32 a;
    s32 b;
    s32 c;
    u8 mq[1];
} FlashromReq;

extern s32 SysFlashrom_Write(s32 a, s32 b, s32 c);
extern s32 SysFlashrom_Read(s32 a, s32 b, s32 c);
extern void func_80087CB0(void* mq, s32 msg, s32 flag);

void SysFlashrom_ThreadEntry(FlashromReq* req) {
    switch (req->cmd) {
        case 1:
            req->ret = SysFlashrom_Write(req->a, req->b, req->c);
            func_80087CB0(req->mq, req->ret, 1);
            break;
        case 2:
            req->ret = SysFlashrom_Read(req->a, req->b, req->c);
            func_80087CB0(req->mq, req->ret, 1);
            break;
    }
}
