#pragma once
#include "Ficha.h"
enum style {english, asimetric, german};
class Game
{
private:
	style game_style;
	vector<Ficha*> arrFichas;
	bool error_temp;
public:
	Game(style new_style);
	~Game();
	void Print();
	void Request_Input();
	bool Valid_Movement(int x_origin, int y_origin, int x_destination, int y_destination);
	void Delete_Surpassed_Pieces(int x_origin, int y_origin, int x_destination, int y_destination);
	void Move(int x_origin, int y_origin, int x_destination, int y_destination);
	string Error_Message();
	bool End_Game();
};

