// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_jpeg.h"

s32 Jpeg_Decode(void* data, void* zbuffer, void* work, u32 workSize) {
    s32 y;
    s32 x;
    s32 j;
    s32 i;
    JpegContext jpegCtx;
    JpegHuffmanTable hTables[4];
    JpegDecoder decoder;
    JpegDecoderState state;
    JpegWork* workBuff = work;

    if (workSize < sizeof(JpegWork)) {
        return -1;
    }

    osCreateMesgQueue(&jpegCtx.mq, &jpegCtx.msg, 1);
    Sched_FlushTaskQueue();

    jpegCtx.workBuf = workBuff;

    Jpeg_ParseMarkers(data, &jpegCtx);

    switch (jpegCtx.dqtCount) {
        case 1:
            JpegUtils_ProcessQuantizationTable(jpegCtx.dqtPtr[0], &workBuff->qTableY, 3);
            break;

        case 2:
            JpegUtils_ProcessQuantizationTable(jpegCtx.dqtPtr[0], &workBuff->qTableY, 1);
            JpegUtils_ProcessQuantizationTable(jpegCtx.dqtPtr[1], &workBuff->qTableU, 1);
            JpegUtils_ProcessQuantizationTable(jpegCtx.dqtPtr[1], &workBuff->qTableV, 1);
            break;

        case 3:
            JpegUtils_ProcessQuantizationTable(jpegCtx.dqtPtr[0], &workBuff->qTableY, 1);
            JpegUtils_ProcessQuantizationTable(jpegCtx.dqtPtr[1], &workBuff->qTableU, 1);
            JpegUtils_ProcessQuantizationTable(jpegCtx.dqtPtr[2], &workBuff->qTableV, 1);
            break;

        default:
            return -1;
    }

    switch (jpegCtx.dhtCount) {
        case 1:
            if (JpegUtils_ProcessHuffmanTable(jpegCtx.dhtPtr[0], &hTables[0], workBuff->codesLengths, workBuff->codes,
                                              4)) {
                return -1;
            }
            break;

        case 4:
            
            if (JpegUtils_ProcessHuffmanTable(jpegCtx.dhtPtr[0], &hTables[0], workBuff->codesLengths, workBuff->codes,
                                              1)) {
            } else if (JpegUtils_ProcessHuffmanTable(jpegCtx.dhtPtr[1], &hTables[1], workBuff->codesLengths,
                                                     workBuff->codes, 1)) {
            } else if (JpegUtils_ProcessHuffmanTable(jpegCtx.dhtPtr[2], &hTables[2], workBuff->codesLengths,
                                                     workBuff->codes, 1)) {
            } else if (!JpegUtils_ProcessHuffmanTable(jpegCtx.dhtPtr[3], &hTables[3], workBuff->codesLengths,
                                                      workBuff->codes, 1)) {
                break;
            }
            return -1;

        default:
            return -1;
    }

    decoder.imageData = jpegCtx.imageData;
    decoder.mode = jpegCtx.mode;
    decoder.unk_05 = 2;

    decoder.hTablePtrs[0] = &hTables[0];
    decoder.hTablePtrs[1] = &hTables[1];
    decoder.hTablePtrs[2] = &hTables[2];
    decoder.hTablePtrs[3] = &hTables[3];
    decoder.unk_18 = 0;

    x = y = 0;
    for (i = 0; i < 300; i += 4) {
        if (!JpegDecoder_Decode(&decoder, (u16*)workBuff->data, 4, (i != 0), &state)) {
            Jpeg_ScheduleDecoderTask(&jpegCtx);

            for (j = 0; j < 4; j++) {
                Jpeg_CopyToZbuffer(workBuff->data[j], zbuffer, x, y);
                x++;

                if (x >= 20) {
                    x = 0;
                    y++;
                }
            }
        }
    }

    return 0;
}
