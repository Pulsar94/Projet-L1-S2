//
// Created by Lucas on 15/05/2022.
//

#include <stdio.h>
#include <unistd.h>

#include "auto_resolve.h"
#include "regles_taku.h"
#include "game_control.h"

#define INCORECT 4
#define VALIDE 3
#define CORRECT 2
#define TRUE 1
#define FALSE 0



void auto_resolve(int** tab_game, int** tab_solution, int taille, int player)
{
    char alpha_maj[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

    printf("Résolution automatique de la grille.");

    int* indice = indice_init();
    int h;
    int bool_input_matrice;

    for(int j = 0; j<taille ; j++)
    {

        for(int i = 1; i<taille + 1; i++) {
            h = 0;
            bool_input_matrice = FALSE;
            affichage_matrice(tab_game, taille, 1);
            if (tab_game[j][i] == -1) {
                do {
                    printf("\nInjection dans la matrice => coords: %c %d valeur: %d", alpha_maj[j], i, h);
                    bool_input_matrice = input_into_matrice(tab_game, tab_solution, i, alpha_maj[j], h, taille, indice);
                    if (bool_input_matrice == CORRECT) // COUP CORRECT ?
                    {
                        printf("-+-+-+-+-+ COUP CORRECT !-+-+-+-+-+\n");
                    } else {
                        if (bool_input_matrice == INCORECT) // COUP INCORRECT ?
                        {
                            printf("\033[1;31m-+-+-+-+-+ COUP INCORRECT !-+-+-+-+-+\nIl ne respecte pas les règles du Takuzu !\n\033[0m");
                            recherche_indice(indice, TRUE);
                            h++;
                        } else // COUP VALIDE
                        {
                            printf("-+-+-+-+-+ COUP VALIDE !-+-+-+-+-+\n Il respecte les règles du Takuzu mais n'est pas la solution.\n");
                            h++;
                        }
                    }
                    affichage_matrice(tab_game, taille, 1);
                    sleep(1);
                } while (bool_input_matrice != CORRECT);
            }
        }
    }
    // VERIF ENDGAME
    if (grille_pleine(tab_solution, tab_game, taille) == TRUE)
    {
        printf("\n-+-+-+-+-+-+-+-+-+\nRésolution automatique terminée\n-+-+-+-+-+-+-+-+-+\n");
        printf("Grille solution :\n");
        affichage_matrice(tab_solution, taille, 1);
    }

}