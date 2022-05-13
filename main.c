#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matrice.h"


void welcome();
/*
 * Function: welcome
 * -----------------
 * Just a welcome block
 * Sign generated by : https://fsymbols.com/generators/wide/
 */
void menu();
/*
 * Function: menu
 * -----------------
 * Menu to choice
 */

int main() {
    // initialisation de la seed sur le temps
    srand(time(NULL));

    // Welcome message
    welcome();

    printf("\n");

    // Select menu
    menu();

    return 0;
}

void welcome()
{
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
           "████████╗ ░█████╗░ ██╗░░██╗ ██╗░░░██╗ ███████╗ ██╗░░░██╗\n"
           "╚══██╔══╝ ██╔══██╗ ██║░██╔╝ ██║░░░██║ ╚════██║ ██║░░░██║\n"
           "░░░██║░░░ ███████║ █████═╝░ ██║░░░██║ ░░███╔═╝ ██║░░░██║\n"
           "░░░██║░░░ ██╔══██║ ██╔═██╗░ ██║░░░██║ ██╔══╝░░ ██║░░░██║\n"
           "░░░██║░░░ ██║░░██║ ██║░╚██╗ ╚██████╔╝ ███████╗ ╚██████╔╝\n"
           "░░░╚═╝░░░ ╚═╝░░╚═╝ ╚═╝░░╚═╝ ░╚═════╝░ ╚══════╝ ░╚═════╝░\n"
           "░░░░░░░░░░░░░░░░░░░░░░░░░Marque déposée le 31/01/2006░░░\n");
}
void menu()
{
    int choice = -1;
    do {
        printf("Bienvenu dans le jeux du Takuzu. Choisissez votre menu : \n"
               "1 - Resoudre une grille.\n"
               "2 - Resoudre automatiquement une grille  de Takuzu.\n"
               "3 - Generer une grille de Takuzu.\n"
               "4 - Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            {
                // 1
                break;
            }
            case 2:
            {
                // 2
                break;
            }
            case 3:
            {
                // 3
                break;
            }
            case 4:
            {
                printf("Sortie du menu...");
                break;
            }
            default: printf("Choix non valide. SVP essayez a nouveau.\n");
        }
    } while (choice != 4);
}