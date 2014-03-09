#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    int numero = atoi(argv[1]);
    int resultado = log2(numero);
    for(int exponente=resultado; exponente >= 0; exponente--){
	int elevado = exp2(exponente);
	//printf("\nelevado %i - nº %i\n", elevado, numero);
	if(numero >= elevado){
	    numero -= elevado;
	    printf("1");
	}
	else
	    printf("0");
    }
    printf("\n");

    return EXIT_SUCCESS;
}
