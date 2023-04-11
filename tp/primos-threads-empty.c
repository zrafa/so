
/* Ejemplo de dos threads en Linux. Compilar con: gcc -o p p.c -lpthread */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 500000

int total = 0;

void *thread(void * i)
{
        int n = *((int *) i);

        if (n == 0) {
                printf("Este es el thread nro: %i \n", n);
        } else {
                printf("Este es el thread nro: %i \n", n);
        }
}


int main()
{
        int i0=0;
        int i1=1;
        pthread_t tid[2];

        /* Create independent threads each of which will execute function */
        pthread_create( &tid[0], NULL, thread, (void *) &i0);
        pthread_create( &tid[1], NULL, thread, (void *) &i1);

        /* Wait till threads are complete before main continues.   */
        for (int i = 0; i < 2; i++)
                pthread_join(tid[i], NULL);

        printf("Total : %i \n", total);

        return 0;
}



