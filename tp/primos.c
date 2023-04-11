
 /* primos entre el número 1 y MAX */

 #include <stdio.h>

 #define MAX 500000

 int total = 0;

 int encontrar_primos(int from, int to)
 {
         int i, n, primo;
         printf( "\n   " );

          for ( i = from ; i <= to ; i++ ) {
                  primo = 1;
                  n = 2;

                   while ( n <= i / 2 && primo ) {
                           if ( i % n == 0 )
                                   primo = 0;

                            n++;
                   }

                   if ( primo )
                           printf( "%d \n", i );
          }

          total++;
          return 0;
 }

 int main()
 {
         encontrar_primos(1, MAX);
         printf("Total : %i \n", total);

          return 0;
 }


