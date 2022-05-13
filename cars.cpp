#include "cars.h"
#include "gui.h"
#include "math.h"
#include <iostream>
using namespace std;



// Constructeur par défaut
Car::Car() {
}



// Ajoute la vitesse de la voiture à sa position
void Car::apply_speed(float delta_t) {
    _x += _speed * cos(_angle) * delta_t;
    _y += _speed * sin(_angle) * delta_t;
}


// Ajoute une accélération à la voiture
void Car::apply_acceleration(float delta_t) {
    _speed += _acceleration * delta_t;
}


// Freine la voiture
void Car::apply_break(float delta_t) {
    _speed *= pow(1 - _break, delta_t);
    _speed -= _deceleration * delta_t;
}

// Tourne la voiture (direction gauche <-> droite, respectivement -1 <-> 1)
void Car::steer(float direction, float delta_t) {
    float angular_speed = direction * _steer * _speed / _steer_max_speed * exp(- _exp_steer * abs(_speed)) * exp(_exp_steer * _steer_max_speed) * delta_t * PI;
    _angle += angular_speed;
    // Ralentit un peu la voiture aussi
    apply_break(delta_t * abs(direction) * 0.1);
}


// Applique les forces de friction linéaire à la voiture
void Car::apply_linear_friction(float delta_t) {
    _speed *= pow(1 - _linear_friction, delta_t);
}