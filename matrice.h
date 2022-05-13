#ifndef PROJET_L1_S2_MATRICE_H
#define PROJET_L1_S2_MATRICE_H

int matrice4[4][4] = {{1,0,0,1},
                      {1,0,1,0},
                      {0,1,1,0},
                      {0,1,0,1}};

int matrice8[8][8] = {{1,0,1,1,0,1,0,0},
                      {1,0,1,0,1,0,0,1},
                      {0,1,0,1,1,0,1,0},
                      {0,1,0,1,0,1,1,0},
                      {1,0,1,0,0,1,0,1},
                      {0,1,0,0,1,0,1,1},
                      {0,0,1,1,0,1,1,0},
                      {1,1,0,0,1,0,0,1}};


int** creation_matrice(int);
void libere_matrice(int, int**);
int verification_cote(int, int, int, int, int**);
void verification_lig_col();
void verification_nb_iden();
void generation_solution(int, int**);
void creer_masque();
void takuzu_utilisateur();

#endif //PROJET_L1_S2_MATRICE_H
