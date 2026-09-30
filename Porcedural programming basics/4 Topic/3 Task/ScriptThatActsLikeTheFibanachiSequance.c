#include <stdio.h>

int main() {

printf("Please input whole positive values of a, b and c \n");
int a, b, c;
scanf("%d %d %d", &a,&b,&c);
int fibonacciNumber = 0;

if (c == 0) {                         //A check for when c input is 0, as the for loop messes up on these positions
    printf("The number is: %d", a);
    return 0;
} else if (c == 1) {
    printf("The number is: %d", b);
    return 0;
    }

    int prev1 = a;
    int prev2 = b;


for(int i = 0;  i < c-1; i++) {                           //Fibonachi number couner
        fibonacciNumber = prev1 + prev2;

        prev1 = prev2;
        prev2 = fibonacciNumber;

}

printf("The number is: %d", fibonacciNumber);







return 0;
}
