#include <stdio.h>
#include <math.h>

int main() {

    int a, b, c;


    printf("Please insert your a, b and c values (ax^2+bx+c=0): \n");  //Info gets put into the code by the user
    scanf("%d %d %d", &a, &b, &c);

    if (a==0){
        if (b==0) {
            if (c==0) {
                printf("Infinite solutions. \n");
            } else {
            printf("No solution. \n");
            }
        } else {

        printf("The answer is %lf\n", -c / b);
        }
        return 0;
    }

    double discriminant = b*b - 4*a*c; //The discriminant gets counted


    if (discriminant < 0) {
        printf("The equation has no answers");   //If the discriminant is less than zero the equation cannot be solved
    }

    if (discriminant == 0) {
        printf("The equation has one answer and its: x = %lf ", -b /(2.0 *a));  //If the discriminant is equal to 0, it only has one solution
    }

    if (discriminant > 0) {
        printf("The equation has two answers and they are: x1 = %lf and x2 = %lf", (-b+sqrt(discriminant))/(2.0 *a), (-b-sqrt(discriminant))/(2.0 *a)); //If the discriminant is above 0 it has two solutions
    }




return 0;
}
