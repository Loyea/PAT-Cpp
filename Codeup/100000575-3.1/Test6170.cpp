#include <cstdio>
#include <cmath>

long long calcP(long long a, long long da){
    int count = 0;
    long long mod;
    while (true) {
        if (a == 0) {
            break;
        }
        mod = a % 10LL;
        a = a / 10;
        if (mod == da) {
            count++;
        }
    }


    long long result = 0;
    for (int i = 0; i < count; i++) {
        result += da * pow(10, i);
    }
    return result;
}

int main() {
    long long a, da, b, db;
    while (scanf("%lld%lld%lld%lld", &a, &da, &b, &db) != EOF) {
        printf("%lld\n", calcP(a, da) + calcP(b, db));
    }
    return 0;
}