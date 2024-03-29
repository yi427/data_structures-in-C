#include <stdlib.h>
#include "poarray.h"
int main(){
    array_t *t = (array_t*)malloc(sizeof(array_t));
    Array_Init(t, 15);
    for(int i = 0; i < 10; ++i){
        Array_Add(t, i);    
    }
    Array_Print(t);
    return 0;
}
