#include <cstdio>
#include <cmath>

const double pi = acos(-1);
const double eps = 1e-5;

// r = S1/S2
//S2是半圆面基
//S1是扇形面积减去三角形面基
//扇形面积 = 半径 * 弧长 / 2
// 弧长 = 半径 * 角度
double calc_r(double h, double R) {
    double angle_aob = 2 * acos((R - h) / R);
    double ab_arc = R * angle_aob;
    double sector_aob = R * ab_arc / 2;
    double len_ab = 2 * sqrt(R * R - (R - h) * (R - h));
    double triangle_aob = len_ab * (R - h) / 2;
    double s1 = sector_aob - triangle_aob;
    double s2 = pi * R * R / 2;
    return s1 / s2;
}

int main() {

    double R = 4, left = 0, right = 4, mid, r = 0;

    while (right - left > eps) {
        mid = (left + right) / 2;
        if (calc_r(mid, R) > r) {
            right = mid;
        } else {
            left = mid;
        }
    }
    printf("%f", mid);

    return 0;
}