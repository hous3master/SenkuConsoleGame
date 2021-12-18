#include "Menu.h"
Menu::Menu() {}
Menu::~Menu() {}
void Menu::Draw() {
    cout << "Menú - Juego Senku\n";
    cout << "---------------------------------------\n";
    cout << "1. Estilo inglés\n";
    cout << "2. Estilo asimétrico\n";
    cout << "3. Estilo alemán\n";
    cout << "---------------------------------------\n";
    cout << "0. Salir del Programa\n\n";
    
}
void Menu::new_option() { 
    do
    {
        cout << "Seleccionar la opción: "; cin >> option;
    } while (option < 0 || option > 3);
    system("cls");
}
int Menu::return_option() { return option; }