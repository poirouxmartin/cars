class Cam {
    public:


        // Attributs

        // Position (m)
        float _x = 0;
        float _y = 0;

        // Hauteur (m)
        float _h = 100;


        // Angle du champ en largeur (°) 
        float _view_angle = 100;


        // Voiture que la caméra suit
        int _following = -1;


        // Constructeurs

        // Par défaut
        Cam();


        // Fonctions


};