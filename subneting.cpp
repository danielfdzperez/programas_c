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

void mascara(int binario[], int red[]){
    int mascara[8];


    for(int rellenar=0; rellenar<8; rellenar++)
	mascara[rellenar]=0;

    mascara[0]=1;
    mascara[1]=1;

    for(int x=0; x<2; x++)
	red[x] = binario[x] / mascara[x];
}
int main(int argc, char *argv[]){
    int numero = atoi(argv[1]);
    int binario[8],
	red[8];


    int numero2 = atoi(argv[1]),
	resultado = log2(numero2),
	binario2;

    for(int rellenar=0; rellenar<8; rellenar++)
	binario[rellenar]=0;

    for(int exponente=resultado; exponente >= 0; exponente--){
	int elevado = exp2(exponente);

	if(numero2 >= elevado){
	    numero2 -= elevado;
	    binario[exponente] = 1;
	}
	else
	    binario[exponente] = 0;
    } 



    to_binario(numero);
    mascara(binario, red);

    for(int x=0; x<8; x++)
	printf("%i", binario[x]);
    printf("\n");

    for(int x=0; x<2; x++)
	printf("%i", red[x]);
    printf("\n");

    return EXIT_SUCCESS;
}
