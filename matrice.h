#ifndef PROJET_L1_S2_MATRICE_H
#define PROJET_L1_S2_MATRICE_H


int** creation_mat_modele(int);
int** creation_matrice(int);
void libere_matrice(int, int**);
int verification_cote(int, int, int, int, int**);
void verification_lig_col();
void verification_nb_iden();
void generation_solution(int, int**);
void creer_masque_aleat();
void creer_masque_spe();
void takuzu_utilisateur();

#endif //PROJET_L1_S2_MATRICE_H
