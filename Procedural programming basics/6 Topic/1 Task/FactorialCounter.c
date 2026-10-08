#include <stdio.h>
#include <math.h>


int main() {

    double DoubleEnteredNumber;
    int EnterNumber;

printf("This code tells you the factorial of any positive non decimal number you enter. \nPlease enter a positive number:\n");


while (1){
    if(scanf("%lf", &DoubleEnteredNumber) != 1) {
        printf("Invalid input, please enter a number:\n");

        while (getchar() != '\n');

        continue;
    }

         if (DoubleEnteredNumber <= 0) {
        printf("The number you entered wasnt positive, please re-enter a positive number: \n");
        continue;
    }

    if (floor(DoubleEnteredNumber) != DoubleEnteredNumber) {
    printf("The number you entered wasnt a whole number. Please try again:\n");
    continue;
}

    EnterNumber = (int)DoubleEnteredNumber;

    printf("You entered: %d\n", EnterNumber);
    break;


       }

       int TheEndValue=1;

       for (int i = 1; i <= EnterNumber; i++) {
            TheEndValue = TheEndValue * i;
       }

       FILE *file =fopen("out.txt", "w");

       if (file == NULL) {
        printf("Could not create the file. \n");
        return 1;
       }

       fprintf(file, "The factorial of %d is %d\n", EnterNumber, TheEndValue);

       fclose(file);

       printf("The answer was saved to factorial.txt\n");



return 0;
}
