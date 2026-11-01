#include "types.h"

typedef struct {
    s32 pos;
    u8 pad4[0x1E];
    u16 bank;
    u8 pad24[0xC];
} SfxRequest;

extern void AudioSfx_StopByPosAndBankImpl(u8 bank);
extern void AudioSfx_RemoveMatchingRequests(s32 type, SfxRequest *request);

void AudioSfx_StopByPosAndBank(u8 bank, s32 pos) {
    SfxRequest request;

    AudioSfx_StopByPosAndBankImpl(bank);
    request.bank = bank << 12;
    request.pos = pos;
    AudioSfx_RemoveMatchingRequests(1, &request);
}
