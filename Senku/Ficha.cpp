#include "Ficha.h"
Ficha::Ficha(int px, int py) {
    x = px;
    y = py;
    flag = false;
}
Ficha::~Ficha() {}
void Ficha::new_x(int new_data) { x = new_data; }
void Ficha::new_y(int new_data) { y = new_data; }
void Ficha::new_flag(bool new_data) { flag = new_data; }
int Ficha::return_x() { return x; }
int Ficha::return_y() { return y; }
bool Ficha::return_flag() { return flag; }