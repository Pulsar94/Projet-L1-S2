#ifndef LAB_AFFICHAGE_H
#define LAB_AFFICHAGE_H

void affichage_matrice(int** tab, int taille);
int alpha_to_indice(char c, int taille);
int input_into_matrice(int**tab, int x, char y_char, int val, int taille);
int verif_legal_input(int taille, int x, int y, int val);
void game(int** tab, int taille);

#endif