#ifndef LAB_AFFICHAGE_H
#define LAB_AFFICHAGE_H

void affichage_matrice(int**, int, int);
int alpha_to_indice(char c, int);
int input_into_matrice(int**, int**, int, char, int, int, int*);
int verif_legal_input(int, int, int, int);
int sortie_de_zone_input(char, int, int);
void game(int**, int**, int);

#endif