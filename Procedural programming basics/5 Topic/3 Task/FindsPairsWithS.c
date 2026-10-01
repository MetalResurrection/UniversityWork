#include <stdio.h>

int main() {

    printf("Please input the values of s and n: \n");
    int s, n;

    scanf("%d %d", &s, &n);

    int X[n];

    for(int i = 0; i < n; i++) {

            printf("Enter a positive number for x[%d]: ", i);
            scanf("%d", &X[i]);

            while (X[i] <= 0) {
                printf("Number must be positive. Try again: ");
                scanf("%d", &X[i]);
            }
    }


    printf("\nPairs whose multiplication result is equal to %d:\n", s);

    for (int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {

            if(X[i] * X[j] == s) {
                printf("(%d, %d)\n", X[i], X[j]);
            }
        }
    }





return 0;
}
