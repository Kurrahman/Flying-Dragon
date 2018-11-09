/* File: Jam.c */
/* Tanggal: 31 Agustus 2018 */
/* Definisi ADT JAM */

#include "boolean.h"
#include <stdio.h>
#include "Jam.h"


/* *** Definisi TYPE JAM <HH:MM:SS> *** */

boolean IsJAMValid (int H, int M, int S)
/**** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
    {
    	// Algoritma
		return ((H<=23) && (H >=0) && ( M >= 0) && (M<=59) && ( S >= 0) && (S<=59));
    }
    
/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
	{  
		// Kamus
 		JAM J;
 		
 		// Algoritma
   		Hour(J) = HH; 
		Minute(J) = MM; 
		Second(J) = SS;

  	    return (J);
	}


void BacaJAM (JAM *J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
  { 
  		
  		// Kamus
  		int x,y,z;
		
		// Algoritma
		
        scanf("%d %d %d",&x,&y,&z);
        do
        if (!IsJAMValid(x,y,z))
        {
            printf("Jam tidak valid\n");
            scanf("%d %d %d",&x,&y,&z);
        }
        while (!(IsJAMValid(x,y,z)));
        
        *J=MakeJAM(x,y,z);
   }

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
	    long int x;
	    
	    // Algoritma
	    x=3600*Hour(J)+60*Minute(J)+Second(J);
	    return (x);
	    
	}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
   {
   		// Kamus
       long int N1;
       int sisa,x;
       JAM J;
       
       // Algoritma
       
       if (N>=86400)
       		{
           		N1= N % 86400;
       		}
       else
       		{
           		N1=N;
       		}

       Hour(J)=N / 3600;
       sisa = N % 3600;
       Minute(J)=sisa / 60;
       x = sisa % 60;
       Second(J)=x;
       return (J);
   }

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
	{
	    return ((J1.HH==J2.HH)&&(J1.MM==J2.MM)&&(J1.SS==J2.SS));
	}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
	{
	    return ((J1.HH!=J2.HH)||(J1.MM!=J2.MM)||(J1.SS!=J2.SS));
	}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
	{
	    return (JAMToDetik(J1)<JAMToDetik(J2));
	}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
	{
	    return (JAMToDetik(J1)>JAMToDetik(J2));
	}
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
	{
		// Kamus
	    long int a;
	    JAM Jx;
	    
	   // ALgoritma
	   
	    a = (JAMToDetik(J)+1);
	    Jx = DetikToJAM(a);
	    return (Jx);
	}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
	{
		// Kamus
	    long int a;
	    JAM Jx;
	    
	    // Algoritma
	    a = JAMToDetik(J) + N;
	    Jx = DetikToJAM(a);
	    return (Jx);
	}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
	{
	    // Kamus
		long int x;
		JAM Jx;
		
		// Algoritma
	    x = JAMToDetik(J)-1;
	    Jx = DetikToJAM(x);
	    return (Jx);
	}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
	{
		// Kamus
	    long int a;
	    JAM Jx;
	    
	    // Algoritma
	    a = JAMToDetik(J) - N;
	    Jx = DetikToJAM(a);
	    return (Jx);
	}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
	{
		// Kamus
		long detikawal;
		long detikakhir;
		long duration;
		
		// Algoritma
	    if (JAMToDetik(JAw)<JAMToDetik(JAkh))
			{
				detikawal = JAMToDetik(JAw);
				detikakhir = JAMToDetik(JAkh);
				duration = detikakhir - detikawal;
			   	return (duration);
			}
	    else
		    {
		    	detikawal = JAMToDetik(JAw);
				detikakhir = JAMToDetik(JAkh);
				duration = detikakhir - detikawal + 86400;
		        return (duration);
		    }
	}
