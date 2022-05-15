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
        if (cpt > (taille/2)){
            return FALSE;
        }
    }
    cpt = 0;
    for (int j = 0; j < taille; ++j) {
        if (val == taku_jeu[pos_i][j]){
            cpt += 1;
        }
        if (cpt > (taille/2)){
            return FALSE;
        }
    }
    return TRUE;
}

int grille_pleine(int** tab_sol, int**tab_game, int taille)
{
    int i = 0, j = 0;
    while(i < taille && i != -1 && j != -1)
    {
        while(j < taille && i != -1 && j != -1)
        {
            if (tab_game[i][j] == -1)
            {
                i = -1; j = -1;
            }
            else
            {
                j++;
            }
        }
        if (j != -1)
        {
            i++;
        }
    }
    if ((i > taille) && (j > taille))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}