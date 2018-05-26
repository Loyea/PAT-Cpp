#include <cstdio>
#include <cmath>

const double eps = 1e-4;

bool equ(double a ,double b){
    return fabs(a - b) < eps;
}

bool more(double a, double b) {
    return a - b > eps;
}

bool less(double a, double b){
    return a - b < -eps;
}

int main() {

    double r1, p1, r2, p2;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    double a = r1 * r2 * (cos(p1) * cos(p2) - sin(p1) * sin(p2));
    double b = r1 * r2 * (cos(p1) * sin(p2) + sin(p1) * cos(p2));

    if (equ(a, 0)) {
        printf("0.00");
    } else {
        printf("%.2f", a);
    }

    if (equ(b, 0)) {
        printf("+0.00i");
    } else if (more(b, 0)) {
        printf("+%.2fi", b);
    } else {
        printf("%.2fi", b);
    }

    return 0;
}