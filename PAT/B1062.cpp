#include <cstdio>

struct fraction {
    long long up, down;
};

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

long long abs(long long a) {
    if (a < 0) {
        a = -a;
    }
    return a;
}

fraction reduction(fraction f) {
    if (f.down < 0) {
        f.up *= -1;
        f.down *= -1;
    }
    if (f.up == 0) {
        f.down = 1;
    } else {
        long long d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}

long long lcm(long long a, long long b) {
    long long d = gcd(a, b);
    return a / d * b;
}



int main() {
    fraction f1, f2;
    long long n;

    scanf("%lld/%lld %lld/%lld %lld", &f1.up, &f1.down, &f2.up, &f2.down, &n);

    f1 = reduction(f1);
    f2 = reduction(f2);

    long long m1 = lcm(f1.down, f2.down);
    long long m2 = lcm(m1, n);

    long long start = m2 / f1.down * f1.up;
    long long end = m2 / f2.down * f2.up;

    if (start > end) {
        long long temp = start;
        start = end;
        end = temp;
    }

    fraction temp;
    int count = 0;
    for (long long i = start + 1; i < end; i++) {
        temp.up = i;
        temp.down = m2;
        temp = reduction(temp);
        if (temp.down == n) {
            if (count != 0) {
                printf(" ");
            }
            printf("%lld/%lld", temp.up, temp.down);
            count++;
        }
    }


    return 0;
}