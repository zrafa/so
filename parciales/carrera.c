
#define ASCII_ESC 27

int vel_a = 0;
int vel_b = 0;

corredor_a()
{
	while(1) {
		vel_a++;
	}

}

corredor_b()
{

	while(1) {
		vel_b++;
	}
}


muestra_carrera() 
{
	/* limpiar toda la pantalla */
	printf( "%c[2J", ASCII_ESC );

	while(1) {
		/* Nos posicionamos en la fila 5 columna 10 */
    		printf( "%c[5;10f", ASCII_ESC );
    		printf( "Velocidad corredor A: %d \n", vel_a);

		/* Nos posicionamos en la fila 6 columna 10 */
    		printf( "%c[6;10f", ASCII_ESC );
    		printf( "Velocidad corredor B: %d \n", vel_b);

		sleepms(50);
	}


}

