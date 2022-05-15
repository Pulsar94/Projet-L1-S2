#include <stdio.h>
#include "regles_taku.h"
#include "game_control.h"

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

int input_into_matrice(int**tab, int x, char y_char, int val, int taille)
/*
 * Fonction: input_into_matrice
 * -----------------
 * Injecte la valeur dans le Takuzu
 * Convertie la valeur y_char qui est un input de type char en sa position dans l'alphabet par la fonction alpha_to_indice()
 * Condition: Vérifie tout d'abord avec la fonction verif_legal_input() si la valeur est autorisée ou non.
 *
 * **tab: pointeur de tableau
 * x: position x de val
 * y_char: position y de val (lettre correspondante)
 * val: valeur choisie par l'utilisateur (0 ou 1)
 * taille: taille du tableau
 *
 * return: boolean en fonction de condition respectée ou non
 *
 */
{
  int y = alpha_to_indice(y_char, taille);
  x--;
  if ((y != -1) && (verif_legal_input(taille, x, y, val) == TRUE))
  {
    tab[x][y] = val;
    // function verif();
    return TRUE;
  }
  return FALSE;
}

void game(int** tab_game, int**tab_solu, int taille)
{
    int resolved = FALSE, HP = 3;
    do
    {
        char y;
        int x, val, i = 0;
        affichage_matrice(tab_game, taille, 1);
        printf("\nSaisir une valeur à injecter sous la forme \nCOLONNE(LETTRE) LIGNE(CHIFFRE) 0/1(VALEUR) : ");
        scanf(" %c %d %d", &y, &x, &val);

        // VERIF IF INPUT IS LEGAL OR NOT
        if ((input_into_matrice(tab_game, x, y, val, taille)) == FALSE)
        {
            printf("\nSaisie illégale\n");
        }

        /*// VERIF IF INPUT IS VALID OR NOT
        if (( == TRUE)) // COUP CORRECT ?
        {
            printf("-+-+-+-+-+COUP CORRECT !-+-+-+-+-+");
        }
        else
        {
            if ( == FALSE) // COUP INCORRECT ?
            {
                printf("-+-+-+-+-+COUP INCORRECT !-+-+-+-+-+\n Il ne respecte pas les règles du Takuzu !");
                // INDICE
                printf("\nVous perdez une vie. Points de vie actuel : %d", HP);
            }
            else // COUP CORRECT
            {
                printf("-+-+-+-+-+COUP VALIDE !-+-+-+-+-+\n Il respecte les règles du Takuzu mais n'est pas la solution.");
            }
        }*/
        HP = 0;

    } while(resolved == FALSE && HP < 0);
    if (HP == 0)
    {
        printf("\n-+-+-+-+-+-+-+-+-+\nGAME LOST\n-+-+-+-+-+-+-+-+-+\n");
    }
    else if (resolved == TRUE)
    {
        printf("\n-+-+-+-+-+-+-+-+-+\nGAME WIN\n-+-+-+-+-+-+-+-+-+\n");
    }
    printf("Grille finale :\n");
    affichage_matrice(tab_solu, taille, 1);
}