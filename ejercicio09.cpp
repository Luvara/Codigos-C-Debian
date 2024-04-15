#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUM 100

int fibonacci[MAX_NUM];

void *calcular_fibonacci(void *n) {
	int num = *((int*)n);
	
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	
	for (int i = 2; i <= num; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Uso: %s <numero>\n", argv[0]);
		return 1;
	}
	
	int num = atoi(argv[1]);
	if (num < 0 || num >= MAX_NUM) {
		fprintf(stderr, "Error: El número debe ser un entero positivo menor a %d.\n", MAX_NUM);
		return 1;
	}
	
	pthread_t thread;
	int rc;
	
	rc = pthread_create(&thread, NULL, calcular_fibonacci, (void*)&num);
	if (rc) {
		fprintf(stderr, "Error al crear el hilo. Código de error: %d\n", rc);
		return 1;
	}
	
	pthread_join(thread, NULL);
	
	printf("Secuencia de Fibonacci para %d:\n", num);
	for (int i = 0; i <= num; i++) {
		printf("%d ", fibonacci[i]);
	}
	printf("\n");
	
	return 0;
}
