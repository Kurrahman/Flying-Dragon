// mainjam.c sebagai driver untuk header Jam.h dan body Jam.c

#include <stdio.h>
#include "jam.h"

int main()
	{
		// Kamus
        JAM J1;

		// Algoritma
		    // Untuk testing fungsi detiktojam
		        J1= DetikToJAM(10000);
		        printf("10000 detik sama dengan jam : \n");
		        TulisJAM(J1);
		        printf("\n");
				// Untuk testing fungsi JAMToDetik
						printf("Jam to detik : \n");
						printf("%ld",JAMToDetik(J1));
						printf("\n");
		  	// Untuk testing IncrementJAM
						printf("Increment jam : \n");
						IncrementJAM(&J1);
						TulisJAM(J1);
						printf("\n");
        return 0;
    }
