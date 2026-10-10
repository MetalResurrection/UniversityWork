#include <stdio.h>
#include <stdbool.h>

int main() {

    printf("This program will take the date you enter and output what day it is.\n\n"
           "Enter the date in this format YYYY-MM-DD: ");

           bool validDate = false;
           unsigned int day, month, year;

    while(!validDate) {
     if(scanf("%u-%u-%u", &year, &month, &day) == 3 && day <= 31 && month <= 12 && day >= 1 && month >= 1 && year >= 1) {
      validDate = true;
     }
     else {
        printf("Invalid date! Please try again.\n");

        while (getchar() != '\n');
     }
    }

    int offsets[] = {0, 3, 2, 5, 0, 3, //How many numbers to subtract to get the day number
                 5, 1, 4, 6, 2, 4};

                 int adjustedYear = year;

                 if (month < 3) {
                    adjustedYear--;
                 }

                 int weekday = (adjustedYear + adjustedYear/4 - adjustedYear/100 + adjustedYear/400 + offsets[month - 1] + day) % 7;

                 int index = (weekday + 6) % 7;


char weekdays[7][100];
FILE *file = fopen("week.txt", "r");

if (file == NULL) {
    printf("Could not open week.txt!\n");
    return 1;
}

for (int i = 0; i < 7; i++) {
    if (fgets(weekdays[i], sizeof(weekdays[i]), file) == NULL) {
        printf("Error reading week.txt!\n");
        fclose(file);
        return 1;
    }

    for (int j = 0; weekdays[i][j] != '\0'; j++) {
        if (weekdays[i][j] == '\n' || weekdays[i][j] == '\r') {
            weekdays[i][j] = '\0';
            break;
        }
    }
}

fclose(file);

printf("The day is: %s\n", weekdays[index]);







return 0;
}
