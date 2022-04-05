class Car {
    public:


    // Attributs

    // Position (m)
    float _x = 0;
    float _y = 0;

    // Dimensions (m)
    //float _length = 2;
    //float _width = 1;

    // Voiture en cercle plutôt? (radius en m)
    float _radius = 1;

    // Vitesse (m/s)
    float _speed = 0.1;

    // Angle de la voiture (radians)
    float _angle = 0; 

    // Accélération de la voiture (m/s²)
    float _acceleration = 0.0025;


    // Constructeurs

    // Par défaut
    Car();

    // Fonctions

    // Ajoute la vitesse de la voiture à sa position
    void apply_speed();


};