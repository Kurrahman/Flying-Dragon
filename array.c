#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void ArMakeEmpty(ArOrder * T, int n);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas ArIdxMax-ArIdxMin+1, Neff = 0, dan Last = n*/

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ArNbElmt(ArOrder T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
ArIdxType ArGetLastIdx(ArOrder T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir yang memiliki nilai terdefinisi */

/* ********** Test Indeks yang valid ********** */
boolean ArIsIdxEff(ArOrder T, ArIdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara 1..Last(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean ArIsEmpty(ArOrder T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Range yang dicek adalah [1..Last(T)] */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void ArTulisIsi(ArOrder T);
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
ArIdxType ArSearch(ArOrder T, ArType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */

int ArBanOrderX(ArOrder T, ArType X);
/* Mengembalikan berapa banyak order dengan nilai X */
/* Bernilai nol untuk array kosong atau tidak terdapat order dengan nilai X */

/* ********** MENAMBAH ELEMEN ********** */
void ArAddEli  (ArOrder * T, ArType X, ArIdxType i);
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu  elemen yang sudah ada */
/* I.S. Tabel boleh kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/*      i adalah indeks dengan elemen tidak terdefinisi */
/* F.S. X adalah elemen ke-i T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void ArDelEli  (ArOrder * T, ArIdxType i);
/* Menghapus elemen ke-i tabel tanpa mengganggu elemen lain */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/*      Elemen pada indeks i menjadi tidak terdefinisi */