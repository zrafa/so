#include <xinu.h>
#include "oso.h"

void mutex_init();
void mutex_lock();
void mutex_unlock();


int32 rojo = 0x00ff0000;
int x = 0;
int y = 0;

void mostrar_imagen(int n, int espera, int padre)
{
	int cant;
	for (int y=n; y < n+64; y++) {
		cant = 0;
		for (int x=0;x<128; x++) {
			/*   pintar un pixel en la coordenada x,y :
			 *   pixel(x, y, color);
			 */

			/* el acceso a la pantalla es compartido entre 
			 * los dos procesos. Hay que revisar el codigo 
			 * de pixel() y demas funciones para saber si es seguro
			 * acceder concurrentemente
			 */
			/* Como a priori no sabemos, lo protegemos con un 
			 * mutex 
			 */
			mutex_lock();
			if (oso[y*128+x] == 0 ) {
				pixel (x, y, rojo );
				cant++;
			} else {
				pixel (x, y, oso[y*128+x] );
			}
			mutex_unlock();
		}
		sleepms(espera);
		send(padre, cant);
	}
}

process imagen()
{
	int padre = getpid();
	int cantidad;

	mutex_init();

	/* los dos hijos tendran prioridad menor al padre, para que el padre no 
	 * pierda mensajes 
	 */
	resume( create(mostrar_imagen, 1024, 19, "mostrar 1", 3, 0, 20, padre) );
	resume( create(mostrar_imagen, 1024, 19, "mostrar 2", 3, 64, 50, padre) );
	cantidad = 0;
	recvclr();
	for (int i=0; i<128; i++) {
		cantidad = cantidad + receive();
	}
	printf("Se han modificado %d pixeles negros \n\r", cantidad);
}

