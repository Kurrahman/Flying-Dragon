#include "boolean.h"
#include <stdio.h>
#include "jam.h"

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
  printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
  // Kamus
  long x;
  // Algoritma
  x = 3600*Hour(J)+60*Minute(J)+Second(J);
  return x;
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
  // Kamus
  long sisa,x;
  JAM J;
  // Algoritma
  Hour(J) = N / 3600;
  sisa = N % 3600;
  Minute(J) = sisa / 60;
  x = sisa % 60;
  Second(J) = x;
  return (J);
}

void IncrementJAM (JAM *J)
/* Jam akan diincrement dari setiap step yang dijalankan */
{
  //Kamus
  long N1;
  //Algoritma
  N1 = JAMToDetik(*J);
  N1 += 1;
  *J = DetikToJAM(N1);
}
