#include <cstdio>
#include <cmath>

typedef long long ll;

const int maxn = 100000;
ll prime[maxn], pNum = 0;
bool p[maxn] = {false};

struct factor {
    ll x, count;
};

void find_prime(ll n) {
    for (ll i = 2; i < n; i++) {
        if (p[i] == false) {
            prime[pNum++] = i;
            for (ll j = i + i; j < n; j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    ll n, duplicate;
    scanf("%lld", &n);
    duplicate = n;

    if (n == 1) {
        printf("1=1");
        return 0;
    }

    ll upper = (ll) sqrt(1.0 * n);
    find_prime(upper + 1); //允许upper取到

    factor fac[100];

    int fac_count = 0;

    for (ll i = 0; i < pNum; i++) {
        if (n % prime[i] == 0) {
            fac[fac_count].x = prime[i];
            fac[fac_count].count = 0;
            while (n % prime[i] == 0) {
                fac[fac_count].count++;
                n /= prime[i];
            }
            fac_count++;
        }
    }

    if (n != 1) {
        fac[fac_count].x = n;
        fac[fac_count].count = 1;
        fac_count++;
    }



    printf("%lld=", duplicate);
    for (int i = 0; i < fac_count; i++) {
        printf("%lld", fac[i].x);
        if (fac[i].count > 1) {
            printf("^%lld", fac[i].count);
        }
        if (i != fac_count - 1) {
            printf("*");
        }
    }


    return 0;
}