#include "time_tests.h"
#include "math.h"
#include "gui.h"
#include "scene.h"


/* TODO


----- Structure globale du projet -----

-> Créer une classe circuit
-> Multi-caméras
-> Accélération angulaire ou vitesse angulaire?
-> Système réaliste d'accélération et de freinage
-> Implémentation des dérapages
-> Collision des voitures avec les bords
-> Utiliser un diviser pour régner pour les collisions entre les voitures et les bords pour optimiser

-> Faire un système exact? ne dépendant plus de delta t -> calcul de la position par intégrations


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
            scene._cars[0].apply_acceleration(scene._delta_t * scene._time_scale);

        // Décélère la voiture (à changer, car là ça accélère)
        if (IsKeyDown(KEY_DOWN))
            scene._cars[0].apply_break(scene._delta_t * scene._time_scale);

        // Tourne vers la gauche
        if (IsKeyDown(KEY_LEFT))
            scene._cars[0].steer(-1.0, scene._delta_t * scene._time_scale);

        // Tourne vers la droite
        if (IsKeyDown(KEY_RIGHT))
            scene._cars[0].steer(1.0, scene._delta_t * scene._time_scale);


        // Déplacement de la caméra
        if (IsKeyDown(KEY_KP_6))
            scene._camera._x += scene._camera._h / 1000;
        if (IsKeyDown(KEY_KP_4))
            scene._camera._x -= scene._camera._h / 1000;
        if (IsKeyDown(KEY_KP_8))
            scene._camera._y -= scene._camera._h / 1000;
        if (IsKeyDown(KEY_KP_5))
            scene._camera._y += scene._camera._h / 1000;

        // Zoom/DeZoom
        if (IsKeyDown(KEY_KP_0))
            scene._camera._h *= 1.01;
        if (IsKeyDown(KEY_KP_2))
            scene._camera._h /= 1.01;

        // Attachement de la caméra à une voiture
        if (IsKeyPressed(KEY_SPACE))
            scene._camera._following = (scene._camera._following >= 0) * -1;

        // Scroller pour changer de voiture suivie
        

        // Changement de la vitesse du temps
        if (IsKeyPressed(KEY_KP_ADD))
            scene._time_scale *= 2;

        if (IsKeyPressed(KEY_KP_SUBTRACT))
            scene._time_scale /= 2;


        // Application des vitesses aux voitures
        scene.update();


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