
/* bisiestos.c en XINU */

#include <xinu.h>

#define ASCII_ESC 27
long int calculo[2];

/* completar el codigo del programa bisiesto */
bisiesto()
{
	int i;

	/* base, limite y n vienen como argumentos */
	for (i=base; i<=limite; i++) {
		if  /* anio i es bisiesto */ 
			calculo[n] = i;	
			sleepms(300);
	}

}

muestra_bisiestos() 
{
	/* limpiar toda la pantalla */
	printf( "%c[2J", ASCII_ESC );

	while(1) {
		/* Nos posicionamos en la fila 5 columna 10 */
    		printf( "%c[5;10f", ASCII_ESC );
    		printf( "proceso a: %d \n", calculo[0]);

		/* Nos posicionamos en la fila 6 columna 10 */
    		printf( "%c[7;10f", ASCII_ESC );
    		printf( "proceso b: %d \n", calculo[0]);

		sleepms(50);
	}
}


/* completar el gestor de procesos bisiestos */
gestor_bisiestos()
{
	while(1) {
		/* gestionar las pulsaciones del teclado, procesar, informar al usuario */

		sleepms(5);
	}

}

