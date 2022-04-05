#include "time_tests.h"
#include "math.h"
#include "gui.h"
#include "scene.h"


/* TODO


----- Structure globale du projet -----

-> Créer une classe circuit
-> Créer une caméra (classe?) -> une classe scène avec voitures, circuit, caméra ?
-> Ajout de friction
-> Définir un delta t
-> Multi-caméras


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


    // Initialisation de la scène
    Scene scene;



    // Boucle principale (Quitter à l'aide de la croix, ou en faisant échap)
    while (!WindowShouldClose()) {

        // Fonction test pour les temps
        if (IsKeyDown(KEY_T))
            test_function(&test, 1);


        // ----- Contrôle d'une des voitures -----

        // Accélère la voiture
        if (IsKeyDown(KEY_UP))
            scene._cars[0]._speed += scene._cars[0]._acceleration;

        // Décélère la voiture
        if (IsKeyDown(KEY_DOWN))
            scene._cars[0]._speed -= scene._cars[0]._acceleration;

        // Tourne vers la gauche
        if (IsKeyDown(KEY_LEFT))
            scene._cars[0]._angle -= 0.01;

        // Tourne vers la droite
        if (IsKeyDown(KEY_RIGHT))
            scene._cars[0]._angle += 0.01;


        // Déplacement de la caméra
        if (IsKeyDown(KEY_KP_6))
            scene._camera._x += 0.1;
        if (IsKeyDown(KEY_KP_4))
            scene._camera._x -= 0.1;
        if (IsKeyDown(KEY_KP_8))
            scene._camera._y -= 0.1;
        if (IsKeyDown(KEY_KP_5))
            scene._camera._y += 0.1;

        // Zoom/DeZoom
        if (IsKeyDown(KEY_KP_2))
            scene._camera._h *= 1.01;
        if (IsKeyDown(KEY_KP_0))
            scene._camera._h /= 1.01;


        // Application des vitesses aux voitures
        scene.apply_cars_speed();


        // Dessins
        BeginDrawing();

            // Couleur de fond
            ClearBackground(background_color);


           
            // Affichage de la scène
            scene.draw();

            
        // Fin de la zone de dessin
        EndDrawing();
    

    }

    // Fermeture de la fenêtre
    CloseWindow();


    return 0;

}