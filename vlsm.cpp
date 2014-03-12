#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]){
    int ip[4],
	mascara_subred[4],
	clase,
	bit_host[20],
	intermediario,
	redes,
	mascara_abrebiada;

    redes = 0;
    intermediario = 0;
    mascara_abrebiada = 32;

    printf("Introduzca la IP: ");
    scanf(" %i.%i.%i.%i", &ip[0], &ip[1], &ip[2], &ip[3]);

    //
    for(int pedir_host=0; intermediario != -1; pedir_host ++){
	printf("Introduzca la cantidad de host de red: ");
	scanf(" %i", &intermediario);
	if(intermediario > 0){
	    bit_host[pedir_host] = intermediario;
	    redes++;
	}
    }

    for(int bits=0; bits<redes; bits++)
	for(int numero_bits=1; numero_bits<=8; numero_bits++)
	    if(bit_host[bits] < exp2 (numero_bits)){
		bit_host[bits] = numero_bits;
		break;
	    }
    printf("1º red: %i.%i.%i.%i/%i ", ip[0], ip[1], ip[2],
	    ip[3], mascara_abrebiada - bit_host[0]);
    printf("Bro:%i.%i.%i.%i", ip[0], ip[1], ip[2], ip[3]+exp2(bit_host[0]));

    //comprueba a que clase pertenece la ip introducida por el usuario
    if(ip[0]<128)
	clase = 1;
    else
	if(ip[0]<192) 
	    clase = 2;
	else
	    clase = 3;



    return EXIT_SUCCESS;
}
