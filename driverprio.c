#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    //Kamus Lokal
    Queue Q1;
    infotype A1,A2,A3,A4,Aout;
    int MaxElmt;
    address indeks;
    //Algoritma
    MaxElmt = 4;
    CreateEmpty (&Q1,MaxElmt); //Ngecek CreateEmpty

    if (IsEmpty(Q1)){ // Ngecek IsEmpty
        printf ("Queue masih kosong\n");
    }

    // Nyoba Add
    A1.info = 2;
    A1.prio = 1;
    A2.info = 2;
    A2.prio = 2;
    A3.info = 3;
    A3.prio = 3;
    A4.info = 4;
    A4.prio = 3;
    Add(&Q1,A1);
    Add(&Q1,A2);
    Add(&Q1,A3);
    Add(&Q1,A4);

    // Ngecek print
    indeks = Head(Q1);
    while (indeks <= Tail(Q1)){
        printf("%d %d \n",Prio(Elmt(Q1,indeks)), Info(Elmt(Q1,indeks)));
        indeks = indeks + 1;    
    }
    printf("\n");

    //ngecek decre
    DecreInfo(&Q1);
    indeks = Head(Q1);
    while (indeks <= Tail(Q1)){
        printf("%d %d \n",Prio(Elmt(Q1,indeks)), Info(Elmt(Q1,indeks)));
        indeks = indeks + 1;    
    }
    printf("\n");

    //ngecek DEl
    Del(&Q1,&Aout);
    Del(&Q1,&Aout);
    indeks = Head(Q1);
    while (indeks <= Tail(Q1)){
        printf("%d %d \n",Prio(Elmt(Q1,indeks)), Info(Elmt(Q1,indeks)));
        indeks = indeks + 1;    
    }
    
return 0;
}