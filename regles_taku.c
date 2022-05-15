//
// noms des créateurs
//

#include "regles_taku.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int verification_cote (int val, int taille, int pos_i, int pos_j, int** taku_jeu) {
    // Regarde si la règle de pas plus de 2 chiffes identiques côte à côte est respectée
    // première boucle i = 4 pour vérification sur les quatre directions (haut,bas,droite,gauche)
    int j, temp = 0, cpt = 0;
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:{
                // haut
                for (j = pos_i - 1; j >= 0; --j) {
                    // pas besoin de verifier plus loin que 2 cases
                    if (cpt > 2){
                        break;
                    }
                    if (taku_jeu[j][pos_j] != val){
                        break;
                    }
                    else {
                        if (taku_jeu[j][pos_j] == val){
                            temp += 1;
                        }
                    }
                    // verification pour 2 identiques
                    if (temp == 2){
                        return FALSE;
                    }
                    cpt += 1;
                }
                cpt = 0;
                break;
            }

            case 1:{
                // bas
                for (j = pos_i + 1; j < taille; ++j) {
                    // pas besoin de verifier plus loin que 2 cases
                    if (cpt > 2){
                        break;
                    }
                    if (taku_jeu[j][pos_j] != val){
                        break;
                    }
                    else {
                        if (taku_jeu[j][pos_j] == val){
                            temp += 1;
                        }
                    }
                    // verification pour 2 identiques
                    if (temp == 2){
                        return FALSE;
                    }
                    cpt += 1;
                }
                cpt = 0;
                temp = 0;
                break;
            }

            case 2:{
                //gauche
                for (j = pos_j - 1; j >= 0; --j) {
                    // pas besoin de verifier plus loin que 2 cases
                    if (cpt > 2){
                        break;
                    }
                    if (taku_jeu[pos_i][j] != val){
                        break;
                    }
                    else {
                        if (taku_jeu[pos_i][j] == val){
                            temp += 1;
                        }
                    }
                    // verification pour 2 identiques
                    if (temp == 2){
                        return FALSE;
                    }
                    cpt += 1;
                }
                cpt = 0;
                break;
            }

            case 3:{
                // droite
                for (j = pos_j + 1; j < taille; ++j) {
                    // pas besoin de verifier plus loin que 2 cases
                    if (cpt > 2){
                        break;
                    }
                    if (taku_jeu[pos_i][j] != val){
                        break;
                    }
                    else {
                        if (taku_jeu[pos_i][j] == val){
                            temp += 1;
                        }
                    }
                    // verification pour 2 identiques
                    if (temp == 2){
                        return FALSE;
                    }
                    cpt += 1;
                }
                cpt = 0;
                break;
            }
        }
    }
    return TRUE;
}

int verification_lig_col(int taille, int pos_i, int pos_j, int** taku_jeu){
    int cpt = 0, t = 0, i, j, k;
    int* tab = (int*) malloc(taille * sizeof (int ));
    //******************************* LIGNE : *******************************
    // Vérifie qu'il n'y a que 2 cases vides sur la ligne concernée
    for (i = 0; i < taille; ++i) {
        if (taku_jeu[pos_i][i] == -1){
            cpt++;
        }
    }
    if (cpt == taille-3){
        // Vérifie qu'il n'y a que 2 cases vides sur la ligne concernée
        // Puis vérifie qu'aucunes lignes ne sont identiques entre-elles
        cpt = 0;
        for (i = 0; i < taille; ++i) {
            for (j = 0; j < taille; ++j) {
                // verifie que les lignes sont pleines
                if ((taku_jeu[i][j] == 0) || (taku_jeu[i][j] == 1)){
                    cpt++;
                }
                if (cpt == taille-1){
                    // indexe le numéro des lignes pleines dans le tableau
                    tab[t] = i;
                    t++;
                }
            }
            cpt = 0;
        }
        for (i = t; i < taille; ++i) {
            // Sécurise la non-utilisation des autres cases pour ne pas qu'une valeur au hasard aie la même valeur qu'un numéro de ligne
            tab[i] = -1;
        }
        for (i = 0; i < taille; ++i) {
            if (tab[i] == -1){
                break;
            }
            for (k = 0; k < taille; ++k) {
                if (taku_jeu[tab[i]][k] == taku_jeu[pos_i][k]){
                    cpt++;
                }
            }
            if (cpt == taille-3){
                free(tab);
                return FALSE;
            }
        }
    }
    // ******************************* COLONNE : *******************************
    // Vérifie qu'aucunes colonnes ne sont identiques entre-elles
    cpt = 0;
    t = 0;
    for (i = 0; i < taille; ++i) {
        if (taku_jeu[i][pos_j] == -1){
            cpt++;
        }
    }
    if (cpt == taille-3){
        // Vérifie qu'il n'y a que 2 cases vides sur la colonne concernée
        // Puis vérifie qu'aucunes colonnes ne sont identiques entre-elles
        cpt = 0;
        for (i = 0; i < taille; ++i) {
            for (j = 0; j < taille; ++j) {
                // verifie que les colonnes sont pleines
                if ((taku_jeu[j][i] == 0) || (taku_jeu[j][i] == 1)){
                    cpt++;
                }
                if (cpt == taille-1){
                    // indexe le numéro des lignes pleines dans le tableau
                    tab[t] = i;
                    t++;
                }
            }
            cpt = 0;
        }
        for (i = t; i < taille; ++i) {
            // Sécurise la non-utilisation des autres cases (à partir de la dernière valeur) pour ne pas qu'une valeur au hasard aie la même valeur qu'un numéro de ligne
            tab[i] = -1;
        }
        for (i = 0; i < taille; ++i) {
            if (tab[i] == -1){
                break;
            }
            for (k = 0; k < taille; ++k) {
                if (taku_jeu[k][tab[i]] == taku_jeu[k][pos_j]){
                    cpt++;
                }
            }
            if (cpt == taille-3){
                free(tab);
                return FALSE;
            }
        }
    }
    free(tab);
    return TRUE;
}

