#pragma once
#include <iostream>
using namespace std;
class Menu
{
private:
	int option;
public:
	Menu();
	~Menu();
	void Draw();
	void new_option();
	int return_option();
};

