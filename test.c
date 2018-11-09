#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char comm[10] = "1234567890";
    ArOrder Ord;
    ArCreateEmpty(&Ord,6);
    ArAddEli(&Ord, 51, 4);
    ArAddEli(&Ord, 61, 2);
    ArTulisIsi(Ord);
    printf("%d\n%c\n", sizeof(comm), comm[sizeof(comm)-1]);
    return 0;
}