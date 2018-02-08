//
// Created by venkataramana on 08/02/18.
//

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