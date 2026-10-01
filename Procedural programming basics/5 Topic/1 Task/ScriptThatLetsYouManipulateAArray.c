#include <stdio.h>

int main() {

    int masyvas[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int dydis = 10;
    for (int i = 0; i < dydis; i++) {
        printf("%d ", masyvas[i]);
    }
    printf("\n");
    masyvas[0] = 1;
    masyvas[3] = 2;
    masyvas[9] = 3;

    for (int i = 2; i < dydis - 1; i++) {
        masyvas[i] = masyvas[i+1];
    }
    dydis--;

    for (int i = dydis; i > 6; i--) {
        masyvas[i] = masyvas[i - 1];
    }
    masyvas[6] = 4;
    dydis++;

     for (int i = 0; i < dydis; i++) {
        printf("%d ", masyvas[i]);
    }
    printf("\n");

    int x, y;

    while (printf("Please write which array element you want to replace [1-10] and what number you want instead of the existing one: \n")) {
    scanf("%d %d", &x, &y);

    if(x > dydis || x < 0) {
        printf("x value can't be below the 0 or higher than the array size [1-10]");
    }
    else {
        masyvas[x-1] = y;
        break;
    }
    }

         for (int i = 0; i < dydis; i++) {
        printf("%d ", masyvas[i]);
    }
    printf("\n");


    while (printf("Please write which array element you want to remove [1-10]: \n")) {
    scanf("%d", &x);

    if(x > dydis || x < 0) {
        printf("x value can't be below the 0 or higher than the array size [1-10]");
    }
    else {
        for (int i = x-1; i < dydis - 1; i++) {
            masyvas[i] = masyvas[i+1];
        }
        dydis--;
        break;
    }
    }




while (printf("Please write in which position [1-10] you'd like to add a element and what number: \n")) {
    scanf("%d %d", &x, &y);

    if(x > dydis || x < 0) {
        printf("x value can't be below the 0 or higher than the array size [1-10]");
    }
    else {
            for (int i = dydis; i > x-1; i--) {
        masyvas[i] = masyvas[i - 1];
    }
    masyvas[x-1] = y;
    dydis++;

        break;
    }
    }

  for (int i = 0; i < dydis; i++) {
        printf("%d ", masyvas[i]);
    }
    printf("\n");









return 0;
}
