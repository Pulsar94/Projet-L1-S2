#include <stdio.h>
#include "affichage.h"

#define TRUE 1
#define FALSE 0
char alph[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

void affichage_matrice(int** tab, int taille)
/*
 * Fonction: affichage_matrice
 * -----------------
 * Permet l'affichage de la matrice sur la console de manière propre et dynamique
 * 
 * tab: pointeur sur tableau
 * taille: taille du tableau
 *
 */
{
  for(int i=0; i<taille; i++)
  {
    printf("\t%c", alph[i]);
  }
  printf("\n");

  for(int i=0; i<taille; i++)
  {
    printf("  ");
    for(int j=0; j<taille; j++)
    {
      printf("+---");
    }
    printf("+\n");
    printf("%d ", i + 1);
    for(int j=0; j<taille; j++)
    {
      if(tab[i][j] == -1)
      {
        printf("|   ");
      }
      else
      {
      printf("| %d ", tab[i][j]);  
      }
    }
    printf("|\n");
  }
  printf("  ");
  for(int j=0; j<taille; j++)
  {
    printf("+---");
  }
  printf("+\n");
}

int alpha_to_indice(char c, int taille)
{
  int y = -1;
  for(int i = 0; i<taille; i++)
    {
      if (alph[i] == c)
      {
        y = i;
      }
    }
  return y;
}

int verif_legal_input(int taille, int x, int y, int val)
{
  if(((y >= 0) && (y < taille)) && ((x >= 0) && (x < taille)) && ((val == 0) || (val == 1)))
  {
    return TRUE;
  }
  return FALSE;
}

int input_into_matrice(int**tab, int x, char y_char, int val, int taille)
{
  int y = alpha_to_indice(y_char, taille);
  x--;
  if ((y != -1) && (verif_legal_input(taille, x, y, val) == TRUE))
  {
    tab[x][y] = val;
    return TRUE;
  }
  return FALSE;
}