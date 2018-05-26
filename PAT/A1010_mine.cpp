#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

typedef long long LL;

int to_int(char a) {
    if (a >= '0' && a <= '9') {
        return a - '0';
    } else {
        return a - 'a' + 10;
    }
}

LL to_decimal(string s, LL radix) {
    int len = s.length();
    LL result = 0;
    for (int i = 0; i < len; i++) {
        LL current_digit = to_int(s[i]);
        result = result * radix + current_digit;
        if (result < 0) {
            return -1; //-1 mean overflowed.
        }
    }
    return result;
}

LL find_minimum_radix(string s) {
    int len = s.length();
    LL min_radix = 2;
    for (int i = 0; i < len; i++) {
        LL current_digit = to_int(s[i]);
        if (current_digit + 1 > min_radix) {
            min_radix = current_digit + 1;
        }
    }
    return min_radix;
}

int cmp(LL n1, string n2, LL n2_r) {
    LL n2l = to_decimal(n2, n2_r);
    if (n2l < 0) {
        //overflow, must be large than n1
        return -1;
    }

    if (n1 == n2l) {
        return 0;
    } else if (n1 > n2l) {
        return 1;
    } else {
        return -1;
    }
}

int main() {

    string n1, n2;
    int tag;
    LL radix;

    cin >> n1;
    cin >> n2;

    scanf("%d %lld", &tag, &radix);

    if (tag == 2) {
        string temp = n2;
        n2 = n1;
        n1 = temp;
    }
    //n1 的进制为 radix

    //题目隐藏了n1的十进制数不会超过LL范围的事实。
    LL l1 = to_decimal(n1, radix);

    //对n2进行二分查找的进制下界
    LL left = find_minimum_radix(n2);
    LL right = max(left, l1);

    while (left < right) {
        LL mid = (left + right) / 2; //prevent overflow
        if (cmp(l1, n2, mid) <= 0) {    //n2 大于等于 n1
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (cmp(l1, n2, left) == 0) {
        printf("%lld", left);
    } else {
        printf("Impossible");
    }


    return 0;
}