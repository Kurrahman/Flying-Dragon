#include "mesinmix.h"
#include <ctype.h>
#include <stdio.h>

int CInt;
Kata CKata;
boolean EndFile;
boolean CompStr(char S1[], char S2[]){
	int i = 0;
	boolean stop = true;
	int len = StrLen(S2);
	while ((i < len) && stop){
		if(S1[i] != S2[i]){
			stop = false;
		}
		i++;
	}
	return stop;
}
int StrLen(char s[]) {
	int c = 0;
	while (s[c] != '\0')
		c++;
	
	return c;
}

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
	while( (CC == BLANK || CC== '\n') && CC!=MARK)
		ADV();
}

void STARTMIX(){
/* I.S. : CC sembarang 
   F.S. : EndFile = true, dan CC = MARK; 
          atau EndKata = false, CKata / Cint terdefinisi (bisa keduanya atau salah satu)
          CC karakter pertama sesudah karakter terakhir kata (bisa blank atau mark)*/
	START();
	EndFile = true;
	IgnoreBlank();
	if (CC != MARK){
		EndFile=false;
		SalinKata();
	}
}

void ADVMIX(char C){
/* I.S. : apabila C = D maka CC adalah karaker pertama adalah kata yang siap diakuisisi. bila C = I atau K ada kemungkinan CC separator atau karakter pertama dari hal yang siap diakuisisi
   F.S. : CKata atau CInt Bisa terdefinisi atau tidak , 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	if (CC !=MARK){
		if (C =='D'){
			CInt=IntUndef;
			CKata.Length=0;
			SalinKata();
		}
		else if (C == 'K'){
			SalinKata();
		}
		else if (C == 'I'){
			SalinInt();
		}
	}
	else
		EndFile=true;
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	int i=-1;
	while (CC!=BLANK && CC!=MARK){
		if (i<NMax){
		i=i+1;
		CKata.TabKata[i]=tolower(CC);
		}
		else if (i=NMax){
		CKata.TabKata[i+1]=tolower(CC);
		}
		ADV();
	}
	CKata.TabKata[i+1]='\0';
	CKata.Length=i+1;
	IgnoreBlank();
}

int KarToInteger(char c){
	switch (c) {
		case '0' :
			return 0;
		case '1' :
			return 1;
		case '2' :
			return 2;
		case '3' :
			return 3;
		case '4' :
			return 4;
		case '5' :
			return 5;
		case '6' :
			return 6;
		case '7' :
			return 7;
		case '8' :
			return 8;
		case '9' :
			return 9;
	}
}
void SalinInt(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	char temp;
	CInt=0;
	while ((CC=='0' || CC=='1' || CC=='2' || CC=='3' || CC=='4' || CC=='5' || CC=='6' || CC=='7' || CC=='8' || CC=='9')){
		temp=CC;
		ADV();
		if ((CC=='0' || CC=='1' || CC=='2' || CC=='3' || CC=='4' || CC=='5' || CC=='6' || CC=='7' || CC=='8' || CC=='9'))
			CInt= (CInt + KarToInteger(temp))*10;
		else
			CInt= (CInt + KarToInteger(temp));
	}
	IgnoreBlank();
}