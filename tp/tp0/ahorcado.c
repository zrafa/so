#include <stdio.h>
#include <stdlib.h>	/* para las funciones system y exit */

int main() {

	int c;

	/* Decirle al sistema que el modo input es RAW */
	system ("/bin/stty raw");

	while(1) {
		printf("\r                                                          ");
		printf("\r c = %c  ingrese una letra (0 para salir): ", c);
		c = getchar();

		if (c == '0')
			break;
	}

	system ("/bin/stty sane erase ^H");
}
