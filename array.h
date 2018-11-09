/* MODUL ARRAY PESANAN */
/* Berisi definisi dan semua primitif pemrosesan tabel pesanan (string) */
/* Penempatan elemen sesuai dengan nomer meja (contoh : Order[3] = "Indomie"; berarti meja 3 memesan Indomie) */
/* Untuk meja yang belum/tidak memesan akan diberikan nilai blank " "*/
/* Semua fungsi dan prosedur yang tertulis di sini diawali dengan Ar<nama sub-program> */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"

/*  Kamus Umum */
#define ArIdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define ArIdxMin 1
/* Indeks minimum array */
#define ArIdxUndef -999 
/* Indeks tak terdefinisi*/
#define ArElUndef " "
/* Element yang tidak terdefinisi */

/* Definisi elemen dan koleksi objek */
typedef char Arstring[255]; /* type string */
typedef int ArIdxType;  /* type indeks */
typedef Arstring ArType;   /* type elemen tabel */
typedef struct { 
	ArType ArTI[ArIdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int ArNeff; /* >=0, banyaknya elemen efektif */
  ArIdxType ArLast; /* Indeks terakhir yang relevan dengan restoran (banyaknya meja pada restoran) */
} ArOrder;
/* Indeks yang digunakan [ArIdxMin..ArIdxMax] */
/* Jika T adalah ArOrder, cara deklarasi dan akses: */
/* Deklarasi : T : ArOrder */
/* Maka cara akses: 
   T.ArNeff  untuk mengetahui banyaknya elemen 
   T.ArTI    untuk mengakses seluruh nilai elemen tabel 
   T.ArTI[i] untuk mengakses elemen ke-i 
   T.ArLast  untuk mengakses indeks terakhir dari tabel*/
   
/* Definisi : 
  Tabel kosong: T.ArNeff = 0
  Definisi elemen pertama : T.ArTI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.ArTI[i] dengan i=T.ArLast */
  
/* ********** SELEKTOR ********** */
#define ArNeff(T)   (T).ArNeff
#define ArTI(T)     (T).ArTI
#define ArElmt(T,i) (T).ArTI[(i)]
#define ArLast(T)   (T).ArLast

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
void ArCopyStr(Artype *Sin, Artype Sout);
/* Menyalin Sout ke Sin */
/* I.S.  */
/* ********** MENGHAPUS ELEMEN ********** */
void ArDelEli  (ArOrder * T, ArIdxType i);
/* Menghapus elemen ke-i tabel tanpa mengganggu elemen lain */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/*      Elemen pada indeks i menjadi tidak terdefinisi */
#endif