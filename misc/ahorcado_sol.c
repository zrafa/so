
#include <stdio.h>
#include <stdlib.h>	/* para las funciones system y exit */

int main() {

	int i = 0;
	int c = 0;
	int n = 0;	/* cant de letras */
	char secreta[80];
	char adivina[80];
	int aciertos = 0;
	int vidas = 5;
	int ronda_ok = 0;

	/* Decirle al sistema que el modo input es RAW */
	system ("/bin/stty raw");

	/* inicializo adivina con guiones */
	for (i=0; i<80; i++)
		adivina[i] = '_';

	printf("(El juego no distingue mayusculas de minusculas.)\n\r");
	printf("Ingrese una palabra y presione ENTER: ");
	i = 0;
	while (c != 13) {

		c = getchar();
		if (c == 13) {
			secreta[i] = '\0'; /* fin de linea */
			adivina[i] = '\0'; /* fin de linea */
			break;
		}

		secreta[i] = c;
		i++;
	}
	n = i;

	/* borramos la linea anterior */
	printf("\r                                                           ");

	while(1) {
		printf("\rAdivine (vidas %i): %s", vidas, adivina);

		ronda_ok = 0;
		c = getchar();
		for (i=0; i<n; i++) {
			if ((secreta[i] == c) && (adivina[i] == '_')) {
				adivina[i] = c;
				aciertos++;
				ronda_ok = 1;
			}
		}
		if (!ronda_ok)
			vidas--;

		if (aciertos == n) {
			printf("\n\rGANO!! \n\r");
			break;
		}
		if (vidas == 0) {
			printf("\n\rPerdio!! :(\n\r");
			break;
		}
			
	}

	printf("palabra secreta: %s\n\r", secreta);
	system ("/bin/stty sane erase ^H");
}
