/* File: mesincampuran.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINMIX_H__
#define __MESINMIX_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '
#define SEPARATOR ':'
#define IntUndef -999

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndFile;
extern Kata CKata;
extern int CInt;
/*CKata dikatakan tidak terdefinisi ketika CKata.Length = 0
CInt dikatakan tidak terdefinisi ketika CInt = IntUndef*/
boolean CompStr(char S1[], char S2[]);
int StrLen(char s[]);
void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTMIX();
/* I.S. : CC sembarang 
   F.S. : EndFile = true, dan CC = MARK; 
          atau EndKata = false, CKata / Cint terdefinisi (bisa keduanya atau salah satu)
          CC karakter pertama sesudah karakter terakhir kata (bisa blank atau mark)*/

void ADVMIX(char C);
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void SalinInt();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif

