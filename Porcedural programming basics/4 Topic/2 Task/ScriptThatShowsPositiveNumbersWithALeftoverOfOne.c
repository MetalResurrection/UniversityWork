#include <stdio.h>
#include <stdbool.h>

int main() {

    printf("Please input a, b, c to see all the number between (a,b] that have a leftover 1 after getting divided by c: \n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (c == 0) {
        printf("Division from 0 is not possible \n");
        return 0;
    }
    printf("\n");

    bool happened = 0; //Checks if any numbers got a leftover division of 1

    for(int i = a+1; i <= b; i++) {
        if (i > 0 && i%c == 1) {
            printf("%d \n", i);
            happened = 1;
        }
    }

    if (happened == 0) {
        printf("No numbers matched the criteria \n ");
    }





return 0;
}
