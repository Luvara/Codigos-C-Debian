#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_DEPOSITOS 10

pthread_mutex_t mutex;
double saldo = 0;

void* depositar(void* arg) {
	double cantidad = *((double*)arg);
	pthread_mutex_lock(&mutex); // Bloquear el mutex antes de realizar la operación crítica
	saldo += cantidad;
	printf("Cantidad depositada: %.2f\n", cantidad);
	pthread_mutex_unlock(&mutex); // Desbloquear el mutex después de realizar la operación crítica
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_DEPOSITOS];
	double cantidades[NUM_DEPOSITOS] = {100, 200, 150, 300, 250, 180, 220, 170, 190, 210};
	
	if (pthread_mutex_init(&mutex, NULL) != 0) {
		fprintf(stderr, "Error al inicializar el mutex\n");
		return 1;
	}
	
	for (int i = 0; i < NUM_DEPOSITOS; i++) {
		if (pthread_create(&threads[i], NULL, depositar, (void*)&cantidades[i]) != 0) {
			fprintf(stderr, "Error al crear el hilo %d\n", i);
			return 1;
		}
	}
	
	for (int i = 0; i < NUM_DEPOSITOS; i++) {
		pthread_join(threads[i], NULL);
	}
	
	printf("Saldo final de la cuenta: %.2f\n", saldo);
	
	pthread_mutex_destroy(&mutex);
	
	return 0;
}
