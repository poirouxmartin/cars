// Variables globales

// Nombre de voitures
const int n_cars = 50;






class Car {
    public:


    // Attributs

    // Position (m)
    float _x = 0;
    float _y = 0;

    // Vitesse (m/s)
    float _speed = 0.1;

    // Angle de la voiture (radians)
    float _angle = 0; 


    // Dimensions (m)
    float _length = 25;
    float _width = 15;

    // Voiture en cercle plutôt? (radius en m)
    float _radius = 10;


    // Constructeurs

    // Par défaut
    Car();

    // Fonctions
    
    // Dessine la voiture
    void draw();

    // Ajoute la vitesse de la voiture à sa position
    void apply_speed();


};