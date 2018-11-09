#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void ArCreateEmpty(ArOrder * T, int n){
    ArIdxType i;
    for (i = 1; i <= n; i++){
        ArElmt(*T,i) = ArElUndef;
    }
    ArLast(*T) = n;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas ArIdxMax-ArIdxMin+1, Neff = 0, dan Last = n*/

/* *** Daya tampung container *** */
ArIdxType ArGetLastIdx(ArOrder T){
    ArIdxType i = ArLast(T);
    while ((i > 1) && (ArElUndef)){
        i++;
    }
    return i;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir yang memiliki nilai terdefinisi */

/* ********** Test Indeks yang valid ********** */
boolean ArIsIdxEff(ArOrder T, ArIdxType i){
    return ((i >= ArIdxMin) && (i <= ArLast(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara 1..Last(T) */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void ArTulisIsi(ArOrder T){
    printf("Order \n");
    ArIdxType i;
    for (i = 1; i <= ArLast(T); i++){
        if (ArElmt(T,i) != ArElUndef){
            switch (ArElmt(T,i)){
                case (51) : {
                        printf("Banana Split, %d\n", i);
                        break;
                    }
                case (52) : {
                        printf("Sundae, %d\n", i);
                        break;
                    }
                case (53) : {
                        printf("Nasi Telur Dadar, %d\n", i);
                        break;
                    }
                case (54) : {
                        printf("Nasi Ayam Goreng, %d\n", i);
                        break;
                    }
                case (55) : {
                        printf("Burger, %d\n", i);
                        break;
                    }
                case (56) : {
                        printf("Hot Dog, %d\n", i);
                        break;
                    }
                case (61) : {
                        printf("Spaghetti Bolognese, %d\n", i);
                        break;
                    }
                case (58) : {
                        printf("Spaghetti Carbonara, %d\n", i);
                        break;
                    }
                default :{
                        break;
                    }
            }
        }
    }

}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : menulis "Order" dan indeks dan elemen tabel */
/*      ditulis berderet ke bawah dengan mengabaikan elemen yang tidak terdefinisi*/
/*      Jika T kosong : Hanya menulis "Order" */
/* Contoh: Jika isi Tabel: ["Burger", "Indomie", " ", "Ayam Geprek"]
   Maka tercetak di layar:
   Burger, 1
   Indomie, 2
   Ayam Geprek, 4
*/

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
ArIdxType ArSearch(ArOrder T, ArType X){
    ArIdxType i = 1;
    while ((i < ArLast(T)) && (ArElmt(T,i) != X)){
        i++;
    }
    if (ArElmt(T,i) != X){
        return ArIdxUndef;
    }
    else{
        return i;
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */

int ArBanOrderX(ArOrder T, ArType X){
    int n = 0;
    ArIdxType i;
    for (i = 1; i <= ArLast(T); i++){
        if (X){
            n++;
        }
    }
    return n;
}
/* Mengembalikan berapa banyak order dengan nilai X */
/* Bernilai nol untuk array kosong atau tidak terdapat order dengan nilai X */

/* ********** MENAMBAH ELEMEN ********** */
void ArAddEli  (ArOrder * T, ArType X, ArIdxType i){
    ArElmt(*T,i) = X;
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu  elemen yang sudah ada */
/* I.S. Tabel boleh kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/*      i adalah indeks dengan elemen tidak terdefinisi */
/* F.S. X adalah elemen ke-i T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void ArDelEli  (ArOrder * T, ArIdxType i){
    ArElmt(*T,i) = ArElUndef;
}
/* Menghapus elemen ke-i tabel tanpa mengganggu elemen lain */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/*      Elemen pada indeks i menjadi tidak terdefinisi */