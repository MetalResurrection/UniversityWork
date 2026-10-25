//This is a code that you input integers until you input a "0" in which it will stop and then tell you the sum of every number that started with "1" E.g.: 1000, 1023, 1234. NOT: 2423, 0.25, 0abc;

#include <stdio.h>
#include <stdlib.h>


int main() {

    int *numbers = NULL;
    int num, count = 0;
    char line[100];
    char extra;

    printf("Please enter a element you want to add to the array, to stop adding - type a \'0\'\n");

    while(1) {
         if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        if (sscanf(line, "%d %c", &num, &extra) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            continue;
        }

        if (num == 0) {
            break;
        }

        int *temp = realloc(numbers, (count +1) * sizeof(int));

        if (temp == NULL) {
            printf("Memory allocation has failed.");
            free(numbers);
            return 1;
        }

        numbers = temp;
        numbers[count] = num;
        count++;
    }

    int sum = 0;

    for (int i = 0; i < count; i++) {
    int num = numbers[i];

    while (num >= 10 || num <= -10) {
        num /= 10;
    }

    if (num == 1 || num == -1) {
        sum += numbers[i];
    }
}

printf("The sum of every starting with 1 is: %d\n", sum);

    free(numbers);
return 0;
}
