#include <stdio.h>

int main() {

    int WrittenNumber;

    scanf("%d", &WrittenNumber);

    printf("The number is %s\n", (WrittenNumber % 2 == 0) ? "even" : "not even");


return 0;

}
