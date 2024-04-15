#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool checkSyntax(const string& line) {
	vector<char> stack;
	
	for (char c : line) {
		if (c == '(' || c == '{' || c == '[') {
			stack.push_back(c);
		} else if (c == ')' || c == '}' || c == ']') {
			if (stack.empty()) {
				return false;
			}
			
			char top = stack.back();
			stack.pop_back();
			
			if ((c == ')' && top != '(') ||
				(c == '}' && top != '{') ||
				(c == ']' && top != '[')) {
				return false;
			}
		}
	}
	
	return stack.empty();
}

int main() {
	string filename;
	cout << "Ingrese el nombre del archivo .c: ";
	cin >> filename;
	
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "No se pudo abrir el archivo." <<endl;
		return 1;
	}
	
	string line;
	int lineNumber = 0;
	bool syntaxError = false;
	
	while (getline(file, line)) {
		lineNumber++;
		if (!checkSyntax(line)) {
			syntaxError = true;
			cout << "Error de sintaxis en la línea " << lineNumber << ": " << line << endl;
		}
	}
	
	if (!syntaxError) {
		cout << "No se encontraron errores de sintaxis." << endl;
	}
	
	file.close();
	return 0;
}
