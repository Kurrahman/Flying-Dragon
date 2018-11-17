#include <stdio.h>
#include "mesinmix.h"
#include "matriks.h"
int main () {
	int TmpTableNum=0;
	MATRIKS mat1,mat2,mat3;
	int i,j,temp;
	Kata command;
	STARTMIX();	
	MakeMATRIKS(&mat1);
	MakeMATRIKS(&mat2);
	MakeMATRIKS(&mat3);
	printf("%d %d\n",StrLen(CKata.TabKata),StrLen("meja"));
	scanf("%d",&i);
	while (!CompStr(CKata.TabKata,":")){
		i=0;
		while (i<=StrLen(CKata.TabKata)){
			command.TabKata[i] = CKata.TabKata[i];
			i=i+1;
		}		
		ADVMIX('I');
		i= CInt;
		ADVMIX('I');
		j= CInt;
		if (CompStr(command.TabKata,"meja")){
			ADVMIX('I');
			temp = CInt;
			ElID(Elmt(mat1,i,j))='N';
			No(Elmt(mat1,i,j))=temp;
			ADVMIX('I');
			temp = CInt;
			Qty(Elmt(mat1,i,j))=temp;
		}
		else if (CompStr(command.TabKata,"kursiisi")){
			ElID(Elmt(mat1,i,j))='C';
		}
		else if (CompStr(command.TabKata,"kursikos")){
			ElID(Elmt(mat1,i,j))='X';
		}
		else if (CompStr(command.TabKata,"bahan")){
			ElID(Elmt(mat1,i,j))='M';
		}
		else if (CompStr(command.TabKata,"tray")){
			ElID(Elmt(mat1,i,j))='T';
		}
		ADVMIX('D');
	}
	TulisMATRIKS(mat1,1,1);
	TulisMATRIKS(mat2,1,1);
	TulisMATRIKS(mat3,1,1);
	return 0;
}