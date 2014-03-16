#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void  pedir_host_red(int intermediario, int *redes, int bit_host[]){
    //Pide los host por red

    for(int pedir_host=0; intermediario != -1; pedir_host ++){
	printf("Introduzca la cantidad de host de red: ");
	scanf(" %i", &intermediario);
	if(intermediario > 0){
	    bit_host[pedir_host] = intermediario;
	    (*redes)++;
	}
    }

}
void seleccion_de_red(int suma_bits, int ip[], int *octetos_editables){

    if(suma_bits <= exp2 (8) - 2){
	//printf("Clase C\n");
	ip[0] = 192;
	ip[1] = 168;
	ip[2] = 1;
	ip[3] = 0;
	*octetos_editables = 3;
    }
    else
	if(suma_bits <= exp2 (16) - 2){
	    //  printf("Clase B\n");
	    ip[0] = 172;
	    ip[1] = 16;
	    ip[2] = 0;
	    ip[3] = 0;
	    *octetos_editables = 2;

	}
	else{
	    //printf("Clase A\n");
	    ip[0] = 10;
	    ip[1] = 0;
	    ip[2] = 0;
	    ip[3] = 0;
	    *octetos_editables = 1;

	}

}
void calcular_bits_host_por_red(int bit_host[], int redes, int *suma_bits, int host_red[]){

    for(int calculo = 0; calculo<redes; calculo ++){
	bool bits_encontrados=false;
	for(int exponente=0; bits_encontrados!=true; exponente++)
	    if(bit_host[calculo] <= (exp2 (exponente)) - 2 ){
		bit_host[calculo] = exponente;
		host_red[calculo] = (exp2 (exponente) - 2);
		bits_encontrados = true;
	    }
    }
    //suma el total de bits 
    for(int suma = 0; suma < redes; suma ++)
	(*suma_bits) += exp2 (bit_host[suma]) - 2;
}
void calcular_mascara_subred(int mascara_abrebiada, int mascara[]){

    int mascara_temporal;
    for(int reiniciar=0; reiniciar<4; reiniciar++)
	mascara[reiniciar] = 0;
    mascara_temporal = mascara_abrebiada;
    for(int restar=0; mascara_temporal >0; restar++){

	if(mascara_temporal> 8){
	    mascara_temporal -= 8;
	    for(int expo=0; expo<8; expo++)
		mascara[restar] += exp2 (expo);
	}
	else{
	    for(int expo=7; expo>=8-mascara_temporal; expo--)
		mascara[restar] += exp2(expo);
	    mascara_temporal -= mascara_temporal;
	}
    }

}

int main (int argc, char *argv[]){
    int ip[4],
	mascara_subred[4],
	clase,
	octetos_editables;

    int	bit_host[20],
	suma_bits,
	host_red[20],
	intermediario,
	redes,
	mascara_abrebiada[21],
	mascara[]={0,0,0,0};

    redes = 0;
    intermediario = 0;
    suma_bits = 0;

    pedir_host_red(intermediario, &redes, bit_host);

    calcular_bits_host_por_red(bit_host, redes, &suma_bits, host_red);

    seleccion_de_red(suma_bits, ip, &octetos_editables);

    for(int x=0; x<redes; x++)
	mascara_abrebiada[x] = 32 - bit_host[x];

    int broadcast;
    for(int mostrar_redes=0; mostrar_redes<redes; mostrar_redes++){
	broadcast = host_red[mostrar_redes] +1;

	printf("red: ");
	for(int red=0; red<4; red ++)
	    if(red != 3)
		printf("%i.",ip[red]);
	    else
		printf("%i ",ip[red]);

	for(int octetos=3; octetos>=octetos_editables; octetos--)
	    if(ip[octetos] + broadcast < 255){
		ip[octetos] += broadcast;
		break;
	    }
	    else
		ip[octetos] = 0;
	    
	printf("----------- broadcast: ");
	for(int red=0; red<4; red ++)
	    if(red != 3)
		printf("%i.",ip[red]);
	    else
		printf("%i ",ip[red]);

	for(int octetos=3; octetos>=octetos_editables; octetos--)
	    if(ip[octetos] + 1 < 255){
		ip[octetos] ++;
		break;
	    }
	    else
		ip[octetos] = 0;
	printf("\n");

    }

    /*//comprobaciones
      printf("Bits por red\n");
      for(int x=0; x<redes; x++)
      printf(" %i /%i %i --", bit_host[x], mascara_abrebiada[x], host_red[x]);
      printf("\n");

      printf("Direccion de red\n");
      for(int x=0; x<4; x++)
      printf("%i.", ip[x]);
      printf("/%i\n", mascara_abrebiada[0]);

      printf("Numero total de bits de host \n %i \n", suma_bits);

      printf("bit: %i, /%i, mas: %i.%i.%i.%i\n", bit_host[1], mascara_abrebiada[1], mascara[0], mascara[1], mascara[2], mascara[3]);
     */

    return EXIT_SUCCESS;
}
