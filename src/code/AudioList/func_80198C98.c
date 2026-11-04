#include "types.h"

typedef struct AudioListItem {
    struct AudioListItem *prev;
    struct AudioListItem *next;
    s32 unk8;
    void *pool;
} AudioListItem;

void AudioList_PushBack(AudioListItem *list, AudioListItem *item) {
    if (item->prev == NULL) {
        list->prev->next = item;
        item->prev = list->prev;
        item->next = list;
        list->prev = item;
        list->unk8++;
        item->pool = list->pool;
    }
}
