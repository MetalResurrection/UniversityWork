#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int main() {

    printf("This code will ask you to input 3 numbers and will output the number thats the middle number by value. \n\n");

           char InputSequence[100];
           bool validNumber = false;
           int howManySemiColons = 0;
           int num1, num2, num3;
           int MiddleNumber;

           while(!validNumber) {
                printf("Please enter the sequence which includes 3 numbers each separated by a \";\" the values can be negative and positive, this input mustn't be larger than 100 characters: ");
                scanf("%99s", InputSequence);
                howManySemiColons = 0;

                validNumber = true;


    for (int i = 0; i < strlen(InputSequence); i++) {
            if(InputSequence[i] == ';') {
                howManySemiColons++;
            }
    if (!isdigit(InputSequence[i]) && InputSequence[i] != ';' && InputSequence[i] != '-') {

        printf("\nThis number doesn't meet the criteria.\n\n");
        validNumber = false;
        break;
    }
           if(howManySemiColons > 2) {
            printf("\nYou have inputed too many \";\" \n\n ");
            validNumber = false;
            break;
           }
}


if (sscanf(InputSequence, "%d;%d;%d", &num1, &num2, &num3) != 3) {
    printf("Invalid input format.\n");
    validNumber = false;
}
           }


if ((num1 >= num2 && num1 <= num3) ||
    (num1 <= num2 && num1 >= num3)) {
    MiddleNumber = num1;
}
else if ((num2 >= num1 && num2 <= num3) ||
         (num2 <= num1 && num2 >= num3)) {
    MiddleNumber = num2;
}
else {
    MiddleNumber = num3;
}

bool validFileName = false;
char fileName[100];
int lengthOfFile;

while(!validFileName) {
        printf("Please write a name for the txt file you wish to make, it must end with .txt\n");

        scanf("%99s", &fileName);

        lengthOfFile = strlen(fileName);

        if(lengthOfFile < 4 || strcmp(fileName + lengthOfFile - 4, ".txt") != 0) {
            printf("Filename must end in .txt!\n\n");
        }
        else {
            printf("Filename is valid %s\n", fileName);
            validFileName = true;
        }


}

FILE *file = fopen(fileName, "w");

if (file == NULL) {
    printf("Error creating the file \n");
    return 1;
}

fprintf(file, "Middle number: %d", MiddleNumber);

fclose(file);

printf("Information saved to %s\n", fileName);





return 0;
}

