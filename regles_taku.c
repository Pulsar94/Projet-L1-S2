//
// noms des créateurs
//

#include "regles_taku.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int verification_cote (int val, int taille, int pos_i, int pos_j, int** taku_lig) {
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
                    if (taku_lig[j][pos_j] != val){
                        break;
                    }
                    else {
                        if (taku_lig[j][pos_j] == val){
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
                    if (taku_lig[j][pos_j] != val){
                        break;
                    }
                    else {
                        if (taku_lig[j][pos_j] == val){
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
                    if (taku_lig[pos_i][j] != val){
                        break;
                    }
                    else {
                        if (taku_lig[pos_i][j] == val){
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
                    if (taku_lig[pos_i][j] != val){
                        break;
                    }
                    else {
                        if (taku_lig[pos_i][j] == val){
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

void verification_lig_col(){
    // Vérifie aucunes lignes et colonnes sont identiques

}

void verification_nb_iden(int taille, int pos_i, int pos_j, int** taku_lig){
    // Vérifie s'il y a le même nombre de 0 et de 1 dans la ligne ou la colonne

}
