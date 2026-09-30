#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int masyvas[1000];

    printf("Please enter the interval size and the generated amount of numbers: \n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int upperBound = b;
    int lowerBound = a;

    for (int i = 0; i < c; i++) {

            int randomNumber = rand() % (upperBound - lowerBound +1) + lowerBound;

    printf("%d \n", randomNumber);


    }









    return 0;
}
