#include "scene.h"
#include "gui.h"
#include "math.h"
#include <iostream>
#include <string>
using namespace std;


// Constructeur par défaut
Scene::Scene() {

    // Initialisation des voitures
    for (int i = 0; i < _n_cars; i++) {
        Car car;
        _cars[i] = car;
    }

    // Initialisation de la caméra
    Cam cam;
    _camera = cam;

    // Initialisation du temps
    _t = clock();

    // Initialisation des variables
    _optimal_delta_t = 1 / (float)fps;
    _delta_t = 1 / (float)fps;

}


// Application de la vitesse des voitures à leur position
void Scene::apply_cars_speed() {
    for (Car & c : _cars) {
        c.apply_speed(_delta_t * time_speed);
    }
}


// Application de la friction linéaire aux voitures
void Scene::apply_cars_linear_friction() {
    for (Car & c : _cars) {
        c.apply_linear_friction(_delta_t * time_speed);
    }
}




// Application de l'ensemble des déplacements physiques dans la scene
void Scene::update() {
    while (clock() - _t > _optimal_delta_t * 0) {

        _delta_t = (clock() - _t) / 1000.0;


        // Applique la vitesse aux voitures
        apply_cars_speed();

        // Applique la friction linéaire aux voitures
        apply_cars_linear_friction();

        // Position de la caméra
        if (_camera._following >= 0) {
            _camera._x = _cars[_camera._following]._x;
            _camera._y = _cars[_camera._following]._y;
        }

        _t = clock();
    }
}


// Dessin de la scène
void Scene::draw() {

    // Largeur du champ de la caméra
    float L = _camera._h * tan(_camera._view_angle / 2 * PI / 180);

    // Echelle d'affichage
    float k = screen_width / L;



    // Dessin du quadrillage

    // Calcul du nombre de lignes et colonnes
    int _grid_col = L / grid_size + 2;
    int _grid_lin = L * screen_height / screen_width / grid_size + 2;
    

    // Dessine chaque colonne
    for (int i = -_grid_col / 2; i < _grid_col / 2; i++) {
        DrawLine(screen_width / 2 + i * grid_size * k - fmod(_camera._x, grid_size) * k, 0, screen_width / 2 + i * grid_size * k - fmod(_camera._x, grid_size) * k, screen_height, grid_color);
    }

    // Dessine chaque ligne
    for (int i = -_grid_lin / 2; i < _grid_lin / 2; i++) {
        DrawLine(0, screen_height / 2 + i * grid_size * k - fmod(_camera._y, grid_size) * k, screen_width, screen_height / 2 + i * grid_size * k - fmod(_camera._y, grid_size) * k, grid_color);
    }


    // Dessin des voitures
    for (Car & c : _cars) {
        // Calcul des coordonnées d'affichage
        float x_display = (c._x - _camera._x) * k + screen_width / 2;
        float y_display = (c._y - _camera._y) * k + screen_height / 2;


        // Dessine la voiture
        DrawCircle(x_display, y_display, c._radius * k, car_color);

        // Dessine une ligne indiquand sa direction
        DrawLine(x_display, y_display, x_display + k * cos(c._angle) * c._radius * 2, y_display + k * sin(c._angle) * c._radius * 2, direction_color);
    }



    // Dessin de texte

    // Vitesse du véhicule
    DrawText(("speed : " + to_string(_cars[0]._speed) + "m/s\n          " + to_string(_cars[0]._speed * 3.6) + "km/h").c_str(), 16, 16, 32, RED);

    // Nombre de FPS
    DrawText(("FPS : " + to_string(1 / _delta_t)).c_str(), screen_width - 256, 16, 32, RED);

    // (Vitesse du temps)

    // Temps
    DrawText(("time : " + to_string(clock() * time_speed / 1000) + "s").c_str(), 16, 128, 32, RED);

}