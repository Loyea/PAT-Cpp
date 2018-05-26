#include <cstdio>
#include <cmath>

typedef long long LL;

//二分幂 or快速幂
//求 a^b

LL binary_pow(LL a, LL b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 1) {
        return 2 * binary_pow(a, b - 1);    //这里是-1
    } else {
        LL mul = binary_pow(a, b / 2);      //这里是/2 这里一定要用个变量保存计算的结果，而不是binary_pow*binary_pow 这样时间复杂度就上去了
        return mul * mul;
    }
}

int main() {


    LL a = binary_pow(2, 16);
    LL b = pow(2, 16);

    printf("%ld\n%ld", a, b);


    return 0;
}