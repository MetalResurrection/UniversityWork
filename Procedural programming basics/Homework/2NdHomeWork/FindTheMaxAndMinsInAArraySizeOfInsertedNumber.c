//This code will find the maximum and minimum in the array made by the user, it will output the co-ordinate of the number aswell
#include <stdio.h>
#include <stdlib.h>


typedef struct theDesiredArray {
    int *theArrayBoard; //The array itself which will follow the format of theArrayBoard[N][N]
    int sizeOfTheArray; //The size of the array, AKA the N itself
} Array;


void makingTheArray(Array *array);            //The function that assigns the array the given size
void assigningValuesToTheArray(Array *array); //The function that lets you assign values to each single array member
int checkIfTheNumberIsAInteger(Array *array); //The function that checks if a inputed value is a integer
void findingMinAndMax(Array *array);          //The function that finds the max and min numbers and their coordinates


int main() {
    Array array = {NULL, 0};                                                                                 //Declaring the array and initializing it

    printf("Enter board size: ");

    makingTheArray(&array);
    assigningValuesToTheArray(&array);
    findingMinAndMax(&array);

return 0;
}


void makingTheArray(Array *array) {

    int temp;

    while (1) {

        temp = checkIfTheNumberIsAInteger(array);          //Assigns the value thats gotten from the function to a temp value

        if (temp <= 0) {                                   //The array cant be 0 so it declines it
            printf("Board size must be positive!\n");
            continue;
        }

        array->sizeOfTheArray = temp;                      //If its more than 0 is assigns the size of the array to it

        array->theArrayBoard = malloc(                     //Makes the array
            array->sizeOfTheArray *
            array->sizeOfTheArray *
            sizeof(int)
        );

        if (array->theArrayBoard == NULL) {                //A failsafe for memory allocation fail
            printf("Memory allocation failed!\n");
            array->sizeOfTheArray = 0;
            return;
        }

        break;
    }
}


void assigningValuesToTheArray(Array *array) {

    printf("The chosen array size will include %d elements, you will need to input every single value.\n", array->sizeOfTheArray*array->sizeOfTheArray);

    for (int i = 0; i < array->sizeOfTheArray; i++) {
        for (int j = 0; j < array->sizeOfTheArray; j++) {
                printf("What integer would you like to input into [%d][%d]?\n", i, j);
                array->theArrayBoard[i * array->sizeOfTheArray + j] = checkIfTheNumberIsAInteger(array);

        }
    }



}
int checkIfTheNumberIsAInteger(Array *array) {

    int temp;                                   //Variable that gets the number
    char extra;                                 //Variable that gets the extra character after the number
    int result;                                 //Variable that fully checks if the input is correct

    while (1) {


        result = scanf("%d%c", &temp, &extra);

        if (result == 2 && extra == '\n') {    //If its fine it returns temp;
            return temp;
        }

        if (result == EOF) {                   // Prevents code breaking from end of line "ctrl + z"
            return -1;
        }

        printf("Please enter a valid integer!\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);    //Clears the input

        if (ch == EOF) {                                  //If it reaches End Of Line returns -1
            return -1;
        }
    }
}

void findingMinAndMax(Array *array) {

    for (int i = 0; i < array->sizeOfTheArray; i++) {

        //Declares the min and max by the fist value in the array, rather then just 0, cause there might not be numbers lower/higher than 0
        int min = array->theArrayBoard[i * array->sizeOfTheArray];
        int max = array->theArrayBoard[i * array->sizeOfTheArray];

        //Declares the min and max position as the first integer in the array, because we declared it as such in the line above, if it finds nothing more than the initialized one, that meants the first element worked
        int minPosition = 0;
        int maxPosition = 0;

        for (int j = 1; j < array->sizeOfTheArray; j++) {                            //We start with j = 1, because we declared min and max to start at 0, so we dont need to check them again

            int currentValue = array->theArrayBoard[i * array->sizeOfTheArray + j];

            if (currentValue < min) {
                min = currentValue;
                minPosition = j;
            }

            if (currentValue > max) {
                max = currentValue;
                maxPosition = j;
            }
        }

        printf("\nRow %d:\n", i);

        printf("Minimum value: %d at [%d][%d]\n", min, i, minPosition);

        printf("Maximum value: %d at [%d][%d]\n", max, i, maxPosition);
    }
}

