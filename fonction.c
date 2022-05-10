#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** creation_matrice(int taille) {
    // Création d'une matrice carrée
    // taku_lig représente les lignes de la matrice, autrement dit la porte d'entrée
    int** taku_lig = (int**) malloc(taille * sizeof (int));
    for (int i = 0; i < taille; ++i) {
        int* taku_col = (int*) malloc(taille * sizeof(int));
        taku_lig[i] = taku_col;
    }
    return taku_lig;
}

void libere_matrice(int taille, int** taku_lig){
    // Free de la matrice carrée
    // taku_lig représente les lignes de la matrice, autrement dit la porte d'entrée
    for (int i = 0; i < taille; ++i) {
        free(taku_lig[i]);
        taku_lig[i] = NULL;
    }
    free(taku_lig);
    taku_lig = NULL;
}

void generation_solution(int taille){
    // Matrice Takuzu solution
}


void creer_masque() {
    // Masque qui détermine l'affichage Takuzu utilisateur

}

void takuzu_utilisateur() {
    // Takuzu visible par l'utilisateur

}