int verification_nb_iden(int taille, int pos_i, int pos_j, int val, int** taku_jeu){
    // Vérifie s'il y a le même nombre de 0 et de 1 dans la ligne ou la colonne
    int cpt = 0;
    for (int i = 0; i < taille; ++i) {
        if (val == taku_jeu[i][pos_j]){
            cpt += 1;
        }
        if (cpt >= (taille/2)){
            return FALSE;
        }
    }
    cpt = 0;
    for (int j = 0; j < taille; ++j) {
        if (val == taku_jeu[pos_i][j]){
            cpt += 1;
        }
        if (cpt >= (taille/2)){
            return FALSE;
        }
    }
    return TRUE;
}

int verif_regles_taku(int** tab_game, int x, int y, int val, int taille, int* indice)
{
    if (verification_cote(val, taille, x, y, tab_game) == FALSE)
    {
        modif_indice(indice, 0, 1);
        return FALSE;
    }
    else if (verification_lig_col(taille, x, y, tab_game) == FALSE)
    {
        modif_indice(indice, 1, 1);
        return FALSE;

    }
    else if (verification_nb_iden(taille, x, y, val, tab_game) == FALSE)
    {
        modif_indice(indice, 2, 1);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int* indice_init()
/*
 * Function indice_init()
 * ----------------------
 * Initialise la fonction avec un tableau dyn de val 0 et de taille 3
 * Position 1: Règle verification_cote()
 * Position 2: Règle verification_lig_col()
 * Position 3: Règle verification_nb_iden()
 *
 * Si la valeur est à 0, c'est que la règle est pour l'instant respecté
 * Si la valeur est à 1, la règle correspondante n'est pas respecté. Il faut donc transmettre la raison/indice au joueur.
 *
 * return: pointeur sur tableau
 */
{
    int* indice = (int*) calloc(3, sizeof (int));
    return indice;
}

void supprime_indice(int* indice)
{
    free(indice);
}

void recherche_indice(int* indice, int player)
{
    if (indice[0] == 1)
    {
        if (player == TRUE)
        {
            printf("\nAttention ! La règle suivante n'est pas respectée : \033[0;31mDans une ligne ou une colonne, il ne peut y avoir plus de deux 0 ou deux 1 à la suite (on ne peut pas avoir\n"
                   "trois 0 de suite ou trois 1 de suite).\n\033[0m");
        }
        printf("\nIndice : \n\033[0;32mAu-dessus, en dessous, à gauche, à droite d’une série de deux 0,il ne peut y avoir qu’un 1."
               "\n\033[0;32mAu-dessus, en dessous, à gauche, à droite d’une série de deux 1,il ne peut y avoir qu’un 0.\n\033[0m");
        modif_indice(indice, 0, 0);
    }
    else if (indice[1] == 1)
    {
        if (player == TRUE)
        {
            printf("\nAttention ! La règle suivante n'est pas respectée : \033[0;31mIl ne peut pas y avoir deux lignes/colonnes identiques dans une grille.\n\033[0m");
        }
        printf("\nIndice : \n\033[0;32mEn comparant une ligne (ou une colonne) déjà̀ remplie avec une ligne (ou une colonne) à laquelle il manque 2 valeurs, si toutes les valeurs correspondent, alors on peut remplir la ligne (ou la colonne) à laquelle il manque deux valeurs.\n\033[0m");
        modif_indice(indice, 1, 0);
    }
    else if(indice[2] == 1)
    {
        if (player == TRUE)
        {
            printf("Attention ! La règle suivante n'est pas respectée : \033[0;31mDans une ligne/colonne, il doit y avoir autant de 0 que de 1.\n\033[0m");
        }

        printf("\nIndice : \n\033[0;32mEntre deux 0, il ne peut y avoir qu’un 1."
               "\n\033[0;32mEntre deux 1, il ne peut y avoir qu’un 0.\033[0m\n");
        modif_indice(indice, 2, 0);
    }
}

void modif_indice(int* indice, int index_indice, int val)
{
    indice[index_indice] = val;
}

int grille_pleine(int** tab_sol, int**tab_game, int taille)
{
    int isCorrect = TRUE;
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (tab_sol[i][j] != tab_game[i][j])
            {
                isCorrect = FALSE;
            }
        }
    }
    return isCorrect;
}

int verification_ligne_sol(int* tab_sol, int taille, int val){
    int cpt = 0, i, temp = -2;
    for (i = 0; i < taille; ++i) {
        if (tab_sol[i] == temp) {
            cpt++;
            if (cpt == 2){
                return FALSE;
            }

        } else {
            cpt = 0;
        }
        temp = tab_sol[i];
    }
    return TRUE;
}