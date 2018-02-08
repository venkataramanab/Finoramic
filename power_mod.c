//
// Created by venkataramana on 08/02/18.
//
/*
 *
https://www.interviewbit.com/problems/implement-power-function/

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

 Constraint: Expecting x,n,d are positive integers.
 * */
#include <printf.h>

void main() {
    int x, n, d;
    scanf("%d%d%d", &x, &n, &d);
    printf("result %d", powMod(x, n, d));
}

int powMod(int x, int n, int d) {
    int result = 1;
    x = x % d;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * x) % d;
        }
        n /= 2;
        x = (x * x) % d;
    }
    return result;
}