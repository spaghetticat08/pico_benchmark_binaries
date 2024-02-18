#include "math_library.h"

int sum_of_two(int x, int y) {
    int res = x + y;
    return res;
}

int sum_of_four(int w, int x, int y, int z) {
    int res_1 = sum_of_two(w, x);
    int res_2 = sum_of_two(y, z);
    int final_res = res_1 + res_2;
    return final_res;
}

int power_of_two(int x) {
    int res = x * x;
    return res;
}