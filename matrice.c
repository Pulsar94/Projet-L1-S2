#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

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

int** creer_masque_spe(int taille) {
    // Masque qui détermine l'affichage Takuzu utilisateur
    return NULL;
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


