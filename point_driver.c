// File : mpoint.c //

#include "point.h"
#include <stdio.h>

int main ()
{
	/* KAMUS */
	POINT P;
	float dx, dy;
	boolean valid;
	/* ALGORITMA */
	/* Test Baca dan Tulis */
	printf("Masukkan nilai absis dan ordinat P: \n");
	BacaPOINT(&P);
	printf("Titik P yang dibaca = ");
	TulisPOINT(P);
	printf("\n");
	valid = true;
	/* Test GoRight */
	printf("Setelah bergerak ke kanan\n");
	GoRight(&P, valid);
	TulisPOINT(P);
	printf("\n");
	/* Test GoLeft */
	printf("Setelah bergerak ke kiri\n");
	GoLeft(&P, valid);
	TulisPOINT(P);
	printf("\n");
	/* Test GoUp */
	printf("Setelah bergerak ke atas\n");
	GoUp(&P, valid);
	TulisPOINT(P);
	printf("\n");
	/* Test GoDown */
	printf("Setelah bergerak ke bawah\n");
	GoDown(&P, valid);
	TulisPOINT(P);
	printf("\n");
	return 0;
}
