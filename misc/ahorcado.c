/* includes de linux */
#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 
#include <stdlib.h> 

int verificar(char letra, char *palabra, char *adivinada)
{
	int acierto = 0;
	for (int i = 0; i < 5; i++) {
		if (palabra[i] == letra) {
			adivinada[i] = letra;
			acierto = 1;
		}
	}
	return acierto;
}

int main()
{
	char acertijo[] = "linux";
	char aux[] = "-----";
	int intentos = 6;
	int encontrada = 0;
	int c;

	/* Decirle al sistema que el modo input es RAW */
	system("/bin/stty raw");
  
	while (intentos && !encontrada) {

		printf("\n\r c = %c  Ingrese una letra (0 para salir) (%s) (%d intentos restantes): ", c, aux, intentos);

		c = getchar();
		if (c == '0') {
			/* salir */
			break;
		} 

		if (verificar(c, acertijo, aux)) {
			printf("\n\r Acierto! La letra %c ha sido encontrada\n", c);
			if (strcmp(acertijo, aux) == 0) {
				encontrada = 1;
			}
		} else {
			printf("\n\r La letra %c no ha sido encontrada\n", c);
			intentos--;
		}
	}

	if (intentos == 0) {
		printf("\n\r Perdiste, la palabra era linux.\n");
	} else if (encontrada) {
		printf("\n\r Ganaste, la palabra es linux!\n");
	}
    
	printf("\n\r Salir.\n");
	system("/bin/stty sane erase ^H");
}
