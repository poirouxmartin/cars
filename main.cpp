#include "cars.h"
#include "time_tests.h"
#include "math.h"
#include "gui.h"


/* TODO


----- Structure globale du projet -----

-> Créer une classe circuit
-> Créer une caméra (classe?) -> une classe scène avec voitures, circuit, caméra ?
-> Ajout de friction
-> Définir un delta t



*/




// Fonction qui permet de tester le temps que prend une fonction
void test() {


}




// Main
int main() {

    // Initialisation de la fenêtre
    InitWindow(screen_width, screen_height, "Cars");

    // Initialisation de l'audio
    InitAudioDevice();

    // Nombre d'images par secondes
    SetTargetFPS(fps);



    // Génération des voitures
    Car cars[n_cars];

    for (int i = 0; i < n_cars; i++) {
        Car car;
        car.index = i;
        cars[i] = car;
    }



    // Boucle principale (Quitter à l'aide de la croix, ou en faisant échap)
    while (!WindowShouldClose()) {

        // Fonction test pour les temps
        if (IsKeyDown(KEY_T))
            test_function(&test, 1);
        

        // Application de la physique sur les voitures
        for (Car & c : cars) {
            c.apply_speed();
        }


        // Contrôle d'une des voitures
        if (IsKeyDown(KEY_UP))
            cars[0]._speed += 0.01;


        // Dessins
        BeginDrawing();

            // Couleur de fond
            ClearBackground(background_color);


            // Dessin des voitures
            for (Car & c : cars) {
                c.draw();
            }

            
        // Fin de la zone de dessin
        EndDrawing();
    

    }

    // Fermeture de la fenêtre
    CloseWindow();


    return 0;

}