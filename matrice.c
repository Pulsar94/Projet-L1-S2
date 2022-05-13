#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


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
    int** taku_lig = (int**) malloc(taille * sizeof (int));
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

void creer_masque() {
    // Masque qui détermine l'affichage Takuzu utilisateur
}

void takuzu_utilisateur() {
    // Takuzu visible par l'utilisateur

}

