#include "Menu.h"
Menu::Menu() {}
Menu::~Menu() {}
void Menu::Draw() {
    cout << "Men� - Juego Senku\n";
    cout << "---------------------------------------\n";
    cout << "1. Estilo ingl�s\n";
    cout << "2. Estilo asim�trico\n";
    cout << "3. Estilo alem�n\n";
    cout << "---------------------------------------\n";
    cout << "0. Salir del Programa\n\n";
    
}
void Menu::new_option() { 
    do
    {
        cout << "Seleccionar la opci�n: "; cin >> option;
    } while (option < 0 || option > 3);
    system("cls");
}
int Menu::return_option() { return option; }