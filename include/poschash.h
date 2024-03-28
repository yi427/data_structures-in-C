#ifndef __POSCHASH_H
#define __POSCHASH_H
#include <stdbool.h>
#include <sys/types.h>
#define TYPE void *
#define public
#define private

// @breif: design the list node
typedef struct __node_t {
  TYPE val;
  struct __node_t *next;
} node_t;

typedef struct __list_t {
  int len; 
  node_t *head;
  node_t *tail;
} list_t;

// @brief: design the Seprate Chaining Hash Table
typedef struct __hash_t {
  int current_size;
  node_t theLists [  ];
} hash_t;

// @brief: define the function pointer
typedef TYPE (*REF_T) (TYPE);
typedef size_t (*HASH_T) (TYPE);

// define the List type function
private void List_Init(list_t *, REF_T);
private void List_Push_Front(list_t *, TYPE);
private void List_Push_Back(list_t *, TYPE);
private bool List_Contain(list_t *, TYPE);
private void List_Remove(list_t *, TYPE);
private void List_Size(list_t *);
private void List_Clean(list_t *);

// define the Hash type function
public void Hash_Init(hash_t *, REF_T, HASH_T);
public void Hash_Init_Number(hash_t*, int);
public bool Hash_IsEmpty(hash_t *);
public void Hash_Insert(hash_t *, TYPE);
public void Hash_Remove(hash_t *, TYPE);
public bool Hash_Contains(hash_t *, TYPE);

#undef TYPE
#undef public
#undef private
#endif
