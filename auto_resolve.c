//
// Created by Lucas on 15/05/2022.
//

#include <stdio.h>

#include "auto_resolve.h"
#include "regles_taku.h"
#include "game_control.h"

#define INCORECT 4
#define VALIDE 3
#define CORRECT 2
#define TRUE 1
#define FALSE 0

char alpha_maj[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

int auto_resolve(int** tab_game, int** tab_solution, int taille, int player)
{
    printf("Résolution automatique de la grille.");

    int* indice = indice_init();

    for(int i = 0; i < taille; i++)
    {
        for(int j = 0; j < taille; j++)
        {
            for(int h = 0; h < 2; h++)
            {
                int bool_input_matrice = FALSE;
                do {
                    bool_input_matrice = input_into_matrice(tab_game, tab_solution, i, alpha_maj[j], h, taille, indice);
                } while(bool_input_matrice != CORRECT);
            }

        }
    }

}