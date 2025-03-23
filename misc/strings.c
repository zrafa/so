
#include <stdio.h>

int main() 
{
    /* declaramos un arreglo para que contenga un string */
    char mensaje[] = "Hola mundo";

    /* declaramos un arreglo para que contenga valores enteros */
    int cant[10];

    int n = 10;
    int i;

    for (i=0; i<n; i++) {
	    cant[i] = n + i;
    }

    /* mostramos el arreglo */
    for (i=0; i<n; i++) {
	    printf("la posicion %i contiene el valor %i \n", i ,cant[i]);
    }

    /* Imprimimos el mensaje original */
    printf("Mensaje original: %s\n", mensaje);

    /* Recorremos el string hasta encontrar el fin del string 
     * que es el valor nulo '\0'
     */
    i = 0;
    while (mensaje[i] != '\0') {
    	    i++;
    }

    printf("El ult indice del arreglo mensaje[] es %i \n", i);
    printf("Por lo tanto el arreglo mensaje[] contiene %i elementos \n", i+1);
    n = i;

    /* modificamos una letra del string */
    mensaje[4] = 'X';

    /* mostramos el strign letra por letra */
    for (i=0; i<=n; i++) {
	    printf("la posicion %i contiene el valor %c \n", i, mensaje[i]);
    }

    return 0;
}
