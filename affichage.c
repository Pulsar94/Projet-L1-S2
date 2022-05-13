#include <stdio.h>
#include "affichage.h"

char alph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

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