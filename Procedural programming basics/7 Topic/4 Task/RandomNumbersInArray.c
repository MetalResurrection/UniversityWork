#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high);

int main() {

    srand(time(NULL));

    printf("Enter the desired number generated amount, the minimum and the maximum number:\n");
    int size, low, high;
    while(scanf("%d %d %d", &size, &low, &high)) {
     if (size < 0 || low > high || high < low) {
        printf("The entered numbers are incorrect, either the size is below 0, or the low and high are not possible, please re-enter the values: \n");
     }
     else
     break;
    }
    int data[size];
    generateArray(data, size, low, high);



return 0;
}

void generateArray(int data[], int size, int low, int high) {

    for (int i = 0; i < size; i++) {
        data[i] = (rand() % (high - low + 1)) + low;

        printf("%d ", data[i]);
    }



}
