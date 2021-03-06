#include "array.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void ArCreateEmpty(ArOrder * T, int n){
    ArIdxType i;
    for (i = 1; i <= n; i++){
        OrderMeja(*T,i) = ArElUndef;
    }
    ArLast(*T) = n;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas ArIdxMax-ArIdxMin+1, Neff = 0, dan Last = n*/

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void ArTulisIsi(ArOrder T){
    printf("Order \n");
    ArIdxType i;
    for (i = 1; i <= ArLast(T); i++){
        if (OrderMeja(T,i) != ArElUndef){
            switch (OrderMeja(T,i)){
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

/* ********** MENAMBAH ELEMEN ********** */
void ArAddEli  (ArOrder * T, ArType X, ArIdxType i){
    OrderMeja(*T,i) = X;
}
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu  elemen yang sudah ada */
/* I.S. Tabel boleh kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/*      i adalah indeks dengan elemen tidak terdefinisi */
/* F.S. X adalah elemen ke-i T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void ArDelEli  (ArOrder * T, ArIdxType i){
    OrderMeja(*T,i) = ArElUndef;
}
/* Menghapus elemen ke-i tabel tanpa mengganggu elemen lain */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/*      Elemen pada indeks i menjadi tidak terdefinisi */

void ORDER (ArOrder *T, MATRIKS *M, int nomor, boolean isorder){
/* Menerima order dari meja
  I.S : Array order telah terdefinisi dan player berada dimanapun di dalam peta
  F.S : Jika isorder bernilai true, maka akan menerima orderan makanan yang dirandom 
  */
    //Kamus Lokal
    int intmakanan;
    //Algoritma
    if (isorder){
        intmakanan = rand() % 62;
        while (intmakanan==51 || intmakanan==52 || intmakanan== 53 || intmakanan== 54 || intmakanan== 55 || intmakanan== 56 || intmakanan== 58 || intmakanan==61){
            intmakanan = rand() % 62;
        } //Dapat random makanan
        ArAddEli(T,intmakanan,nomor);
    }
}


