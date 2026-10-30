// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

void osSpTaskLoad(OSTask *task) {
    OSTask *tp;

    tp = _VirtualToPhysicalTask(task);
    if (tp->t.flags & OS_TASK_YIELDED) {
        tp->t.ucode_data = tp->t.yield_data_ptr;
        tp->t.ucode_data_size = tp->t.yield_data_size;
        task->t.flags &= ~OS_TASK_YIELDED;
        if (tp->t.flags & OS_TASK_YIELD_DATA) {
            tp->t.ucode = (u64 *)(*(u32 *)(((u32)task->t.yield_data_ptr + 0xBFC) | K1BASE));
        }
    }
    func_8008A780(tp, 0x40);
    __osSpSetStatus(SPSTATUS_CLEAR_SIG0 | SPSTATUS_CLEAR_SIG1 | SPSTATUS_CLEAR_SIG2 | SPSTATUS_SET_INTR_BREAK);
    while (__osSpSetPc(SP_IMEM_START) == -1) {
    }
    while (__osSpRawStartDma(OS_WRITE, SP_IMEM_START - 0x40, tp, 0x40) == -1) {
    }
    while (__osSpDeviceBusy()) {
    }
    while (__osSpRawStartDma(OS_WRITE, SP_IMEM_START, tp->t.ucode_boot, tp->t.ucode_boot_size) == -1) {
    }
}
