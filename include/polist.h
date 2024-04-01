#ifndef POLIST_H
#define POLIST_H
#include <stdio.h>
#define TYPE void *

typedef int (*compare_t)(void *, void *);
typedef void (*print_t)(void *);
typedef void *(*ref_t)(void*);
typedef struct __node_t node_t;
typedef struct __list_t list_t;

list_t *List_Construction();
void List_Init(list_t *, ref_t);
void List_Push_Back(list_t *, TYPE);
void List_Push_Front(list_t *, TYPE);
void List_Pop_Back(list_t *);
void List_Pop_Front(list_t *);
void* List_Front(list_t *);
void* List_Back(list_t *);
void List_Insert(list_t *, int, TYPE);
void List_Erase(list_t*, int);
node_t* List_Search(const list_t*, compare_t, TYPE val);
size_t  List_Size(const list_t*);

void List_Clean(list_t *);
void Node_Clean(node_t *);
void List_Print(const list_t *, print_t);

#undef public
#undef private
#undef TYPE
#endif
