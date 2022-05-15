//
// Created by thiba on 13/05/2022.
//

#ifndef PROJET_L1_S2_REGLES_TAKU_H
#define PROJET_L1_S2_REGLES_TAKU_H


int verification_cote (int, int, int, int, int**);
int verification_lig_col(int, int, int, int**);
int verification_nb_iden(int, int, int, int, int**);
int verif_regles_taku(int**, int, int, int, int, int*);
int grille_pleine(int**, int**, int);
int* indice_init();
void supprime_indice(int*);
void recherche_indice(int*, int);
void modif_indice(int*, int, int);
int verification_ligne_sol(int*, int);
int verification_colonne_sol(int**, int);
int verification_nombre_sol_col(int, int**);
int verification_nombre_sol_lig(int, int*);


#endif //PROJET_L1_S2_REGLES_TAKU_H
