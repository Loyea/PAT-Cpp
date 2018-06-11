#include <cstdio>

struct Fraction{
    long long up, down;
};

long long abs(long long a) {
    if (a < 0) {
        a = -a;
    }
    return a;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

Fraction reduction(Fraction f) {
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

Fraction add(Fraction f1, Fraction f2) {
    Fraction f;
    f.up = f1.up * f2.down + f2.up * f1.down;
    f.down = f1.down * f2.down;
    return reduction(f);
}

Fraction sub(Fraction f1, Fraction f2) {
    Fraction f;
    f.up = f1.up * f2.down - f2.up * f1.down;
    f.down = f1.down * f2.down;
    return reduction(f);
}

Fraction multi(Fraction f1, Fraction f2) {
    Fraction f;
    f.up = f1.up * f2.up;
    f.down = f1.down * f2.down;
    return reduction(f);
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction f;
    f.up = f1.up * f2.down;
    f.down = f1.down * f2.up;
    return reduction(f);
}

void showFraction(Fraction f) {
    f = reduction(f);
    if (f.up < 0) {
        printf("(");
    }

    if (f.down == 1) {
        printf("%lld", f.up);
    } else if (abs(f.up) > f.down) {
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }

    if (f.up < 0) {
        printf(")");
    }
}

int main() {

    Fraction f1, f2;

    scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);

    showFraction(f1);
    printf(" + ");
    showFraction(f2);
    printf(" = ");
    showFraction(add(f1, f2));
    printf("\n");

    showFraction(f1);
    printf(" - ");
    showFraction(f2);
    printf(" = ");
    showFraction(sub(f1, f2));
    printf("\n");

    showFraction(f1);
    printf(" * ");
    showFraction(f2);
    printf(" = ");
    showFraction(multi(f1, f2));
    printf("\n");

    

    showFraction(f1);
    printf(" / ");
    showFraction(f2);
    printf(" = ");
    f2 = reduction(f2);
    if (f2.up == 0) {
        printf("Inf");
    } else {
        showFraction(divide(f1, f2));
    }


    return 0;
}