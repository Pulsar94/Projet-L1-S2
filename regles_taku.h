//
// Created by thiba on 13/05/2022.
//

#ifndef PROJET_L1_S2_REGLES_TAKU_H
#define PROJET_L1_S2_REGLES_TAKU_H


int verification_cote (int, int, int, int, int**);
int verification_lig_col(int, int, int, int**);
int verification_nb_iden(int, int, int, int, int**);
int verif_regles_taku(int** tab_game, int x, int y, int val, int taille);
int grille_pleine(int** tab_sol, int**tab_game, int taille);


#endif //PROJET_L1_S2_REGLES_TAKU_H
