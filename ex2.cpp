#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Função que transforma um nome para o formato de agenda telefônica
string transformar_nome(string nome) {
    string sobrenome, resto;
    // Encontra o último sobrenome
    size_t pos = nome.find_last_of(" ");
    if (pos != string::npos) {
        sobrenome = nome.substr(pos+1);
        resto = nome.substr(0, pos);
    } else {
        sobrenome = nome;
        resto = "";
    }
    // Coloca o sobrenome na frente do nome
    return sobrenome + ", " + resto;
}

int main() {
    // Abre o arquivo de entrada
    ifstream entrada("nomes.txt");
    if (!entrada.is_open()) {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
        return 1;
    }
    // Abre o arquivo de saída
    ofstream saida("nomes_transformados.txt");
    if (!saida.is_open()) {
        cout << "Erro ao abrir o arquivo de saída" << endl;
        return 1;
    }
    // Lê cada nome do arquivo de entrada, transforma e escreve no arquivo de saída
    string nome;
    while (getline(entrada, nome)) {
        string nome_transformado = transformar_nome(nome);
        saida << nome_transformado << endl;
    }
    // Fecha os arquivos
    entrada.close();
    saida.close();
    return 0;
}