#include "poschash.h"
#include <assert.h>
#include <stdlib.h>
#define TYPE void *
#define NEW_NODE(_val, _next) (node_t) {\
  .val = _val, \
  .next = _next}

static REF_T REF;

void List_Init(list_t *l) {
  assert(l); // Check the l is to alloct
  *l = (list_t) {
    .head = NULL,
    .tail = NULL,
    .len = 0
  };
}

void List_Push_Front(list_t *l, TYPE val) {
  assert(l);
  node_t *node = (node_t *)malloc(sizeof(node_t));
  assert(node);
  *node = NEW_NODE(REF(val), NULL);
  if (!l->head) { // check the list head node is not null
    l->head = node;
  } else {
    node->next = l->head;
    l->head = node;
  }
  l->len++;
}

void List_Push_Back(list_t *l, TYPE val) {
  assert(l);
  node_t *node = (node_t *)malloc(sizeof(node_t));
  assert(node);
  *node = NEW_NODE(REF(val), NULL);
  if (!l->tail) { // Check the list tail is not null
    l->tail = node;
  } else {
    l->tail->next = node;
    l->tail = node;
  }
  l->len++;
}

#undef TYPE
