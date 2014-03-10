/*Programa calcula una mascara de red*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void comprobar_parametros(int argc, char *argv[]){
    if(argc < 2){
      fprintf(stderr, "Uso: %s <mascara abrebiada>\n", argv[0]);
      exit(EXIT_FAILURE);
    }
}

int main (int argc, char *argv[]){
    comprobar_parametros(argc, argv);
    int mascara_abrebiada = atoi(argv[1]),
	mascara[4]={0, 0, 0, 0,};

    //resta 8 a la mascara hasta que esta sea menor que 8 y calcula los bits restantes
    for(int restar=0; mascara_abrebiada >0; restar++){

	if(mascara_abrebiada > 8){
	  mascara_abrebiada -= 8;
          for(int expo=0; expo<8; expo++)
	      mascara[restar] += exp2 (expo);
	}
	else{
	    for(int expo=7; expo>=8-mascara_abrebiada; expo--)
		mascara[restar] += exp2(expo);
	    mascara_abrebiada -= mascara_abrebiada;
	}
    }
    //imprime la cascara por pantalla
    for(int imprimir=0; imprimir<4; imprimir++)
	printf("%i.", mascara[imprimir]);
    printf("\n");
    return EXIT_SUCCESS;
}
