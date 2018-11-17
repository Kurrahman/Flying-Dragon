/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H
#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 8
#define KolMin 1
#define KolMax 8
#define MapUndef '-'
typedef struct {
	boolean GU; /*Validasi fungsi GU*/
	boolean GD; /*Validasi fungsi GD*/
	boolean GL; /*Validasi fungsi GL*/
	boolean GR; /*Validasi fungsi GR*/
	boolean ORD; /*Validasi fungsi Order*/
	boolean PUT; /*Validasi fungsi Put*/
	boolean TAKE; /*Validasi fungsi Take*/
	boolean CH; /*Validasi fungsi CH*/
	boolean CT; /*Validasi fungsi CT*/
	boolean PLACE; /*Validasi fungsi Place*/
	boolean GIVE; /*Validasi fungsi Give*/
} predikat;
typedef struct {
	int Out; /*menyimpan jam ketika pelanggan kehabisan kesabaran */
	int No; /*identifikasi nomer meja*/
	int QTY; /*kapasitas duduk pada meja itu 2/4*/
} table;
typedef int indeks; /* indeks baris, kolom */
typedef struct {
	char ElID; /*identifikasi jenis elemen, hanya berisi C,X,T,M,K,N, MapUndef
	C untuk menandakan elemen berupa kursi berisi
	X untuk menandakan elemen berupa kursi kosong
	T untuk menandakan elemen berupa Tray
	M untuk menandakan elemen berupa tempat mengambil barang
	K untuk menandakan elemen berupa lantai kosong
	N untuk menandakan elemen berupa meja*/
	predikat Validasi; /*berisi kemampuan player ketika menginjak lantai tertentu, validasi hanya dimiliki oleh elemen berupa lantai kosong. karena pemain tidak mungkin bisa menuju lantai tidak kosong*/ 
	table Meja; /*berisi identitas meja jika dia berchar N selain itu tidak memiliki Meja*/
} ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
	/*Tidak perlu Neff karena pemrosesan matriks langsung menggunakan min max, karena map pasti diproses secara keseluruhan*/
} MATRIKS;
/* Map Kosong merupakan matriks yang terdapat satu buah MapUndef pada ElIDnya*/
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu penuh*/

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (MATRIKS *M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi*/
/* I.S. Matriks M Sembarang */
/* F.S. semua ElID pada matriks M diisi MapUndef */

/* *** Selektor *** */
/*Selektor pada elemen*/
#define ElID(E) (E).ElID
#define IsGU(E) (E).Validasi.GU
#define IsGD(E) (E).Validasi.GD
#define IsGL(E) (E).Validasi.GL
#define IsGR(E) (E).Validasi.GR
#define IsORD(E) (E).Validasi.ORD
#define IsPUT(E) (E).Validasi.PUT
#define IsTAKE(E) (E).Validasi.TAKE
#define IsCH(E) (E).Validasi.CH
#define IsCT(E) (E).Validasi.CT
#define IsPLACE(E) (E).Validasi.PLACE
#define IsGIVE(E) (E).Validasi.GIVE
#define Out(E) (E).Meja.Out
#define No(E) (E).Meja.No
#define Qty(E) (E).Meja.QTY
/*Selektor pada matriks*/
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */

void IsMapEmpty (MATRIKS *M);
/*Mencari sebuah elemen ID bernilai MapUndef pada map. bila ada maka map dianggap kosong, dan bila tidak ada map dianggap sudah siap pakai dan tidak kosong*/


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
void TulisMATRIKS (MATRIKS M,int px,int py);
/* I.S. M terdefinisi */
/* F.S. apabila ElID K maka hanya menulis spasi, bila ElIDnya M akan menulis identitas bahannya dan sisanya ditampilkan sesuai ID ditulis ke layar per baris per kolom, masing-masing elemen per baris dipisahkan sebuah spasi */
/* Proses: Menulis setiap ElID pada sel M ke layar dengan traversal dan analisis ElID per baris dan per kolom */
/* Contoh:
  C   
C 1 C C 2 C
  C   
*/

void UpdateTable(MATRIKS *M, int nomor, char fungsi[],int jmlhorg);
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

void UpdatePredikat(MATRIKS M, int nomor, char fungsi[]);
/*I.S. M terdefinisi dan tidak kosong 
F.S. beberapa predikat pada area meja berubah, seperti predikat IsPlace, IsGive, IsOrder. 
untuk predikat movement tidak akan pernah diupdate karena map tidak pernah diupdate.
untuk predikat CH CT tidak pernah diupdate karena bisa dilakukan di lantai kosong manapun
untuk predikat Take tidak pernah diupdate juga karena tidak ada kondisi bahan habis atau harus beli. atau tidak bisa mengambil.
*/
#endif
