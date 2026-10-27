#include "types.h"

typedef struct {
    u8 pad0[0x40];
    void *unk40;
} AudioTask;
extern void func_80087CB0();
void AudioMgr_NotifyTaskDone(u8 *arg0) {
    void *new_var;
    AudioTask *task = *((AudioTask **) (arg0 + 0x60));
    void **new_var2;
    ;
    if (task->unk40 != 0) {
        new_var2 = &task->unk40;
        if (1) {
            func_80087CB0(*new_var2, 0, 1);
        }
    }
    goto dummy_label_181665; dummy_label_181665: ;
}
