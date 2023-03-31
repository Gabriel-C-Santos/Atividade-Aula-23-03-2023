#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

string AgendaTel (string msg) {
	int tamanho = msg.size();
	int espaco = 0;
	for (int i = 0; i < tamanho; i++) {
		if (msg[i] == ' ') {
			espaco = i;
		}
	}

	string sobrenome = "";
	string nome = "";

	for (int i = 0; i < tamanho; i++) {
		if (i < espaco) {
			sobrenome += msg[i];
		}
		if (i > espaco) {
			nome += msg[i];
		}
		
	}
	return nome + ", " + sobrenome;
}

int main () {
	setlocale(LC_ALL, "");
	string linha;
	ifstream arq("nomes.txt");
	
	if (arq.is_open()) {
		while (! arq.eof()) {
			getline(arq, linha);
			cout << AgendaTel(linha) << endl;
		}
		arq.close();
	}
	else {
		cout << "Erro ao abrir o arquivo";
	}
	
	return 1;
}