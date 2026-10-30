// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_cont.h"
#include "os_internal.h"

#define MOTOR_PAK_ADDRESS 0x600

/* Fills the first `channel` bytes with 0 then writes one 32-byte pak write command (address 0x600) and the end marker. */
void __osMakeMotorData(s32 channel, u8 *buf) {
    u8 *ptr;
    __OSContRamReadFormat format;
    s32 i;

    ptr = buf;
    format.dummy = 0xFF;
    format.txsize = 0x23;
    format.rxsize = 0x01;
    format.cmd = CONT_CMD_WRITE_MEMPACK;
    format.addrh = MOTOR_PAK_ADDRESS >> 3;
    format.addrl = (u8)(__osContAddressCrc(MOTOR_PAK_ADDRESS) | (MOTOR_PAK_ADDRESS << 5));
    if (channel != 0) {
        for (i = 0; i < channel; i++) {
            *ptr = 0;
            ptr++;
        }
    }
    *(__OSContRamReadFormat *)ptr = format;
    ptr += sizeof(__OSContRamReadFormat);
    *ptr = CONT_CMD_END;
}
