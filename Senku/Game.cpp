#include "Game.h"
Game::Game(style new_style) {
    game_style = new_style;
    error_temp = false;
    if (game_style == style::english) {
        for (int height = 0; height < 7; height++) {
            for (int widht = 0; widht < 7; widht++) {
                if (widht >= 2 && widht <= 4)
                    arrFichas.push_back(new Ficha(widht, height));
                else if (height >= 2 && height <= 4)
                    arrFichas.push_back(new Ficha(widht, height));
            }
        }
        arrFichas.erase(arrFichas.begin() + 16);
    }
    else if (game_style == style::asimetric) {
        for (int height = 0; height < 8; height++) {
            for (int widht = 0; widht < 8; widht++) {
                if (widht >= 2 && widht <= 4)
                    arrFichas.push_back(new Ficha(widht, height));
                else if (height >= 3 && height <= 5)
                    arrFichas.push_back(new Ficha(widht, height));
            }
        }
        arrFichas.erase(arrFichas.begin() + 20);
    }
    else if (game_style == style::german) {
        for (int height = 0; height < 9; height++) {
            for (int widht = 0; widht < 9; widht++) {
                if (widht >= 3 && widht <= 5)
                    arrFichas.push_back(new Ficha(widht, height));
                else if (height >= 3 && height <= 5)
                    arrFichas.push_back(new Ficha(widht, height));
            }
        }
        arrFichas.erase(arrFichas.begin() + 22);
    }
}
Game::~Game(){}
void Game::Print() {
    if (game_style == style::english) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
        cout << " 1234567\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        for (int height = 0; height < 7; height++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
            cout << height + 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int widht = 0; widht < 7; widht++) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
                bool temp = true;
                for (int i = 0; i < arrFichas.size() && temp; i++) {
                    if (arrFichas.at(i)->return_x() == widht && arrFichas.at(i)->return_y() == height) {
                        cout << "O";
                        temp = false;
                    }
                }
                if (temp)
                    cout << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            cout << "\n";
        }
    }
    else if (game_style == style::asimetric) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
        cout << " 12345678\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        for (int height = 0; height < 8; height++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
            cout << height + 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int widht = 0; widht < 8; widht++) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
                bool temp = true;
                for (int i = 0; i < arrFichas.size() && temp; i++) {
                    if (arrFichas.at(i)->return_x() == widht && arrFichas.at(i)->return_y() == height) {
                        cout << "O";
                        temp = false;
                    }
                }
                if (temp)
                    cout << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            cout << "\n";
        }
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
        cout << " 123456790\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        for (int height = 0; height < 9; height++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
            cout << height + 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            for (int widht = 0; widht < 9; widht++) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
                bool temp = true;
                for (int i = 0; i < arrFichas.size() && temp; i++) {
                    if (arrFichas.at(i)->return_x() == widht && arrFichas.at(i)->return_y() == height) {
                        cout << "O";
                        temp = false;
                    }
                }
                if (temp)
                    cout << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            cout << "\n";
        }
    }
}
void Game::Request_Input() {
    cout << "\n\n";
    int row_origin, column_origin, row_destination, column_destination;
    cout << "Ingrese la posición de origen (fila): ";
    cin >> row_origin;
    cout << "Ingrese la posición de origen (columna): ";
    cin >> column_origin;
    cout << "Ingrese la posición de destino (fila): ";
    cin >> row_destination;
    cout << "Ingrese la posición de destino (columna): ";
    cin >> column_destination;
    if (Valid_Movement(column_origin - 1, row_origin - 1, column_destination - 1, row_destination - 1))
        Move(column_origin - 1, row_origin - 1, column_destination - 1, row_destination - 1);
    else error_temp = true;
}
bool Game::Valid_Movement(int x_origin, int y_origin, int x_destination, int y_destination) {
    //Not valid inputs
    if (x_destination <= 0 || y_destination <= 0 || x_origin <= 0 || y_origin <= 0)
        return false;
    //Region out of boundaries
    if (game_style == style::english) {
        if (x_destination <= 1 && y_destination <= 1)
            return false;
        if (x_destination >= 5 && y_destination <= 1)
            return false;
        if (x_destination <= 1 && y_destination >= 5)
            return false;
        if (x_destination >= 5 && y_destination >= 5)
            return false;
    }
    else if (game_style == style::asimetric) {
        if (x_destination <= 1 && y_destination <= 2)
            return false;
        if (x_destination >= 5 && y_destination <= 2)
            return false;
        if (x_destination <= 1 && y_destination >= 6)
            return false;
        if (x_destination >= 5 && y_destination >= 6)
            return false;
    }
    else {
        if (x_destination <= 2 && y_destination <= 2)
            return false;
        if (x_destination >= 6 && y_destination <= 2)
            return false;
        if (x_destination <= 2 && y_destination >= 6)
            return false;
        if (x_destination >= 6 && y_destination >= 6)
            return false;
    }
    //Destination already occupied
    for (int i = 0; i < arrFichas.size(); i++) {
        if (arrFichas.at(i)->return_x() == x_destination && arrFichas.at(i)->return_y() == y_destination)
            return false;
    }
    //Origin is empty
    bool empty = true;
    for (int i = 0; i < arrFichas.size(); i++) {
        if (arrFichas.at(i)->return_x() == x_origin && arrFichas.at(i)->return_y() == y_origin)
            empty = false;
    }
    if (empty)
            return false;
    //Piece is able to jump
    if (((x_destination - x_origin == 2) || (x_destination - x_origin == -2)) && (y_destination == y_origin))
        return true;
    else if (((y_destination - y_origin == 2) || (y_destination - y_origin == -2)) && (x_destination == x_origin))
        return true;
    else
        return false;
    return true;
}
void Game::Delete_Surpassed_Pieces(int x_origin, int y_origin, int x_destination, int y_destination) {
    //Mark up the in between piece and then delete it
    int x_to_del, y_to_del;
    x_to_del = (x_origin + x_destination) / 2;
    y_to_del = (y_origin + y_destination) / 2;
    for (int i = 0; i < arrFichas.size(); i++) {
        if (arrFichas.at(i)->return_x() == x_to_del && arrFichas.at(i)->return_y() == y_to_del)
            arrFichas.at(i)->new_flag(true);
    }
    //Erase
    for (int i = 0; i < arrFichas.size(); i++) {
        if (arrFichas.at(i)->return_flag()) {
            arrFichas.erase(arrFichas.begin() + i);
        }
    }
}
void Game::Move(int x_origin, int y_origin, int x_destination, int y_destination) {
    int IDX = 0;
    for (int i = 0; i < arrFichas.size(); i++) {
        if (arrFichas.at(i)->return_x() == x_origin && arrFichas.at(i)->return_y() == y_origin) {
            IDX = i;
            break;
        }
    }
    arrFichas.at(IDX)->new_x(x_destination);
    arrFichas.at(IDX)->new_y(y_destination);
    Delete_Surpassed_Pieces(x_origin, y_origin, x_destination, y_destination);   
}
string Game::Error_Message(){
    string text = "\n";
    if (error_temp) {
        error_temp = false;
        text = "\nERROR: Movimiento no válido detectado";
    }
    return text;
}
bool Game::End_Game() {
    if (arrFichas.size() <= 1)
        return true;
    return false;
}