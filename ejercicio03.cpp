#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	const int BUFFER_SIZE = 1000; // Tama�o del buffer
	char* buffer = new char[BUFFER_SIZE]; // Crear un buffer din�mico para almacenar el texto
	int index = 0; // �ndice para recorrer el buffer
	
	cout << "Ingrese un texto y presione Ctrl+D para terminar:\n";
	
	int c;
	// Leer caracteres uno por uno hasta llegar al final del archivo (EOF)
	while ((c = getchar()) != EOF) {
		// Si el car�cter no es un espacio ni un tabulador, agregarlo al buffer
		if (c != ' ' && c != '\t') {
			buffer[index++] = c;
		}
	}
	
	// A�adir el car�cter nulo al final del buffer para formar una cadena de caracteres v�lida
	buffer[index] = '\0';
	
	// Imprimir el texto resultante sin espacios en blanco ni tabuladores
	cout << "Texto sin espacios en blanco ni tabuladores:\n";
	cout << buffer << endl;
	
	// Liberar la memoria asignada al buffer
	delete[] buffer;
	
	return 0;
}
