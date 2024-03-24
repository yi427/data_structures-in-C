#ifndef POLIST_H
#define POLIST_H
#include "posymbol.h"
#include <stdio.h>
#define public 
#define private

typedef int (*compare_t)(void *, void *);
typedef void (*print_t)(void *);
typedef void *(*ref_t)(void*);
typedef struct __node_t {
    TYPE val;
    struct __node_t *next;
    struct __node_t *prev;
} node_t;

typedef struct __list_t {
    node_t *head;
    node_t *tail;
} list_t;

public void List_Init(list_t *, ref_t);
public void List_Push_Back(list_t *, TYPE);
public void List_Push_Front(list_t *, TYPE);
public void List_Pop_Back(list_t *);
public void List_Pop_Front(list_t *);
public void* List_Front(list_t *);
public void* List_Back(list_t *);
public void List_Insert(list_t *, int, TYPE);
public void List_Erase(list_t*, int);
public node_t* List_Search(const list_t*, compare_t, TYPE val);
public size_t  List_Size(const list_t*);

public void List_Clean(list_t *);
public void Node_Clean(node_t *);
public void List_Print(const list_t *, print_t);

private void List_Check(const list_t*);

#undef public
#undef private
#endif
