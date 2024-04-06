#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define __GET_STREUCT__
#include "polist.h"

#define CHECK 0
#define public extern
#define private static
#define P(x) *(x)
#define TYPE void *
#define NEW_NODE(VAL, NEXT, PREV) (node_t) {  \
  .val = VAL,                                 \
  .next = NEXT,                               \
  .prev = PREV                                \
}

private void Node_Clean(node_t *);
private void List_Check(const list_t *);

typedef struct __node_t {
    TYPE val;
    struct __node_t *next;
    struct __node_t *prev;
} node_t;

typedef struct __list_t {
  node_t *head;
  node_t *tail;
} list_t;

static ref_t GET;

public list_t *List_Construction() {
  list_t *res = (list_t*) malloc(sizeof(list_t));
  assert(res);
  return res;
}

public void List_Init(list_t *t, ref_t _r) {
  assert(t != NULL);
  assert(_r != NULL);
  t->head = t->tail = NULL;
  GET = _r;
}

public void List_Push_Front(list_t *t, TYPE val) {
  assert(t);
  node_t *node = (node_t*)malloc(sizeof(node_t));
  assert(node);		  // Check the malloc 
  P(node) = NEW_NODE(GET(val), NULL, NULL);
  node_t *head = t->head;
  if (!head) {// The list don't have arbitrary node
    t->head = t->tail = node;
    return;
  }
  assert(head);
  node->next = head; // Update the next pointer
  head->prev = node; // Update the prev pointer
  t->head = node;// Update the head node
  if (CHECK) List_Check(t);
}

public void List_Push_Back(list_t *t, TYPE val) {
  assert(t);
  node_t *node = (node_t*)malloc(sizeof(node_t));
  assert(node); // Check the malloc 
  P(node) = NEW_NODE(GET(val), NULL, NULL);
  node_t *tail = t->tail;
  if (!tail) {// The list don't have arbitrary node
    t->head = t->tail = node;
    return;
  }
  assert(tail);
  tail->next = node; // Update the next pointer
  node->prev = tail; // Update the prev pointer
  t->tail = node;    // Update the tail node
  if (CHECK) List_Check(t);
}

public node_t* List_Search(const list_t *t, compare_t com, TYPE val) {
  node_t* curr = t->head;
  while (curr) {
    assert(curr->val);
    if (com(val, curr->val) == 0) {
      break;
    }
    curr = curr->next;
  }
  return curr;
}
// @brief: insert the index front, else if the index == size, will equie to the Push_Back
public void List_Insert(list_t *t, int index, TYPE val) {
  assert(t);
  if (index == 0) {
    List_Push_Front(t, val);
    return;
  } 
  node_t *curr = t->head;
  while (curr && index) {
    curr = curr->next;
    index--;
  }
  if (!curr) {
    if (!index) List_Push_Back(t, val);
    return;
  }
  node_t *node = (node_t*)malloc(sizeof(node_t));
  P(node) = NEW_NODE(GET(val), curr, curr->prev);
  assert(curr->prev);
  curr->prev->next = node;
  curr->prev = node;
}

public void List_Erase(list_t *t, int index) {
  assert(t);
  if (index == 0) {
    List_Pop_Front(t);
    return;
  } 
  node_t *curr = t->head;
  while (curr && index) {
    curr = curr->next;
    index--;
  }
  if (!curr) return;
  else if (curr == t->tail) {
    List_Pop_Back(t);
    return;
  }
  assert(curr->prev);
  curr->prev->next = curr->next;
  assert(curr->next);
  curr->next->prev = curr->prev;
  Node_Clean(curr);
}

public void Node_Clean(node_t *n) {
  assert(n);
  free(n->val);
  free(n);
}

public void List_Clean(list_t *t) {
  if (CHECK) List_Check(t);
  while (t->head) {// for-each the list
    node_t *curr = t->head;
    assert(curr);
    assert(curr->val);
    t->head = curr->next;
    free(curr->val); // release the currently val
    free(curr);// release the currently node
  }
  free(t);// release the list
}

public size_t List_Size(const list_t *t) {
  assert(t);
  size_t res = 0;
  node_t *curr = t->head;
  while (curr) {
    res++;
    curr = curr->next;
  }
  return res;
}

public void List_Pop_Front(list_t *t) {
  assert(t);
  if (!t->head && !t->tail) return;
  node_t *head = t->head;
  if (t->head == t->tail) {
    t->head = t->tail = NULL;
  } else {
    t->head = t->head->next;
    t->head->prev = NULL; // Notes: must set the prev is the NULL
  }
  Node_Clean(head);
}

public void* List_Front(list_t* t) {
  assert(t && t->head);
  return t->head->val;
}

public void List_Pop_Back(list_t *t) {
  assert(t);
  if (!t->head && !t->tail) return;
  node_t *tail = t->tail;
  if (t->head == t->tail) {
    t->head = t->tail = NULL;
  } else {
    t->tail = t->tail->prev;
    t->tail->next = NULL; // Notes: must be set the next is the NULL
  }
  Node_Clean(tail);
}

public void* List_Back(list_t *t) {
  assert(t && t->tail);
  return t->tail->val;
}

public void List_Print(const list_t *t, print_t pri) {
  if (CHECK) List_Check(t);
  const node_t *curr = t->head;
  if (!t || !t->head) goto End;
  assert(t->head);
  while (curr != NULL) {
    pri(curr->val);
    curr = curr->next;
  }
End:
  printf("NULL\n");
}

private void List_Check(const list_t *t) {
  if (!t || !t->head) return;
  assert(t->head);
  const node_t *curr = t->head;
  const node_t *prev = curr->prev;
  while (curr) {
    assert(curr->prev == prev);
    prev = curr;
    curr = curr->next;
  }
}

#undef public
#undef private
#undef P
