#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void mostrar_menu(){
    printf("Ejemplo exec:\n\
	    1-firefox\n\
	    2-ls\n\
	    3-Salir\n");
}

int spawn(const char * programa, char **argumentos){
    pid_t pid_hijo = 0;
    pid_hijo = fork();

    if(pid_hijo != 0)
	return pid_hijo;
    else{
	execvp(programa, argumentos);
	fprintf(stderr, "Error de execvp\n");
	abort();
    }
}

int main(int argc, char * argv[]){
    int respuesta;
    char argumentos[10][20];
    mostrar_menu();
    scanf("%i", &respuesta);
    switch(respuesta){
	case 1: 
	    for(int i=0; i<2; i++){
		int byte;
		byte = scanf(" %s", argumentos[i]);
		printf("%i\n", byte);
		argumentos[5] = NULL;
	    }
	    //spawn("firefox", argumentos);
	    break;
	case 2:
	    printf("ls\n");
	    break;
	default:
	    return EXIT_SUCCESS;
	    break;
    }
    printf("Padre muerto\n");
    return EXIT_SUCCESS;
}
