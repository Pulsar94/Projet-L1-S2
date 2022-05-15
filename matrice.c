#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "game_control.h"
#include "regles_taku.h"

#define TRUE 1
#define FALSE 0

int** creation_mat_modele(int taille){
    /*
     * Fonction: creation_mat_modele
     * -----------------------------
     * Génère des grilles de Takuzu en dur
     *
     * taille: taille de la grille de Takuzu
     *
     * return: pointeur sur la grille
     */
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

int** generation_solution(int taille, int** taku_lig){
    /*
     * Fonction: generation_solution
     * -----------------------------
     * Génère des grilles de Takuzu
     *
     * taille: taille de la grille
     *
     * return: pointeur sur tableau
     */
    int i, j, val, nbr;
    int* code_binaire = (int*) malloc(taille * sizeof (int));
    int** matrice_sol = (int**) malloc(taille * sizeof (int*));
    switch (taille) {
        case 4:
            for (int k = 0; k < taille; ++k) {
                do {
                    nbr = rand() % 16;
                    for (i = 0; i < taille; ++i) {
                        // conversion en binaire dans le tableau
                        for(j = 0; nbr > 0; j++)
                        {
                            code_binaire[j] = nbr % 2;
                            nbr = nbr/2;
                        }
                    }
                } while ((verification_ligne_sol(code_binaire, taille) == FALSE) || (verification_nombre_sol_lig(taille, code_binaire) == FALSE));
                matrice_sol[k] = code_binaire;
                if ((verification_colonne_sol(matrice_sol, taille) == FALSE) || verification_nombre_sol_col(taille, matrice_sol) == FALSE){
                    do {
                        nbr = rand() % 16;
                        for (i = 0; i < taille; ++i) {
                            // conversion en binaire dans le tableau
                            for(j = 0; nbr > 0; j++)
                            {
                                code_binaire[j] = nbr % 2;
                                nbr = nbr/2;
                            }
                        }
                    } while (verification_ligne_sol(code_binaire, taille) == FALSE);
                    matrice_sol[k] = code_binaire;
                }
            }
            break;

        case 8:
            for (int k = 0; k < taille; ++k) {
                do {
                    nbr = rand() % 256;
                    for (i = 0; i < taille; ++i) {
                        // conversion en binaire dans le tableau
                        for(j = 0; nbr > 0; j++)
                        {
                            code_binaire[j] = nbr % 2;
                            nbr = nbr/2;
                        }
                    }
                } while ((verification_ligne_sol(code_binaire, taille) == FALSE) || (verification_nombre_sol_lig(taille, code_binaire) == FALSE));
                matrice_sol[k] = code_binaire;
                if ((verification_colonne_sol(matrice_sol, taille) == FALSE) || verification_nombre_sol_col(taille, matrice_sol) == FALSE){
                    do {
                        nbr = rand() % 16;
                        for (i = 0; i < taille; ++i) {
                            // conversion en binaire dans le tableau
                            for(j = 0; nbr > 0; j++)
                            {
                                code_binaire[j] = nbr % 2;
                                nbr = nbr/2;
                            }
                        }
                    } while (verification_ligne_sol(code_binaire, taille) == FALSE);
                    matrice_sol[k] = code_binaire;
                }
            }
            break;

        case 16:
            for (int k = 0; k < taille; ++k) {
                do {
                    nbr = rand() % 65536;
                    for (i = 0; i < taille; ++i) {
                        // conversion en binaire dans le tableau
                        for(j = 0; nbr > 0; j++)
                        {
                            code_binaire[j] = nbr % 2;
                            nbr = nbr/2;
                        }
                    }
                } while ((verification_ligne_sol(code_binaire, taille) == FALSE) || (verification_nombre_sol_lig(taille, code_binaire) == FALSE));
                matrice_sol[k] = code_binaire;
                if ((verification_colonne_sol(matrice_sol, taille) == FALSE) || verification_nombre_sol_col(taille, matrice_sol) == FALSE){
                    do {
                        nbr = rand() % 16;
                        for (i = 0; i < taille; ++i) {
                            // conversion en binaire dans le tableau
                            for(j = 0; nbr > 0; j++)
                            {
                                code_binaire[j] = nbr % 2;
                                nbr = nbr/2;
                            }
                        }
                    } while (verification_ligne_sol(code_binaire, taille) == FALSE);
                    matrice_sol[k] = code_binaire;
                }
            }
            break;
    }
    return matrice_sol;
}

int** creer_masque_aleat(int taille) {
    /*
     * Fonction: creer_masque_aleat
     * ----------------------------
     * Création d'un masque aléatoire
     *
     * taille: taille de la grille
     *
     * return: pointeur sur masque
     */
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
/*
 * Fonction: creer_masque_spe
 * ----------------------------
 * Création d'un masque manuellement
 * L'utilisateur saisie les coords
 *
 * taille: taille de la grille
 *
 * return: pointeur sur masque
 */
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
    /*
     * Fonction: takuzu_utilisateur
     * ----------------------------
     * return: tableau sur tableau masqué
     */
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


