#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void imprimir_uso(const char *nombre_programa){
    fprintf(stderr, "\nUso: %s [opciones] <numero ip separado por espacios>"
	    " <mascara de red separa por espacioes>"
	    "\n"
	    "\n"
	    "\n\tOPTIONS"
	    "\n\t======="
	    "\n\t\t -h muestra la ayuda"
	    "\n\n", 
	    nombre_programa);
}

int main(int argc, char *argv[]){

    
    
    int numero[4],
	mascara[4],
	red[4];
    int opciones;
    bool imprimir_ayuda = false,
	 ayuda_impresa = false;

    while((opciones = getopt(argc, argv, "h")) != -1)
	switch(opciones){
	    case 'h':
		imprimir_ayuda = true;
		break;
	    case '?':
		imprimir_ayuda = true;
		break;
	}

    if(imprimir_ayuda == true){
	imprimir_uso(argv[0]);
        ayuda_impresa = true;
    }

    if(argc - optind < 8){
	if(ayuda_impresa == false)
	    imprimir_uso(argv[0]);
	return EXIT_FAILURE;
    }
    //asigna un valor a la ip y a la mascara
    for(int ip=0; ip<4; ip++){
	numero[ip] = atoi(argv[ip+optind]);
	mascara[ip] = atoi(argv[ip+4+optind]);
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
