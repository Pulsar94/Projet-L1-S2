#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** creation_matrice(int taille) {
    // Matrice Takuzu solution
    int** taku_lig = (int**) malloc(taille * sizeof (int));
    for (int i = 0; i < taille; ++i) {
        int* taku_col = (int*) malloc(taille * sizeof(int));
        taku_lig[i] = taku_col;
    }
    return taku_lig;
}

void generation_solution(){

}


void creer_masque() {
    // Masque qui détermine l'affichage Takuzu utilisateur

}

void takuzu_utilisateur() {
    // Takuzu visible par l'utilisateur

}

