#include "pico/stdlib.h"

#include "math_library.h"


int main() {

    int a = 3;
    int b = 4;
    int c = 8;
    int d = 2;

    int res_1 = sum_of_two(a, b);
    printf("The result of the sum of %d and %d is %d\n", a, b, res_1);

    int res_2 = sum_of_four(a, b, c, d);
    printf("The result of the sum of %d and %d and %d and %d is %d\n", a, b, c, d, res_2);

    int res_3 = power_of_two(a);
    printf("The power of %d is %d", a, res_3);

}