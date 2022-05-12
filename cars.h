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
    float _speed = 0.0;

    // Angle de la voiture (radians)
    float _angle = 0; 

    // Accélération de la voiture (m/s²)
    float _acceleration = 3.0;

    // Puissance de freinage (entre 0 et 1, correspond à une friction)
    float _break = 0.15;

    // Decélération de la voiture (m/s²)
    float _deceleration = 5.0;

    // Friction linéaire des pneus sur la route
    float _linear_friction = 0.05;

    // Vitesse maximale angulaire de la voiture (rad/s)
    float _steer = 1.0;

    // Vitesse à laquelle la voiture tourne le plus (m/s)
    float _steer_max_speed = 10.0;

    // Facteur de décroissance exponentielle de vitesse angulaire en fonction de la vitesse
    float _exp_steer = 0.08;


    // Constructeurs

    // Par défaut
    Car();

    // Fonctions

    // Ajoute la vitesse de la voiture à sa position
    void apply_speed(float);

    // Ajoute une accélération à la voiture
    void apply_acceleration(float);

    // Freine la voiture
    void apply_break(float);

    // Tourne la voiture (direction gauche <-> droite, respectivement -1 <-> 1)
    void steer(float, float);

    // Applique les forces de friction linéaire à la voiture
    void apply_linear_friction(float);


};