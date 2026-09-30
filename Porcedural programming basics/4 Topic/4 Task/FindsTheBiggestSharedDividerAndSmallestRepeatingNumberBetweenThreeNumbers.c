#include <stdio.h>

int main(){
int a, b, c;

printf("Please input 3 natural numbers: \n");
scanf("%d %d %d", &a, &b, &c);

while (a == 0 || b == 0 || c == 0) {
        printf("None of the numbers can be 0, please re-enter the values \n");
        scanf("%d %d %d", &a, &b, &c);
    }


int max;
int biggest_shared_divider = 0;
if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }

for (int i = 1; i <= max; i++) {

    if(a%i == 0 && b%i == 0 && c%i == 0) {
        if (biggest_shared_divider < i) {
            biggest_shared_divider = i;
        }
    }
}
    int lcm = max;
    while (lcm % a != 0 || lcm % b != 0 || lcm % c != 0) {
        lcm += max;
    }

printf("Biggest shared divider %d \n", biggest_shared_divider);
printf("Least common multiple %d", lcm);






return 0;
}
