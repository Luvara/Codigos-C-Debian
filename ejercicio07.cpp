#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Uso: %s <numero_de_procesos_hijos>\n", argv[0]);
		return 1;
	}
	
	int num_hijos = atoi(argv[1]);
	if (num_hijos <= 0) {
		fprintf(stderr, "Error: El número de procesos hijos debe ser un entero positivo.\n");
		return 1;
	}
	
	pid_t pid;
	int i;
	
	printf("Proceso padre: PID = %d, PPID = %d\n", getpid(), getppid());
	
	for (i = 0; i < num_hijos; i++) {
		pid = fork();
		
		if (pid < 0) {
			fprintf(stderr, "Error al crear el proceso hijo.\n");
			return 1;
		} else if (pid == 0) {
			// Proceso hijo
			printf("Hijo #%d:   PID = %d, PPID = %d\n", i + 1, getpid(), getppid());
			return 0;
		}
	}
	
	// Proceso padre espera a que todos los hijos terminen
	for (i = 0; i < num_hijos; i++) {
		wait(NULL);
	}
	
	return 0;
}
