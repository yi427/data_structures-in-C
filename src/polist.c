#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../include/polist.h"

#define CHECK 1
#define public extern
#define private extern
#define NEW_NODE(VAL, NEXT, PREV) (node_t) {  \
  .val = VAL,                                 \
  .next = NEXT,                               \
  .prev = PREV                                \
}

public void List_Init(list_t *t) {
  assert(t != NULL);
  t->head = t->tail = NULL;
}

public void List_Push_Front(list_t *t, TYPE val) {
  assert(t);
  node_t *node = (node_t*)malloc(sizeof(node_t));
  assert(node);		  // Check the malloc 
  P(node) = NEW_NODE(val, NULL, NULL);
  node_t *head = t->head;
  if (!head) {			// The list don't have arbitrary node
  	t->head = t->tail = node;
  	return;
  }
  assert(head);
  node->next = head; // Update the next pointer
  head->prev = node; // Update the prev pointer
  t->head = node;		 // Update the head node
  if (CHECK) List_Check(t);
}

public void List_Push_Back(list_t *t, TYPE val) {
  assert(t);
  node_t *node = (node_t*)malloc(sizeof(node_t));
  assert(node);		  // Check the malloc 
  P(node) = NEW_NODE(val, NULL, NULL);
  node_t *tail = t->tail;
  if (!tail) {			// The list don't have arbitrary node
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

public void List_Clean(list_t *t) {
  if (CHECK) List_Check(t);
  while (t->head) {				// for-each the list
    node_t *curr = t->head;
    assert(curr);
    assert(curr->val);
    t->head = curr->next;
    free(curr->val); // release the currently val
    free(curr);			// release the currently node
  }
  free(t);						// release the list
}


public void List_Print(const list_t *t, print_t pri) {
  if (CHECK) List_Check(t);
  const node_t *curr = t->head;
  while (curr != NULL) {
    pri(curr->val);
    curr = curr->next;
  }
  printf("NULL\n");
}

private void List_Check(const list_t *t) {
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
