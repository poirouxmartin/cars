#include "cars.h"
#include "time_tests.h"
#include "math.h"
#include "gui.h"


/* TODO


----- Structure globale du projet -----

-> Créer une classe de voitures



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



    // Boucle principale (Quitter à l'aide de la croix, ou en faisant échap)
    while (!WindowShouldClose()) {

        // Fonction test pour les temps
        if (IsKeyDown(KEY_T))
            test_function(&test, 1);
        

    


        // Dessins
        BeginDrawing();

            // Couleur de fond
            ClearBackground(background_color);
            
        // Fin de la zone de dessin
        EndDrawing();
    

    }

    // Fermeture de la fenêtre
    CloseWindow();


    return 0;

}