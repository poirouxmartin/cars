#include "raylib.h"
#include "time.h"


// Définition des variables


// Paramètres d'initialisation
static float screen_width = 1800;
static float screen_height = 900;

// Nombre de FPS
static int fps = 144;

// Couleur de fond
static Color background_color = {25, 25, 25};

// Couleur du texte
static Color text_color = {255, 100, 100, 255};

// Couleur des voitures
static Color car_color = {0, 255, 0, 255};

// Couleur du point de direction de la voiture
static Color direction_color = {255, 0, 0, 255};

// Couleur du quadrillage
static Color grid_color = {255, 255, 255, 100};

// Couleur des bords du circuit
static Color edge_color = {255, 150, 150, 255};

// Taille d'un carreau du quadrillage (m)
static float grid_size = 5;
