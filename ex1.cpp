#include <iostream>
#include <string>
#include <unistd.h>
#include <windows.h>

using namespace std;

void print_centered(string texto) {
    int esp = (80 - texto.length()) / 2;
    for (int i = 0; i < esp; i++) {
        cout << " ";
    }
    cout << texto << endl;
}

void gotoxy(short x, short y){
COORD position = {x, y};
SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main() {

    cout << "Digite uma mensagem de 1 a 15 caracteres: ";
    string msg;
    getline(cin, msg);
	
	gotoxy(5,1);
	
	print_centered(msg);
	
    for (int linha = 6; linha <= 20; linha++) {
        for (int i = 0; i < msg.length(); i++) {
            if (linha >= (i + 6)) {
                cout << msg[i];
            } else {
                cout << " ";
            }
            
        }
        cout << endl;
    }

    return 0;
}