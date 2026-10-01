#include <stdio.h>

int main() {

    printf("This program will let you enter numbers as much as you want, when you want to end it type a non-positive number \n");

    int biggestAmountOfNumbers = 0;
    int biggestInput;

      while(printf("Please enter a number \n")) {
int input;
scanf("%d", &input);



int numberAmount = 0;
int tempInput = input;

if (tempInput < 0) {
    tempInput = -tempInput;
}
   while(tempInput > 0) {
    numberAmount++;
    tempInput /= 10;
   }

   if(numberAmount > biggestAmountOfNumbers) {
    biggestAmountOfNumbers = numberAmount;
    biggestInput = input;
   }

   if (input <= 0) {
    break;
}

      }

      printf("The number with the most amount of numbers is %d", biggestInput);



return 0;
}
