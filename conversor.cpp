#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void comprobar_parametros(int argc, char *argv[]){
     if(argc<3){
	 fprintf(stderr, "Uso: %s <poner 0 para convertir a binario" 
		 " y 1 para convertir a decimal> <numero>\n", argv[0]);
	 exit(EXIT_FAILURE);
     }

}
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
    //comprueba que hay suficientes parametros
    comprobar_parametros(argc, argv);
    int numero = atoi(argv[2]),
	eleccion = atoi(argv[1]);
    //en funcion de la eleccion hace una conversion u otra
    if(eleccion == 0)
	printf("decimal:%i ---- binario:%i \n", numero, to_binario(numero));
    else
        printf("binario:%i ---- decimal:%i \n", numero, to_decimal(numero));

    return EXIT_SUCCESS;
}
