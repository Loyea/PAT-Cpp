#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    long long a, b, c;
    bool res;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if (a > 0 && b > 0) {
            if (sum < 0) { //overflowed, a + b must more than c.
                res = true;
            } else {
                res = sum > c;
            }
        } else if (a < 0 && b < 0) {
            if(sum >= 0) { // !!!>=!!! sum may be 0. overflowed, a + b must less than c.
                res = false;
            } else {
                res = sum > c;
            }
        } else {
            res = sum > c;
        }

        if (res) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}