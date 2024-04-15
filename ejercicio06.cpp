#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void collatz(int n) {
	printf("%d, ", n);
	while (n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
		} else {
			n = 3 * n + 1;
		}
		printf("%d, ", n);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Uso: %s <numero>\n", argv[0]);
		return 1;
	}
	
	int num = atoi(argv[1]);
	if (num <= 0) {
		fprintf(stderr, "Error: El número debe ser un entero positivo.\n");
		return 1;
	}
	
	pid_t pid = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Error al crear el proceso hijo.\n");
		return 1;
	} else if (pid == 0) {
		// Proceso hijo
		collatz(num);
	} else {
		// Proceso padre
		wait(NULL);
	}
	
	return 0;
}
