// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_flashrom_ctx.h"

s32 SysFlashrom_Write(void* addr, u32 pageNum, u32 pageCount) {
    void* data;
    size_t size;
    s32 ret;

    if (!SysFlashrom_IsInit()) {
        return -1;
    }
    size = pageCount * FLASH_BLOCK_SIZE;
    data = malloc(size);
    if (data == NULL) {
        ret = SysFlashrom_AttemptWrite(addr, pageNum, pageCount);
    } else {
        SysFlashrom_Read(data, pageNum, pageCount);
        if (bcmp(data, addr, size) == 0) {
            ret = 0;
        } else {
            
            if (SysFlashrom_NeedsToErase(data, addr, pageCount)) {
                ret = SysFlashrom_AttemptWrite(addr, pageNum, pageCount);
            } else {
                ret = SysFlashrom_AttemptWrite(addr, pageNum, pageCount);
            }
            if (ret == 0) {
                SysFlashrom_Read(data, pageNum, pageCount);
                if (bcmp(data, addr, size) == 0) {
                    ret = 0;
                } else {
                    ret = -1;
                }
            }
        }
        free(data);
    }
    return ret;
}
