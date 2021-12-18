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
        cout << " 1234567\n";
        for (int height = 0; height < 7; height++) {
            cout << height + 1;
            for (int widht = 0; widht < 7; widht++) {
                bool temp = true;
                for (int i = 0; i < arrFichas.size() && temp; i++) {
                    if (arrFichas.at(i)->return_x() == widht && arrFichas.at(i)->return_y() == height) {
                        cout << "0";
                        temp = false;
                    }
                }
                if (temp)
                    cout << " ";
            }
            cout << "\n";
        }
    }
    else if (game_style == style::asimetric) {
        cout << " 12345679\n";
        for (int height = 0; height < 8; height++) {
            cout << height + 1;
            for (int widht = 0; widht < 8; widht++) {
                bool temp = true;
                for (int i = 0; i < arrFichas.size() && temp; i++) {
                    if (arrFichas.at(i)->return_x() == widht && arrFichas.at(i)->return_y() == height) {
                        cout << "0";
                        temp = false;
                    }
                }
                if (temp)
                    cout << " ";
            }
            cout << "\n";
        }
    }
    else {
        cout << " 123456789\n";
        for (int height = 0; height < 9; height++) {
            cout << height + 1;
            for (int widht = 0; widht < 9; widht++) {
                bool temp = true;
                for (int i = 0; i < arrFichas.size() && temp; i++) {
                    if (arrFichas.at(i)->return_x() == widht && arrFichas.at(i)->return_y() == height) {
                        cout << "0";
                        temp = false;
                    }
                }
                if (temp)
                    cout << " ";
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
    //Jump up
    if (y_destination < y_origin) {
        for (int i = 0; i < arrFichas.size(); i++) {
            if (arrFichas.at(i)->return_x() == x_origin && arrFichas.at(i)->return_y() - 1 == y_destination) {
                //arrFichas.at(i + 1)->new_x(arrFichas.at(i + 1)->return_x() + 1);
                arrFichas.at(i)->new_flag(true);
                break;
            }
        }
    }
    //Jump down
    else if (y_destination > y_origin) {
        for (int i = 0; i < arrFichas.size(); i++) {
            if (arrFichas.at(i)->return_x() == x_origin && arrFichas.at(i)->return_y() + 1 == y_destination) {
                arrFichas.at(i)->new_flag(true);
                break;
            }
        }
    }
    //Jump left
    else if (x_destination < x_origin) {
        for (int i = 0; i < arrFichas.size(); i++) {
            if (arrFichas.at(i)->return_y() == y_origin && arrFichas.at(i)->return_x() - 1 == x_destination) {
                arrFichas.at(i)->new_flag(true);
                break;
            }
        }
    }
    //Jump right
    else if (x_destination > x_origin) {
        for (int i = 0; i < arrFichas.size(); i++) {
            if (arrFichas.at(i)->return_y() == y_origin && arrFichas.at(i)->return_x() + 1 == x_destination) {
                arrFichas.at(i)->new_flag(true);
                break;
            }
        }
    }
    for (int i = 0; i < arrFichas.size(); i++) {
        if (arrFichas.at(i)->return_flag()) {
            arrFichas.erase(arrFichas.begin() + i);
            break;
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
    Delete_Surpassed_Pieces(x_origin, y_origin, x_destination, y_destination);
    arrFichas.at(IDX)->new_x(x_destination);
    arrFichas.at(IDX)->new_y(y_destination);
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