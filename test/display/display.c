#include "podisplay.h"
#include "polist.h"
#include <stdlib.h>

int *ref(int * i) {
	int *res = (int*)malloc(sizeof(int));
	*res = *i;
	return res;
}

int
main() {
	list_t *t = List_Construction();
	List_Init(t, (void*) ref);
	for (int i = 0; i < 10; ++i) {
		List_Push_Front(t, &i);
	}
	Display_List(t, "test.dot");
	int v = 10;
	List_Insert(t, 5, &v);
	Display_List(t, "insert.dot");
	List_Erase(t, 3);
	Display_List(t, "delete.dot");
	List_Clean(t);
}
