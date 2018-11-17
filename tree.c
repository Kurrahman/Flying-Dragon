#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R){
    BinTree T = (BinTree) malloc (sizeof(Node));
    if (T != Nil){
        Akar(T) = Akar;
        Left(T) = L;
        Right(T) = R;
    }
    return T;
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
    *P = Tree(Akar,L,R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */


/* Manajemen Memory */
addrNode AlokNode(infotype X){
    addrNode P = (addrNode) malloc (sizeof(Node));
    if (P != Nil){
        Akar(P) = X;
        Right(P) = Nil;
        Left(P) = Nil;
    }
    return P;
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
    return (P == Nil);
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
    return (Right(P) == Nil) && (Left(P) == Nil);
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
    return (Left(P) != Nil) && (Right(P) == Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
    return (Right(P) != Nil) && (Left(P) == Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
    return (Right(P) != Nil) && (Left(P) != Nil);
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

int Level(BinTree P, infotype X){
    if (Akar(P) == X){
        return 1;
    }
    else{
        if (SearchTree(Left(P),X)){
            return (1 + Level(Left(P),X));
        }
        else{
            return (1 + Level(Right(P),X));
        }
    }
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */

/* *** Traversal *** */
void PrintTree(BinTree P, int h){
    int i; 
    switch (Akar(P)){
        case (11) : {
            printf("Piring\n");
            break;
        }
        case (21) : {
            printf("Sendok\n");
            break;
        }
        case (22) : {
            printf("Garpu\n");
            break;
        }
        case (31) : {
            printf("Es Krim\n");
            break;
        }
        case (32) : {
            printf("Nasi\n");
            break;
        }
        case (33) : {
            printf("Roti\n");
            break;
        }
        case (34) : {
            printf("Spaghetti\n");
            break;
        }
        case (41) : {
            printf("Pisang\n");
            break;
        }
        case (42) : {
            printf("Stroberi\n");
            break;
        }
        case (43) : {
            printf("Telur\n");
            break;
        }
        case (44) : {
            printf("Ayam Goreng\n");
            break;
        }
        case (45) : {
            printf("Patty\n");
            break;
        }
        case (46) : {
            printf("Sosis\n");
            break;
        }
        case (47) : {
            printf("Bolognese\n");
            break;
        }
        case (48) : {
            printf("Carbonara\n");
            break;
        }
        case (51) : {
            printf("Banana Split\n");
            break;
        }
        case (52) : {
            printf("Sundae\n");
            break;
        }
         case (53) : {
            printf("Nasi Telur Dadar\n");
            break;
        }
        case (54) : {
            printf("Nasi Ayam Goreng\n");
            break;
        }
        case (55) : {
            printf("Burger\n");
            break;
        }
        case (56) : {
            printf("Hot Dog\n");
            break;
        }
        case (57) : {
            printf("Keju\n");
            break;
        }
        case (58) : {
            printf("Spaghetti Carbonara\n");
            break;
        }
        default :{
            break;
        }
        case (61) : {
            printf("Spaghetti Bolognese\n");
            break;
        }
    }
    if (Left(P) != Nil){
        for (i = 1; i <= h/2; i++){
            printf("  ");
        }
        PrintTree(Left(P), h + 4);
    }

    if (Right(P) != Nil){
        for (i = 1; i <= h/2; i++){
            printf("  ");
        }
        PrintTree(Right(P), h + 4);
    }
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
    if (IsTreeOneElmt(P)){
        return (Akar(P) == X);
    }
    else{
        if (IsUnerLeft(P)){
            return (Akar(P) == X) || SearchTree(Left(P),X);
        }
        else if (IsUnerRight(P)){
            return (Akar(P) == X) || SearchTree(Right(P),X);
        }
        else if (IsBiner(P)){
            return (Akar(P) == X) || SearchTree(Left(P),X) || SearchTree(Right(P),X);
        }
        else{
            return false;
        }
    }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
    if (IsTreeOneElmt(P)){
        return 1;
    }
    else{
        if (IsUnerLeft(P)){
            return 1 + NbElmt(Left(P));
        }
        else if (IsUnerRight(P)){
            return 1 + NbElmt(Right(P));
        }
        else if (IsBiner(P)){
            return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
        }
        else{
            return 0;
        }
    }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P){
    if (IsTreeOneElmt(P)){
        return 1;
    }
    else{
        if (IsUnerLeft(P)){
            return NbDaun(Left(P));
        }
        else if (IsUnerRight(P)){
            return NbDaun(Right(P));
        }
        else if (IsBiner(P)){
            return NbDaun(Left(P)) + NbDaun(Right(P));
        }
        else{
            return 0;
        }
    }
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
void InitTreeRecipe(BinTree *A){
    MakeTree(11,Nil,Nil,A);
    Left(*A) = AlokNode(21);
    Right(*A) = AlokNode(22);
    Left(Left(*A)) = AlokNode(31);
    Right(Left(*A)) = AlokNode(32);
    Left(Right(*A)) = AlokNode(33);
    Right(Right(*A)) = AlokNode(34);
    Left(Left(Left(*A))) = AlokNode(41);
    Right(Left(Left(*A))) = AlokNode(42);
    Left(Right(Left(*A))) = AlokNode(43);
    Right(Right(Left(*A))) = AlokNode(44);
    Left(Left(Right(*A))) = AlokNode(45);
    Right(Left(Right(*A))) = AlokNode(46);
    Left(Right(Right(*A))) = AlokNode(47);
    Right(Right(Right(*A))) = AlokNode(48);
    Left(Left(Left(Left(*A)))) = AlokNode(51);
    Left(Right(Left(Left(*A)))) = AlokNode(52);
    Left(Left(Right(Left(*A)))) = AlokNode(53);
    Left(Right(Right(Left(*A)))) = AlokNode(54);
    Left(Left(Left(Right(*A)))) = AlokNode(55);
    Left(Right(Left(Right(*A)))) = AlokNode(56);
    Left(Left(Right(Right(*A)))) = AlokNode(57);
    Left(Right(Right(Right(*A)))) = AlokNode(58);
    Left(Left(Left(Right(Right(*A))))) = AlokNode(61);
}