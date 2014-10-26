/* Hilos y señales 
 * Daniel Fernandez Perez
 * Crea dos hilos que sumaran y restaran hasta conseguir un numero
 * Solo terminara el programa cuando se alcance el numero deseado y el usuario presione ctrl-c
 * Si el usuario presiona ctrl-c y no se alcanzo el numero deseado el programa contiuara su ejecucion
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

#define NMAX  1000000

enum Toperacion{SUMA, RESTA};

//Variable global que almacena el numero total.
sig_atomic_t n=0;

//Funcion encargada de cerrar el programa cuando n sea >= NMAX.
void cerrar(int signal){
    if(n >= NMAX){
	exit(0);
    }
    else
	printf("\nNo termino\n"
		"Aun esta por el numero %i\n", n);
    if(n < 0){
	printf("Se aborta el programa posible bucle erroneo N = %i\n", n);
	exit(0);
    }
}

//Funcion donde entraran los hilos y ejecutaran su parte del programa
void* operacion(void* args){
    enum Toperacion *arg = (enum Toperacion*) args;

    int contador1 = 0;
    int contador2 = 0;
    switch(*arg){
	case SUMA:
	    printf("ENTRO SUMA    n = %i\n", n);
	    while(n < NMAX){
		int random =  (rand() % 4 + 1);
		n += random;
		contador1 ++;
	    }
	    printf("SALIO SUMA.  SUMA se ejecuto %i n = %i\n", contador1, n);
	    break;

	case RESTA:
	    printf("ENTRO RESTA    n = %i\n", n);
	    while(n < NMAX){
	        int random =  (rand() % 3 + 1);
	        if(n >= NMAX)
	            break;
		else{
		    n -= random;
		    contador2 ++;
		}
	    }
	    printf("SALIO RESTA. RESTA se ejecuto %i n = %i\n",contador2, n);
	    break;
    }
    return NULL;
}

int main(){
    pthread_t hilo1_id, hilo2_id;
    srand(time(NULL));

    struct sigaction senyal;
    memset(&senyal, 0, sizeof(senyal));
    senyal.sa_handler = &cerrar;
    sigaction(SIGINT, &senyal, NULL);

    enum Toperacion operacion1, operacion2;
    operacion1 = SUMA;
    operacion2 = RESTA;


    //Llamada a los hilos
    pthread_create(&hilo1_id, NULL, &operacion, &operacion1);
    pthread_create(&hilo2_id, NULL, &operacion, &operacion2);
    //Espera de los hilos
    pthread_join(hilo1_id, NULL);
    pthread_join(hilo2_id, NULL);

    printf("------TERMINO-------\n"
	    "Numero = %i\n"
	    "Presione ctrl-c para finalizar\n", n);
    while(1);//Espera a que el usuario presione ctr+c
    return EXIT_SUCCESS;

}
