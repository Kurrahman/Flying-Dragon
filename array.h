/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primiArtif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel staArtik */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"

/*  Kamus Umum */
#define IdxArMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxArMin 1
/* Indeks minimum array */
#define IdxArUndef -999 
/* Indeks tak terdefinisi*/
#define ElArUndef " "
/* Element yang tidak terdefinisi */

/* Definisi elemen dan koleksi objek */
typedef char[255] string; /* type string */
typedef int IdxArType;  /* type indeks */
typedef string ArType;   /* type elemen tabel */
typedef struct { 
	ArType ArTI[IdxArMax+1]; /* memori tempat penyimpan elemen (container) */
	int ArNeff; /* >=0, banyaknya elemen efektif */
  IdxArType ArLast; /* Indeks terakhir yang relevan dengan restoran (banyaknya meja pada restoran) */
} OrderAr;
/* Indeks yang digunakan [IdxArMin..IdxArMax] */
/* Jika T adalah OrderAr, cara deklarasi dan akses: */
/* Deklarasi : T : OrderAr */
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
void ArMakeEmpty(OrderAr * T, int n);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxArMax-IdxArMin+1, Neff = 0, dan Last = n*/

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int ArNbElmt(OrderAr T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
IdxType ArGetLastIdx(OrderAr T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir yang memiliki nilai terdefinisi */

/* ********** Test Indeks yang valid ********** */
boolean ArIsIdxEff(OrderAr T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara 1..Last(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean ArIsEmpty(OrderAr T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Range yang dicek adalah [1..Last(T)] */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void ArTulisIsi(OrderAr T);
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
IdxType ArSearch(OrderAr T, ArType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */

int ArBanOrderX(OrderAr T, ArType X);
/* Mengembalikan berapa banyak order dengan nilai X */
/* Bernilai nol untuk array kosong atau tidak terdapat order dengan nilai X */

/* ********** MENAMBAH ELEMEN ********** */
void ArAddEli  (OrderAr * T, ArType X, IdxType i);
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu  elemen yang sudah ada */
/* I.S. Tabel boleh kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/*      i adalah indeks dengan elemen tidak terdefinisi */
/* F.S. X adalah elemen ke-i T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void ArDelEli  (OrderAr * T, IdxType i);
/* Menghapus elemen ke-i tabel tanpa mengganggu elemen lain */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/*      Elemen pada indeks i menjadi tidak terdefinisi */
#endif