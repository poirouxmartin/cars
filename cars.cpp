#include "cars.h"
#include "gui.h"
#include "math.h"



// Constructeur par défaut
Car::Car() {
}


// Dessine la voiture
void Car::draw() {
    // Rectangle r = {_x, _y, _length, _width};
    // DrawRectanglePro(r, {0, 0}, _angle * 180 / PI, car_color);

    // Dessine la voiture
    DrawCircle(_x, _y, _radius, car_color);

    // Dessine un cercle pour indiquer sa direction
    DrawCircle(_x + _radius * cos(_angle), _y + _radius * sin(_angle), _radius / 4, dot_color);
}


// Ajoute la vitesse de la voiture à sa position
void Car::apply_speed() {
    _x += _speed * cos(_angle);
    _y += _speed * sin(_angle);
}