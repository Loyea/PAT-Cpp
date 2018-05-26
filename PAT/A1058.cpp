#include <cstdio>

int main() {
    long long a1, b1, c1, a2, b2, c2;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &b1, &c1, &a2, &b2, &c2);
    long long sum1_knuts = 0, sum2_knuts = 0;
    sum1_knuts = a1 * 17 * 29 + b1 * 29 + c1;
    sum2_knuts = a2 * 17 * 29 + b2 * 29 + c2;

    long long sum = sum1_knuts + sum2_knuts;

    long long a3 = sum / (17 * 29);
    long long b3 = (sum - a3 * 17 * 29) / 29;
    long long c3 = sum - a3 * 17 * 29 - b3 * 29;

    printf("%lld.%lld.%lld", a3, b3, c3);

    return 0;
}