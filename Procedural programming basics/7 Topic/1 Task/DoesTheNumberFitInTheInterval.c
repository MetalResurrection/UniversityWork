#include <stdio.h>

int isInRange(int number, int low, int high);


int main() {

    printf("Please enter a number and the range you want to check it fits (Order of entering: number, low range, high range: \n");
    int number, low, high;
    scanf("%d %d %d", &number, &low, &high);

    if(isInRange(number, low, high) != 1) {
        printf("false");
    }
    else
        printf("true");

return 0;
}

int isInRange(int number, int low, int high) {

    if(low == high) {
        return 0;
    }

    if(number > high || number < low) {
        return 0;
    }

    return 1;
}
