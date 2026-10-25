#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int x = 60;
    int y = 20;

    swap(&x, &y);

    printf("Po sukeitimo: x = %d, y = %d\n", x, y);

return 0;
}

void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
