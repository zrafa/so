
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* un arreglo grande, para que quepan 50 entradas de 100 bytes cada una */
char diccionario[6000]; 
char palabra[4];
int encontrado = -1;

void *buscar(void *arg)
{
	/* un argumento como en el slide o apunte */
    	int n = *(int *)arg;
	int i;

	for (i=0; i<25; i++) {

		if (	palabra[0] == diccionario[(n+i)*100] &&
			palabra[1] == diccionario[(n+i)*100 + 1] &&
			palabra[2] == diccionario[(n+i)*100 + 2] &&
			palabra[3] == diccionario[(n+i)*100 + 3]) {
				encontrado = (n+i)*100;
		}
	}
}




void main() {
	int fd;
	char c;
	int bytes_leidos;
	int i = 0;

	/* modo raw */
	system ("/bin/stty raw");

	printf("Ingrese palabra a buscar (4 letras): ");
	for (i=0; i<4; i++) {
		palabra[i] = getchar();
	}

	/* cargamos el diccionario */
	fd = open("diccionario.txt", O_RDONLY);
	if (fd == -1) {
		printf("Error al abrir archivo\n");
		return;
	}

	i = 0;
	bytes_leidos = 1;
	while (bytes_leidos > 0) {
		bytes_leidos = read(fd, &c, 1);
		diccionario[i] = c;
		i++;
	}

	close(fd);

	/* creamos los threads */
	pthread_t t1, t2;

	int a = 0;	 /* que busque desde la entrada 0 */
	int b = 25;	 /* que busque desde la entrada 50 */

	pthread_create(&t1, NULL, buscar, &a);
	pthread_create(&t2, NULL, buscar, &b);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	if (encontrado == -1) {
		printf("Palabra no encontrada. \n\r");
		system ("/bin/stty sane erase ^?");
		return;
	}

	/* encontrada */
	fd = open("resultado.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);

	for (i=0; i<100; i++) {
		write(fd, &diccionario[encontrado+i], 1);
	}

	close(fd);

	system ("/bin/stty sane erase ^?");
}

