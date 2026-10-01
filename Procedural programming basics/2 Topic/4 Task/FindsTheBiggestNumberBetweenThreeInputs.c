#include <stdio.h>

int main() {

    int firstNumber, secondNumber, thirdNumber;


    scanf("%d %d %d", &firstNumber, &secondNumber, &thirdNumber);

    int theMaxNumberBetweenFirstAndSecond = (firstNumber > secondNumber) ? firstNumber : secondNumber;
    int theMaxNumber = (theMaxNumberBetweenFirstAndSecond > thirdNumber) ? theMaxNumberBetweenFirstAndSecond : thirdNumber;

    int theMinNumberBetweenFirstAndSecond  = (firstNumber < secondNumber) ? firstNumber : secondNumber;
    int theMinNumber = (theMinNumberBetweenFirstAndSecond < thirdNumber) ? theMinNumberBetweenFirstAndSecond : thirdNumber;

    printf("The Max number is: %d \nThe Min number is: %d ", theMaxNumber, theMinNumber);







return 0;
}
