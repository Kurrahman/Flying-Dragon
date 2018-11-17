#include <stdio.h>
#include "tree.h"

int main(){
    BinTree p11,p21,p22,p31,p32,p33,p34,p41,p42,p43,p44,p45,p46,p47,p48,p51,p52,p53,p54,p55,p56,p57,p58,p61;
    MakeTree(61,Nil,Nil,&p61);
    MakeTree(51,Nil,Nil,&p51);
    MakeTree(52,Nil,Nil,&p52);
    MakeTree(53,Nil,Nil,&p53);
    MakeTree(54,Nil,Nil,&p54);
    MakeTree(55,Nil,Nil,&p55);
    MakeTree(56,Nil,Nil,&p56);
    MakeTree(57,p61,Nil,&p57);
    MakeTree(58,Nil,Nil,&p58);
    MakeTree(41,p51,Nil,&p41);
    MakeTree(42,p52,Nil,&p42);
    MakeTree(43,p53,Nil,&p43);
    MakeTree(44,p54,Nil,&p44);
    MakeTree(45,p55,Nil,&p45);
    MakeTree(46,p56,Nil,&p46);
    MakeTree(47,p57,Nil,&p47);
    MakeTree(48,p58,Nil,&p48);
    MakeTree(31,p41,p42,&p31);
    MakeTree(32,p43,p44,&p32);
    MakeTree(33,p45,p46,&p33);
    MakeTree(34,p47,p48,&p34);
    MakeTree(21,p31,p32,&p21);
    MakeTree(22,p33,p34,&p22);
    MakeTree(11,p21,p22,&p11);
    printf("%d\n", SearchTree(p11,61));
    PrintTree(p11,2);
    return 0;
}