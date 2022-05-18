#include <stdio.h>

#include "regles_taku.h"
#include "matrice.h"
#include "game_control.h"

#define INCORECT 4
#define VALIDE 3
#define CORRECT 2
#define TRUE 1
#define FALSE 0
char alpha_maj[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
char alpha_min[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};

void affichage_matrice(int** tab, int taille, int type_of_matrice)
/*
 * Fonction: affichage_matrice
 * -----------------
 * Permet l'affichage de la matrice sur la console de manière propre et dynamique
 * 
 * tab: pointeur sur tableau
 * taille: taille du tableau
 * type_of_matrice:
 *      if 1: matrice de type jeu/solution
 *      if 2: matrice de type masque
 *
 */
{
    switch (type_of_matrice) {
        case 1: {
            for (int i = 0; i < taille; i++) {
                printf("\t%c", alpha_maj[i]);
            }
            printf("\n");

            for (int i = 0; i < taille; i++) {
                printf("  ");
                for (int j = 0; j < taille; j++) {
                    printf("+---");
                }
                printf("+\n");
                printf("%d ", i + 1);
                for (int j = 0; j < taille; j++) {
                    if (tab[i][j] == -1) {
                        printf("|   ");
                    } else {
                        printf("| %d ", tab[i][j]);
                    }
                }
                printf("|\n");
            }
            printf("  ");
            for (int j = 0; j < taille; j++) {
                printf("+---");
            }
            printf("+\n");
            break;
        }
        case 2:
        {
            for (int i = 0; i < taille; i++) {
                printf("\t%c", alpha_maj[i]);
            }
            printf("\n");

            for (int i = 0; i < taille; i++) {
                printf("  ");
                for (int j = 0; j < taille; j++) {
                    printf("+---");
                }
                printf("+\n");
                printf("%d ", i + 1);
                for (int j = 0; j < taille; j++) {
                        printf("| %d ", tab[i][j]);
                    }
                printf("|\n");
                }
            }
            printf("  ");
            for (int j = 0; j < taille; j++) {
                printf("+---");
            }
            printf("+\n");
            break;
        }
}

int alpha_to_indice(char c, int taille)
/*
 * Fonction: alpha_to_indice
 * -----------------
 * Permet de convertir l'input du joueur de la lettre colonne en sa position dans l'alphabet
 *
 * c: charactère
 * taille: taille du tableau
 *
 * return: y (index de c dans alpha). Si lettre non correspondante
 *
 */
{
  int y = -1;
  for(int i = 0; i<taille; i++)
    {
      if (alpha_maj[i] == c)
      {
        y = i;
      }
      else if (alpha_min[i] == c)
      {
          y = i;
      }
    }
  return y;
}

int verif_legal_input(int taille, int x, int y, int val)
/*
 * Fonction: verif_legal_input
 * -----------------
 * Permet de vérifier si l'input est légal ou non
 * Conditions: x et y doivent être positif et inférieur à la taille du tableau, val doit être égale à 0 ou 1
 *
 * taille: taille du tableau
 * x: position x de val
 * y: position y de val
 * val: valeur choisie par l'utilisateur (0 ou 1)
 *
 * return: boolean en fonction de condition respectée ou non
 *
 */
{
  if(((y >= 0) && (y < taille)) && ((x >= 0) && (x < taille)) && ((val == 0) || (val == 1)))
  {
    return TRUE;
  }
  return FALSE;
}

int input_into_matrice(int** tab_game, int** tab_solu, int x, char y_char, int val, int taille, int* indice)
/*
 * Fonction: input_into_matrice
 * -----------------
 * Injecte la valeur dans le Takuzu
 * Convertie la valeur y_char qui est un input de type char en sa position dans l'alphabet par la fonction alpha_to_indice()
 * Condition: Vérifie tout d'abord avec la fonction verif_legal_input() si la valeur est autorisée ou non.
 *
 * tab_game: pointeur de tableau du jeu
 * tab_solu: pointeur de tableau sur solution
 * x: position x de val
 * y_char: position y de val (lettre correspondante)
 * val: valeur choisie par l'utilisateur (0 ou 1)
 * taille: taille du tableau
 * indice: pointeur sur tableau d'indice
 *
 * return: boolean en fonction de condition respectée ou non
 *
 */
{
  int y = alpha_to_indice(y_char, taille);
  x--;
  if ((y != -1) && (verif_legal_input(taille, x, y, val) == TRUE))
  {

      if(tab_solu[x][y] == val)
      {
          tab_game[x][y] = val;
          return CORRECT;
      }
      else
      {
          if (verif_regles_taku(tab_game, x, y, val, taille, indice) == TRUE)
          {
              return VALIDE;
          }
          else
          {
              return INCORECT;
          }
      }
  }
  return FALSE;
}
int sortie_de_zone_input(char y_char, int x, int val)
/*
 * Fonction: sortie_de_zone_input
 * ------------------------------
 * Permet de sortir de la zone de saisie lors de situation grilles/masques
 *
 * y_char: caractère
 * x: entier
 * val: entier
 *
 * return: bool
 */
{
    if ((y_char == 'z' || y_char == 'Z') && x == 0 && val == 0)
    {
        return TRUE;
    }
    return FALSE;
}
//
void game(int** tab_game, int**tab_solu, int taille)
/*
 * Fonction: game
 * ---------------
 * Fonction opérant sur le jeu.
 * Indique si le coup est valide, correct ou incorrect.
 * L'utilisateur à 3 vies.
 * La grille de solution est présentée si le joueur joue jusqu'à la fin.
 * Tout en donnant des indices et rappels de quels règles non respectés.
 *
 * tab_game: grille_jeu
 * tab_solu: grille de solution
 * taille: taille de la grille
 *
 */
{
    int resolved = FALSE;
    char y;
    int x, val;
    int* indice = indice_init();
    int HP = 3;

    do
    {
        affichage_matrice(tab_game, taille, 1);
        printf("\nSaisir une valeur à injecter sous la forme \nCOLONNE(LETTRE) LIGNE(CHIFFRE) 0/1(VALEUR)\nPour sortir du jeu, entrez \033[2;36mZ 0 0\n\033[0;34mChoix :\033[0m ");
        scanf(" %c %d %d", &y, &x, &val);

        int bool_input_matrice = input_into_matrice(tab_game, tab_solu, x, y, val, taille, indice);

        // VERIF IF INPUT IS LEGAL OR NOT
        if ((bool_input_matrice == FALSE) && (sortie_de_zone_input(y, x, val) == FALSE))
        {
            printf("\nSaisie illégale\n");
        }
        else if (sortie_de_zone_input(y, x, val == TRUE))
        {
            printf("\nSortie du jeu...\n");
        }
        else
        {
            // VERIF IF INPUT IS VALID OR NOT
            if (bool_input_matrice == CORRECT) // COUP CORRECT ?
            {
                printf("\n\033[1;32m-+-+-+-+-+ COUP CORRECT !-+-+-+-+-+\n\033[0m");
            } else {
                if (bool_input_matrice == INCORECT) // COUP INCORRECT ?
                {
                    printf("\n\033[1;31m-+-+-+-+-+ COUP INCORRECT !-+-+-+-+-+\nIl ne respecte pas les règles du Takuzu !\n\033[0m");
                    recherche_indice(indice, TRUE);
                    printf("\nVous perdez une vie. Points de vie actuel : %d\n", --HP);
                } else // COUP VALIDE
                {
                    printf("\n-+-+-+-+-+ COUP VALIDE !-+-+-+-+-+\n Il respecte les règles du Takuzu mais n'est pas la solution.\n");
                }
            }
        }

        // VERIF ENDGAME
        if (grille_pleine(tab_solu, tab_game, taille) == TRUE)
        {
            resolved = TRUE;
        }


    } while(((HP > 0) && (resolved == FALSE)) && sortie_de_zone_input(y, x, val) != TRUE);
    if (sortie_de_zone_input(y, x, val) == TRUE)
    {
        printf("\n-+-+-+-+-+-+-+-+-+\nFIN DU JEU\n-+-+-+-+-+-+-+-+-+\n");
    }
    else if (HP == 0)
    {
        printf("\n-+-+-+-+-+-+-+-+-+\nPerdu ! \nVous n'avez plus de vie :c\n-+-+-+-+-+-+-+-+-+\n");
        printf("Grille solution :\n");
        affichage_matrice(tab_solu, taille, 1);
    }
    else if (resolved == TRUE)
    {
        printf("\n-+-+-+-+-+-+-+-+-+\nVictoire !\nVous avez terminée la grile !\n-+-+-+-+-+-+-+-+-+\n");
        printf("Grille solution :\n");
        affichage_matrice(tab_solu, taille, 1);
    }
    supprime_indice(indice);
}