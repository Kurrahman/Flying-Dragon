
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi*/
/* I.S. Matriks M Sembarang */
/* F.S. semua ElID pada matriks M diisi MapUndef */
#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* *** Selektor *** */
void MakeMATRIKS (MATRIKS M){} 

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
return(i<=8&&j>=0&&j<=8&&j>=0);
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */

void IsMapEmpty (MATRIKS *M){
/*Mencari sebuah elemen ID ber{nilai MapUndef pada map. bila ada maka map dianggap kosong, dan bila tidak ada map dianggap sudah siap pakai dan tidak kosong*/
int i=1,j=1;
while(i<=BrsMax){
	j=1;
	while(j<=KolMax){
		
		ElID(Elmt(*M,i,j))='x'; 
		IsGU(Elmt(*M,i,j))=false; 
		IsGD(Elmt(*M,i,j))=false; 
		IsGL(Elmt(*M,i,j))=false; 
		IsGR(Elmt(*M,i,j))=false; 
		IsORD(Elmt(*M,i,j))=false; 
		IsPUT(Elmt(*M,i,j))=false; 
		IsTAKE(Elmt(*M,i,j))=false; 
		IsCH(Elmt(*M,i,j))=false; 
		IsCT(Elmt(*M,i,j))=false; 
		IsPLACE(Elmt(*M,i,j))=false; 
		IsGIVE(Elmt(*M,i,j))=false;
		j++;
		
	}
	i++;
}
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
/*void BacaMATRIKS (MATRIKS * M, FILE * file);
/* I.S. file sudah di open dan siap dibaca*/ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
PROSEDUR BACA MATRIKS DIATAS AKAN DIGANTIKAN DENGAN LOAD PADA PROGRAM UTAMA.*/
void TulisMATRIKS (MATRIKS M,int px,int py){
/* I.S. M terdefinisi */
/* F.S. apabila ElID K maka hanya menulis spasi, bila ElIDnya M akan menulis identitas bahannya dan sisanya ditampilkan sesuai ID ditulis ke layar per baris per kolom, masing-masing elemen per baris dipisahkan sebuah spasi */
/* Proses: Menulis setiap ElID pada sel M ke layar dengan traversal dan analisis ElID per baris dan per kolom */
/* Contoh:
  C   
C 1 C C 2 C
  C   
*/

ElID(Elmt(M,px,py))='P';
int i=1,j=1;
printf("--------------------------------\n");
while(i<=BrsMax){
	j=1;
	while(j<=KolMax){
		printf("| %c ",ElID(Elmt(M,i,j)));
		j++;
		
	}
	i++;
	printf("\n");
	printf("--------------------------------\n");
}
}
		


void UpdateTable(MATRIKS *M, int nomor, char fungsi[],int jmlhorg){
/*I.S. Meja terdefinisi nomor merupakan nomor meja yang valid
F.S. semua komponen pada meja berkemungkinan terupdate, sesuai dengan fungsi yang dilakukan
Place
	ingat validasi jumlah orang pada Q dengan kursi. sehingga proses place bisa tidak terjadi meskipun player valid untuk melakukan place.
	merubah ElId pada elemen sel (perhatikan pada kasus 2 ditaruh di 4)
	merubah waktu Out
	merubah predikat dengan fungsi update predikat
Order
	merubah predikat dengan fungsi update predikat. 
Give
	merubah ElID C menjadi X. 
	merubah predikat dengan fungsi update predikat.
*/
int i,j;
boolean Found;
while(i<=BrsMax&&!Found){
		j=1;
		while(j<=KolMax&&!Found){
			if(No(Elmt(*M,i,j))==nomor){
				Found=false;
			}
			else{
				j++;
			}
		}
		i++;
	}
if(strcmp(fungsi,"place")==0){
	if(jmlhorg==2&&Qty(Elmt(*M,i,j))==2){
		ElID(Elmt(*M,i,j+1))='C';
		ElID(Elmt(*M,i,j-1))='C';
		IsORD(Elmt(*M,i+1,j+1))=true;
		IsORD(Elmt(*M,i-1,j+1))=true;
		IsORD(Elmt(*M,i+1,j))=true;
		IsORD(Elmt(*M,i-1,j))=true;
		IsORD(Elmt(*M,i+1,j-1))=true;
		IsORD(Elmt(*M,i-1,j-1))=true;
		IsORD(Elmt(*M,i,j-2))=true;
		IsPLACE(Elmt(*M,i,j))=false;
		Out(Elmt(*M,i,j))=150;
	}
	else if(jmlhorg==2&&Qty(Elmt(*M,i,j))==4){
		ElID(Elmt(*M,i,j+1))='C';
		ElID(Elmt(*M,i,j-1))='C';
		IsORD(Elmt(*M,i,j+2))=true;
		IsORD(Elmt(*M,i+1,j+1))=true;
		IsORD(Elmt(*M,i-1,j+1))=true;
		IsORD(Elmt(*M,i+1,j-1))=true;
		IsORD(Elmt(*M,i-1,j-1))=true;
		if(i==2){
			IsORD(Elmt(*M,i-2,j))=true;
		}
		else{
			IsORD(Elmt(*M,i+2,j))=true;
		}
		IsPLACE(Elmt(*M,i,j))=false;
		Out(Elmt(*M,i,j))=150;
	}
	else if(jmlhorg==4&&Qty(Elmt(*M,i,j))==4){
		ElID(Elmt(*M,i,j+1))='C';
		ElID(Elmt(*M,i,j-1))='C';
		ElID(Elmt(*M,i+1,j))='C';
		ElID(Elmt(*M,i-1,j))='C';
		IsORD(Elmt(*M,i,j+2))=true;
		IsORD(Elmt(*M,i+1,j+1))=true;
		IsORD(Elmt(*M,i-1,j+1))=true;
		IsORD(Elmt(*M,i+1,j-1))=true;
		IsORD(Elmt(*M,i-1,j-1))=true;
		if(i==2){
			IsORD(Elmt(*M,i-2,j))=true;
		}
		else{
			IsORD(Elmt(*M,i+2,j))=true;
		}
		IsPLACE(Elmt(*M,i,j))=false;
		Out(Elmt(*M,i,j))=150;
	}
	else{
		printf("Meja tidak cukup");
	}
}
else if(strcmp(fungsi,"order")==0){
	if(Qty(Elmt(*M,i,j))==2){
		IsORD(Elmt(*M,i+1,j+1))=false;
		IsORD(Elmt(*M,i-1,j+1))=false;
		IsORD(Elmt(*M,i+1,j))=false;
		IsORD(Elmt(*M,i-1,j))=false;
		IsORD(Elmt(*M,i+1,j-1))=false;
		IsORD(Elmt(*M,i-1,j-1))=false;
		IsORD(Elmt(*M,i,j-2))=false;
		IsGIVE(Elmt(*M,i+1,j+1))=true;
		IsGIVE(Elmt(*M,i-1,j+1))=true;
		IsGIVE(Elmt(*M,i+1,j))=true;
		IsGIVE(Elmt(*M,i-1,j))=true;
		IsGIVE(Elmt(*M,i+1,j-1))=true;
		IsGIVE(Elmt(*M,i-1,j-1))=true;
		IsGIVE(Elmt(*M,i,j-2))=true;
		

	}
	else if(Qty(Elmt(*M,i,j))==4){
		IsORD(Elmt(*M,i,j+2))=false;
		IsORD(Elmt(*M,i+1,j+1))=false;
		IsORD(Elmt(*M,i-1,j+1))=false;
		IsORD(Elmt(*M,i+1,j-1))=false;
		IsORD(Elmt(*M,i-1,j-1))=false;
		
		IsGIVE(Elmt(*M,i,j+2))=true;
		IsGIVE(Elmt(*M,i+1,j+1))=true;
		IsGIVE(Elmt(*M,i-1,j+1))=true;
		IsGIVE(Elmt(*M,i+1,j-1))=true;
		IsGIVE(Elmt(*M,i-1,j-1))=true;
		if(i==7){
			IsGIVE(Elmt(*M,i+2,j))=true;
			IsORD(Elmt(*M,i+2,j))=false;
		}
		else{
		IsGIVE(Elmt(*M,i-2,j))=true;
		IsORD(Elmt(*M,i-2,j))=false;
	}
	}
}
else if(strcmp(fungsi,"give")==0){
	if(jmlhorg==2&&Qty(Elmt(*M,i,j))==2){
		ElID(Elmt(*M,i,j+1))='X';
		ElID(Elmt(*M,i,j-1))='X';
		IsGIVE(Elmt(*M,i+1,j+1))=false;
		IsGIVE(Elmt(*M,i-1,j+1))=false;
		IsGIVE(Elmt(*M,i+1,j))=false;
		IsGIVE(Elmt(*M,i-1,j))=false;
		IsGIVE(Elmt(*M,i+1,j-1))=false;
		IsGIVE(Elmt(*M,i-1,j-1))=false;
		IsGIVE(Elmt(*M,i,j-2))=false;
		IsPLACE(Elmt(*M,i,j))=true;

	}
	else if(jmlhorg==2&&Qty(Elmt(*M,i,j))==4){
		ElID(Elmt(*M,i,j+1))='X';
		ElID(Elmt(*M,i,j-1))='X';
		IsGIVE(Elmt(*M,i,j+2))=false;
		IsGIVE(Elmt(*M,i+1,j+1))=false;
		IsGIVE(Elmt(*M,i-1,j+1))=false;
		IsGIVE(Elmt(*M,i+1,j-1))=false;
		IsGIVE(Elmt(*M,i-1,j-1))=false;
		IsGIVE(Elmt(*M,i+2,j))=false;
		IsGIVE(Elmt(*M,i-2,j))=false;
		IsPLACE(Elmt(*M,i,j))=true;
	}
	else if(jmlhorg==4&&Qty(Elmt(*M,i,j))==4){
		ElID(Elmt(*M,i,j+1))='X';
		ElID(Elmt(*M,i,j-1))='X';
		ElID(Elmt(*M,i+1,j))='X';
		ElID(Elmt(*M,i-1,j))='X';
		IsGIVE(Elmt(*M,i,j+2))=false;
		IsGIVE(Elmt(*M,i,j-2))=false;
		IsGIVE(Elmt(*M,i+1,j+1))=false;
		IsGIVE(Elmt(*M,i-1,j+1))=false;
		IsGIVE(Elmt(*M,i+1,j-1))=false;
		IsGIVE(Elmt(*M,i-1,j-1))=false;
		IsGIVE(Elmt(*M,i+2,j))=false;
		IsGIVE(Elmt(*M,i-2,j))=false;
		IsPLACE(Elmt(*M,i,j))=true;
	}
}
}






void UpdatePredikat(MATRIKS M, int nomor, char fungsi[]){
/*I.S. M terdefinisi dan tidak kosong 
F.S. beberapa predikat pada area meja berubah, seperti predikat IsPlace, IsGive, IsOrder. 
untuk predikat movement tidak akan pernah diupdate karena map tidak pernah diupdate.
untuk predikat CH CT tidak pernah diupdate karena bisa dilakukan di lantai kosong manapun
untuk predikat Take tidak pernah diupdate juga karena tidak ada kondisi bahan habis atau harus beli. atau tidak bisa mengambil.
*/
}
