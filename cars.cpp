#include "cars.h"
#include "gui.h"
#include "math.h"



// Constructeur par défaut
Car::Car() {
}



// Ajoute la vitesse de la voiture à sa position
void Car::apply_speed() {
    _x += _speed * cos(_angle);
    _y += _speed * sin(_angle);
}