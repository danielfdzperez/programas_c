/*Cuenta e imprime en orden alfabetico la cantidad de veces que aparece cada
  letra de una palabra/frase*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comprobar_parametros(int argc, char *argv[]){
    //comprueba que hay parametros suficientes para ejecutar el programa
    if(argc < 2 || argc > 2){
	fprintf(stderr, "Uso: %s <palabra o frase entre comillas dobles> \n", argv[0]);
	exit(EXIT_FAILURE);
    }
}

void restaurar_puntero(int tamano, char *argv[]){
    //devuelve a su posicion inicial el puntero argv.
    for(int restaurar=0; restaurar<tamano; restaurar++)
	*argv[1]--;
}

void guardar_letras(char *argv[], char letras[], int *cantidad_letras, int tamano){
    //guarda las letras, sin repetirlas en una varieble.
    for(int guardar=0; guardar<tamano; guardar++){
	int diferente = 0;

	for(int comparar=0; comparar<tamano; comparar++)
	    if(*argv[1] != letras[comparar])
		diferente ++;

	if(diferente == tamano)
	    for(int introducir=0; introducir<tamano; introducir++)
		if(letras[introducir] == '0'){
		    letras[introducir] = *argv[1];
		    (*cantidad_letras) ++;
		    break;

		}
	*argv[1]++;
    }

}

void ordenar_letras(int cantidad_letras, char orden_alfabetico[], char letras[]){
    //ordena las letras alfabeticamente en una variable.
    int comparador_palabras;
    char letra_temporal; 
    
    for(int ordenar=0; ordenar<cantidad_letras; ordenar++){
	for(int comparacion=ordenar+1; comparacion<cantidad_letras; comparacion++){
	    comparador_palabras = letras[ordenar] - letras[comparacion];
	    if(comparador_palabras > 0){
		letra_temporal = letras[ordenar];
		letras[ordenar] = letras[comparacion];
		letras[comparacion] = letra_temporal;
	    }
	}
	orden_alfabetico[ordenar] = letras[ordenar]; 
    }

}

void contar_letras(int cantidad_letras, int tamano, char orden_alfabetico[], char *argv[]){
    //imprime y cuenta las letras.
    int letra_igual;
    for(int letra=0; letra<cantidad_letras; letra++){
	letra_igual=0;
	for(int contar=0; contar<tamano; contar++){
	    if(orden_alfabetico[letra] == *argv[1])
		letra_igual ++;
	    *argv[1]++;
	}

	printf("%c - %i\n", orden_alfabetico[letra], letra_igual);
	restaurar_puntero(tamano, argv);
    }
}

int main(int argc, char *argv[]){

    comprobar_parametros(argc, argv);
    int tamano = (unsigned) strlen(argv[1]),
	cantidad_letras=0;

    char letras[tamano];
    bool econtrado;


    for(int inicializa=0; inicializa<tamano; inicializa++)
	letras[inicializa]='0';

    guardar_letras(argv, letras, &cantidad_letras, tamano);

    char orden_alfabetico[cantidad_letras];

    ordenar_letras(cantidad_letras, orden_alfabetico, letras);

    restaurar_puntero(tamano, argv);

    contar_letras(cantidad_letras, tamano, orden_alfabetico, argv);

    return EXIT_SUCCESS;
}
