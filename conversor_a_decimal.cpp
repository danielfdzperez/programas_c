#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int to_decimal(int numero){

    if(!numero)
	return 0;
    return numero % 10 + 2 * to_decimal(numero/10);
}

int to_binario(int numero){
    if(!numero)
	return 0;
    return numero % 2 + 10 * to_binario(numero/2);

}

int main(int argc, char *argv[]){
    int numero = atoi(argv[1]);
	int binario;
    binario = to_binario(numero);

    printf("binario= %i\n decimal= %i\n", to_binario(numero), to_decimal(binario));
    printf("\n");

    return EXIT_SUCCESS;
}
