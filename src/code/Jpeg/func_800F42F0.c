#include "types.h"

typedef struct {
    /* 0x00 */ u8 countA;
    /* 0x01 */ u8 pad01[3];
    /* 0x04 */ u8 *tableA[3];
    /* 0x10 */ u8 countB;
    /* 0x11 */ u8 pad11[3];
    /* 0x14 */ u8 *tableB[4];
    /* 0x24 */ u8 *scanEnd;
    /* 0x28 */ u8 mode;
} JpegMarkerInfo;

s32 Jpeg_GetUnalignedU16(u8 *arg0);

void Jpeg_ParseMarkers(u8 *data, JpegMarkerInfo *info) {
    s32 done = 0;
    s32 marker;

    info->countA = 0;
    info->countB = 0;

    for (;;) {
        if (done) {
            break;
        }
        if (*data++ == 0xFF) {
            marker = *data++;
            switch (marker) {
                case 0:
                    break;
                case 0xE0:
                    data += Jpeg_GetUnalignedU16(data);
                    break;
                case 0xE1:
                    data += Jpeg_GetUnalignedU16(data);
                    break;
                case 0xE2:
                    data += Jpeg_GetUnalignedU16(data);
                    break;
                case 0xDB:
                    info->tableA[info->countA] = data + 2;
                    info->countA++;
                    data += Jpeg_GetUnalignedU16(data);
                    break;
                case 0xC4:
                    info->tableB[info->countB] = data + 2;
                    info->countB++;
                    data += Jpeg_GetUnalignedU16(data);
                    break;
                case 0xDD:
                    data += Jpeg_GetUnalignedU16(data);
                    break;
                case 0xC0:
                    if (data[9] == 0x21) {
                        info->mode = 0;
                    } else if (data[9] == 0x22) {
                        info->mode = 2;
                    }
                    data += Jpeg_GetUnalignedU16(data);
                    break;
                case 0xDA:
                    data += Jpeg_GetUnalignedU16(data);
                    info->scanEnd = data;
                    break;
                case 0xD9:
                    done = 1;
                    break;
                case 0xD8:
                    break;
                default:
                    data += Jpeg_GetUnalignedU16(data);
                    break;
            }
        }
    }
}
