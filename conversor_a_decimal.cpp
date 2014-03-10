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

int puerta_and(int *numero_binario[3]){
    int *mascara[3];
    int numero[3];
    /*mascara[0] =1;
    mascara[1] =1;
    mascara[2] =1;*/
    *mascara[0]=111;

    for(int i=0; i<3; i++){
	numero[i] = *numero_binario[i] / *mascara[i];
    }



    for(int i=0; i<3; i++)
	printf("%i", numero[i]);
    printf("\n");
}

int main(int argc, char *argv[]){
    /*int numero = atoi(argv[1]),
      resultado = log2(numero),
      binario,
      x = 0;*/

    /*for(int exponente=resultado; exponente >= 0; exponente--){
      int elevado = exp2(exponente);

      if(numero >= elevado){
      numero -= elevado;
      binario += pow (10, exponente);
      }
      }	*/
    int numero = atoi(argv[1]);
	int *binario[3];
	int binario2;

    binario2 = to_binario(numero);
    *binario[0]=binario2;
    /*binario[1]=1;
    binario[2]=0;*/
    puerta_and(binario);

    printf("binario= %i\n decimal= %i\n", to_binario(numero), to_decimal(binario2));
    printf("\n");

    return EXIT_SUCCESS;
}
