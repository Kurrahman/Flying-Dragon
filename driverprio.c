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
    Sabar(A1) = 2;
    Prio(A1) = 1;
    Jumlah(A1) = 2;

    Sabar(A2) = 3;
    Prio(A2) = 2;
    Jumlah(A2) = 2;

    Sabar(A3) = 3;
    Prio(A3) = 3;
    Jumlah(A3) = 4;

    Sabar(A4) = 5;
    Prio(A4) = 1;
    Jumlah(A4) = 4;

    Add(&Q1,A1);
    Add(&Q1,A2);
    Add(&Q1,A3);
    Add(&Q1,A4);

    // Ngecek print
    indeks = Head(Q1);
    while (indeks <= Tail(Q1)){
        printf("%d %d %d \n",Prio(Elmt(Q1,indeks)), Sabar(Elmt(Q1,indeks)), Jumlah(Elmt(Q1,indeks)));
        indeks = indeks + 1;    
    }
    printf("\n");

    //ngecek decre
    DecreSabar(&Q1);
    indeks = Head(Q1);
    while (indeks <= Tail(Q1)){
        printf("%d %d %d \n",Prio(Elmt(Q1,indeks)), Sabar(Elmt(Q1,indeks)), Jumlah(Elmt(Q1,indeks)));
        indeks = indeks + 1;    
    }
    printf("\n");

    //ngecek DEl
    Del(&Q1,&Aout);
    Del(&Q1,&Aout);
    indeks = Head(Q1);
    while (indeks <= Tail(Q1)){
        printf("%d %d %d \n",Prio(Elmt(Q1,indeks)), Sabar(Elmt(Q1,indeks)), Jumlah(Elmt(Q1,indeks)));
        indeks = indeks + 1;    
    }
    printf("\n");
    
    //ngecek print
    PrintQueue(Q1);
return 0;
}