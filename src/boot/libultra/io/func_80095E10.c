// FLAGS: -O2 -g0 -mips2
#include "os_voice.h"

s32 osVoiceCheckWord(u8 *word) {
    s32 count = 0;
    s32 err = 0;
    u16 ch;
    u16 prev = 0;
    u8 *p = word;

    while (*p != 0) {
        ch = (p[0] << 8) + p[1];
        if (((ch != 0x815B) && (ch < 0x829F)) || ((ch >= 0x82F2) && (ch < 0x8340)) || (ch == 0x837F) || (ch >= 0x8397)) {
            err = 0xE;
        } else if ((count == 0) && ((ch == 0x815B) || (ch == 0x82F1) || (ch == 0x82C1) || (ch == 0x82EC) || (ch == 0x8393) || (ch == 0x8362) || (ch == 0x838E) || (ch == 0x8395) || (ch == 0x8396))) {
            err = 0xE;
        } else if (((ch == 0x829F) || (ch == 0x8340)) && (prev != 0x82D3) && (prev != 0x8374) && (prev != 0x8394)) {
            err = 0xE;
        } else if (((ch == 0x82A1) || (ch == 0x8342)) && (prev != 0x82A4) && (prev != 0x82C4) && (prev != 0x82C5) && (prev != 0x82D3) && (prev != 0x8345) && (prev != 0x8365) && (prev != 0x8366) && (prev != 0x8374) && (prev != 0x8394)) {
            err = 0xE;
        } else if (((ch == 0x82A3) || (ch == 0x8344)) && (prev != 0x82C6) && (prev != 0x82C7) && (prev != 0x82D3) && (prev != 0x8367) && (prev != 0x8368) && (prev != 0x8374) && (prev != 0x8394)) {
            err = 0xE;
        } else if (((ch == 0x82A5) || (ch == 0x8346)) && (prev != 0x82A4) && (prev != 0x82B5) && (prev != 0x82B6) && (prev != 0x82BF) && (prev != 0x82C0) && (prev != 0x82C2) && (prev != 0x82D3) && (prev != 0x8345) && (prev != 0x8356) && (prev != 0x8357) && (prev != 0x8360) && (prev != 0x8361) && (prev != 0x8363) && (prev != 0x8374) && (prev != 0x8394)) {
            err = 0xE;
        } else if (((ch == 0x82A7) || (ch == 0x8348)) && (prev != 0x82A4) && (prev != 0x82D3) && (prev != 0x8345) && (prev != 0x8374) && (prev != 0x8394)) {
            err = 0xE;
        } else if (((ch == 0x82E1) || (ch == 0x82E3) || (ch == 0x82E5) || (ch == 0x8383) || (ch == 0x8385) || (ch == 0x8387)) && (prev != 0x82AB) && (prev != 0x82B5) && (prev != 0x82BF) && (prev != 0x82C9) && (prev != 0x82D0) && (prev != 0x82DD) && (prev != 0x82E8) && (prev != 0x82AC) && (prev != 0x82B6) && (prev != 0x82C0) && (prev != 0x82D1) && (prev != 0x82D2) && (prev != 0x834C) && (prev != 0x8356) && (prev != 0x8360) && (prev != 0x836A) && (prev != 0x8371) && (prev != 0x837E) && (prev != 0x838A) && (prev != 0x834D) && (prev != 0x8357) && (prev != 0x8361) && (prev != 0x8372) && (prev != 0x8373) && (prev != 0x8394)) {
            err = 0xE;
        } else if ((ch == 0x815B) && ((prev == 0x82F1) || (prev == 0x82C1) || (prev == 0x8393) || (prev == 0x8362))) {
            err = 0xE;
        } else if (((ch == 0x82F1) || (ch == 0x8393)) && ((prev == 0x82F1) || (prev == 0x8393))) {
            err = 0xE;
        } else if (((prev == 0x82C1) || (prev == 0x8362)) && ((ch == 0x815B) || (ch == 0x82A0) || (ch == 0x82A2) || (ch == 0x82A4) || (ch == 0x82A6) || (ch == 0x82A8) || (ch == 0x82C8) || (ch == 0x82C9) || (ch == 0x82CA) || (ch == 0x82CB) || (ch == 0x82CC) || (ch == 0x82DC) || (ch == 0x82DD) || (ch == 0x82DE) || (ch == 0x82DF) || (ch == 0x82E0) || (ch == 0x82E2) || (ch == 0x82E4) || (ch == 0x82E6) || (ch == 0x82E7) || (ch == 0x82E8) || (ch == 0x82E9) || (ch == 0x82EA) || (ch == 0x82EB) || (ch == 0x82ED) || (ch == 0x82EE) || (ch == 0x82EF) || (ch == 0x82F0) || (ch == 0x82F1) || (ch == 0x829F) || (ch == 0x82A1) || (ch == 0x82A3) || (ch == 0x82A5) || (ch == 0x82A7) || (ch == 0x82E1) || (ch == 0x82E3) || (ch == 0x82E5) || (ch == 0x82C1) || (ch == 0x82EC) || (ch == 0x8341) || (ch == 0x8343) || (ch == 0x8345) || (ch == 0x8347) || (ch == 0x8349) || (ch == 0x8369) || (ch == 0x836A) || (ch == 0x836B) || (ch == 0x836C) || (ch == 0x836D) || (ch == 0x837D) || (ch == 0x837E) || (ch == 0x8380) || (ch == 0x8381) || (ch == 0x8382) || (ch == 0x8384) || (ch == 0x8386) || (ch == 0x8388) || (ch == 0x8389) || (ch == 0x838A) || (ch == 0x838B) || (ch == 0x838C) || (ch == 0x838D) || (ch == 0x838F) || (ch == 0x8390) || (ch == 0x8391) || (ch == 0x8392) || (ch == 0x8393) || (ch == 0x8340) || (ch == 0x8342) || (ch == 0x8344) || (ch == 0x8346) || (ch == 0x8348) || (ch == 0x8383) || (ch == 0x8385) || (ch == 0x8387) || (ch == 0x8362) || (ch == 0x838E))) {
            err = 0xE;
        }
        if (err != 0) {
            return err;
        }
        count += 2;
        p += 2;
        prev = ch;
    }
    if (ch == 0x82C1 || ch == 0x8362) {
        err = 0xE;
    }
    return err;
}
