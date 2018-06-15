#include <cstdio>
#include <cmath>

typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    ll start = 0, len = 0;
    ll sqr = (ll) sqrt(1.0 * n);

    for (ll i = 2; i <= sqr; i++) {
        ll temp = 1, j = i;
        while (true) {
            temp *= j;
            if (n % temp == 0) {
                if (j - i + 1 > len) {
                    len = j - i + 1;
                    start = i;
                }
            } else {
                break;
            }
            j++;
        }
    }


    if (len == 0) {
        printf("1\n%lld", n);
    } else {
        printf("%lld\n", len);
        for (ll i = 0; i < len; i++) {
            printf("%lld", start + i);
            if (i != len - 1) {
                printf("*");
            }
        }
    }

    return 0;
}