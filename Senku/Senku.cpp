#include "Game.h"
#include "Menu.h"
int main() {
    Game* objGame;
    Menu* objMenu = new Menu();
    //Menu execution
    objMenu->Draw();
    objMenu->new_option();
    if (objMenu->return_option() == 0) {
        delete objMenu, objGame;
        return 0;
    }
    if (objMenu->return_option() == 1)        objGame = new Game(style::english);
    else if (objMenu->return_option() == 2)        objGame = new Game(style::asimetric);
    else        objGame = new Game(style::german);
    //Game execution
    while (!objGame->End_Game()) {
        objGame->Print();
        objGame->Request_Input();
        cout << objGame->Error_Message();
        if (objGame->Error_Message() != "") Sleep(1000);
        system("cls");
    }
    delete objGame, objMenu;
    _getch();
    return 0;
}