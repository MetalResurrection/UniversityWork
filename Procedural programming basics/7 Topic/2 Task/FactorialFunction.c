#include <stdio.h>

int getFactorial(int number);

int main() {

    printf("Enter a number of which you want to find out the factorial of: \n");
    int number;
    scanf("%d", &number);
    printf("%d", getFactorial(number));



return 0;
}

int getFactorial(int number) {

    if(number < 0) {
        return 0;
    }
    if(number == 0) {
        return 1;
    }

    number *= getFactorial(number - 1);
    return number;

}

