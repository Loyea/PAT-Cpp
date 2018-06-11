#include <cstdio>

typedef long long LL;

struct fraction {
    LL up, down;
    fraction() {
        up = 0;
        down = 1;   //important!
    }
};

LL abs(LL a) {
    if (a < 0) {
        a = -a;
    }
    return a;
}

LL gcd(LL a, LL b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

fraction add(fraction f1, fraction f2) {
    fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return result;
}

fraction reduction(fraction f) {
    if (f.down < 0) {
        f.up *= -1;
        f.down *= -1;
    }

    if (f.up == 0) {
        f.down = 1;
    } else {
        LL d = gcd(f.up, f.down);
        f.up /= d;
        f.down /= d;
    }
    return f;
}

void showFraction(fraction f) {
    if (f.down == 1) {
        printf("%lld", f.up);
    } else if (abs(f.up) > f.down) {
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
}

int main() {
    int n;
    fraction f[110];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &f[i].up, &f[i].down);
    }

    fraction result;
    for (int i = 0; i < n; i++) {
        result = add(result, f[i]);
    }

    result = reduction(result);

    showFraction(result);



    return 0;
}