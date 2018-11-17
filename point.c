/* File : point.c */

#include "point.h"
#include <stdio.h>
#include "boolean.h"
#include <math.h>
#include <assert.h>


// DEFINISI PROTOTIPE PRIMITIF //
// Konstruktor membentuk POINT //
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	/* KAMUS */
	POINT P;
	/* ALGORITMA */
	Absis(P) = X;
	Ordinat(P) = Y;
	return P;
}

// KELOMPOK Interaksi dengan I/O device, BACA/TULIS //
void BacaPOINT (POINT *P) 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	/* KAMUS */
	float x, y;
	/* ALGORITMA */
	scanf("%f %f", &x, &y);
	*P = MakePOINT(x,y);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layer dengan format "(X,Y)" */
{
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

// KELOMPOK OPERASI LAIN TERHADAP TYPE //
<<<<<<< HEAD
void GoRight (POINT *P,boolean valid)
/* Mengirim salinan P dengan absis ditambah satu */
{
	if (valid) {
		*P = MakePOINT((Absis(*P) + 1), (Ordinat(*P)));
	} else {
		printf("notok boy");
	}
	
}
void GoLeft (POINT *P, boolean valid)
/* Mengirim salinan P dengan absis dikurangi satu */
{
	if (valid){
		*P = MakePOINT((Absis(*P) - 1), (Ordinat(*P)));
	} else {
		printf("notok boy");
	}
	
}
void GoUp (POINT *P, boolean valid)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	if (valid) {
		*P = MakePOINT((Absis(*P)), (Ordinat(*P) + 1));	
	} else {
		printf("notok boy");
	}
	
}
void GoDown (POINT *P, boolean valid)
/* Mengirim salinan P dengan ordinat dikurangi satu */
{
	if (valid) {
		*P = MakePOINT((Absis(*P)), (Ordinat(*P) - 1));
	} else {
		printf("notok boy");
	}
	
}
