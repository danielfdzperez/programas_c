#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int numero[4],
	mascara[4],
	red[4];

    //asigna un valor a la ip y a la mascara
    for(int ip=0; ip<4; ip++){
	numero[ip] = atoi(argv[ip+1]);
        mascara[ip] = atoi(argv[ip+5]);
    }
    //hace la funcion logica and de la ip con la mascara
    for(int and_logico=0; and_logico<4; and_logico++)
	red[and_logico] = numero[and_logico] & mascara[and_logico];

    //imprime a la red que pertenece
    for(int imprimir=0; imprimir<4; imprimir++)
	if(imprimir == 3)
	    printf("%i", red[imprimir]);
	else
	    printf("%i.", red[imprimir]);
    printf("\n");

    return EXIT_SUCCESS;
}
