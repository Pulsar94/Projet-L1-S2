#ifndef PROJET_L1_S2_MATRICE_H
#define PROJET_L1_S2_MATRICE_H


int** creation_mat_modele(int);
int** creation_matrice(int);
void libere_matrice(int, int**);
int verification_cote(int, int, int, int, int**);
int** generation_solution(int, int**);
int** creer_masque_aleat(int);
int** creer_masque_spe(int);
int input_into_masque(int**, int, char, int, int);
int** takuzu_utilisateur(int**, int**, int, int);

#endif //PROJET_L1_S2_MATRICE_H
