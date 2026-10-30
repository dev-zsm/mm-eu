// FLAGS: -O2 -g0 -mips2
#include "libultra_libc.h"

OSTask *_VirtualToPhysicalTask(OSTask *task) {
    OSTask_t *t = &D_8009D140.t;

    bcopy(task, &D_8009D140, sizeof(OSTask));
    if (t->ucode != NULL) {
        t->ucode = (u64 *)osVirtualToPhysical(t->ucode);
    }
    if (t->ucode_data != NULL) {
        t->ucode_data = (u64 *)osVirtualToPhysical(t->ucode_data);
    }
    if (t->dram_stack != NULL) {
        t->dram_stack = (u64 *)osVirtualToPhysical(t->dram_stack);
    }
    if (t->output_buff != NULL) {
        t->output_buff = (u64 *)osVirtualToPhysical(t->output_buff);
    }
    if (t->output_buff_size != NULL) {
        t->output_buff_size = (u64 *)osVirtualToPhysical(t->output_buff_size);
    }
    if (t->data_ptr != NULL) {
        t->data_ptr = (u64 *)osVirtualToPhysical(t->data_ptr);
    }
    if (t->yield_data_ptr != NULL) {
        t->yield_data_ptr = (u64 *)osVirtualToPhysical(t->yield_data_ptr);
    }
    return &D_8009D140;
}
