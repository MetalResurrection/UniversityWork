#include <stdio.h>
#include <stdlib.h>

int main(){

    int *numbers = NULL;
    int count = 0;
    int number;

    printf("Enter positive numbres (Negative numbers will cause it to stop):\n");

    scanf("%d", &number);

    while (number > 0) {

            count++;

            numbers = realloc(numbers, count * sizeof(int));

            numbers[count - 1] = number;

            scanf("%d", &number);

    }

    printf("\nPrimeNumbers:\n");

    for(int i = 0; i < count; i++) {

        int isPrime = 1;
        int alreadyPrinted = 0;

        if (numbers[i] < 2) {
            isPrime = 0;
            break;
        }


        for (int j = 2; j * j <= numbers[i]; j++) {
            if (numbers[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }

           for (int j = 0; j < i; j++) {
            if (numbers[j] == numbers[i]) {
                alreadyPrinted = 1;
                break;
            }
           }

           if(isPrime && !alreadyPrinted) {
            printf("%d ", numbers[i]);
           }


        }


    free(numbers);




return 0;

}
