#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int c;
	int wordCount = 0;
	int inWord = 0;
	
	cout << "Ingrese un texto y presione Ctrl+D para terminar:\n";
	
	// Leer caracteres uno por uno hasta llegar al final del archivo (EOF)
	while ((c = getchar()) != EOF) {
		// Si el carácter es un espacio, un salto de línea o un tabulador, y estamos dentro de una palabra,
		// incrementamos el contador de palabras y establecemos que no estamos dentro de una palabra
		if (c == ' ' || c == '\n' || c == '\t') {
			if (inWord) { 
				inWord = 0;
				wordCount++;
			}
		} else { // Si el carácter no es un espacio, un salto de línea o un tabulador, establecemos que estamos dentro de una palabra
			inWord = 1;
		}
	}
	
	// Si estamos dentro de una palabra al llegar al final del archivo, incrementamos el contador de palabras
	if (inWord) {
		wordCount++;
	}
	
	cout << "Cantidad de palabras ingresadas: " << wordCount << endl;
	
	return 0;
}
