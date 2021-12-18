#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
class Ficha
{
private:
    int x, y;
    bool flag;
public:
    Ficha(int px, int py);
    ~Ficha();
    void new_x(int new_data);
    void new_y(int new_data);
    void new_flag(bool new_data);
    int return_x();
    int return_y();
    bool return_flag();
};

