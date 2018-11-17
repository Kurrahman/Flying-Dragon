#include <stdio.h>
#include "stackt.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S)==Nil);
}
boolean IsFull (Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S)==MaxEl);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    Top(*S) ++;
    InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S)--;
}

void CH (Stack *S){
/* Membuang seluruh bahan makanan yang terdapat di stack tangan pemain
    I.S : Stack tangan terdefinisi
    F.S : Stack tangan menjadi kosong */
    //Kamus Lokal
    infotype Xout;
    //Algoritma
    while (!IsEmpty(*S)) {
        Pop(S,&Xout);
    }
}

void CT (Stack *S){
/* Membuang seluruh makanan yang berada di dalam stack tray
    I.S : Stack tray terdefinisi
    F.S : Stack tray menjadi kosong */
    //Kamus Lokal
    infotype Xout;
    //Algoritma
    while (!IsEmpty(*S)){
        Pop(S,&Xout);
    }
}

void GIVE (Stack *S, MATRIKS *M, int nomor, boolean isgive){
/* Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan
    I.S : Stack Tray Terdefinisi dan posisi player telah berada di sebelah pengunjung
    F.S : Mengeluarkan Top of Stack dari Stack Array dan memberikannya ke pengunjung
    */ 
   //Kamus Lokal
   infotype Xout;
   //Algoitma
   if (!IsEmpty(*S)){
        if (isgive){
            Pop(S,&Xout);
            UpdateTable(M, nomor,"give", 2);
        } else {
            printf ("Tidak bisa give");
        }
   }
   
}