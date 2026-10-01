#include <stdio.h>

int main() {

    printf("How many numbers do you want to enter?\n");

    int n;
    scanf("%d", &n);

    double N[n];

    double sum = 0;
    double minimum, maksimum;

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &N[i]);

        sum += N[i];

        if (i == 0) {
            minimum = N[i];
            maksimum = N[i];
        } else {
            if (N[i] < minimum) {
                minimum = N[i];
            }

            if (N[i] > maksimum) {
                maksimum = N[i];
            }
        }
    }

    double vidurkis = sum / n;

    printf("\nSum: %.2lf\n", sum);
    printf("Vidurkis: %.2lf\n", vidurkis);
    printf("Minimumas: %.2lf\n", minimum);
    printf("Maksimumas: %.2lf\n", maksimum);

    return 0;
}

