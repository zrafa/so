
/* Padre crea dos hijos */

#include   <stdio.h>
#include   <unistd.h>
#include   <sys/types.h>
#include   <sys/wait.h>

int total = 0;

#define MAX 500000

int   main(void)
{
      int pid;
      int pid2;
      int wstatus;

      pid = fork();
      if (pid == 0) {
         printf("Proceso hijo porque pid es %i\n", pid);

      } else {

          printf("Proceso padre porque pid es %i \n", pid);

          pid2 = fork();
          if (pid2 == 0) {
                  printf("Proceso hijo porque pid es %i \n", pid2);
          } else
                  printf("Proceso padre porque pid es %i \n", pid2);

      }

      /* esperamos a los hijos */
      waitpid(pid, &wstatus, 0);
      waitpid(pid2, &wstatus, 0);
      printf("Total : %i \n", total);

      return 0;
}

