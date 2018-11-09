#include "array.h"

int main(){
    ArOrder Ord;
    ArCreateEmpty(&Ord,6);
    ArAddEli(&Ord, 51, 4);
    ArAddEli(&Ord, 61, 2);
    ArTulisIsi(Ord);
    
    return 0;
}