#include "scene.h"
#include "gui.h"
#include "math.h"



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



}


// Application de la vitesse de la voiture à sa position
void Scene::apply_cars_speed() {
    for (Car & c : _cars) {
        c.apply_speed();
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
    for (int i = 0; i < _grid_col; i++) {
        DrawLine(i * grid_size * k - fmod(_camera._x, grid_size) * k, 0, i * grid_size * k - fmod(_camera._x, grid_size) * k, screen_height, grid_color);
    }

    // Dessine chaque ligne
    for (int i = 0; i < _grid_lin; i++) {
        DrawLine(0, i * grid_size * k - fmod(_camera._y, grid_size) * k, screen_width, i * grid_size * k - fmod(_camera._y, grid_size) * k, grid_color);
    }


    // Dessin des voitures
    for (Car & c : _cars) {
        // Calcul des coordonnées d'affichage
        float x_display = (c._x - _camera._x) * k + screen_width / 2;
        float y_display = (c._y - _camera._y) * k + screen_height / 2;


        // Dessine la voiture
        DrawCircle(x_display, y_display, c._radius * k, car_color);

        // Dessine un cercle pour indiquer sa direction
        DrawCircle(x_display + c._radius * k * cos(c._angle), y_display + c._radius * k * sin(c._angle), c._radius * k / 4, dot_color);
    }


}