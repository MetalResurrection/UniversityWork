#include <stdio.h>
#include <stdlib.h>


int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main() {

    char *menuTitle = "=== Best Video Game Made===";
    char *menuOptions[] =  {
        "Start the Peak",
        "Config",
        "Quit the peak"
    };
    int menuSize = 3;
    char *inputMsg = "Please input your choice: ";





    int choice = showMenu(menuTitle, menuOptions, menuSize, inputMsg);
    printf("You selected option %d.\n", choice);

return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {


    while (1) {

    printf("%s\n", menuTitle);

    for (int i = 0; i < menuSize; i++) {
            printf("%d. %s\n", i+1, menuOptions[i]);
    }

    printf("%s", inputMsg);
    int choice;
    scanf("%d", &choice);



    if(choice >= 1 && choice <= menuSize) {
        return choice;
    }
    else
        printf("Invalid choice. Try again. \n\n");

    }






}

