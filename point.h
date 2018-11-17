#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct {
	float X; /* absis   */
	float Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P);
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
void GoRight (POINT *P);
/* Mengirim salinan P dengan absis ditambah satu */
void GoLeft (POINT *P);
/* Mengirim salinan P dengan absis dikurangi satu */
void GoUp (POINT *P);
/* Mengirim salinan P dengan ordinat ditambah satu */
void GoDown (POINT *P);
/* Mengirim salinan P dengan ordinat dikurangi satu */

#endif
