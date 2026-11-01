#include "types.h"

void func_80088070(void *arg0, s32 *arg1, s32 arg2);
void Sched_HandleAudioCancel(void *arg0);
void Sched_HandleGfxCancel(void *arg0);
void Sched_HandleNotify(void *arg0);
void Sched_HandleRSPDone(void *arg0);
void Sched_HandleRDPDone(void *arg0);
void Sched_HandleRetrace(void *arg0);
void func_80177538(void *arg0);
void Sched_HandleNMI(void *arg0);

void func_80178330(void *arg0) {
    s16 *msg = 0;
    s32 pad[2]; // padding: the ROM frame is 8 bytes larger

    while (1) {
        func_80088070(arg0, (s32 *)&msg, 1);
        switch ((s32)msg) {
            case 0x29F:
                Sched_HandleAudioCancel(arg0);
                break;
            case 0x2A0:
                Sched_HandleGfxCancel(arg0);
                break;
            case 0x29E:
                Sched_HandleNotify(arg0);
                break;
            case 0x29B:
                Sched_HandleRSPDone(arg0);
                break;
            case 0x29C:
                Sched_HandleRDPDone(arg0);
                break;
            default:
                switch (*msg) {
                    case 1:
                        Sched_HandleRetrace(arg0);
                        break;
                    case 4:
                        func_80177538(arg0);
                        break;
                    case 3:
                        Sched_HandleNMI(arg0);
                        break;
                }
                break;
        }
    }
}
