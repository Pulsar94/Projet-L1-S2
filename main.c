#include <stdio.h>

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
        printf("Welcome in Takuzu. Please choose a menu : \n"
               "1 - Play on a grid.\n"
               "2 - Solve automatically a grid of Takuzu.\n"
               "3 - Generate a grid of Takuzu.\n"
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
                printf("Exiting menu...");
                break;
            }
            default: printf("Choice not available. Please try again.\n");
        }
    } while (choice != 4);
}