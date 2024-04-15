#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quickSort(vector<string*>& lines, int left, int right) {
	if (left < right) {
		int pivotIndex = left + (right - left) / 2;
		string* pivot = lines[pivotIndex];
		int i = left;
		int j = right;
		
		while (i <= j) {
			while (*lines[i] < *pivot) {
				i++;
			}
			while (*lines[j] > *pivot) {
				j--;
			}
			if (i <= j) {
				swap(lines[i], lines[j]);
				i++;
				j--;
			}
		}
		
		if (left < j) {
			quickSort(lines, left, j);
		}
		if (i < right) {
			quickSort(lines, i, right);
		}
	}
}

int main() {
	vector<string*> lines;
	
	cout << "Ingrese las líneas de texto presione Ctrl+D para terminar:" << endl;
	
	string line;
	while (getline(cin, line)) {
		lines.push_back(new string(line));
	}
	
	quickSort(lines, 0, lines.size() - 1);
	
	cout << "\nTexto ordenado:\n";
	for (const auto& strPtr : lines) {
		cout << *strPtr << endl;
		delete strPtr; // Liberar la memoria asignada a cada línea
	}
	
	return 0;
}
