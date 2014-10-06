/*Daniel Fernandez*/
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

int spawn(const char *programa, char **argumentos){
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

void copiar(char **a, char *p){
    *a = (char *) malloc(30 * sizeof(char *));
    strcpy(*a, p);
}

int arg(char **argumentos, char *programa){
    char palabra[20];
    copiar(argumentos, programa);
    *argumentos++;
    int n_argumentos = 1;
    //for(int i=0; strcmp(palabra, "fin") != 0; i++){
    while(strcmp(palabra, "fin") != 0){
	scanf(" %s", palabra);
	if(strcmp(palabra, "fin") != 0){
	    copiar(argumentos, palabra);
	    *argumentos++;
	    n_argumentos ++;
	}
    }
    *argumentos = '\0';
    return n_argumentos;
}

void liberar(char **a, int n_argumentos){
    for(int i=0; i<n_argumentos; i++)
       free(a[i]);
}

int main(int argc, char * argv[]){
    int respuesta, n_argumentos;
    char *argumentos[20];

    mostrar_menu();
    scanf("%i", &respuesta);
    switch(respuesta){
	case 1: 
	    n_argumentos = arg(argumentos, "firefox");
	    spawn("firefox", argumentos);
	    break;
	case 2:
	    printf("ls\n");
	    n_argumentos = arg(argumentos, "ls");
	    spawn("ls", argumentos);
	    break;
	default:
	    return EXIT_SUCCESS;
	    break;
    }

    liberar(argumentos, n_argumentos);
    printf("Padre muerto\n");
    return EXIT_SUCCESS;
}
