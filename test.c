#include <stdio.h>
#include "tree.h"

int main(){
    BinTree L,R,A;
    MakeTree(51,Nil,Nil,&L);
    MakeTree(52,Nil,Nil,&R);
    MakeTree(41,L,Nil,&L);
    MakeTree(42,R,Nil,&R);
    MakeTree(31,L,R,&A);
    PrintTree(A,2);
    printf("%d\n",SearchTree(A, 91));
    printf("%d\n",NbElmt(A));
    printf("%d\n",NbDaun(A));
    return 0;
}