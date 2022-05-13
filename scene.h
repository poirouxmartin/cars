#include "cars.h"
#include "track.h"
#include "camera.h"
#include "time.h"


class Scene {
    public:


    // Attributs

    // Nombre de voitures
    static const int _n_cars = 50;

    // Liste des voitures
    Car _cars[_n_cars];

    // Caméra associée
    Cam _camera;

    // Nombre de bords pour le circuit
    static const int _n_edges = 100;

    // Liste des bords du circuit
    Edge _edges[_n_edges];

    // Ligne d'arrivée
    Finish _finish_line;

    // Nombre de checkpoints pour le circuit
    static const int _n_checkpoints = 1;

    // Liste des bords du circuit
    Checkpoint _checkpoints[_n_checkpoints];

    // delta T (s)
    float _optimal_delta_t;
    float _delta_t;

    // nombre de steps actuel
    int _steps = 0;

    // temps calculé à l'itération précédente
    double _t;

    // Vitesse du temps
    float _time_scale = 1.0;

    
    // Constructeurs

    // Par défaut
    Scene();


    // Fonctions


    // Application de la vitesse des voitures à leur position
    void apply_cars_speed();

    // Application de la friction linéaire aux voitures
    void apply_cars_linear_friction();

    // Detecte s'il y a une collision entre une voiture et un bord du circuit
    bool is_collision(Car, Edge);

    // Application de l'ensemble des déplacements physiques dans la scene
    void update();

    // Dessin de la scène
    void draw();


};