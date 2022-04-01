#include "cars.h"
#include "gui.h"



// Constructeur par défaut
Car::Car() {
}


// Dessine la voiture
void Car::draw() {
    DrawRectangle(_x, _y, _length, _width, car_color);
}