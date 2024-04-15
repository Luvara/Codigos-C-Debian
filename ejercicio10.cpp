#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Uso: %s <texto>\n", argv[0]);
		return 1;
	}
	
	char texto[BUFFER_SIZE];
	strcpy(texto, argv[1]);
	
	int pipefd[2]; // File descriptors para la tubería
	
	if (pipe(pipefd) == -1) {
		perror("pipe");
		return 1;
	}
	
	pid_t pid = fork();
	
	if (pid == -1) {
		perror("fork");
		return 1;
	}
	
	if (pid == 0) {
		// Proceso hijo
		close(pipefd[0]); // Cerramos el descriptor de lectura en el proceso hijo
		
		// Escribir el texto en la tubería
		if (write(pipefd[1], texto, strlen(texto)) == -1) {
			perror("write");
			return 1;
		}
		
		close(pipefd[1]); // Cerramos el descriptor de escritura en el proceso hijo
		exit(0);
	} else {
		// Proceso padre
		close(pipefd[1]); // Cerramos el descriptor de escritura en el proceso padre
		
		char buffer[BUFFER_SIZE];
		ssize_t nbytes;
		
		// Leer el texto desde la tubería
		if ((nbytes = read(pipefd[0], buffer, BUFFER_SIZE)) == -1) {
			perror("read");
			return 1;
		}
		
		printf("Texto recibido por el proceso padre: %.*s\n", (int)nbytes, buffer);
		
		close(pipefd[0]); // Cerramos el descriptor de lectura en el proceso padre
	}
	
	return 0;
}
