#include <stdlib.h>

#include "include/polist.h"

int main() {
    list_t *t = (list_t*)malloc(sizeof(list_t));
    List_Init(t);
		for (int i = 0; i < 10; ++i) {
			int *tmp = (int*)malloc(sizeof(int));
			*tmp = i;
			List_Push_Back(t, (void *)tmp);
		}
		for (int i = 0; i < 10; ++i) {
			int *tmp = (int*)malloc(sizeof(int));
			*tmp = i;
			List_Push_Front(t, (void*)tmp);
		}
    List_Print(t);
    List_Clean(t);
    return 0;
}
