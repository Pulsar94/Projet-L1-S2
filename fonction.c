#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int** creation_matrice(int taille) {
    // Création d'une matrice carrée
    int** taku_lig = (int**) malloc(taille * sizeof (int));
    for (int i = 0; i < taille; ++i) {
        int* taku_col = (int*) malloc(taille * sizeof(int));
        taku_lig[i] = taku_col;
    }
    return taku_lig;
}

void libere_matrice(int taille, int** taku_lig){
    // Free de la matrice carrée
    for (int i = 0; i < taille; ++i) {
        free(taku_lig[i]);
    }
    free(taku_lig);
}

int verification_cote (int val, int taille, int pos_i, int pos_j, int** taku_lig) {
    // première boucle i = 4 pour vérification sur les quatres directions (haut,bas,droite,gauche)
    int temp = 0, cpt = 0, verif = TRUE;
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:{
                // haut
                for (int j = pos_i - 1; j >= 0; --j) {
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
                    // verification pour 2 identiques au-dessus
                    if (temp == 2){
                        return FALSE;
                    }
                    cpt += 1;
                }
                temp = 0;
                cpt = 0;
                break;
            }

            case 1:{
                // bas
                break;
            }

            case 2:{
                //gauche
                break;
            }

            case 3:{
                // droite
                break;
            }
        }
    }
    
    
}



void generation_solution(int taille, int** taku_lig){
    // Matrice solution du Takuzu
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            taku_lig[i][j] = rand() % 2;
            if (NULL) {
                // besoin de coder les conditions avant de remplir la matrice
            }
        }
    }
}


void creer_masque() {
    // Masque qui détermine l'affichage Takuzu utilisateur
}

void takuzu_utilisateur() {
    // Takuzu visible par l'utilisateur

}

