#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep function
#include <time.h>

#include "matrice.h"
#include "game_control.h"
#include "auto_resolve.h"

#define TRUE 1
#define FALSE 0

void welcome();
void main_menu();
void freeplay_menu();
int masque_menu();
void autoresolve_menu();
void autogenerate_grid_menu();

int main() {
    // initialisation de la seed sur le temps
    srand(time(NULL));

    // Welcome message
    welcome();

    printf("\n");

    // Select menu
    main_menu();

    printf("\n\n-+-+-+-+-+-+-+-+-+\nSortie du programme.\n-+-+-+-+-+-+-+-+-+\n");

    return 0;
}

void welcome()
/*
 * Function: welcome
 * -----------------
 * Just a welcome block
 * Sign generated by : https://fsymbols.com/generators/wide/
 */
{
    printf("\033[0;34m░░░░░░░░░░░░░░░░░░\033[0m░░░░░░░░░░░░░░░░░░░\033[0;31m░░░░░░░░░░░░░░░░░░░\n"
           "\033[0;34m████████╗ ░█████╗░\033[0m ██╗░░██╗ ██╗░░░██╗\033[0;31m ███████╗ ██╗░░░██╗\n"
           "\033[0;34m╚══██╔══╝ ██╔══██╗\033[0m ██║░██╔╝ ██║░░░██║\033[0;31m ╚════██║ ██║░░░██║\n"
           "\033[0;34m░░░██║░░░ ███████║\033[0m █████═╝░ ██║░░░██║\033[0;31m ░░███╔═╝ ██║░░░██║\n"
           "\033[0;34m░░░██║░░░ ██╔══██║\033[0m ██╔═██╗░ ██║░░░██║\033[0;31m ██╔══╝░░ ██║░░░██║\n"
           "\033[0;34m░░░██║░░░ ██║░░██║\033[0m ██║░╚██╗ ╚██████╔╝\033[0;31m ███████╗ ╚██████╔╝\n"
           "\033[0;34m░░░╚═╝░░░ ╚═╝░░╚═╝\033[0m ╚═╝░░╚═╝ ░╚═════╝░\033[0;31m ╚══════╝ ░╚═════╝░\n"
           "\033[0;34m░░░░░░░░░░░░░░░░░░\033[0m░░░░░░░Marque dépos\033[0;31mée le 31/01/2006░░░\n");
    printf("\033[0m");
}
void main_menu()
/*
 * Function: main_menu
 * -----------------
 * Menu principal, l'utilisateur à trois choix possible
 */
{
    int choice = -1;
    do {
        printf("\033[1mMenu principal. \033[2;34mChoisissez votre menu : \033[0m\n"
               "1 - Résoudre une grille.\n"
               "2 - Résoudre automatiquement une grille de Takuzu.\n"
               "3 - Génère une grille de Takuzu.\n"
               "4 - Quitter le programme.\n"
               "\033[0;34mChoix : \033[0m");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            {
                freeplay_menu();
                break;
            }
            case 2:
            {
                autoresolve_menu();
                break;
            }
            case 3:
            {
                autogenerate_grid_menu();
                break;
            }
            case 4:
            {
                break;
            }
            default: printf("Choix non valide. SVP essayez a nouveau.\n");
        }
    } while (choice != 4);
}

void freeplay_menu()
{
    int choice = -1;
    do {
        printf("\033[0;34mQuelle taille de grille souhaitez-vous ?\n\033[0mTailles disponible : \033[0;32m4\033[0m, \033[0;33m8, \033[0;31m16 \033[0m(Choisissez \033[0;36m0\033[0m pour revenir au menu principal)\n\033[0;34mChoix :\033[0m ");
        scanf("%d", &choice);

        if (choice == 4 || choice == 8 || choice == 16)
        {
            int** grille_solution = creation_mat_modele(choice);
            int** grille_jeu = creation_mat_modele(choice);

            int choice_masque = masque_menu();

            printf("\n-+-+-+-+-+-+-+-+-+ MASQUE -+-+-+-+-+-+-+-+-+\n");
            int** grille_masque = takuzu_utilisateur(grille_solution, grille_jeu, choice, choice_masque);
            affichage_matrice(grille_masque, choice, 2);
            printf("\n-+-+-+-+-+-+-+-^^ MASQUE ^^-+-+-+-+-+-+-+-+-\n");


            game(grille_jeu, grille_solution, choice);
            sleep(3); // Cooldown : 3 sec le temps qu'il regarde sa grille
            printf("Retour au ");
            libere_matrice(choice, grille_jeu);
            libere_matrice(choice, grille_solution);
        }
        /*
        else {
            if (choice == 16) {
                printf("\n\033[0;31m*Zone pas encore terminée*\n");
            } else {
                if (choice == 0) {
                    printf("Sortie en cours...\n");
                } else {
                    printf("Taille indisponible ou non reconnue. Veuillez réessayer.\n");
                }
            }
        }*/

    } while (!(choice == 4 || choice == 8 || choice == 16 || choice == 0));
    //printf("\n-+-+-+-+-+-+-+-+-+\nSortie du grid_menu().\n-+-+-+-+-+-+-+-+-+\n");
}

