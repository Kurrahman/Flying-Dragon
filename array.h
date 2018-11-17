/* MODUL ARRAY PESANAN */
/* Berisi definisi dan semua primitif pemrosesan tabel pesanan (string) */
/* Penempatan elemen sesuai dengan nomer meja (contoh : Order[3] = "Indomie"; berarti meja 3 memesan Indomie) */
/* Untuk meja yang belum/tidak memesan akan diberikan nilai blank " "*/
/* Semua fungsi dan prosedur yang tertulis di sini diawali dengan Ar<nama sub-program> */

#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "matriks.h"

/*  Kamus Umum */
#define ArIdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define ArIdxMin 1
/* Indeks minimum array */
#define ArIdxUndef -999 
/* Indeks tak terdefinisi*/
#define ArElUndef -999
/* Element yang tidak terdefinisi */

/* Definisi elemen dan koleksi objek */
typedef int ArIdxType;  /* type indeks */
typedef int ArType;   /* type elemen tabel */
typedef struct { 
	ArType ArTI[ArIdxMax+1]; /* memori tempat penyimpan elemen (container) */
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
#define ArTI(T)     (T).ArTI
#define OrderMeja(T,i) (T).ArTI[(i)]
#define ArLast(T)   (T).ArLast

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void ArCreateEmpty(ArOrder * T, int n);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas ArIdxMax-ArIdxMin+1, Neff = 0, dan Last = n*/

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

void ORDER (ArOrder *T, MATRIKS *M, int nomor, boolean isorder);
/* Menerima order dari meja
  I.S : Array order telah terdefinisi dan player berada dimanapun di dalam peta
  F.S : Jika isorder bernilai true, maka akan menerima orderan makanan yang dirandom 
  */


#endif