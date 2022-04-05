#include "cars.h"
#include "camera.h"


class Scene {
    public:


    // Attributs

    // Nombre de voitures
    static const int _n_cars = 50;

    // Liste des voitures
    Car _cars[_n_cars];

    // Caméra associée
    Cam _camera;

    
    // Constructeurs

    // Par défaut
    Scene();


    // Fonctions


    // Application de la vitesse de la voiture à sa position
    void apply_cars_speed();

    // Dessin de la scène
    void draw();


};