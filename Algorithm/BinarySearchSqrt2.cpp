#include <cstdio>

int main() {

    double left = 1, right = 2, mid;
    double eps = 1e-5;
    while (right - left > eps) {
        mid = (left + right) / 2;
        if (mid * mid > 2) {
            right = mid;
        } else {
            left = mid;
        }
    }

    printf("%f", mid);

    return 0;
}