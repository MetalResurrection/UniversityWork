
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkLength(char *number, const char *filename);

int main() {

    printf("Enter a number to save in in.txt.\n");
    printf("The number must be between 10 and 1000, ");
    printf("with no more than 3 decimal places.\n\n");

    char number[100];
    char filename[100] = "in.txt";

    // Ask the user to enter a number
    printf("Enter a number (use a comma for decimals): ");
    scanf("%99s", number);

    // Write the number into in.txt using fwrite
    FILE *file = fopen("in.txt", "w");

    if (file == NULL) {
        printf("Could not create in.txt.\n");
        return 1;
    }

    fwrite(number, sizeof(char), strlen(number), file);
    fclose(file);

    // Check the number in the current file
    int length = checkLength(number, filename);

    // Keep asking for filenames until a valid number is found
    while (length != 1) {

        if (length == -1) {
            printf("File not found or couldn't be read.\n");
        }
        else if (length == -2) {
            printf("The number doesn't meet the criteria.\n");
        }

        printf("Please enter a different filename: ");
        scanf("%99s", filename);

        length = checkLength(number, filename);
    }

    printf("Valid number found!\n");
    printf("Number of characters: %d\n", (int)strlen(number));

    return 0;
}

int checkLength(char *number, const char *filename) {

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return -1;
    }

    if (fscanf(file, "%99s", number) != 1) {
        fclose(file);
        return -1;
    }

    fclose(file);


    char *comma = strchr(number, ',');

    if (comma == NULL || comma == number || comma[1] == '\0') {
        return -2;
    }


    int decimals = (int)strlen(comma + 1);

    if (decimals > 3) {
        return -2;
    }


    *comma = '.';

    char *end;
    double value = strtod(number, &end);

    if (*end != '\0' || value < 10.0 || value > 1000.0) {
        *comma = ',';
        return -2;
    }

    // Restore the comma
    *comma = ',';

    return 1;
}
