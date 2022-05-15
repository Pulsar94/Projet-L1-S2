#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "game_control.h"

#define TRUE 1
#define FALSE 0

int** creation_mat_modele(int taille){
    int** adresse = NULL;
    if (taille == 4){
        int matrice4[4][4] = {{1,0,0,1},
                              {1,0,1,0},
                              {0,1,1,0},
                              {0,1,0,1}};
        adresse = creation_matrice(taille);
        for (int i = 0; i < taille; ++i) {
            for (int j = 0; j < taille; ++j) {
                adresse[i][j] = matrice4[i][j];
            }
        }
    } else{
        if (taille == 8){
            int matrice8[8][8] = {{1,0,1,1,0,1,0,0},
                                  {1,0,1,0,1,0,0,1},
                                  {0,1,0,1,1,0,1,0},
                                  {0,1,0,1,0,1,1,0},
                                  {1,0,1,0,0,1,0,1},
                                  {0,1,0,0,1,0,1,1},
                                  {0,0,1,1,0,1,1,0},
                                  {1,1,0,0,1,0,0,1}};
            adresse = creation_matrice(taille);
            for (int i = 0; i < taille; ++i) {
                for (int j = 0; j < taille; ++j) {
                    adresse[i][j] = matrice8[i][j];
                }
            }
        } else{
            if (taille == 16){
                int matrice16[16][16] = {{0,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0},
                                        {1,1,0,0,1,1,0,1,0,0,1,0,1,0,0,1},
                                        {0,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0},
                                        {1,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1},
                                        {1,0,0,1,0,1,0,1,0,0,1,1,0,1,1,0},
                                        {0,1,1,0,1,1,0,0,1,0,1,0,1,0,1,0},
                                        {0,0,1,0,1,0,1,1,0,1,0,0,1,1,0,1},
                                        {1,0,0,1,0,1,1,0,1,1,0,1,0,0,1,0},
                                        {0,1,0,1,1,0,0,1,0,0,1,0,1,1,0,1},
                                        {1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,1},
                                        {0,1,0,1,1,0,1,0,1,1,0,1,0,0,1,0},
                                        {1,1,0,0,1,0,1,1,0,0,1,0,1,0,0,1},
                                        {1,0,1,0,0,1,0,0,1,1,0,1,0,1,0,1},
                                        {0,1,0,1,0,0,1,0,1,1,0,1,0,1,1,0},
                                        {0,1,1,0,1,0,0,1,0,0,1,0,1,0,1,1},
                                        {1,0,1,1,0,1,1,0,1,0,0,1,0,1,0,0}};
                adresse = creation_matrice(taille);
                for (int i = 0; i < taille; ++i) {
                    for (int j = 0; j < taille; ++j) {
                        adresse[i][j] = matrice16[i][j];
                    }
                }
            }
        }
    }
    return adresse;
}




int** creation_matrice(int taille) {
    /*
     * Fonction: creation_matrice
     * -------------------
     * Création d'une matrice carrée en fonction de la taille donnée pour insérer les données du takuzu
     *
     * taille: taille de la matrice
     *
     * return: pointeur sur le tableau
     */
    int** taku_lig = (int**) malloc(taille * sizeof (int*));
    for (int i = 0; i < taille; ++i) {
        int* taku_col = (int*) malloc(taille * sizeof(int));
        taku_lig[i] = taku_col;
    }
    return taku_lig;
}

void libere_matrice(int taille, int** taku_lig){
    /*
     * Fonction: libère matrice
     * -------------------
     * Libère la matrice du Takuzu reservée précédemment par le malloc
     */
    for (int i = 0; i < taille; ++i) {
        free(taku_lig[i]);
    }
    free(taku_lig);
}

void generation_solution(int taille, int** taku_lig){
    // Matrice solution du Takuzu
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            taku_lig[i][j] = rand() % 2;
            if (NULL) {
                // besoin de coder les conditions avant de remplir la matrice
                // remplir un tableau ligne et vérifie les règles et intègre dans la matrice
                // vérifier les autres règles après
            }
        }
    }
}

int** creer_masque_aleat(int taille) {
    // Masque qui détermine l'affichage Takuzu utilisateur
    int** masque = creation_matrice(taille);
    for(int i=0; i<taille; i++)
    {
        for(int j=0; j<taille; j++)
        {
            masque[i][j] = rand() % 2;
        }
    }
    return masque;
}

int** creer_masque_spe(int taille)
{
    // Init matrice
    int** masque = creation_matrice(taille);
    for(int i=0; i<taille; i++)
    {
        for(int j=0; j<taille; j++)
        {
            masque[i][j] = 0;
        }
    }

    // Saisie masque
    char y;
    int x, val;
    do {
        affichage_matrice(masque, taille, 2);
        printf("\nSaisir une valeur à injecter sous la forme \nCOLONNE(LETTRE) LIGNE(CHIFFRE) 0/1(VALEUR)\nPour quitter la saisie du masque, entrez Z 0 0\n Choix : ");
        scanf(" %c %d %d", &y, &x, &val);

        // VERIF IF INPUT IS LEGAL OR NOT
        if (((input_into_masque(masque, x, y, val, taille)) == FALSE) && (sortie_de_zone_input(y, x, val) == FALSE)) {
            printf("\nSaisie illégale\n");
        }
    } while (sortie_de_zone_input(y, x, val) == FALSE);
    return masque;
}

int input_into_masque(int**tab, int x, char y_char, int val, int taille)
/*
 * Fonction: input_into_masque
 * -----------------
 * Injecte la valeur dans le masque
 * Convertie la valeur y_char qui est un input de type char en sa position dans l'alphabet par la fonction alpha_to_indice()
 * Condition: Vérifie tout d'abord avec la fonction verif_legal_input() si la valeur est autorisée ou non.
 *
 * **tab: pointeur de tableau
 * x: position x de val
 * y_char: position y de val (lettre correspondante)
 * val: valeur choisie par l'utilisateur (0 ou 1)
 * taille: taille du tableau
 *
 * return: boolean en fonction de condition respectée ou non
 *
 */
{
    int y = alpha_to_indice(y_char, taille);
    x--;
    if ((y != -1) && (verif_legal_input(taille, x, y, val) == TRUE))
    {
        tab[x][y] = val;
        return TRUE;
    }
    return FALSE;
}

int** takuzu_utilisateur(int**tab_sol, int** tab_game, int taille, int choice) {
    // Takuzu visible par l'utilisateur
    // choice = 1 : masque aleat ; choice = 0 ; masque manuel
    // mettre -1 pour les cases vides, non visible par l'utilisateur mais pour éviter confusion par la machine
    int** grille_masque = NULL;
    switch (choice)
    {
        case 1:
        {
            grille_masque = creer_masque_spe(taille);
            break;
        }
        case 2:
        {
            grille_masque = creer_masque_aleat(taille);
            break;
        }
    }
    for (int i = 0; i<taille; i++)
    {
        for(int j = 0; j<taille; j++)
        {
            if (grille_masque[i][j] == 0)
            {
                tab_game[i][j] = -1;
            }
        }
    }
    return grille_masque;
}


