#include <stdio.h>
#include <math.h>

int main() {

    double x, y, z;
    double aCounting;
    double bCounting;

printf("Please insert x, y and z values: \n");
scanf("%lf %lf %lf", &x, &y, &z);

aCounting = x + 4 * y + z*z*z;
bCounting = (x+sqrt(y))*((pow(z, 4)) - fabs(z)+46.3);

printf("x+4y+z^3 is equals to: %f\n\n", aCounting);
printf("(x+root(y))*(z^4-|z|+46.3) is equals to: %f\n\n", bCounting);

return 0;
}