void autoresolve_menu()
{
    int choice = -1;
    do {
        printf("\033[0;34mQuelle taille de grille souhaitez-vous ?\n\033[0mTailles disponible : \033[0;32m4\033[0m, \033[0;33m8, \033[0;31m16 \033[0m(Choisissez \033[0;36m0\033[0m pour revenir au menu principal)\n\033[0;34mChoix :\033[0m ");
        scanf("%d", &choice);

        if (choice == 4 || choice == 8 || choice == 16)
        {
            int** grille_solution = creation_mat_modele(choice);
            int** grille_jeu = creation_mat_modele(choice);

            int choice_masque = masque_menu();

            printf("\n-+-+-+-+-+-+-+-+-+ MASQUE -+-+-+-+-+-+-+-+-+\n");
            int** grille_masque = takuzu_utilisateur(grille_solution, grille_jeu, choice, choice_masque);
            affichage_matrice(grille_masque, choice, 2);
            printf("\n-+-+-+-+-+-+-+-^^ MASQUE ^^-+-+-+-+-+-+-+-+-\n");

            auto_resolve(grille_jeu, grille_solution, choice, TRUE);

            printf("Retour au ");
            libere_matrice(choice, grille_jeu);
            libere_matrice(choice, grille_solution);
        }
        /*
        else {
            if (choice == 16) {
                printf("\n\033[0;31m*Zone pas encore terminée*\n");
            } else {
                if (choice == 0) {
                    printf("Sortie en cours...\n");
                } else {
                    printf("Taille indisponible ou non reconnue. Veuillez réessayer.\n");
                }
            }
        }*/

    } while (!(choice == 4 || choice == 8 || choice == 16 || choice == 0));
}

void autogenerate_grid_menu()
{
    int choice = -1;
    do {
        printf("\033[0;34mQuelle taille de grille souhaitez-vous ?\n\033[0mTailles disponible : \033[0;32m4\033[0m, \033[0;33m8, \033[0;31m16 \033[0m(Choisissez \033[0;36m0\033[0m pour revenir au menu principal)\n\033[0;34mChoix :\033[0m ");
        scanf("%d", &choice);

        if (choice == 4 || choice == 8)
        {
            int** grille_solution = creation_mat_modele(choice);
            int** grille_jeu = creation_mat_modele(choice);
            /*
            int choice_masque = masque_menu();

            printf("\n-+-+-+-+-+-+-+-+-+ MASQUE -+-+-+-+-+-+-+-+-+\n");
            int** grille_masque = takuzu_utilisateur(grille_solution, grille_jeu, choice, choice_masque);
            affichage_matrice(grille_masque, choice, 2);
            printf("\n-+-+-+-+-+-+-+-^^ MASQUE ^^-+-+-+-+-+-+-+-+-\n");
            */
            generation_solution(choice, grille_jeu);

            printf("Retour au ");
            libere_matrice(choice, grille_jeu);
            libere_matrice(choice, grille_solution);
        }
        /*
        else {
            if (choice == 16) {
                printf("\n\033[0;31m*Zone pas encore terminée*\n");
            } else {
                if (choice == 0) {
                    printf("Sortie en cours...\n");
                } else {
                    printf("Taille indisponible ou non reconnue. Veuillez réessayer.\n");
                }
            }
        }*/

    } while (!(choice == 4 || choice == 8 || choice == 0));
}

int masque_menu()
{
    int choice_masque = -1;

    do
    {
        printf("\033[0;34mVeuillez choisir un type de masque.\033[0m\n"
               "1. Masque manuellement saisie.\n"
               "2. Masque aléatoire.\n"
               "\033[0;34mChoix :\033[0m ");
        scanf("%d", &choice_masque);

        if (!(choice_masque == 1 || choice_masque == 2))
        {
            printf("Choix du masque incorrect. Veuillez réessayer.\n");
        }

    } while (!(choice_masque == 1 || choice_masque == 2));

    return choice_masque;
}