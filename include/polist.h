#ifndef POLIST_H
#define POLIST_H
#include "posymbol.h"
#define private static

typedef struct __node_t {
    TYPE val;
    struct __node_t *next;
    struct __node_t *prev;
} node_t;

typedef struct __list_t {
    node_t *head;
    node_t *tail;
} list_t;

void List_Init(list_t *);
void List_Push_Back(list_t *, TYPE);
void List_Push_Front(list_t *, TYPE);
void List_Clean(list_t *);
void List_Print(const list_t *);

#endif //POLIST_H
