#include <stdio.h>
#include "tree.h"

int main(){
    BinTree A;
    MakeTree(11,Nil,Nil,&A);
    Left(A) = AlokNode(21);
    Right(A) = AlokNode(22);
    Left(Left(A)) = AlokNode(31);
    Right(Left(A)) = AlokNode(32);
    Left(Right(A)) = AlokNode(33);
    Right(Right(A)) = AlokNode(34);
    Left(Left(Left(A))) = AlokNode(41);
    Right(Left(Left(A))) = AlokNode(42);
    Left(Right(Left(A))) = AlokNode(43);
    Right(Right(Left(A))) = AlokNode(44);
    Left(Left(Right(A))) = AlokNode(45);
    Right(Left(Right(A))) = AlokNode(46);
    Left(Right(Right(A))) = AlokNode(47);
    Right(Right(Right(A))) = AlokNode(48);
    Left(Left(Left(Left(A)))) = AlokNode(51);
    Left(Right(Left(Left(A)))) = AlokNode(52);
    Left(Left(Right(Left(A)))) = AlokNode(53);
    Left(Right(Right(Left(A)))) = AlokNode(54);
    Left(Left(Left(Right(A)))) = AlokNode(55);
    Left(Right(Left(Right(A)))) = AlokNode(56);
    Left(Left(Right(Right(A)))) = AlokNode(57);
    Left(Right(Right(Right(A)))) = AlokNode(58);
    Left(Left(Left(Right(Right(A))))) = AlokNode(61);
    PrintTree(A,2);
    return 0;
}