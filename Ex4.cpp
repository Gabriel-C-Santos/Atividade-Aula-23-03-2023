#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

string CitacaoBiblio (string msg) {
	int tamanho = msg.size();
	int espacofinal = 0;
	int espacoinicial = msg.find(" ");
	
	string sobrenome = "";
	
	for (int i = 0; i < tamanho; i++) {
		if (msg[i] == ' ') {
			espacofinal = i;
		}
	}
	for (int i = 0; i < tamanho; i++) {
		if (msg[i] == ' ' && i != espacofinal) {
			sobrenome += msg[i + 1];
			sobrenome += ". ";
		}
	}
	string nome = "";
	string Nome1 = "";

	for (int i = 0; i < tamanho; i++) {
		
		if (i > espacofinal) {
			nome += msg[i];
		}
		if (i < espacoinicial) {
			Nome1 += msg[i];
		}
		
	}
	for (auto & c: nome) c = toupper(c);
	return nome + ", " + Nome1 + " " + sobrenome;
}

int main () {
	setlocale(LC_ALL, "");
	string linha;
	ifstream arq("nomes.txt");
	
	if (arq.is_open()) {
		while (! arq.eof()) {
			getline(arq, linha);
			cout << CitacaoBiblio(linha) << endl;
		}
		arq.close();
	}
	else {
		cout << "Erro ao abrir o arquivo";
	}
	
	return 1;
}
