#include <stdio.h>

int getPositiveNumber(char *msg);

int main() {
    int number = getPositiveNumber("Enter a number: ");

    printf("You entered: %d\n", number);

    return 0;
}

int getPositiveNumber(char *msg) {
    int number;
    char extra;

    while (1) {
        printf("%s", msg);

        if (scanf("%d%c", &number, &extra) == 2 && extra == '\n') {
            return number;
        }

        while (getchar() != '\n') {

        }
    }
}
